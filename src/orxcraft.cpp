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
 * @file OrxCraft.cpp
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#define __SCROLL_IMPL__
#include "orxCraft.h"
#undef  __SCROLL_IMPL__

#include "InfoWindow.h"
#include "ObjectEditor.h"
#include "FXSlotEditorWindow.h"

#include "ScrollGUICEGUI.h"

#include "CEDialogManager.h"

#include "constants.h"

#include <string>

using std::string;

// Widgets
static const orxSTRING infoWindow = "O-InfoWindow";

string OrxCraft::m_projectFileName;

OrxCraft::OrxCraft () :
    m_dialogManager     (NULL),
    m_gui               (NULL),
    m_dirty             (false),
    m_dirtySave         (false),
    m_dirtyAutosave     (false),
    m_localTime         (0),
    m_autoSaveTimeStamp (0),
    m_autoSaveInterval  (0)
{
}

ScrollObject * OrxCraft::GetObjectByName (const orxSTRING name) const
{
    ScrollObject *foundObject = NULL;

    for (ScrollObject *obj = GetNextObject (orxNULL);
	 obj != orxNULL;
	 obj = GetNextObject (obj))
    {
	if (orxString_Compare (name, obj->GetModelName ()) == 0)
	{
	    foundObject = obj;
	    break;
	}
    }
    return foundObject;
}

orxSTATUS OrxCraft::Init ()
{
    orxSTATUS eResult = orxSTATUS_SUCCESS;

    orxPARAM  stParams;
    // Asks for command line project parameter
    orxMemory_Zero (&stParams, sizeof(orxPARAM));
    stParams.pfnParser  = OrxCraft::ProcessParams;
    stParams.u32Flags   = orxPARAM_KU32_FLAG_NONE;
    stParams.zShortName = projectParamShortName;
    stParams.zLongName  = projectParamLongName;
    stParams.zShortDesc = projectParamShortDesc;
    stParams.zLongDesc  = projectParamLongDesc;
    orxParam_Register (&stParams);

    // Load things we want to edit from config
    InitConfig ();
    SetupConfig ();
    LoadUserSettings ();

    // Create instance of dialog manager
    m_dialogManager = new CEDialogManager ();

    // Init GUI system
    m_gui = new ScrollGUICEGUI ();
    m_gui->Init ();

    CreateObject (infoWindow);

    // Init object editor
    m_dialogManager->MakeDialog ("ObjectEditor");
    // Init FX slot editor
    m_dialogManager->MakeDialog ("FXSlotEditor");

    orxEvent_AddHandler (orxEVENT_TYPE_INPUT, EventHandler);

    return eResult;
}

orxSTATUS OrxCraft::Run ()
{
  orxSTATUS eResult = orxSTATUS_SUCCESS;

  // Quitting?
  if(orxInput_IsActive (inputQuit))
  {
    // Updates result
    eResult = orxSTATUS_FAILURE;
  }

  // Done!
  return eResult;
}

void OrxCraft::Exit ()
{
    delete m_dialogManager;
    m_dialogManager = NULL;
    delete m_gui;
    m_gui = NULL;
}

void OrxCraft::BindObjects ()
{
    ScrollBindObject<ScrollGUICEGUI::CEGUIScrollObject> (scrollGUIName);
}

void OrxCraft::Update (const orxCLOCK_INFO &_rstInfo)
{
    orxSTATUS eResult;

    // Want to update the objects' state?
    if (m_dirty)
    {
	m_dirty = false;
	// Do setup again
	SetupConfig ();
    }

    // Updates local time
    m_localTime += _rstInfo.fDT;

    // Uses autosave?
    if (m_autoSaveInterval > orxFLOAT_0)
    {
	// Is it time?
	if (m_localTime >= m_autoSaveTimeStamp + m_autoSaveInterval)
	{
	    // Are there changes to save?
	    if (m_dirtyAutosave)
	    {
		// Saves backup
		eResult = SaveBackup ();
		// Successful?
		if (eResult != orxSTATUS_FAILURE)
		{
		    // Adds action display
		    AddActionDisplay (uiStringAutoSave);
		    m_dirtyAutosave = false;
		}
	    }

	    /*
	     * Updates time stamp
	     * Do it even if there were no changes otherwise autosave will be
	     * triggered immediatly after a change was made instead in fixed
	     * intervals.
	     */
	    m_autoSaveTimeStamp = m_localTime;
	}
    }

    // Save?
    if (orxInput_IsActive (inputSave) && orxInput_HasNewStatus (inputSave))
    {
	// Save project
	eResult = SaveProject ();
	// Successful?
	if (eResult != orxSTATUS_FAILURE)
	{
	    AddActionDisplay (uiStringSave);
	    m_dirtySave = false;
	}
    }

    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    orxVECTOR worldPos;
    orxRender_GetWorldPosition (&mousePos, &worldPos);

    // GUI windows are on top of Orx objects. Check if mouse is inside of a window.
    CEGUI::System::getSingleton ().injectMousePosition (mousePos.fX,
							mousePos.fY);
    CEGUI::Window *window =
	CEGUI::System::getSingleton ().getWindowContainingMouse ();
    // Root window covers whole viewport but it is invisible.
    if (window != NULL &&
	orxString_Compare (window->getName().c_str(), "root") != 0)
    {
	// Pass input to GUI
	m_gui->InputMouseMove ();
    }
}

