/**
 * @file ScrollGUIRocket.cpp
 * @date 2012-06-08
 * @author fritz@fritzmahnke.com
 *
 */
#include "ScrollGUIRocket.h"
#include "OrxCraft.h"

#include "Rocket/Core.h"
#include "Rocket/Controls.h"
#include "RocketRenderInterfaceOrx.h"
#include "RocketFileInterface.h"

static RocketFileInterface* file_interface = NULL;

ScrollGUIRocket::ScrollGUIRocket () :
    m_renderInterface (NULL),
    m_sysInterface (NULL),
    m_context (NULL),
    m_document (NULL)
{
}

void ScrollGUIRocket::OnCreate ()
{
    // Rocket
    m_renderInterface = new RocketRenderInterfaceOrx ();
    Rocket::Core::SetRenderInterface (m_renderInterface);

    m_sysInterface    = new OrxSystemInterface ();
    Rocket::Core::SetSystemInterface (m_sysInterface);

	file_interface = new RocketFileInterface("");
	Rocket::Core::SetFileInterface(file_interface);

    Rocket::Core::String font_names[4];
    font_names[0] = "Delicious-Roman.otf";
    font_names[1] = "Delicious-Italic.otf";
    font_names[2] = "Delicious-Bold.otf";
    font_names[3] = "Delicious-BoldItalic.otf";

    Rocket::Core::Initialise ();
    Rocket::Controls::Initialise ();

    for (int i = 0; i < sizeof(font_names) / sizeof(Rocket::Core::String); i++)
    {
	Rocket::Core::FontDatabase::LoadFontFace("Delicious-Roman.otf");
    }

    m_context =	Rocket::Core::CreateContext (
	"main",
        Rocket::Core::Vector2i(1024, 768));

    if (m_context == NULL)
    {
	Rocket::Core::Shutdown();
    }
    m_document = m_context->LoadDocument ("demo.rml");

    if (m_document != NULL)
    {
	m_document->Show ();
    }
}

void ScrollGUIRocket::OnDelete ()
{
    // Rocket

    m_context->RemoveReference ();

    delete m_sysInterface;
    m_sysInterface = NULL;

    delete m_renderInterface;
    m_renderInterface = NULL;
}

void ScrollGUIRocket::Input ()
{
    orxVECTOR mousePos;
    orxMouse_GetPosition (&mousePos);

    orxVECTOR worldPos;
    orxRender_GetWorldPosition (&mousePos, &worldPos);

    m_context->ProcessMouseMove (worldPos.fX, worldPos.fY, 0);
}

void ScrollGUIRocket::InputMouseDown ()
{
    m_context->ProcessMouseButtonDown (0, 0);
}

void ScrollGUIRocket::InputMouseUp ()
{
    m_context->ProcessMouseButtonUp (0, 0);
}

void ScrollGUIRocket::InputKeyPress (const orxSTRING orxKey)
{
    using Rocket::Core::Input::KeyIdentifier;
    KeyIdentifier key = KeyIdentifier::KI_UNKNOWN;
    char inputChar = '\0';

    if (orxString_Compare (orxKey, "LeftArrow") == 0)
    {
	key = KeyIdentifier::KI_LEFT;
    }
    if (orxString_Compare (orxKey, "RightArrow") == 0)
    {
	key = KeyIdentifier::KI_RIGHT;
    }
    if (orxString_Compare (orxKey, "UpArrow") == 0)
    {
	key = KeyIdentifier::KI_UP;
    }
    if (orxString_Compare (orxKey, "DownArrow") == 0)
    {
	key = KeyIdentifier::KI_DOWN;
    }
    if (orxString_Compare (orxKey, "Char0") == 0)
    {
	key = KeyIdentifier::KI_0;
	inputChar = '0';
    }
    if (orxString_Compare (orxKey, "Char1") == 0)
    {
	key = KeyIdentifier::KI_1;
	inputChar = '1';
    }
    if (orxString_Compare (orxKey, "Char2") == 0)
    {
	key = KeyIdentifier::KI_2;
	inputChar = '2';
    }
    if (orxString_Compare (orxKey, "Char3") == 0)
    {
	key = KeyIdentifier::KI_3;
	inputChar = '3';
    }
    if (orxString_Compare (orxKey, "Char4") == 0)
    {
	key = KeyIdentifier::KI_4;
	inputChar = '4';
    }
    if (orxString_Compare (orxKey, "Char5") == 0)
    {
	key = KeyIdentifier::KI_5;
	inputChar = '5';
    }
    if (orxString_Compare (orxKey, "Char6") == 0)
    {
	key = KeyIdentifier::KI_6;
	inputChar = '6';
    }
    if (orxString_Compare (orxKey, "Char7") == 0)
    {
	key = KeyIdentifier::KI_7;
	inputChar = '7';
    }
    if (orxString_Compare (orxKey, "Char8") == 0)
    {
	key = KeyIdentifier::KI_8;
	inputChar = '8';
    }
    if (orxString_Compare (orxKey, "Char9") == 0)
    {
	key = KeyIdentifier::KI_9;
	inputChar = '9';
    }
    if (orxString_Compare (orxKey, "Delete") == 0)
    {
	key = KeyIdentifier::KI_DELETE;
    }
    if (orxString_Compare (orxKey, "Backspace") == 0)
    {
	key = KeyIdentifier::KI_BACK;
    }
    if (orxString_Compare (orxKey, "Return") == 0)
    {
	key = KeyIdentifier::KI_RETURN;
    }
    if (orxString_Compare (orxKey, "Subtract") == 0)
    {
	key = KeyIdentifier::KI_SUBTRACT;
	inputChar = '-';
    }
    if (orxString_Compare (orxKey, "Period") == 0)
    {
	key = KeyIdentifier::KI_OEM_PERIOD;
	inputChar = '.';
    }
    if (orxString_Compare (orxKey, "Dash") == 0)
    {
	key = KeyIdentifier::KI_SUBTRACT;
	inputChar = '-';
    }

    m_context->ProcessKeyDown (key, 0);
    if (inputChar != '\0')
    {
	m_context->ProcessTextInput (inputChar);
    }
}

orxBOOL ScrollGUIRocket::OnRender ()
{
    m_context->Update ();
    m_context->Render ();

    return false; 
}

void ScrollGUIRocket::Update(const orxCLOCK_INFO &_rstInfo)
{
}
