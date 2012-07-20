/**
 * @file WidgetManagerRocket.cpp
 * @date 2012-06-09
 * @author fritz@fritzmahnke.com
 *
 */
#ifdef USE_LIBROCKET
#include "WidgetManagerRocket.h"
#include "Rocket/Core.h"
#include "Rocket/Controls.h"
#include "ScrollFrameWindow.h"
#include "ScrollWidget.h"
#include "ScrollGUIRocket.h"
#include "RocketListbox.h"
#include "RocketDataSource.h"
#include "RocketListener.h"

using Rocket::Core::Context;
using Rocket::Core::Element;
using Rocket::Core::EventListener;
using Rocket::Core::String;
using Rocket::Core::Variant;
using Rocket::Controls::ElementDataGrid;

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
	element->AddEventListener ("mousedown", listener);
	AddListenerRecursive (listener, element);
    }
}

void RemoveListenerRecursive (EventListener *listener, Element *root)
{
    for (Element *element = root->GetFirstChild ();
	 element != NULL;
	 element = element->GetNextSibling ())
    {
	element->RemoveEventListener ("keydown", listener);
	element->RemoveEventListener ("mousedown", listener);
	RemoveListenerRecursive (listener, element);
    }
}

}   // namespace widget_manager_rocket

WidgetManagerRocket::WidgetManagerRocket () :
    m_scrollWindow (NULL),
    m_dataSource   (NULL),
    m_listener     (NULL)
{
};

WidgetManagerRocket::~WidgetManagerRocket ()
{
    delete m_dataSource;
    widget_manager_rocket::RemoveListenerRecursive (
	m_listener,
	widget_manager_rocket::GetRootElement ());
    delete m_listener;
}

void WidgetManagerRocket::Init (const orxSTRING widgetName,
				ScrollFrameWindow *scrollWindow)
{
    m_scrollWindow = scrollWindow;
    // Setup window name
    strcpy (m_windowName, widgetName);
    // Create event listener
    m_listener     = new RocketListener (this);

    //! @todo Each window will need to pass a unique data source name
    m_dataSource = new RocketDataSource ("objectsectionlist");

    Element *root = widget_manager_rocket::GetRootElement ();

    widget_manager_rocket::AddListenerRecursive (m_listener, root);
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
	    // Get element's id
	    const orxSTRING name = element->GetId ().CString ();
	    // Get element's source attribute
	    Variant *source = element->GetAttribute ("source");
	    const orxSTRING sourceName =
		source->Get<String>().CString ();
	    // Find table name (everything after '.')
	    int length = orxString_GetLength (sourceName);
	    int tableIndex = orxString_SearchCharIndex (sourceName, '.', 0);
	    orxSTRING tableName = new orxCHAR [length - tableIndex];
	    orxString_NCopy (tableName, sourceName + tableIndex + 1,
			     length - tableIndex); 

	    // Initialize list box
	    listbox->Init (name);
	    listbox->SetDataTableName (tableName);
	    listbox->SetDataSource (m_dataSource);
	    delete [] tableName;
	    // Add list box to widget list
	    m_widgetList.push_back (listbox);
	}
	AddWidgetRecursive (element);
    }
}

ScrollWidget * WidgetManagerRocket::FindWidget
    (const orxSTRING widgetName) const
{
    orxASSERT (widgetName != orxNULL);

    ScrollWidget *theWidget = NULL;
    vector<ScrollWidget *>::const_iterator widgIter;
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

const orxSTRING WidgetManagerRocket::GetText (const orxSTRING widgetName) const
{
    return NULL;
}

const orxSTRING WidgetManagerRocket::GetWindowName () const
{
    return m_windowName;
}

const orxSTRING WidgetManagerRocket::GetSelectedItem
    (const orxSTRING widgetName) const
{
    orxASSERT (widgetName != orxNULL);

    RocketListbox *listbox =
	reinterpret_cast<RocketListbox *> (FindWidget (widgetName));
    return listbox->GetSelectedItems ();
}

void WidgetManagerRocket::SetSelectedItem (const orxSTRING widgetName,
                                           const orxSTRING selectedItem)
{
    orxASSERT (widgetName != orxNULL);
    orxASSERT (selectedItem != orxNULL);

    RocketListbox *listbox =
	reinterpret_cast<RocketListbox *> (FindWidget (widgetName));

    listbox->SetSelectedItems (selectedItem);
}

int WidgetManagerRocket::SetText (const orxSTRING widgetName, const orxSTRING text)
{
    orxASSERT (widgetName != orxNULL);
    orxASSERT (text       != orxNULL);

    int status = 0;

    Element *root = widget_manager_rocket::GetRootElement ();
    if (root != orxNULL)
    {
	Element *element = root->GetElementById (widgetName);
	if (element != orxNULL)
	{
	    element->SetAttribute ("value", text);
	    status = 1;
	}
    }
    return status;
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
	    const orxSTRING tag = widget->GetTagName ().CString ();
	    if (orxString_ICompare (tag, "datagrid") == 0)
	    {
		ElementDataGrid *datagrid =
		    reinterpret_cast<ElementDataGrid *> (widget);
		/*
		 *  This wouldn't work if more than one field is shown in a Rocket
		 *  DataGrid column.
		 */
		const ElementDataGrid::Column *firstColumn =
		    datagrid->GetColumn (0);
		if (firstColumn != orxNULL)
		{
		    const orxSTRING fieldName =
			firstColumn->fields.at (0).CString ();

		    RocketListbox *listbox =
			(RocketListbox *) FindWidget (widgetName);
		    orxASSERT (listbox != orxNULL);
		    if (listbox != orxNULL)
		    {
			listbox->Fill (fieldName, listItems);
		    }
		}
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
#endif