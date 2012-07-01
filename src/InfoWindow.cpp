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
}

const orxSTRING InfoWindow::GetName ()
{
    orxASSERT (false);
    return orxNULL;
}

void InfoWindow::OnMouseClick (const orxSTRING widgetName)
{
    if (orxString_ICompare (widgetName, "ObjectSectionList") == 0)
    {
	//const orxSTRING itemName = m_widgetManager->GetSelectedItem (widgetName);
    }
    else if (orxString_ICompare (widgetName, "FXSlotSectionList") == 0)
    {
	//const orxSTRING itemName = m_widgetManager->GetSelectedItem (widgetName);
    }
    else if (orxString_ICompare (widgetName, "SaveConfig") == 0)
    {
	OrxCraft::GetInstance ().SaveEditorConfig ();
    }
}

void InfoWindow::OnTextAccepted (const orxSTRING widgetName)
{
    orxASSERT (false);
}