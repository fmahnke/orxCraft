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

#ifndef CONSTANTS_H
#define CONSTANTS_H

// Settings
const orxFLOAT coarseUnit = 5.0;
static const orxSTRING projectParamShortName = "p";
static const orxSTRING projectParamShort = "-p";
static const orxSTRING projectParamLongName = "project";
static const orxSTRING projectParamLong = "--project";
static const orxSTRING projectParamShortDesc = "Project file to open.";
static const orxSTRING projectParamLongDesc = "Opens specified Project ini file. Allows to create/remove/edit Orx objects contained in the project.";
const orxCHAR userSettingsFile[]    = "~/.orxcraft.rc";
const orxCHAR userSettingsSection[] = "UserSettings";
const orxCHAR orxCraftSectionName[] = "OrxCraftSection";

// Scroll Object
const orxCHAR scrollGUIName[]    = "ScrollGUI";

// UI elements
static const orxSTRING uiActionText   = "ActionText";

// Windows
const orxCHAR fxSlotWindowName[] = "FXSlotWindow";
const orxCHAR infoWindowName[]   = "InfoWindow";
const orxCHAR objectEditorName[] = "ObjectEditor";

// UI strings
static const orxSTRING uiStringSave     = "Save";
static const orxSTRING uiStringAutoSave = "Auto Save";

// Inputs
const orxCHAR inputQuit[]        = "Quit";
const orxCHAR inputSave[]        = "Save";
const orxCHAR inputLeftMB[]      = "LeftClick";
const orxCHAR inputLeftArrow[]   = "LeftArrow";
const orxCHAR inputRightArrow[]  = "RightArrow";
const orxCHAR inputUpArrow[]     = "UpArrow";
const orxCHAR inputDownArrow[]   = "DownArrow";

#endif	// CONSTANTS_H

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
