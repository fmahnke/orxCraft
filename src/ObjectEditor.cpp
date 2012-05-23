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

    SetupFields ();
}

void ObjectEditor::SetupFields ()
{
    vector<const orxSTRING> propList =
	OrxCraft::GetInstance ().GetGraphicList ();

    m_widgetManager->FillList ("ObjGraphic", propList);
    propList.clear ();

    orxConfig_PushSection ("ObjectEditor");

    int counter = orxConfig_GetListCounter ("BlendMode");
    for (int i = 0; i < counter; i++)
    {
	// Get and store next property
	const orxSTRING property = orxConfig_GetListString ("BlendMode", i);
	propList.push_back (property);
    }
    // Fill field with list of properties
    m_widgetManager->FillList ("ObjBlendMode", propList);

    orxConfig_PopSection ();
}

const orxSTRING ObjectEditor::GetName ()
{
    orxASSERT (false);
    return orxNULL;
}

const orxSTRING ObjectEditor::GetText (const orxSTRING widgetName) const
{
    return m_widgetManager->GetText (widgetName);
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
	m_widgetManager->SetText ("ObjectConfigName", name);

	orxConfig_PushSection (name);

	// Alpha
	ConfigType::FloatToString (orxConfig_GetFloat ("Alpha"), buffer);
	m_widgetManager->SetText ("ObjAlpha", buffer);
	// AngularVelocity
	ConfigType::FloatToString (orxConfig_GetFloat ("AngularVelocity"), buffer);
	m_widgetManager->SetText ("ObjAngularVelocity", buffer);
	// AnimationFrequency
	ConfigType::FloatToString (orxConfig_GetFloat ("AnimationFrequency"), buffer);
	m_widgetManager->SetText ("ObjAnimFreq", buffer);
	// AnimationSet
	const orxSTRING aS = ConfigType::ListToString ("AnimationSet");
	m_widgetManager->SetText ("ObjAnimSet", aS);
	// AutoScroll
	const orxSTRING aSc = ConfigType::ListToString ("AutoScroll");
	m_widgetManager->SetText ("ObjAutoScroll", aS);
	// BlendMode
	const orxSTRING bl = ConfigType::ListToString ("BlendMode");
	m_widgetManager->SetText ("ObjBlendMode", aS);
	// Body
	const orxSTRING body = ConfigType::ListToString ("Body");
	m_widgetManager->SetText ("ObjBody", aS);
	// ChildList
	/** @todo ChildList */
	// ChildJointList
	/** @todo ChildJointList */
	// Clock
	const orxSTRING clock = ConfigType::ListToString ("Clock");
	m_widgetManager->SetText ("ObjClock", clock);
	// Color
	ConfigType::VectorToString ("Color", 0, buffer);
	m_widgetManager->SetText ("ObjColor0", buffer);
	ConfigType::VectorToString ("Color", 1, buffer);
	m_widgetManager->SetText ("ObjColor1", buffer);
	ConfigType::VectorToString ("Color", 2, buffer);
	m_widgetManager->SetText ("ObjColor2", buffer);
	// DepthScale
	/** @todo DepthScale */
	// Graphic
	const orxSTRING graphic = ConfigType::ListToString ("Graphic");
	m_widgetManager->SetText ("ObjGraphic", graphic);
	// Flip
	const orxSTRING flip = ConfigType::ListToString ("Flip");
	m_widgetManager->SetText ("ObjFlip", flip);
	// FXList
	const orxSTRING fxList = ConfigType::ListToString ("FXList");
	m_widgetManager->SetText ("ObjFXList", fxList);
	// LifeTime
	ConfigType::FloatToString (orxConfig_GetFloat ("LifeTime"), buffer);
	m_widgetManager->SetText ("ObjLifeTime", buffer);
	// ParentCamera
	const orxSTRING parentCam = ConfigType::ListToString ("ParentCamera");
	m_widgetManager->SetText ("ObjParentCam", parentCam);
	// Position
	ConfigType::VectorToString ("Position", 0, buffer);
	m_widgetManager->SetText ("ObjPos0", buffer);
	ConfigType::VectorToString ("Position", 1, buffer);
	m_widgetManager->SetText ("ObjPos1", buffer);
	ConfigType::VectorToString ("Position", 2, buffer);
	m_widgetManager->SetText ("ObjPos2", buffer);
	// Repeat
	ConfigType::VectorToString ("Repeat", 0, buffer);
	m_widgetManager->SetText ("ObjRepeatX", buffer);
	ConfigType::VectorToString ("Repeat", 1, buffer);
	m_widgetManager->SetText ("ObjRepeatY", buffer);
	ConfigType::VectorToString ("Repeat", 2, buffer);
	m_widgetManager->SetText ("ObjRepeatZ", buffer);
	// Rotation
	ConfigType::FloatToString (orxConfig_GetFloat ("Rotation"), buffer);
	m_widgetManager->SetText ("ObjRotation", buffer);
	// Speed
	ConfigType::VectorToString ("Speed", 0, buffer);
	m_widgetManager->SetText ("ObjSpeedX", buffer);
	ConfigType::VectorToString ("Speed", 1, buffer);
	m_widgetManager->SetText ("ObjSpeedY", buffer);
	ConfigType::VectorToString ("Speed", 2, buffer);
	m_widgetManager->SetText ("ObjSpeedZ", buffer);
	// Scale
	ConfigType::VectorToString ("Scale", 0, buffer);
	m_widgetManager->SetText ("ObjScaleX", buffer);
	ConfigType::VectorToString ("Scale", 1, buffer);
	m_widgetManager->SetText ("ObjScaleY", buffer);
	ConfigType::VectorToString ("Scale", 2, buffer);
	m_widgetManager->SetText ("ObjScaleZ", buffer);
	// ShaderList
	//! @todo ShaderList
	// SoundList
	//! @todo SoundList
	// Spawner
	const orxSTRING spawner = ConfigType::ListToString ("Spawner");
	m_widgetManager->SetText ("ObjSpawner", spawner);
	// Smoothing
	orxBOOL smoothing = orxConfig_GetBool ("Smoothing");
	m_widgetManager->SetText ("ObjSmoothing", smoothing ? "true" : "false");
	// UseParentSpace
	orxBOOL useParentSpace = orxConfig_GetBool ("UseParentSpace");
	m_widgetManager->SetText ("ObjUseParentSpace",
	                          useParentSpace ? "true" : "false");
	// UseRelativeSpeed
	orxBOOL useRelativeSpeed = orxConfig_GetBool ("UseRelativeSpeed");
	m_widgetManager->SetText ("ObjUseRelativeSpeed",
				  useRelativeSpeed ? "true" : "false");

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
	const orxSTRING blendMode = GetText ("ObjBlendMode");
	orxConfig_SetString ("BlendMode", blendMode);
    }
    else if (orxString_Compare (widgetName, "ObjBody") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjClock") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_SearchString (widgetName, "ObjColor") > 0)
    {
	orxFLOAT newRFloat;
	orxFLOAT newGFloat;
	orxFLOAT newBFloat;
	orxString_ToFloat (GetText ("ObjColor0"), &newRFloat, orxNULL);
	orxString_ToFloat (GetText ("ObjColor1"), &newGFloat, orxNULL);
	orxString_ToFloat (GetText ("ObjColor2"), &newBFloat, orxNULL);
	orxVECTOR newColor = { newRFloat, newGFloat, newBFloat };
	orxConfig_SetVector ("Color", &newColor);
    }
    else if (orxString_Compare (widgetName, "ObjGraphic") == 0)
    {
	const orxSTRING graphic = GetText ("ObjGraphic");
	orxConfig_SetString ("Graphic", graphic);
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
    else if (orxString_SearchString (widgetName, "ObjPos") > 0)
    {
	orxFLOAT newXFloat;
	orxFLOAT newYFloat;
	orxFLOAT newZFloat;
	orxString_ToFloat (GetText ("ObjPos0"), &newXFloat, orxNULL);
	orxString_ToFloat (GetText ("ObjPos1"), &newYFloat, orxNULL);
	orxString_ToFloat (GetText ("ObjPos2"), &newZFloat, orxNULL);
	orxVECTOR newPosition = { newXFloat, newYFloat, newZFloat };
	orxConfig_SetVector ("Position", &newPosition);
    }
    else if (orxString_SearchString (widgetName, "ObjRepeat") > 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjRotation") == 0)
    {
	const orxSTRING rotation = GetText ("ObjRotation");
	orxConfig_SetString ("Rotation", rotation);
    }
    else if (orxString_SearchString (widgetName, "ObjSpeed") > 0)
    {
	orxFLOAT newXFloat;
	orxFLOAT newYFloat;
	orxFLOAT newZFloat;
	orxString_ToFloat (GetText ("ObjSpeedX"), &newXFloat, orxNULL);
	orxString_ToFloat (GetText ("ObjSpeedY"), &newYFloat, orxNULL);
	orxString_ToFloat (GetText ("ObjSpeedZ"), &newZFloat, orxNULL);
	orxVECTOR newSpeed = { newXFloat, newYFloat, newZFloat };
	orxConfig_SetVector ("Speed", &newSpeed);
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
    OrxCraft::GetInstance ().NeedObjectUpdate ();
}