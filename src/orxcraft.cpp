/**
 * @file OrxCraft.cpp
 * @date 2012-06-04
 * @author fritz@fritzmahnke.com
 *
 */
#define __SCROLL_IMPL__
#include "orxcraft.h"
#undef  __SCROLL_IMPL__

//#include <gl\gl.h>                                // Header File For The OpenGL32 Library
//#include <gl\glu.h>                               // Header File For The GLu32 Library
//#include "RendererModules/OpenGL/CEGUIOpenGLRenderer.h"
//#include <windows.h>                              // Header File For Windows
//#include <gl\glaux.h> 

#include "ObjectEditor.h"
#include "FXSlotEditorWindow.h"

// Widgets
static const orxSTRING infoWindow = "O-InfoWindow";
static const orxSTRING scrollGUI  = "ScrollGUI";
static const orxSTRING objectEditor = "ObjectEditor";

// Settings
static orxFLOAT coarseUnit = 5.0;
static const orxSTRING configFileName = "sampleconfig.ini";

OrxCraft::OrxCraft () :
    m_selectedObject (NULL),
    m_objectEditor (NULL),
    m_scrollGUI (NULL)
{
}

void OrxCraft::SetSelectedObject (const orxSTRING name)
{
    m_selectedObject = GetObjectByName (name);
    m_objectEditor->SetObject (m_selectedObject);
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

    SetupConfig ();

    //CreateObject ("O-InfoWindow");
    //m_selectedObject = CreateObject ("O-Soldier");

    // Init Crazy Eddie
    m_scrollGUI = (ScrollGUI *) CreateObject (scrollGUI);
    CreateObject (infoWindow);
    m_objectEditor = new ObjectEditor ();
    m_objectEditor->Init ("ObjectEditor");
    m_objectEditor->SetObject (m_selectedObject);
    m_fxSlotEditorWindow = new FXSlotEditorWindow ();
    m_fxSlotEditorWindow->Init ("FXSlotWindow");
    m_fxSlotEditorWindow->SetContext ("FXS-Darken");


    orxViewport_CreateFromConfig ("Viewport1");
    //orxCamera_CreateFromConfig ("Camera1");

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

void OrxCraft::Exit()
{
    delete m_objectEditor;
    delete m_fxSlotEditorWindow;
}

void OrxCraft::BindObjects ()
{
    ScrollBindObject<InfoWindow> (infoWindow);
    ScrollBindObject<ScrollGUI>  (scrollGUI);
}

void OrxCraft::Update(const orxCLOCK_INFO &_rstInfo)
{
    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    orxVECTOR worldPos;
    orxRender_GetWorldPosition (&mousePos, &worldPos);

    // Nothing picked
    if (orxObject_Pick (&worldPos) == orxNULL)
    {
	m_scrollGUI->Input ();
    }

    if (m_selectedObject != orxNULL)
    {
	orxVECTOR selObjPosition;
	m_selectedObject->GetPosition (selObjPosition, true);

	if (orxInput_IsActive (inputLeftArrow) &&
	    orxInput_HasNewStatus (inputLeftArrow))
	{
	    selObjPosition.fX -= coarseUnit;
	}
	if (orxInput_IsActive (inputRightArrow) &&
	    orxInput_HasNewStatus (inputRightArrow))
	{
	    selObjPosition.fX += coarseUnit;
	}
	if (orxInput_IsActive (inputUpArrow) &&
	    orxInput_HasNewStatus (inputUpArrow))
	{
	    selObjPosition.fY -= coarseUnit;
	}
	if (orxInput_IsActive (inputDownArrow) &&
	    orxInput_HasNewStatus (inputDownArrow))
	{
	    selObjPosition.fY += coarseUnit;
	}

	m_selectedObject->SetPosition (selObjPosition, true);
    }
}

void OrxCraft::SetupConfig ()
{
    orxConfig_Load (configFileName);

    for (int i = 0, sectionCounter = orxConfig_GetSectionCounter ();
	 i < sectionCounter;
	 i++)
    {
	const orxSTRING sectionName = orxConfig_GetSection (i);
	orxConfig_PushSection (sectionName);
	if (orxConfig_GetBool ("NoEdit") != orxTRUE)
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
	}
	orxConfig_PopSection ();
    }
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
	    pstPayload = (orxINPUT_EVENT_PAYLOAD *) _pstEvent->pstPayload;
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
	    pstPayload = (orxINPUT_EVENT_PAYLOAD *) _pstEvent->pstPayload;
	    if (orxString_Compare (inputLeftMB, pstPayload->zInputName) == 0)
	    {
		OrxCraft::GetInstance ().OnMouseUp ();
	    }
	}
    }

    return result;
}

int main(int argc, char **argv)
{
  // Executes game
  OrxCraft::GetInstance ().Execute (argc, argv);

  // Done!
  return EXIT_SUCCESS;
}
