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
