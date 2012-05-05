#define __SCROLL_IMPL__
#include "orxcraft.h"
#undef  __SCROLL_IMPL__

#include <gl\gl.h>                                // Header File For The OpenGL32 Library
#include <gl\glu.h>                               // Header File For The GLu32 Library
#include "CEGUI.h"
#include "RendererModules/OpenGL/CEGUIOpenGLRenderer.h"
//#include <windows.h>                              // Header File For Windows
//#include <gl\glaux.h> 

#include "InfoWindow.inl"

// Inputs
static const orxSTRING inputQuit       = "Quit";
static const orxSTRING inputLeftArrow  = "LeftArrow";
static const orxSTRING inputRightArrow = "RightArrow";
static const orxSTRING inputUpArrow    = "UpArrow";
static const orxSTRING inputDownArrow  = "DownArrow";

// Widgets
static const orxSTRING infoWindow = "O-InfoWindow";

// Settings
static orxFLOAT coarseUnit = 5.0;

ScrollObject *m_widget;
CEGUI::OpenGLRenderer *myRenderer = NULL;

OrxCraft::OrxCraft () :
  m_selectedObject (NULL)
{
    orxMemory_Zero (&m_objectList, sizeof (orxLINKLIST));
    orxMemory_Zero (&m_graphicList, sizeof (orxLINKLIST));
}

orxSTATUS OrxCraft::Init ()
{
    orxSTATUS eResult = orxSTATUS_SUCCESS;

    SetupConfig ();

    CreateObject ("O-InfoWindow");
    m_selectedObject = CreateObject ("O-Soldier");

    myRenderer = & CEGUI::OpenGLRenderer::bootstrapSystem();

    CEGUI::SchemeManager::getSingleton().create( "TaharezLook.scheme" );
    CEGUI::Window* myRoot = CEGUI::WindowManager::getSingleton().loadWindowLayout( "test.layout" );
    CEGUI::System::getSingleton().setGUISheet( myRoot );

    return eResult;
}

orxSTATUS OrxCraft::Run()
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
  // Removes event handler
}

void OrxCraft::BindObjects ()
{
    ScrollBindObject<InfoWindow> (infoWindow);
}

void OrxCraft::Update(const orxCLOCK_INFO &_rstInfo)
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
    else if (orxInput_IsActive (inputDownArrow) &&
	     orxInput_HasNewStatus (inputDownArrow))
    {
	selObjPosition.fY += coarseUnit;
    }

    m_selectedObject->SetPosition (selObjPosition, true);
}

void OrxCraft::SetupConfig ()
{
    for (int i = 0, sectionCounter = orxConfig_GetSectionCounter ();
	 i < sectionCounter;
	 i++)
    {
	const orxSTRING sectionName = orxConfig_GetSection (i);
	orxOBJECT *getObj = orxObject_CreateFromConfig (sectionName);

	if (getObj != orxNULL)
	{
	    orxBANK *bank = orxBank_Create (10, sizeof (configObject),
		orxBANK_KU32_FLAG_NONE, orxMEMORY_TYPE_MAIN);
	    configObject *pstNode = (configObject *) orxBank_Allocate (bank);
	    pstNode->orxObject = getObj;

	    
	    orxLinkList_AddEnd (&m_objectList, (orxLINKLIST_NODE *)pstNode);
	    continue;
	}
	
	orxGRAPHIC *getGraphic = orxGraphic_CreateFromConfig (sectionName);

	if (getGraphic != orxNULL)
	{
	    orxBANK *bank = orxBank_Create (10, sizeof (configGraphic),
		orxBANK_KU32_FLAG_NONE, orxMEMORY_TYPE_MAIN);
	    configGraphic *pstNode = (configGraphic *) orxBank_Allocate (bank);
	    pstNode->orxGraphic = getGraphic;

	    orxLinkList_AddEnd (&m_graphicList, (orxLINKLIST_NODE *)pstNode);
	    continue;
	}
    }
}

int main(int argc, char **argv)
{
  // Executes game
  OrxCraft::GetInstance ().Execute (argc, argv);

  // Done!
  return EXIT_SUCCESS;
}
