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
 * @file ScrollGUICEGUI.cpp
 * @date 2012-06-08
 * @author fritz@fritzmahnke.com
 *
 */
#include "ScrollGUICEGUI.h"

#include "orxCraft.h"
#include "ObjectEditor.h"
#include "FXSlotEditorWindow.h"
#include "InfoWindow.h"

#include "constants.h"

using CEGUI::System;

ScrollGUICEGUI::ScrollGUICEGUI () :
    m_glRenderer (orxNULL)
{
}

ScrollGUICEGUI::~ScrollGUICEGUI ()
{
    //m_glRenderer->destroySystem ();
    m_glRenderer = orxNULL;
}

void ScrollGUICEGUI::Init ()
{
    // CEGUI renderer has to be initialized first
    m_glRenderer = & CEGUI::OpenGLRenderer::bootstrapSystem();

    // Scroll object initializes CEGUI on creation
    OrxCraft::GetInstance ().CreateObject (scrollGUIName);
}

void ScrollGUICEGUI::CEGUIScrollObject::OnCreate ()
{
    using namespace CEGUI;

    // Initialise the required dirs for the DefaultResourceProvider
    // All CEGUI data files are stored in data/cegui subdirectory relative to OrxCraft executable
    DefaultResourceProvider* rp = 
	static_cast<DefaultResourceProvider*>(System::getSingleton().getResourceProvider());
    rp->setResourceGroupDirectory("schemes", "./cegui/schemes/");
    rp->setResourceGroupDirectory("imagesets", "./cegui/imagesets/");
    rp->setResourceGroupDirectory("fonts", "./cegui/fonts/");
    rp->setResourceGroupDirectory("layouts", "./cegui/layouts/");
    rp->setResourceGroupDirectory("looknfeels", "./cegui/looknfeel/");
    rp->setResourceGroupDirectory("lua_scripts", "./cegui/lua_scripts/");
    rp->setResourceGroupDirectory("schemas", "./cegui/xml_schemas/");
    // Set the default resource groups to be used
    Imageset::setDefaultResourceGroup("imagesets");
    Font::setDefaultResourceGroup("fonts");
    Scheme::setDefaultResourceGroup("schemes");
    WidgetLookManager::setDefaultResourceGroup("looknfeels");
    WindowManager::setDefaultResourceGroup("layouts");
    ScriptModule::setDefaultResourceGroup("lua_scripts");
    // Setup default group for validation schemas
    XMLParser* parser = System::getSingleton().getXMLParser();
    if (parser->isPropertyPresent("SchemaDefaultResourceGroup"))
	parser->setProperty("SchemaDefaultResourceGroup", "schemas");

    SchemeManager::getSingleton().create("TaharezLook.scheme");

    WindowManager &winManager = WindowManager::getSingleton ();
    Window* myRoot = winManager.loadWindowLayout ("Main.layout");
    System::getSingleton().setGUISheet( myRoot );
}

void ScrollGUICEGUI::CEGUIScrollObject::OnDelete ()
{
}

void ScrollGUICEGUI::InputMouseMove ()
{
    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    System::getSingleton ().injectMousePosition (mousePos.fX, mousePos.fY);
}

void ScrollGUICEGUI::InputMouseDown ()
{
    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    System::getSingleton ().injectMousePosition (mousePos.fX, mousePos.fY);
    System::getSingleton ().injectMouseButtonDown (CEGUI::LeftButton);
}

void ScrollGUICEGUI::InputMouseUp ()
{
    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    System::getSingleton ().injectMousePosition (mousePos.fX, mousePos.fY);
    System::getSingleton ().injectMouseButtonUp (CEGUI::LeftButton);
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

    System::getSingleton ().injectKeyDown (key);
    if (inputChar != '\0')
    {
	System::getSingleton ().injectChar (inputChar);
    }
}

orxBOOL ScrollGUICEGUI::CEGUIScrollObject::OnRender ()
{
    DrawGrid ();
    System::getSingleton().renderGUI();
    return false; 
}

void ScrollGUICEGUI::CEGUIScrollObject::DrawGrid ()
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
	orxVECTOR start = { {(float) i * gridRes}, {0}, {0}};
	orxVECTOR end   = { {(float) i * gridRes}, {frustumHeight}, {0}};
	orxDisplay_DrawLine (&start, &end, gridColor);
    }

    for (int i = 1; i <= rows; i++)
    {
	orxVECTOR start = {{0}, {(float) i * gridRes}, {0}};
	orxVECTOR end   = {{frustumWidth}, {(float) i * gridRes}, {0}};
	orxDisplay_DrawLine (&start, &end, gridColor);
    }
}

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
