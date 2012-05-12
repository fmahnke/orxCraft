/**
 * @file CEGUICombobox.cpp
 * @date 2012-05-11
 * @author fritz@fritzmahnke.com
 *
 */

#include "CEGUICombobox.h"
#include "WidgetManager.h"

using CEGUI::Combobox;
using CEGUI::Event;
using CEGUI::Window;

CEGUICombobox::CEGUICombobox (WidgetManager *manager) :
    ScrollCombobox (manager),
    m_ceCombobox   (NULL)
{
}

void CEGUICombobox::Init (const orxSTRING widgetName)
{
    const orxSTRING windowName = m_manager->GetWindowName ();
    Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    Window *window = rootWindow->getChild (windowName);

    Combobox *combobox = (Combobox *) window->getChild (widgetName);
    combobox->subscribeEvent (Window::EventMouseClick,
	Event::Subscriber (&CEGUICombobox::OnMouseClick, this));

    m_ceCombobox = combobox;
    m_widgetName = new char[strlen (widgetName) + 1];
    strcpy (m_widgetName, widgetName);
}

void CEGUICombobox::Fill (const vector<const orxSTRING> &listItems)
{
    for (unsigned int i = 0; i < listItems.size (); i++)
    {
	m_items.push_back (new CEGUI::ListboxTextItem (listItems.at (i)));
	m_ceCombobox->addItem (m_items.back ());
    }
}

bool CEGUICombobox::OnMouseClick (const CEGUI::EventArgs &e)
{
    CEGUI::WindowEventArgs *args = (CEGUI::WindowEventArgs *) &e;
    const orxSTRING widgetName = args->window->getName ().c_str ();
    m_manager->OnMouseClick (widgetName);

    return true;
}