/**
 * @file CEGUICheckbox.cpp
 * @date 2012-05-07
 * @author fritz@fritzmahnke.com
 *
 */

#include "CEGUICheckbox.h"

#include "ObjectEditor.h"

using CEGUI::Checkbox;
using CEGUI::Event;
using CEGUI::Window;

CEGUICheckbox::CEGUICheckbox (ObjectEditor *manager) :
    ScrollCheckbox (manager)
{
}

void CEGUICheckbox::Init (const orxSTRING widgetName) 
{
    const orxSTRING name = m_manager->GetModelName ();
    Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    Window *window = rootWindow->getChild (name);

    Checkbox *checkbox = (Checkbox *) window->getChild (widgetName);
    checkbox->subscribeEvent (Checkbox::EventCheckStateChanged,
	Event::Subscriber (&CEGUICheckbox::OnCheckStateChanged, this));
}

void CEGUICheckbox::SignalCheckStateChanged ()
{
}

bool CEGUICheckbox::OnCheckStateChanged (const CEGUI::EventArgs &e)
{
    // Our item has been checked or unchecked, update our item accordingly.
    return true;
}
