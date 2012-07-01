/**
 * @file OrxCraft.cpp
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#define __SCROLL_IMPL__
#include "orxcraft.h"
#undef  __SCROLL_IMPL__

#include "InfoWindow.h"
#include "ObjectEditor.h"
#include "FXSlotEditorWindow.h"

#ifdef USE_LIBROCKET
#include "ScrollGUIRocket.h"
#else
#include "ScrollGUICEGUI.h"
#endif

// Widgets
static const orxSTRING infoWindow = "O-InfoWindow";
static const orxSTRING scrollGUI  = "ScrollGUI";
static const orxSTRING objectEditor = "ObjectEditor";

// Settings
static orxFLOAT coarseUnit = 5.0;
static const orxSTRING configFileName = "sampleconfig.ini";

OrxCraft::OrxCraft () :
    m_infoWindow         (NULL),
    m_selectedObject     (NULL),
    m_objectEditor       (NULL),
    m_fxSlotEditorWindow (NULL),
    m_scrollGUI          (NULL)
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

    // Init GUI system
#ifdef USE_LIBROCKET
    m_scrollGUI = reinterpret_cast<ScrollGUIRocket *> (
	CreateObject (scrollGUI));
#else
    m_scrollGUI = reinterpret_cast<ScrollGUICEGUI *> (CreateObject (scrollGUI));
#endif
    CreateObject (infoWindow);

    // Init object editor
    m_objectEditor = new ObjectEditor ();
    m_objectEditor->Init (objectEditor);
    m_objectEditor->SetObject (m_selectedObject);

    // Init FX slot editor
    //m_fxSlotEditorWindow = new FXSlotEditorWindow ();
    //m_fxSlotEditorWindow->Init ("FXSlotWindow");
    //m_fxSlotEditorWindow->SetContext ("FXS-Darken");

    // Init info window
    //m_infoWindow = new InfoWindow ();
    //m_infoWindow->Init ("InfoWindow");

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
    delete m_objectEditor;
    delete m_fxSlotEditorWindow;
    delete m_infoWindow;
}

void OrxCraft::BindObjects ()
{
#ifdef USE_LIBROCKET
    ScrollBindObject<ScrollGUIRocket> (scrollGUI);
#else
    ScrollBindObject<ScrollGUICEGUI> (scrollGUI);
#endif
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

    // Nothing picked
    if (orxObject_Pick (&worldPos) == orxNULL)
    {
	// Pass input to GUI
	m_scrollGUI->InputMouseMove ();
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
    m_scrollGUI->InputMouseDown ();
}

void OrxCraft::OnMouseUp ()
{
    m_scrollGUI->InputMouseUp ();
}

void OrxCraft::OnKeyPress (const orxSTRING key)
{
    m_scrollGUI->InputKeyPress (key);
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
