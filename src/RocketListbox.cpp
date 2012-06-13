/**
 * @file RocketListbox.cpp
 * @date 2012-06-12
 * @author fritz@fritzmahnke.com
 *
 */

#include "RocketListbox.h"

#include "WidgetManager.h"

RocketListbox::RocketListbox (WidgetManager *manager) :
    ScrollListbox (manager)
{
}

void RocketListbox::Init (const orxSTRING widgetName)
{
    const orxSTRING windowName = m_manager->GetWindowName ();
    
    m_widgetName = new char[strlen (widgetName) + 1];
    strcpy (m_widgetName, widgetName);

    orxASSERT (false);
}

void RocketListbox::Fill (const vector<const orxSTRING> &listItems)
{
    orxASSERT (false);
    for (unsigned int i = 0; i < listItems.size (); i++)
    {
    }
}
