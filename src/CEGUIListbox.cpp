/**
 * @file CEGUIListbox.cpp
 * @date 2012-05-10
 * @author fritz@fritzmahnke.com
 *
 */

#include "CEGUIListbox.h"

#include "WidgetManager.h"

using CEGUI::Listbox;
using CEGUI::Event;
using CEGUI::Window;

CEGUIListbox::CEGUIListbox (WidgetManager *manager) :
    ScrollListbox (manager)
{
}

void CEGUIListbox::Init (const orxSTRING widgetName)
{
    const orxSTRING windowName = m_manager->GetWindowName ();
    Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    Window *window = rootWindow->getChild (windowName);

    Listbox *listbox = (Listbox *) window->getChild (widgetName);
    listbox->subscribeEvent (CEGUI::Window::EventMouseClick,
	CEGUI::Event::Subscriber (&CEGUIListbox::OnMouseClick, this));
}

bool CEGUIListbox::OnMouseClick (const CEGUI::EventArgs &e)
{
    return true;
}