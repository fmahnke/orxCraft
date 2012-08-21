/*
 *  Copyright (c) 2012 The orxCraft Project
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *     1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *  
 *     2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *  
 *     3. This notice may not be removed or altered from any source
 *     distribution.
 */

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
