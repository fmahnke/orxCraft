/**
 * @file CEGUIEditbox.cpp
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "CEGUIEditbox.h"
#include "ScrollFrameWindow.h"

using CEGUI::Editbox;
using CEGUI::Event;
using CEGUI::Window;

CEGUIEditbox::CEGUIEditbox (ScrollFrameWindow *dialog) :
    ScrollEditbox (dialog),
    m_ceEditbox   (NULL)
{
}

void CEGUIEditbox::Init (const orxSTRING widgetName)
{
    const orxSTRING windowName = m_manager->GetName ();
    Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    Window *window = rootWindow->getChild (windowName);

    Editbox *editbox = reinterpret_cast<Editbox *> (
	window->getChild (widgetName));
    editbox->subscribeEvent (Editbox::EventTextAccepted,
	Event::Subscriber (&CEGUIEditbox::OnTextAccepted, this));

    m_ceEditbox = editbox;
    m_widgetName = new char[strlen (widgetName) + 1];
    strcpy (m_widgetName, widgetName);
}

bool CEGUIEditbox::OnTextAccepted (const CEGUI::EventArgs &e)
{
    CEGUI::WindowEventArgs *args = (CEGUI::WindowEventArgs *) &e;
    const orxSTRING widgetName = args->window->getName ().c_str ();
    m_manager->OnTextAccepted (widgetName);

    return true;
}

const orxSTRING CEGUIEditbox::GetText ()
{
    return m_ceEditbox->getText ().c_str ();
}

void CEGUIEditbox::SetText (const orxSTRING text)
{
    orxASSERT (text != orxNULL);

    m_ceEditbox->setText (text);
}

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
