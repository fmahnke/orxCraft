/**
 * @file WidgetManager.cpp
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "WidgetManager.h"
#include "ScrollFrameWindow.h"
#include "CEGUIEditbox.h"
#include "CEGUIListbox.h"

void WidgetManager::Init (const orxSTRING widgetName, ScrollFrameWindow *scrollWindow)
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
	    /*
	    CEGUICheckbox *checkbox = new CEGUICheckbox (this);
	    checkbox->Init (name);
	    m_widgetList.push_back (checkbox);
	    */
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
    }
}

CEGUI::Window * WidgetManager::FindWidget (const orxSTRING widgetName)
{
    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *window = rootWindow->getChild (m_windowName);
    CEGUI::Window *widget = window->getChild (widgetName);
    return widget;
}

const orxSTRING WidgetManager::GetText (const orxSTRING widgetName)
{
    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *window = rootWindow->getChild (m_windowName);
    CEGUI::Window *widget = window->getChild (widgetName);

    return widget->getText ().c_str ();
}

const orxSTRING WidgetManager::GetWindowName ()
{
    return m_windowName;
}

void WidgetManager::SetText (const orxSTRING widgetName, const orxSTRING text)
{
    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *window = rootWindow->getChild (m_windowName);
    CEGUI::Window *widget = window->getChild (widgetName);

    widget->setText (text);
}

void WidgetManager::OnTextAccepted (const orxSTRING widgetName)
{
    m_scrollWindow->HandleTextAccepted (widgetName);
}