void OrxCraft::NeedObjectUpdate ()
{
    m_dirty = true;
    m_dirtySave = true;
    m_dirtyAutosave = true;
}

void OrxCraft::InitConfig ()
{
    orxConfig_Load (m_projectFileName.c_str());
}

void OrxCraft::SetupConfig ()
{
    for (unsigned int i = 0; i < m_objectList.size (); i++)
    {
	ScrollObject *obj = GetObjectByName (m_objectList.at (i));
	if (obj != orxNULL)
	{
	    DeleteObject (obj);
	}
    }
    m_objectList.clear ();

    for (int i = 0, sectionCounter = orxConfig_GetSectionCounter ();
	 i < sectionCounter;
	 i++)
    {
	const orxSTRING sectionName = orxConfig_GetSection (i);
	orxConfig_PushSection (sectionName);
	if (orxConfig_GetBool ("OrxCraftSection") != orxTRUE)
	{
	    const orxSTRING graphic = orxConfig_GetString ("Graphic");
	    // Does it have a Graphic property?
	    if (orxString_Compare (graphic, "") != 0)
	    {
		// It's an object
		m_objectList.push_back (sectionName);
		CreateObject (sectionName);
		continue;
	    }
	    // Does it have a Texture property?
	    const orxSTRING texture = orxConfig_GetString ("Texture");
	    if (orxString_Compare (texture, "") != 0)
	    {
		// It's a graphic
		m_graphicList.push_back (sectionName);
		CreateObject (sectionName);
		continue;
	    }
	    // Does it have a Curve property?
	    const orxSTRING curve = orxConfig_GetString ("Curve");
	    if (orxString_Compare (curve, "") != 0)
	    {
		// It's an FXSlot
		m_fxSlotList.push_back (sectionName);
		continue;
	    }
	}
	orxConfig_PopSection ();
    }
}

void OrxCraft::LoadUserSettings ()
{
    // Get UserSettings section
    orxConfig_PushSection (userSettingsSection);
    // AutoSave interval
    m_autoSaveInterval = orxConfig_GetFloat ("AutoSaveInterval");
    m_autoSaveTimeStamp = m_autoSaveInterval;
    // Cleanup
    orxConfig_PopSection ();
}

orxSTATUS OrxCraft::SaveEditorConfig () const
{
    orxSTATUS eResult;
    eResult = orxConfig_Save (userSettingsFile, false, &SaveConfigFilter);
    return eResult;
}

orxSTATUS OrxCraft::SaveProject () const
{
    orxSTATUS eResult;
    eResult = orxConfig_Save (m_projectFileName.c_str(), false, &SaveProjectFilter);
    return eResult;
}

void OrxCraft::OnMouseDown ()
{
    m_gui->InputMouseDown ();
}

void OrxCraft::OnMouseUp ()
{
    m_gui->InputMouseUp ();
}

void OrxCraft::OnKeyPress (const orxSTRING key)
{
    m_gui->InputKeyPress (key);
}

