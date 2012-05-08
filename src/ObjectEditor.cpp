/**
 * @file ObjectEditor.cpp
 * @date 2012-06-04
 * @author fritz@fritzmahnke.com
 *
 */
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
    if (orxString_Compare (name, "ObjAlpha") == 0)
    {
	const orxSTRING alpha = GetText ("ObjAlpha");
	orxConfig_SetString ("Alpha", alpha);
    }
    else if (orxString_Compare (name, "ObjAngularVelocity") == 0)
    {
    }
    else if (orxString_Compare (name, "ObjAnimFreq") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjAnimSet") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjAutoScroll") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjBlendMode") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjBody") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjClock") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjColorR") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjColorG") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjColorB") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjGraphic") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjFXList") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjLifeTime") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjParentCam") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjPosX") == 0)
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
    else if (orxString_Compare (name, "ObjRepeatX") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjRotation") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjSpeedX") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjShaderList") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjSoundList") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (name, "ObjSpawner") == 0)
    {
	orxASSERT (false);
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

void ObjectEditor::SetTextFromConfigFloat (const orxSTRING widgetName,
					   const orxSTRING prop)
{
    orxConfig_PushSection (m_object->GetModelName ());

    orxFLOAT propAsFloat = orxConfig_GetFloat (prop);
    char buffer[255];
    sprintf (buffer, "%f", propAsFloat);

    orxConfig_PopSection ();

    SetText (widgetName, buffer);
}

void ObjectEditor::SetTextFromConfigStringList (const orxSTRING widgetName,
					        const orxSTRING prop)
{
    char newBuffer[2048];
    char buffer[2048];
    buffer[0] = '\0';
    const char *separator = " # ";

    orxConfig_PushSection (m_object->GetModelName ());

    orxS32 counter = orxConfig_GetListCounter (prop);
    for (int i = 0; i < counter; i++)
    {
	const orxSTRING propAsString = orxConfig_GetListString (prop, i);
	sprintf (newBuffer, "%s", propAsString);
	// At least one more property after this one?
	if (i + 1 < counter)
	{
	    strcat (newBuffer, separator);
	}
	strcat (buffer, newBuffer);
    }

    orxConfig_PopSection ();

    SetText (widgetName, buffer);
}

void ObjectEditor::SetTextFromConfigVector (const orxSTRING widgetName,
					    const orxSTRING prop,
					    orxU32 elementNum)
{
    orxASSERT (elementNum < 3);

    char buffer[255];

    orxConfig_PushSection (m_object->GetModelName ());

    orxVECTOR propertyAsVector;
    orxConfig_GetVector (prop, &propertyAsVector);

    orxConfig_PopSection ();

    switch (elementNum)
    {
    case 0:
	sprintf (buffer, "%f", propertyAsVector.fX);
	break;
    case 1:
	sprintf (buffer, "%f", propertyAsVector.fY);
	break;
    case 2:
	sprintf (buffer, "%f", propertyAsVector.fZ);
    }

    SetText (widgetName, buffer);
}

void ObjectEditor::SetObject (ScrollObject *object)
{
    m_object = object;
    UpdateFields ();
}

/**
 *  Update all fields on this window using the current values from config
 */
void ObjectEditor::UpdateFields ()
{
    if (m_object != orxNULL)
    {
	char buffer[255];
	
	const orxSTRING name = m_object->GetModelName ();

	// Config name
	SetText ("ObjectConfigName", name);

	orxConfig_PushSection (name);

	// Alpha
	SetTextFromConfigFloat ("ObjAlpha", "Alpha");
	// AngularVelocity
	SetTextFromConfigFloat ("ObjAngularVelocity", "AngularVelocity");
	// AnimationFrequency
	SetTextFromConfigFloat ("ObjAnimFreq", "AnimationFrequency");
	// AnimationSet
	SetTextFromConfigStringList ("ObjAnimSet", "AnimationSet");
	// AutoScroll
	SetTextFromConfigStringList ("ObjAutoScroll", "AutoScroll");
	// BlendMode
	SetTextFromConfigStringList ("ObjBlendMode", "BlendMode");
	// Body
	SetTextFromConfigStringList ("ObjBody", "Body");
	// ChildList
	/** @todo ChildList */
	// ChildJointList
	/** @todo ChildJointList */
	// Clock
	SetTextFromConfigStringList ("ObjClock", "Clock");
	// Color
	SetTextFromConfigVector ("ObjColorR", "Color", 0);
	SetTextFromConfigVector ("ObjColorG", "Color", 1);
	SetTextFromConfigVector ("ObjColorB", "Color", 2);
	// DepthScale
	/** @todo DepthScale */
	// Graphic
	SetTextFromConfigStringList ("ObjGraphic", "Graphic");
	// Flip
	/** @todo Flip */
	// FXList
	SetTextFromConfigStringList ("ObjFXList", "FXList");
	// LifeTime
	SetTextFromConfigFloat ("ObjLifeTime", "LifeTime");
	// ParentCamera
	SetTextFromConfigStringList ("ObjParentCam", "ParentCamera");
	// Position
	SetTextFromConfigVector ("ObjPosX", "Position", 0);
	SetTextFromConfigVector ("ObjPosY", "Position", 1);
	SetTextFromConfigVector ("ObjPosZ", "Position", 2);
	// Repeat
	SetTextFromConfigVector ("ObjRepeatX", "Repeat", 0);
	SetTextFromConfigVector ("ObjRepeatY", "Repeat", 1);
	SetTextFromConfigVector ("ObjRepeatZ", "Repeat", 2);
	// Rotation
	SetTextFromConfigFloat ("ObjRotation", "Rotation");
	// Speed
	SetTextFromConfigVector ("ObjSpeedX", "Speed", 0);
	SetTextFromConfigVector ("ObjSpeedY", "Speed", 1);
	SetTextFromConfigVector ("ObjSpeedZ", "Speed", 2);
	// Scale
	SetTextFromConfigVector ("ObjScaleX", "Scale", 0);
	SetTextFromConfigVector ("ObjScaleY", "Scale", 1);
	SetTextFromConfigVector ("ObjScaleZ", "Scale", 2);
	// ShaderList
	SetTextFromConfigStringList ("ObjShaderList", "ShaderList");
	// SoundList
	SetTextFromConfigStringList ("ObjSoundList", "SoundList");
	// Spawner
	SetTextFromConfigStringList ("ObjSpawner", "Spawner");
	// Smoothing
	/** @todo Smoothing */
	// UseParentSpace
	/** @todo UseParentSpace */
	// UseRelativeSpeed
	/** @todo UseRelativeSpeed */

	orxConfig_PopSection ();
    }
}

void ObjectEditor::Update(const orxCLOCK_INFO &_rstInfo)
{
}