/**
 * @file InfoWindow.cpp
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#include "InfoWindow.h"

#include "OrxCraft.h"

void InfoWindow::Init (const orxSTRING widgetName)
{
    m_widgetManager = new WidgetManager ();
    m_widgetManager->Init (widgetName, this);
}

const orxSTRING InfoWindow::GetName ()
{
    orxASSERT (false);
    return orxNULL;
}

void InfoWindow::HandleTextAccepted (const orxSTRING widgetName)
{
    orxASSERT (false);
}