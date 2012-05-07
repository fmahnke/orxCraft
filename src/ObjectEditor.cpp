#include "ObjectEditor.h"

#include "OrxCraft.h"

ObjectEditor::ObjectEditor () :
    m_object (NULL)
{
}

void ObjectEditor::OnCreate ()
{
    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    m_window = rootWindow->getChild ("ObjectEditor");
    
    CEGUI::Editbox *editbox = (CEGUI::Editbox *) m_window->getChild ("ObjPosX");
    editbox->subscribeEvent (CEGUI::Editbox::EventTextAccepted,
	CEGUI::Event::Subscriber (&ObjectEditor::OnTextAccepted, this));
    editbox = (CEGUI::Editbox *) m_window->getChild ("ObjAlpha");
    editbox->subscribeEvent (CEGUI::Editbox::EventTextAccepted,
	CEGUI::Event::Subscriber (&ObjectEditor::OnTextAccepted, this));
}

void ObjectEditor::OnDelete ()
{
}

bool ObjectEditor::OnTextAccepted (const CEGUI::EventArgs &e)
{
    CEGUI::WindowEventArgs *args = (CEGUI::WindowEventArgs *) &e;
    const orxSTRING name = args->window->getName ().c_str ();

    // Push config section of edited object
    orxConfig_PushSection (m_object->GetModelName ());

    // Update config
    if (orxString_Compare (name, "ObjPosX") == 0)
    {
	const orxSTRING newX = GetText ("ObjPosX");
	orxFLOAT newXFloat;
	orxString_ToFloat (newX,  &newXFloat, orxNULL);
	orxVECTOR oldPosition;
	m_object->GetPosition (oldPosition, true);
	oldPosition.fX = newXFloat;
	//m_object->SetPosition (oldPosition, true);
	orxConfig_SetVector ("Position", &oldPosition);
    }
    else if (orxString_Compare (name, "ObjAlpha") == 0)
    {
	const orxSTRING alpha = GetText ("ObjAlpha");
	orxConfig_SetString ("Alpha", alpha);
    }

    orxConfig_PopSection ();

    // Update object in editor
    UpdateObject ();

    return true;
}

void ObjectEditor::UpdateObject ()
{
    orxConfig_PushSection (m_object->GetModelName ());

    // Position
    m_object->SetPosition (*orxConfig_GetVector ("Position", &orxVECTOR ()),
	                   true);

    // Alpha
    orxCOLOR color;
    m_object->GetColor (color);
    orxFLOAT alpha = orxConfig_GetFloat ("Alpha");
    color.fAlpha = alpha;
    m_object->SetColor (color);

    orxConfig_PopSection ();
}

const orxSTRING ObjectEditor::GetText (const orxSTRING widgetName) const
{
    CEGUI::Window *window  = m_window->getChild (widgetName);
    return window->getText ().c_str ();
}

void ObjectEditor::SetText (const orxSTRING widgetName,
			    const orxSTRING text)
{
    CEGUI::Window *window    = m_window->getChild (widgetName);
    window->setText (text);
}

void ObjectEditor::SetObject (ScrollObject *object)
{
    m_object = object;
    Draw ();
}

void ObjectEditor::Draw ()
{
    if (m_object != orxNULL)
    {
	orxVECTOR position;
	m_object->GetPosition (position, true);

	char buffer[255];

	// Position
	sprintf (buffer, "%f", position.fX);
	SetText ("ObjPosX", buffer);
	sprintf (buffer, "%f", position.fY);
	SetText ("ObjPosY", buffer);
	sprintf (buffer, "%f", position.fZ);
	SetText ("ObjPosZ", buffer);

	// Config name
	const orxSTRING name = m_object->GetModelName ();
	SetText ("ObjectConfigName", name);

	// Alpha
	orxCOLOR color;
	m_object->GetColor (color);
	sprintf (buffer, "%f", color.fAlpha);
	SetText ("ObjAlpha", buffer);
    }
}

void ObjectEditor::Update(const orxCLOCK_INFO &_rstInfo)
{
}