/**
 * @file InfoWindow.cpp
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#include "InfoWindow.h"
#ifdef USE_LIBROCKET
#include "WidgetManagerRocket.h"
#else
#include "WidgetManagerCEGUI.h"
#endif
#include "OrxCraft.h"

void InfoWindow::Init (const orxSTRING widgetName)
{
#ifdef USE_LIBROCKET
    m_widgetManager = new WidgetManagerRocket ();
#else
    m_widgetManager = new WidgetManagerCEGUI ();
#endif
    m_widgetManager->Init (widgetName, this);
    vector<const orxSTRING> objList = OrxCraft::GetInstance ().GetObjectList ();
    m_widgetManager->FillList ("ObjectSectionList", objList);
    vector<const orxSTRING> fxSlotList = OrxCraft::GetInstance ().GetFXSlotList ();
    m_widgetManager->FillList ("FXSlotSectionList", fxSlotList);
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
    else if (orxString_Compare (widgetName, "FXSlotSectionList") == 0)
    {
	const orxSTRING itemName = m_widgetManager->GetSelectedItem (widgetName);
	OrxCraft::GetInstance ().SetSelectedFXSlot (itemName);
    }
    else if (orxString_Compare (widgetName, "SaveConfig") == 0)
    {
	OrxCraft::GetInstance ().SaveEditorConfig ();
    }
}

void InfoWindow::HandleTextAccepted (const orxSTRING widgetName)
{
    orxASSERT (false);
}