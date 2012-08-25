#ifndef CONSTANTS_H
#define CONSTANTS_H

// Settings
static orxFLOAT coarseUnit = 5.0;
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
static const orxSTRING scrollGUIName  = "ScrollGUI";

// UI elements
static const orxSTRING uiActionText   = "ActionText";

// Windows
static const orxSTRING fxSlotWindowName = "FXSlotWindow";
static const orxSTRING infoWindowName   = "InfoWindow";
static const orxSTRING objectEditorName = "ObjectEditor";

// UI strings
static const orxSTRING uiStringSave     = "Save";
static const orxSTRING uiStringAutoSave = "Auto Save";

// Inputs
static const orxSTRING inputQuit       = "Quit";
static const orxSTRING inputSave       = "Save";
static const orxSTRING inputLeftMB     = "LeftClick";
static const orxSTRING inputLeftArrow  = "LeftArrow";
static const orxSTRING inputRightArrow = "RightArrow";
static const orxSTRING inputUpArrow    = "UpArrow";
static const orxSTRING inputDownArrow  = "DownArrow";

#endif	// CONSTANTS_H

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
