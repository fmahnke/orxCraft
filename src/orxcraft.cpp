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

// Widgets
static const orxSTRING infoWindow = "O-InfoWindow";

OrxCraft::OrxCraft () :
    m_gui           (NULL),
    m_dialogManager (NULL)
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

    // Load things we want to edit from config
    InitConfig ();
    SetupConfig ();

    // Create instance of dialog manager
    m_dialogManager = new CEDialogManager ();

    // Init GUI system
    m_gui = new ScrollGUICEGUI ();
    m_gui->Init ();

    CreateObject (infoWindow);

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
    // Want to update the objects' state?
    if (m_dirty)
    {
	m_dirty = false;
	// Do setup again
	SetupConfig ();
    }

    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    orxVECTOR worldPos;
    orxRender_GetWorldPosition (&mousePos, &worldPos);

    // GUI windows are on top of Orx objects. Check if mouse is inside of a window.
    CEGUI::System::getSingleton ().injectMousePosition (mousePos.fX, mousePos.fY);
    CEGUI::Window *window = CEGUI::System::getSingleton ().getWindowContainingMouse ();
    // Root window covers whole viewport but it is invisible.
    if(window != NULL && orxString_Compare(window->getName().c_str(), "root") != 0)
    {
	// Pass input to GUI
	m_gui->InputMouseMove ();
    }
}

void OrxCraft::NeedObjectUpdate ()
{
    m_dirty = true;
}

void OrxCraft::InitConfig ()
{
    orxConfig_Load (configFileName);
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

void OrxCraft::SaveEditorConfig ()
{
    orxConfig_Save (configFileName, false, &SaveConfigFunction);
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

orxSTATUS orxFASTCALL OrxCraft::EventHandler(const orxEVENT *_pstEvent)
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

orxBOOL orxFASTCALL OrxCraft::SaveConfigFunction
    (const orxSTRING _zSectionName,
     const orxSTRING _zKeyName,
     const orxSTRING _zFileName,
     orxBOOL _bUseEncryption)
{
    orxBOOL saveIt = orxFALSE;

    orxConfig_PushSection (_zSectionName);
    orxBOOL isOrxCraftSection = orxConfig_GetBool ("OrxCraftSection");
    orxConfig_PopSection ();

    // NOT one of our editor's sections?
    if (!isOrxCraftSection)
    {
	saveIt = orxTRUE;
    }

    return saveIt;
}

int main(int argc, char **argv)
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
