/**
 * @file CEGUIEditbox.cpp
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "CEGUIEditbox.h"

#include "ObjectEditor.h"

using CEGUI::Editbox;
using CEGUI::Event;
using CEGUI::Window;

CEGUIEditbox::CEGUIEditbox (ObjectEditor *manager) :
    ScrollEditbox (manager)
{
}

void CEGUIEditbox::Init (const orxSTRING widgetName)
{
    const orxSTRING name = m_manager->GetModelName ();
    Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    Window *window = rootWindow->getChild (name);

    Editbox *editbox = (Editbox *) window->getChild (widgetName);
    editbox->subscribeEvent (Editbox::EventTextAccepted,
	Event::Subscriber (&CEGUIEditbox::OnTextAccepted, this));
    m_ceEditbox = editbox;
}

bool CEGUIEditbox::OnTextAccepted (const CEGUI::EventArgs &e)
{
    CEGUI::WindowEventArgs *args = (CEGUI::WindowEventArgs *) &e;
    const orxSTRING widgetName = args->window->getName ().c_str ();
    m_manager->HandleTextAccepted (widgetName);

    return true;
}