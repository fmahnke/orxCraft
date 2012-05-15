/**
 * @file ObjectEditor.cpp
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#include "ObjectEditor.h"
#include "WidgetManager.h"
#include "OrxCraft.h"
#include "ConfigType.h"

ObjectEditor::ObjectEditor () :
    m_object (NULL)
{
}

void ObjectEditor::Init (const orxSTRING widgetName)
{
    m_widgetManager = new WidgetManager ();
    m_widgetManager->Init (widgetName, this);
}

const orxSTRING ObjectEditor::GetName ()
{
    orxASSERT (false);
    return orxNULL;
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

    // Angular velocity
    //orxASSERT (false);
    
    // Rotation
    m_object->SetRotation (orxConfig_GetFloat ("Rotation"));

    orxConfig_PopSection ();
}

const orxSTRING ObjectEditor::GetText (const orxSTRING widgetName) const
{
    return m_widgetManager->GetText (widgetName);
}

void ObjectEditor::SetText (const orxSTRING widgetName,
			    const orxSTRING text) const
{
    m_widgetManager->SetText (widgetName, text);
}

void ObjectEditor::SetObject (ScrollObject *object)
{
    m_object = object;
    UpdateFields ();
}

void ObjectEditor::UpdateFields () const
{
    if (m_object != orxNULL)
    {
	char buffer[255];
	
	const orxSTRING name = m_object->GetModelName ();

	// Config name
	SetText ("ObjectConfigName", name);

	orxConfig_PushSection (name);

	// Alpha
	ConfigType::FloatToString (orxConfig_GetFloat ("Alpha"), buffer);
	SetText ("ObjAlpha", buffer);
	// AngularVelocity
	ConfigType::FloatToString (orxConfig_GetFloat ("AngularVelocity"), buffer);
	SetText ("ObjAngularVelocity", buffer);
	// AnimationFrequency
	ConfigType::FloatToString (orxConfig_GetFloat ("AnimationFrequency"), buffer);
	SetText ("ObjAnimFreq", buffer);
	// AnimationSet
	const orxSTRING aS = ConfigType::ListToString ("AnimationSet");
	SetText ("ObjAnimSet", aS);
	// AutoScroll
	const orxSTRING aSc = ConfigType::ListToString ("AutoScroll");
	SetText ("ObjAutoScroll", aS);
	// BlendMode
	const orxSTRING bl = ConfigType::ListToString ("BlendMode");
	SetText ("ObjBlendMode", aS);
	// Body
	const orxSTRING body = ConfigType::ListToString ("Body");
	SetText ("ObjBody", aS);
	// ChildList
	/** @todo ChildList */
	// ChildJointList
	/** @todo ChildJointList */
	// Clock
	const orxSTRING clock = ConfigType::ListToString ("Clock");
	SetText ("ObjClock", clock);
	// Color
	ConfigType::VectorToString ("Color", 0, buffer);
	SetText ("ObjColorR", buffer);
	ConfigType::VectorToString ("Color", 1, buffer);
	SetText ("ObjColorG", buffer);
	ConfigType::VectorToString ("Color", 2, buffer);
	SetText ("ObjColorB", buffer);
	// DepthScale
	/** @todo DepthScale */
	// Graphic
	//SetTextFromConfigStringList ("ObjGraphic", "Graphic");
	// Flip
	/** @todo Flip */
	// FXList
	const orxSTRING fxList = ConfigType::ListToString ("FXList");
	SetText ("ObjFXList", fxList);
	// LifeTime
	ConfigType::FloatToString (orxConfig_GetFloat ("LifeTime"), buffer);
	SetText ("ObjLifeTime", buffer);
	// ParentCamera
	const orxSTRING parentCam = ConfigType::ListToString ("ParentCamera");
	SetText ("ObjParentCam", parentCam);
	// Position
	ConfigType::VectorToString ("Position", 0, buffer);
	SetText ("ObjPosX", buffer);
	ConfigType::VectorToString ("Position", 1, buffer);
	SetText ("ObjPosY", buffer);
	ConfigType::VectorToString ("Position", 2, buffer);
	SetText ("ObjPosZ", buffer);
	// Repeat
	ConfigType::VectorToString ("Repeat", 0, buffer);
	SetText ("ObjRepeatX", buffer);
	ConfigType::VectorToString ("Repeat", 1, buffer);
	SetText ("ObjRepeatY", buffer);
	ConfigType::VectorToString ("Repeat", 2, buffer);
	SetText ("ObjRepeatZ", buffer);
	// Rotation
	ConfigType::FloatToString (orxConfig_GetFloat ("Rotation"), buffer);
	SetText ("ObjRotation", buffer);
	// Speed
	ConfigType::VectorToString ("Speed", 0, buffer);
	SetText ("ObjSpeedX", buffer);
	ConfigType::VectorToString ("Speed", 1, buffer);
	SetText ("ObjSpeedX", buffer);
	ConfigType::VectorToString ("Speed", 2, buffer);
	SetText ("ObjSpeedX", buffer);
	// Scale
	ConfigType::VectorToString ("Scale", 0, buffer);
	SetText ("ObjScaleX", buffer);
	ConfigType::VectorToString ("Scale", 1, buffer);
	SetText ("ObjScaleY", buffer);
	ConfigType::VectorToString ("Scale", 2, buffer);
	SetText ("ObjScaleZ", buffer);
	// ShaderList
	//SetTextFromConfigStringList ("ObjShaderList", "ShaderList");
	// SoundList
	//SetTextFromConfigStringList ("ObjSoundList", "SoundList");
	// Spawner
	//SetTextFromConfigStringList ("ObjSpawner", "Spawner");
	// Smoothing
	/** @todo Smoothing */
	// UseParentSpace
	/** @todo UseParentSpace */
	// UseRelativeSpeed
	/** @todo UseRelativeSpeed */

	orxConfig_PopSection ();
    }
}

