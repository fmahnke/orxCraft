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
 * @file CEGUIPushButton.cpp
 * @date 2012-05-20
 * @author fritz@fritzmahnke.com
 *
 */

#include "CEGUIPushButton.h"

#include "ScrollFrameWindow.h"

using CEGUI::PushButton;
using CEGUI::Event;
using CEGUI::Window;

CEGUIPushButton::CEGUIPushButton (ScrollFrameWindow *dialog) :
    ScrollPushButton (dialog),
    m_cePushButton   (NULL)
{
}

void CEGUIPushButton::Init (const orxSTRING widgetName)
{
    const orxSTRING windowName = m_manager->GetName ();
    Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    Window *window = rootWindow->getChild (windowName);

    PushButton *pushbutton = reinterpret_cast<PushButton *> (
	window->getChild (widgetName));
    pushbutton->subscribeEvent (PushButton::EventClicked,
	Event::Subscriber (&CEGUIPushButton::OnClicked, this));

    m_cePushButton = pushbutton;
    m_widgetName = new char[strlen (widgetName) + 1];
    strcpy (m_widgetName, widgetName);
}

void CEGUIPushButton::SetText (const orxSTRING text)
{
    orxASSERT (text != orxNULL);

    m_cePushButton->setText (text);
}

bool CEGUIPushButton::OnClicked (const CEGUI::EventArgs &e)
{
    CEGUI::WindowEventArgs *args = (CEGUI::WindowEventArgs *) &e;
    const orxSTRING widgetName = args->window->getName ().c_str ();
    m_manager->OnMouseClick (widgetName);

    return true;
}

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
