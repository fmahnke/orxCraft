/**
 * @file WidgetManagerRocket.cpp
 * @date 2012-06-09
 * @author fritz@fritzmahnke.com
 *
 */

#include "WidgetManagerRocket.h"
#include "Rocket/Core.h"
#include "ScrollFrameWindow.h"
#include "ScrollWidget.h"
#include "ScrollGUIRocket.h"
#include "RocketListbox.h"

using Rocket::Core::Context;
using Rocket::Core::Element;
using Rocket::Core::EventListener;

namespace widget_manager_rocket
{

Element * GetRootElement ()
{
    Context *context = ScrollGUIRocket::GetContext ();
    Element *root = context->GetRootElement ();

    return root;
}

void AddListenerRecursive (EventListener *listener, Element *root)
{
    for (Element *element = root->GetFirstChild ();
	 element != NULL;
	 element = element->GetNextSibling ())
    {
	element->AddEventListener ("keydown", listener);
	AddListenerRecursive (listener, element);
    }
}

}   // namespace widget_manager_rocket

void WidgetManagerRocket::Init (const orxSTRING widgetName,
				ScrollFrameWindow *scrollWindow)
{
    m_scrollWindow = scrollWindow;
    strcpy (m_windowName, widgetName);

    Element *root = widget_manager_rocket::GetRootElement ();

    EventListener *listener =
	reinterpret_cast<EventListener *> (ScrollGUIRocket::GetListener ());
    widget_manager_rocket::AddListenerRecursive (listener, root);
    AddWidgetRecursive (root);
}

void WidgetManagerRocket::AddWidgetRecursive (const Element *root)
{
    orxASSERT (root != orxNULL);

    for (Element *element = root->GetFirstChild ();
	 element != NULL;
	 element = element->GetNextSibling ())
    {
	const orxSTRING tagName = element->GetTagName ().CString ();
	if (orxString_ICompare (tagName, "datagrid") == 0)
	{
	    // As of now, only a single column list box is supported.
	    RocketListbox *listbox = new RocketListbox (this);
	    const orxSTRING name = element->GetId ().CString ();

	    listbox->Init (name);
	    m_widgetList.push_back (listbox);
	}
	AddWidgetRecursive (element);
    }
}

ScrollWidget * WidgetManagerRocket::FindWidget (const orxSTRING widgetName)
{
    orxASSERT (widgetName != orxNULL);

    ScrollWidget *theWidget = NULL;
    vector<ScrollWidget *>::iterator widgIter;
    for (widgIter = m_widgetList.begin (); widgIter != m_widgetList.end ();
	 ++widgIter)
    {
	if (orxString_ICompare ((*widgIter)->GetName (), widgetName) == 0)
	{
	    theWidget = *widgIter;
	    break;
	}
    }
	 
    return theWidget;
}

const orxSTRING WidgetManagerRocket::GetText (const orxSTRING widgetName)
{
    return NULL;
}

const orxSTRING WidgetManagerRocket::GetWindowName ()
{
    return m_windowName;
}

const orxSTRING WidgetManagerRocket::GetSelectedItem (const orxSTRING widgetName)
{
    orxASSERT (widgetName != orxNULL);

    return NULL;
}

void WidgetManagerRocket::SetText (const orxSTRING widgetName, const orxSTRING text)
{
    Element *root = widget_manager_rocket::GetRootElement ();

    Element *element = root->GetElementById (widgetName);
    element->SetAttribute ("value", "mytext");
}

void WidgetManagerRocket::FillList (const orxSTRING widgetName,
			      const vector<const orxSTRING> &listItems)
{
    orxASSERT (widgetName != orxNULL);
    orxASSERT (! listItems.empty ());

    Element *root = widget_manager_rocket::GetRootElement ();
    if (root != orxNULL)
    {
	Element *widget = root->GetElementById (widgetName);
	if (widget != orxNULL)
	{
	    RocketListbox *listbox =
		(RocketListbox *) FindWidget (widgetName);
	    if (listbox != orxNULL)
	    {
		listbox->Fill ("sections", listItems);
	    }
	    else
	    {
		//orxASSERT (false);
	    }
	}
    }
}

void WidgetManagerRocket::OnMouseClick (const orxSTRING widgetName)
{
    m_scrollWindow->HandleMouseClick (widgetName);
}

void WidgetManagerRocket::OnTextAccepted (const orxSTRING widgetName)
{
    m_scrollWindow->HandleTextAccepted (widgetName);
}
