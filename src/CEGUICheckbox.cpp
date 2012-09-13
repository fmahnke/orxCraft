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
 * @file CEGUICheckbox.cpp
 * @date 2012-05-07
 * @author fritz@fritzmahnke.com
 *
 */

#include "CEGUICheckbox.h"

#include "ScrollFrameWindow.h"

using CEGUI::Checkbox;
using CEGUI::Event;
using CEGUI::Window;

CEGUICheckbox::CEGUICheckbox (ScrollFrameWindow *dialog) :
    ScrollCheckbox (dialog),
    m_ceCheckbox   (NULL)
{
}

void CEGUICheckbox::Init (const orxSTRING widgetName) 
{
    const orxSTRING name = m_manager->GetName ();
    Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    Window *window = rootWindow->getChild (name);

    Checkbox *checkbox = reinterpret_cast<Checkbox *> (
	window->getChild (widgetName));
    checkbox->subscribeEvent (Checkbox::EventCheckStateChanged,
	Event::Subscriber (&CEGUICheckbox::OnCheckStateChanged, this));

    m_ceCheckbox = checkbox;
    m_widgetName = new char[strlen (widgetName) + 1];
    strcpy (m_widgetName, widgetName);
}

void CEGUICheckbox::Init (Window* widget)
{
    Checkbox *checkbox = reinterpret_cast<Checkbox *> (widget);
    checkbox->subscribeEvent (Checkbox::EventCheckStateChanged,
	Event::Subscriber (&CEGUICheckbox::OnCheckStateChanged, this));

    m_ceCheckbox = checkbox;
    m_widgetName = new char[strlen (widget->getName().c_str()) + 1];
    strcpy (m_widgetName, widget->getName().c_str());
}

void CEGUICheckbox::SetSelected (const orxBOOL select)
{
    m_ceCheckbox->setSelected(select);
}

const orxBOOL CEGUICheckbox::IsSelected () const
{
    return m_ceCheckbox->isSelected();
}

bool CEGUICheckbox::OnCheckStateChanged (const CEGUI::EventArgs &e)
{
    // Our item has been checked or unchecked, update our item accordingly.
    CEGUI::WindowEventArgs *args = (CEGUI::WindowEventArgs *) &e;
    const orxSTRING widgetName = args->window->getName ().c_str ();
    m_manager->OnTextAccepted (widgetName);

    return true;
}

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
