/**
 * @file WidgetManagerCEGUI.cpp
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "WidgetManagerCEGUI.h"
#include "ScrollFrameWindow.h"
#include "CEGUICombobox.h"
#include "CEGUIEditbox.h"
#include "CEGUIListbox.h"
#include "CEGUIPushButton.h"

using CEGUI::Combobox;
using CEGUI::Listbox;
using CEGUI::Window;

void WidgetManagerCEGUI::Init (const orxSTRING widgetName,
			       ScrollFrameWindow *scrollWindow)
{
    m_scrollWindow = scrollWindow;
    strcpy (m_windowName, widgetName);
    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *window = rootWindow->getChild (widgetName);
    
    int counter = window->getChildCount ();
    for (int i = 0; i < counter; i++)
    {
	const orxSTRING type = window->getChildAtIdx (i)->getType ().c_str ();
	const orxSTRING name = window->getChildAtIdx (i)->getName ().c_str ();
	if (orxString_Compare (type, "TaharezLook/Checkbox") == 0)
	{
	    orxASSERT (false);
	    /*
	    CEGUICheckbox *checkbox = new CEGUICheckbox (this);
	    checkbox->Init (name);
	    m_widgetList.push_back (checkbox);
	    */
	}
	else if (orxString_Compare (type, "TaharezLook/Combobox") == 0)
	{
	    CEGUICombobox *combobox = new CEGUICombobox (this);
	    combobox->Init (name);
	    m_widgetList.push_back (combobox);
	}
	else if (orxString_Compare (type, "TaharezLook/Editbox") == 0)
	{
	    CEGUIEditbox *editbox = new CEGUIEditbox (this);
	    editbox->Init (name);
	    m_widgetList.push_back (editbox);
	}
	else if (orxString_Compare (type, "TaharezLook/Listbox") == 0)
	{
	    CEGUIListbox *listbox = new CEGUIListbox (this);
	    listbox->Init (name);
	    m_widgetList.push_back (listbox);
	}
	else if (orxString_Compare (type, "TaharezLook/Button") == 0)
	{
	    CEGUIPushButton *pushbutton = new CEGUIPushButton (this);
	    pushbutton->Init (name);
	    m_widgetList.push_back (pushbutton);
	}
    }
}

ScrollWidget * WidgetManagerCEGUI::FindWidget
    (const orxSTRING widgetName) const
{
    ScrollWidget *theWidget = NULL;
    vector<ScrollWidget *>::const_iterator widgIter;
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

const orxSTRING WidgetManagerCEGUI::GetWindowName () const
{
    return m_windowName;
}

const orxSTRING WidgetManagerCEGUI::GetSelectedItem
    (const orxSTRING widgetName) const
{
    orxASSERT (widgetName != orxNULL);

    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *window = rootWindow->getChild (m_windowName);
    CEGUI::Listbox *listbox = (CEGUI::Listbox *) window->getChild (widgetName);

    CEGUI::ListboxItem *item = listbox->getFirstSelectedItem ();
    const orxSTRING itemName = item->getText ().c_str ();

    return itemName;
}

void WidgetManagerCEGUI::SetSelectedItem (const orxSTRING widgetName,
			                  const orxSTRING selectedItem)
{
    orxASSERT (false);
}

const orxSTRING WidgetManagerCEGUI::GetText (const orxSTRING widgetName) const
{
    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *window = rootWindow->getChild (m_windowName);
    CEGUI::Window *widget = window->getChild (widgetName);

    return widget->getText ().c_str ();
}

int WidgetManagerCEGUI::SetText (const orxSTRING widgetName, const orxSTRING text)
{
    int status = 1;

    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *window = rootWindow->getChild (m_windowName);
    CEGUI::Window *widget = window->getChild (widgetName);

    widget->setText (text);
    return status;
}

void WidgetManagerCEGUI::FillList (const orxSTRING widgetName,
			      const vector<const orxSTRING> &listItems)
{
    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *window = rootWindow->getChild (m_windowName);
    CEGUI::Window *widget = window->getChild (widgetName);
    const orxSTRING widgetType = widget->getType ().c_str ();

    if (orxString_Compare (widgetType, "TaharezLook/Combobox") == 0)
    {
	CEGUICombobox *combobox = (CEGUICombobox *) FindWidget (widgetName);
	combobox->Fill (listItems);
    }
    else if (orxString_Compare (widgetType, "TaharezLook/Listbox") == 0)
    {
	CEGUIListbox *listbox = (CEGUIListbox *) FindWidget (widgetName);
	listbox->Fill (listItems);
    }
}

void WidgetManagerCEGUI::OnMouseClick (const orxSTRING widgetName)
{
    m_scrollWindow->HandleMouseClick (widgetName);
}

void WidgetManagerCEGUI::OnTextAccepted (const orxSTRING widgetName)
{
    m_scrollWindow->HandleTextAccepted (widgetName);
}