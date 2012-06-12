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

using Rocket::Core::Context;
using Rocket::Core::Element;
using Rocket::Core::EventListener;

namespace WidgetManagerRocketHelp
{

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

}   // namespace WidgetManagerRocketHelp

void WidgetManagerRocket::Init (const orxSTRING widgetName, ScrollFrameWindow *scrollWindow)
{
    m_scrollWindow = scrollWindow;
    strcpy (m_windowName, widgetName);

    Context *context = ScrollGUIRocket::GetContext ();
    Element *root = context->GetRootElement ();

    EventListener *listener =
	reinterpret_cast<EventListener *> (ScrollGUIRocket::GetListener ());
    WidgetManagerRocketHelp::AddListenerRecursive (listener, root);
}

ScrollWidget * WidgetManagerRocket::FindWidget (const orxSTRING widgetName)
{
    ScrollWidget *theWidget = NULL;
    vector<ScrollWidget *>::iterator widgIter;
    for (widgIter = m_widgetList.begin (); widgIter != m_widgetList.end ();
	 ++widgIter)
    {
	if (orxString_Compare ((*widgIter)->GetName (), widgetName) == 0)
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
    Context *context = ScrollGUIRocket::GetContext ();
    Element *root = context->GetRootElement ();

    Element *element = root->GetElementById (widgetName);
    element->SetAttribute ("value", "mytext");
}

void WidgetManagerRocket::FillList (const orxSTRING widgetName,
			      const vector<const orxSTRING> &listItems)
{
}

void WidgetManagerRocket::OnMouseClick (const orxSTRING widgetName)
{
    m_scrollWindow->HandleMouseClick (widgetName);
}

void WidgetManagerRocket::OnTextAccepted (const orxSTRING widgetName)
{
    m_scrollWindow->HandleTextAccepted (widgetName);
}