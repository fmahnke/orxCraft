/*
 *  Copyright (c) 2012 The orxCraft Project
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *     1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *  
 *     2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *  
 *     3. This notice may not be removed or altered from any source
 *     distribution.
 */

/**
 * @file InfoWindow.cpp
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#include "InfoWindow.h"
#include "orxCraft.h"

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

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
