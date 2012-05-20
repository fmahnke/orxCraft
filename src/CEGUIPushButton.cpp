/**
 * @file CEGUIPushButton.cpp
 * @date 2012-05-20
 * @author fritz@fritzmahnke.com
 *
 */

#include "CEGUIPushButton.h"

#include "WidgetManager.h"

using CEGUI::PushButton;
using CEGUI::Event;
using CEGUI::Window;

CEGUIPushButton::CEGUIPushButton (WidgetManager *manager) :
    ScrollPushButton (manager)
{
}

void CEGUIPushButton::Init (const orxSTRING widgetName)
{
    const orxSTRING windowName = m_manager->GetWindowName ();
    Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    Window *window = rootWindow->getChild (windowName);

    PushButton *pushbutton = (PushButton *) window->getChild (widgetName);
    pushbutton->subscribeEvent (PushButton::EventClicked,
	Event::Subscriber (&CEGUIPushButton::OnClicked, this));

    m_widgetName = new char[strlen (widgetName) + 1];
    strcpy (m_widgetName, widgetName);
}

bool CEGUIPushButton::OnClicked (const CEGUI::EventArgs &e)
{
    CEGUI::WindowEventArgs *args = (CEGUI::WindowEventArgs *) &e;
    const orxSTRING widgetName = args->window->getName ().c_str ();
    m_manager->OnMouseClick (widgetName);

    return true;
}
