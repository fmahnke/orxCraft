/**
 * @file CEGUIListbox.cpp
 * @date 2012-05-10
 * @author fritz@fritzmahnke.com
 *
 */

#include "CEGUIListbox.h"

#include "ScrollFrameWindow.h"

using CEGUI::Listbox;
using CEGUI::Event;
using CEGUI::Window;

CEGUIListbox::CEGUIListbox (ScrollFrameWindow *dialog) :
    ScrollListbox (dialog),
    m_ceListbox (NULL)
{
}

void CEGUIListbox::Init (const orxSTRING widgetName)
{
    const orxSTRING windowName = m_manager->GetName ();
    Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    Window *window = rootWindow->getChild (windowName);

    Listbox *listbox = reinterpret_cast<Listbox *> (
	window->getChild (widgetName));
    listbox->subscribeEvent (Window::EventMouseClick,
	Event::Subscriber (&CEGUIListbox::OnMouseClick, this));
    m_ceListbox = listbox;
    m_widgetName = new char[strlen (widgetName) + 1];
    strcpy (m_widgetName, widgetName);
}

void CEGUIListbox::Init (Window* widget)
{
    Listbox *listbox = reinterpret_cast<Listbox *> (widget);
    listbox->subscribeEvent (Window::EventMouseClick,
	Event::Subscriber (&CEGUIListbox::OnMouseClick, this));

    m_ceListbox = listbox;
    m_widgetName = new char[strlen (widget->getName().c_str()) + 1];
    strcpy (m_widgetName, widget->getName().c_str());
}

void CEGUIListbox::Fill (const vector<const orxSTRING> &listItems)
{
    for (unsigned int i = 0; i < listItems.size (); i++)
    {
	m_items.push_back (new CEGUI::ListboxTextItem (listItems.at (i)));
	m_ceListbox->addItem (m_items.back ());
    }
}

bool CEGUIListbox::OnMouseClick (const CEGUI::EventArgs &e)
{
    CEGUI::WindowEventArgs *args = (CEGUI::WindowEventArgs *) &e;
    const orxSTRING widgetName = args->window->getName ().c_str ();
    m_manager->OnMouseClick (widgetName);

    return true;
}

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
