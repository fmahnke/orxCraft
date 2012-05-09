/**
 * @file ScrollGUI.cpp
 * @date 2012-06-04
 * @author fritz@fritzmahnke.com
 *
 */
#include "ScrollGUI.h"

#include "OrxCraft.h"

ScrollGUI::ScrollGUI () :
    m_glRenderer (orxNULL)
{
}

void ScrollGUI::OnCreate ()
{
    m_glRenderer = & CEGUI::OpenGLRenderer::bootstrapSystem();
    CEGUI::SchemeManager::getSingleton().create( "TaharezLook.scheme" );
    CEGUI::Window* myRoot = CEGUI::WindowManager::getSingleton().loadWindowLayout( "test.layout" );
    CEGUI::Window* FXSlotWindowRoot = CEGUI::WindowManager::getSingleton().loadWindowLayout( "FXSlotWindow.layout" );
    CEGUI::Window* FXSlotWindow = FXSlotWindowRoot->getChildAtIdx (0); 
    myRoot->addChildWindow (FXSlotWindowRoot);   
    CEGUI::System::getSingleton().setGUISheet( myRoot );
}

void ScrollGUI::OnDelete ()
{
    //m_glRenderer->destroySystem ();
    m_glRenderer = orxNULL;
}

void ScrollGUI::Input ()
{
    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    orxVECTOR worldPos;
    orxRender_GetWorldPosition (&mousePos, &worldPos);

    CEGUI::System::getSingleton ().injectMousePosition (worldPos.fX, worldPos.fY);
}

void ScrollGUI::InputMouseDown ()
{
    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    orxVECTOR worldPos;
    orxRender_GetWorldPosition (&mousePos, &worldPos);

    CEGUI::System::getSingleton ().injectMousePosition (worldPos.fX, worldPos.fY);
    CEGUI::System::getSingleton ().injectMouseButtonDown (CEGUI::LeftButton);
}

void ScrollGUI::InputMouseUp ()
{
    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    orxVECTOR worldPos;
    orxRender_GetWorldPosition (&mousePos, &worldPos);

    CEGUI::System::getSingleton ().injectMousePosition (worldPos.fX, worldPos.fY);
    CEGUI::System::getSingleton ().injectMouseButtonUp (CEGUI::LeftButton);
}

void ScrollGUI::InputKeyPress (const orxSTRING orxKey)
{
    using CEGUI::Key;
    int key = 0;
    char inputChar = '\0';

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

orxBOOL ScrollGUI::OnRender ()
{
    CEGUI::System::getSingleton().renderGUI();
    return false; 
}