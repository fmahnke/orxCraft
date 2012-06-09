/**
 * @file ScrollGUICEGUI.cpp
 * @date 2012-06-08
 * @author fritz@fritzmahnke.com
 *
 */
#include "ScrollGUICEGUI.h"
#include "OrxCraft.h"

ScrollGUICEGUI::ScrollGUICEGUI () :
    m_glRenderer (orxNULL)
{
}

void ScrollGUICEGUI::OnCreate ()
{
    m_glRenderer = & CEGUI::OpenGLRenderer::bootstrapSystem();
    CEGUI::SchemeManager::getSingleton().create( "TaharezLook.scheme" );
    CEGUI::Window* myRoot = CEGUI::WindowManager::getSingleton().loadWindowLayout( "Main.layout" );
    CEGUI::Window* FXSlotWindowRoot = CEGUI::WindowManager::getSingleton().loadWindowLayout( "FXSlotWindow.layout" );
    CEGUI::Window* FXSlotWindow = FXSlotWindowRoot->getChildAtIdx (0); 
    myRoot->addChildWindow (FXSlotWindow);   
    CEGUI::System::getSingleton().setGUISheet( myRoot );
}

void ScrollGUICEGUI::OnDelete ()
{
    //m_glRenderer->destroySystem ();
    m_glRenderer = orxNULL;
}

void ScrollGUICEGUI::Input ()
{
    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    orxVECTOR worldPos;
    orxRender_GetWorldPosition (&mousePos, &worldPos);

    CEGUI::System::getSingleton ().injectMousePosition (worldPos.fX, worldPos.fY);
}

void ScrollGUICEGUI::InputMouseDown ()
{
    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    orxVECTOR worldPos;
    orxRender_GetWorldPosition (&mousePos, &worldPos);

    CEGUI::System::getSingleton ().injectMousePosition (worldPos.fX, worldPos.fY);
    CEGUI::System::getSingleton ().injectMouseButtonDown (CEGUI::LeftButton);
}

void ScrollGUICEGUI::InputMouseUp ()
{
    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    orxVECTOR worldPos;
    orxRender_GetWorldPosition (&mousePos, &worldPos);

    CEGUI::System::getSingleton ().injectMousePosition (worldPos.fX, worldPos.fY);
    CEGUI::System::getSingleton ().injectMouseButtonUp (CEGUI::LeftButton);
}

void ScrollGUICEGUI::InputKeyPress (const orxSTRING orxKey)
{
    using CEGUI::Key;
    int key = 0;
    char inputChar = '\0';

    if (orxString_Compare (orxKey, "LeftArrow") == 0)
    {
	key = Key::ArrowLeft;
    }
    if (orxString_Compare (orxKey, "RightArrow") == 0)
    {
	key = Key::ArrowRight;
    }
    if (orxString_Compare (orxKey, "UpArrow") == 0)
    {
	key = Key::ArrowUp;
    }
    if (orxString_Compare (orxKey, "DownArrow") == 0)
    {
	key = Key::ArrowDown;
    }
    if (orxString_Compare (orxKey, "Char0") == 0)
    {
	key = Key::Zero;
	inputChar = '0';
    }
    if (orxString_Compare (orxKey, "Char1") == 0)
    {
	key = Key::One;
	inputChar = '1';
    }
    if (orxString_Compare (orxKey, "Char2") == 0)
    {
	key = Key::Two;
	inputChar = '2';
    }
    if (orxString_Compare (orxKey, "Char3") == 0)
    {
	key = Key::Three;
	inputChar = '3';
    }
    if (orxString_Compare (orxKey, "Char4") == 0)
    {
	key = Key::Four;
	inputChar = '4';
    }
    if (orxString_Compare (orxKey, "Char5") == 0)
    {
	key = Key::Five;
	inputChar = '5';
    }
    if (orxString_Compare (orxKey, "Char6") == 0)
    {
	key = Key::Six;
	inputChar = '6';
    }
    if (orxString_Compare (orxKey, "Char7") == 0)
    {
	key = Key::Seven;
	inputChar = '7';
    }
    if (orxString_Compare (orxKey, "Char8") == 0)
    {
	key = Key::Eight;
	inputChar = '8';
    }
    if (orxString_Compare (orxKey, "Char9") == 0)
    {
	key = Key::Nine;
	inputChar = '9';
    }
    if (orxString_Compare (orxKey, "Delete") == 0)
    {
	key = Key::Delete;
    }
    if (orxString_Compare (orxKey, "Backspace") == 0)
    {
	key = Key::Backspace;
    }
    if (orxString_Compare (orxKey, "Return") == 0)
    {
	key = Key::Return;
    }
    if (orxString_Compare (orxKey, "Subtract") == 0)
    {
	key = Key::Subtract;
	inputChar = '-';
    }
    if (orxString_Compare (orxKey, "Period") == 0)
    {
	key = Key::Period;
	inputChar = '.';
    }
    if (orxString_Compare (orxKey, "Dash") == 0)
    {
	key = Key::Minus;
	inputChar = '-';
    }

    CEGUI::System::getSingleton ().injectKeyDown (key);
    if (inputChar != '\0')
    {
	CEGUI::System::getSingleton ().injectChar (inputChar);
    }
}

orxBOOL ScrollGUICEGUI::OnRender ()
{
    DrawGrid ();
    CEGUI::System::getSingleton().renderGUI();
    return false; 
}

void ScrollGUICEGUI::DrawGrid ()
{
    orxConfig_PushSection ("MainCamera");
    float frustumWidth = orxConfig_GetFloat ("FrustumWidth");
    float frustumHeight = orxConfig_GetFloat ("FrustumHeight");
    orxConfig_PopSection ();

    int gridRes = 100;
    int columns = (int) frustumWidth / gridRes;
    int rows = (int) frustumHeight / gridRes;

    orxRGBA gridColor = orx2RGBA (200, 0, 0, 255);

    for (int i = 1; i <= columns; i++)
    {
	orxVECTOR start = { (float) i * gridRes, 0, 0};
	orxVECTOR end   = { (float) i * gridRes, frustumHeight, 0};
	orxDisplay_DrawLine (&start, &end, gridColor);
    }

    for (int i = 1; i <= rows; i++)
    {
	orxVECTOR start = {0, (float) i * gridRes, 0};
	orxVECTOR end   = {frustumWidth, (float) i * gridRes, 0};
	orxDisplay_DrawLine (&start, &end, gridColor);
    }
}