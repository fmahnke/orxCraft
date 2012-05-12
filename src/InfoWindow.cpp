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
    vector<const orxSTRING> objList = OrxCraft::GetInstance ().GetObjectList ();
    m_widgetManager->FillList ("ObjectSectionList", objList);
}

const orxSTRING InfoWindow::GetName ()
{
    orxASSERT (false);
    return orxNULL;
}

void InfoWindow::HandleMouseClick (const orxSTRING widgetName)
{
    if (orxString_Compare (widgetName, "ObjectSectionList") == 0)
    {
	const orxSTRING itemName = m_widgetManager->GetSelectedItem (widgetName);
	OrxCraft::GetInstance ().SetSelectedObject (itemName);
    }
}

void InfoWindow::HandleTextAccepted (const orxSTRING widgetName)
{
    orxASSERT (false);
}