orxSTATUS orxFASTCALL OrxCraft::EventHandler (const orxEVENT *_pstEvent)
{
    orxSTATUS result = orxSTATUS_SUCCESS;

    // Key pressed?
    if (_pstEvent->eType == orxEVENT_TYPE_INPUT)
    {
	if(_pstEvent->eID == orxINPUT_EVENT_ON)
	{
	    orxINPUT_EVENT_PAYLOAD *pstPayload;
	    pstPayload = reinterpret_cast<orxINPUT_EVENT_PAYLOAD *> (
		_pstEvent->pstPayload);
	    switch (pstPayload->aeType[0])
	    {
	    case orxINPUT_TYPE_KEYBOARD_KEY:
		OrxCraft::GetInstance ().OnKeyPress (pstPayload->zInputName);
		break;
	    case orxINPUT_TYPE_MOUSE_BUTTON:
		OrxCraft::GetInstance ().OnMouseDown ();
		break;
	    default:
	    	break;
	    }
	}
	if(_pstEvent->eID == orxINPUT_EVENT_OFF)
	{
	    orxINPUT_EVENT_PAYLOAD *pstPayload;
	    pstPayload = reinterpret_cast<orxINPUT_EVENT_PAYLOAD *> (
		_pstEvent->pstPayload);
	    if (orxString_Compare (inputLeftMB, pstPayload->zInputName) == 0)
	    {
		OrxCraft::GetInstance ().OnMouseUp ();
	    }
	}
    }

    return result;
}

orxBOOL orxFASTCALL OrxCraft::SaveConfigFilter (const orxSTRING sectionName,
					        const orxSTRING keyName,
						const orxSTRING fileName,
						orxBOOL useEncryption)
{
    orxBOOL saveIt = orxFALSE;

    // Save only UserSettings section
    if (orxString_Compare (sectionName, userSettingsSection) == 0)
    {
	saveIt = orxTRUE;
    }

    return saveIt;
}

orxBOOL orxFASTCALL OrxCraft::SaveProjectFilter (const orxSTRING sectionName,
						 const orxSTRING keyName,
						 const orxSTRING fileName,
						 orxBOOL useEncryption)
{
    orxBOOL saveIt = orxFALSE;

    /*
     *  All objects that do not have OrxCraftSection key are part of the project
     *  data and will be saved.
     */
    //! @todo filterout the RT* objects whatever they are.
    orxConfig_PushSection (sectionName);
    orxBOOL isOrxCraftSection = orxConfig_GetBool (orxCraftSectionName);
    orxConfig_PopSection ();

    // NOT one of our editor's sections?
    if (! isOrxCraftSection)
    {
	saveIt = orxTRUE;
    }

    return saveIt;
}

orxSTATUS OrxCraft::SaveBackup () const
{
    orxSTATUS eResult;
    string saveName;
    string backupName;

    // Gets current map name
    saveName = m_projectFileName;
    backupName = saveName + ".swp";

    // Sets backup name
    m_projectFileName = backupName;

    // Saves backup
    eResult = SaveProject ();

    // Restores map name
    m_projectFileName = saveName;

    // Done!
    return eResult;
}

orxSTATUS orxFASTCALL OrxCraft::ProcessParams (orxU32 paramCount,
					       const orxSTRING params[])
{
    orxSTATUS eResult;

    // Has a valid project parameter?
    if (paramCount >= 2 &&
     (orxString_Compare (params[0], projectParamLong) == 0 ||
      orxString_Compare (params[0], projectParamShort) == 0))
    {
	// Stores projects file name
	m_projectFileName = params[1];

	// Updates result
	eResult = orxSTATUS_SUCCESS;
    }
    else
    {
	// Updates result
	eResult = orxSTATUS_FAILURE;
    }

    // Done!
    return eResult;
}

orxSTATUS OrxCraft::AddActionDisplay (const orxSTRING action) const
{
    orxSTATUS eResult = orxSTATUS_FAILURE;

    // Has valid action
    if (action)
    {
	orxOBJECT *pstActionText;

	// Creates action test
	pstActionText = orxObject_CreateFromConfig (uiActionText);

	// Valid?
	if (pstActionText)
	{
	  // Updates its content
	  orxObject_SetTextString (pstActionText, action);

	  // Updates result
	  eResult = orxSTATUS_SUCCESS;
	}
    }

    // Done!
    return eResult;
}

int main (int argc, char **argv)
{
    // Executes game
    OrxCraft::GetInstance ().Execute (argc, argv);

    // Done!
    return EXIT_SUCCESS;
}

void OrxCraft::SetSelectedFXSlot (const orxSTRING name)
{
    orxASSERT (false);
}

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