void ObjectEditor::HandleMouseClick (const orxSTRING widgetName)
{
    orxASSERT (false);
}

void ObjectEditor::HandleTextAccepted (const orxSTRING widgetName)
{
    orxASSERT (widgetName != orxNULL);
    orxASSERT (m_object != orxNULL);

    // Push config section of edited object
    orxConfig_PushSection (m_object->GetModelName ());

    // Update config
    if (orxString_Compare (widgetName, "ObjAlpha") == 0)
    {
	const orxSTRING alpha = GetText ("ObjAlpha");
	orxConfig_SetString ("Alpha", alpha);
    }
    else if (orxString_Compare (widgetName, "ObjAngularVelocity") == 0)
    {
	const orxSTRING angularVelocity = GetText ("ObjAngularVelocity");
	orxConfig_SetString ("AngularVelocity", angularVelocity);
    }
    else if (orxString_Compare (widgetName, "ObjAnimFreq") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjAnimSet") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjAutoScroll") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjBlendMode") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjBody") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjClock") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjColorR") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjColorG") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjColorB") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjGraphic") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjFXList") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjLifeTime") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjParentCam") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjPosX") == 0 ||
	     orxString_Compare (widgetName, "ObjPosY") == 0 ||
	     orxString_Compare (widgetName, "ObjPosZ") == 0)
    {
	const orxSTRING newX = GetText ("ObjPosX");
	const orxSTRING newY = GetText ("ObjPosY");
	const orxSTRING newZ = GetText ("ObjPosZ");
	orxFLOAT newXFloat;
	orxFLOAT newYFloat;
	orxFLOAT newZFloat;
	orxString_ToFloat (newX,  &newXFloat, orxNULL);
	orxString_ToFloat (newY,  &newYFloat, orxNULL);
	orxString_ToFloat (newZ,  &newZFloat, orxNULL);
	orxVECTOR newPosition = { newXFloat, newYFloat, newZFloat };
	orxConfig_SetVector ("Position", &newPosition);
    }
    else if (orxString_Compare (widgetName, "ObjRepeatX") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjRotation") == 0)
    {
	const orxSTRING rotation = GetText ("ObjRotation");
	orxConfig_SetString ("Rotation", rotation);
    }
    else if (orxString_Compare (widgetName, "ObjSpeedX") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjShaderList") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjSoundList") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjSpawner") == 0)
    {
	orxASSERT (false);
    }
   
    orxConfig_PopSection ();

    // Update object in editor
    UpdateObject ();
}