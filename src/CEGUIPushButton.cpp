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
