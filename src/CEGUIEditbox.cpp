/**
 * @file CEGUIEditbox.cpp
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "CEGUIEditbox.h"

#include "WidgetManager.h"

using CEGUI::Editbox;
using CEGUI::Event;
using CEGUI::Window;

CEGUIEditbox::CEGUIEditbox (WidgetManager *manager) :
    ScrollEditbox (manager)
{
}

void CEGUIEditbox::Init (const orxSTRING widgetName)
{
    const orxSTRING windowName = m_manager->GetWindowName ();
    Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    Window *window = rootWindow->getChild (windowName);

    Editbox *editbox = reinterpret_cast<Editbox *> (
	window->getChild (widgetName));
    editbox->subscribeEvent (Editbox::EventTextAccepted,
	Event::Subscriber (&CEGUIEditbox::OnTextAccepted, this));

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

void CEGUIEditbox::SetText (const orxSTRING windowName,
			    const orxSTRING widgetName, const orxSTRING text)
{
    Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    Window *window = rootWindow->getChild (windowName);
}