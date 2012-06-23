/**
 * @file ObjectEditor.cpp
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#include "ObjectEditor.h"
#ifdef USE_LIBROCKET
#include "WidgetManagerRocket.h"
#else
#include "WidgetManagerCEGUI.h"
#endif
#include "OrxCraft.h"
#include "orx_config_util.h"

ObjectEditor::ObjectEditor () :
    m_object (NULL)
{
}

void ObjectEditor::Init (const orxSTRING widgetName)
{
#ifdef USE_LIBROCKET
    m_widgetManager = new WidgetManagerRocket ();
#else
    m_widgetManager = new WidgetManagerCEGUI ();
#endif
    m_widgetManager->Init (widgetName, this);

    SetupFields ();
}

void ObjectEditor::SetupFields ()
{
    vector<const orxSTRING> propList =
	OrxCraft::GetInstance ().GetGraphicList ();

    m_widgetManager->FillList ("ObjGraphic", propList);

    orxConfig_PushSection ("ObjectEditor");

    // Fill combo boxes
    propList.clear ();
    orx_config_util::GetListIntoVector ("AutoScroll", propList);
    m_widgetManager->FillList ("ObjAutoScroll", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("BlendMode", propList);
    m_widgetManager->FillList ("ObjBlendMode", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("DepthScale", propList);
    m_widgetManager->FillList ("ObjDepthScale", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("Flip", propList);
    m_widgetManager->FillList ("ObjFlip", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("Smoothing", propList);
    m_widgetManager->FillList ("ObjSmoothing", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("UseParentSpace", propList);
    m_widgetManager->FillList ("ObjUseParentSpace", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("UseRelativeSpeed", propList);
    m_widgetManager->FillList ("ObjUseRelativeSpeed", propList);

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
	orx_config_util::FloatToString (orxConfig_GetFloat ("Alpha"), buffer);
	m_widgetManager->SetText ("ObjAlpha", buffer);
	// AngularVelocity
	orx_config_util::FloatToString (orxConfig_GetFloat ("AngularVelocity"), buffer);
	m_widgetManager->SetText ("ObjAngularVelocity", buffer);
	// AnimationFrequency
	orx_config_util::FloatToString (orxConfig_GetFloat ("AnimationFrequency"), buffer);
	m_widgetManager->SetText ("ObjAnimFreq", buffer);
	// AnimationSet
	const orxSTRING aS = orx_config_util::ListToString ("AnimationSet");
	m_widgetManager->SetText ("ObjAnimSet", aS);
	// AutoScroll
	const orxSTRING aSc = orx_config_util::ListToString ("AutoScroll");
	m_widgetManager->SetText ("ObjAutoScroll", aSc);
	// BlendMode
	const orxSTRING bl = orx_config_util::ListToString ("BlendMode");
	m_widgetManager->SetText ("ObjBlendMode", bl);
	// Body
	const orxSTRING body = orx_config_util::ListToString ("Body");
	m_widgetManager->SetText ("ObjBody", body);
	// ChildList
	/** @todo ChildList */
	// ChildJointList
	/** @todo ChildJointList */
	// Clock
	const orxSTRING clock = orx_config_util::ListToString ("Clock");
	m_widgetManager->SetText ("ObjClock", clock);
	// Color
	orx_config_util::VectorToString ("Color", 0, buffer);
	m_widgetManager->SetText ("ObjColor0", buffer);
	orx_config_util::VectorToString ("Color", 1, buffer);
	m_widgetManager->SetText ("ObjColor1", buffer);
	orx_config_util::VectorToString ("Color", 2, buffer);
	m_widgetManager->SetText ("ObjColor2", buffer);
	// DepthScale
	orx_config_util::BoolToString (orxConfig_GetBool ("DepthScale"), buffer);
	m_widgetManager->SetText ("ObjDepthScale", buffer);
	// Graphic
	const orxSTRING graphic = orx_config_util::ListToString ("Graphic");
	m_widgetManager->SetText ("ObjGraphic", graphic);
	// Flip
	const orxSTRING flip = orx_config_util::ListToString ("Flip");
	m_widgetManager->SetText ("ObjFlip", flip);
	// FXList
	const orxSTRING fxList = orx_config_util::ListToString ("FXList");
	m_widgetManager->SetText ("ObjFXList", fxList);
	// LifeTime
	orx_config_util::FloatToString (orxConfig_GetFloat ("LifeTime"), buffer);
	m_widgetManager->SetText ("ObjLifeTime", buffer);
	// ParentCamera
	const orxSTRING parentCam = orx_config_util::ListToString ("ParentCamera");
	m_widgetManager->SetText ("ObjParentCam", parentCam);
	// Position
	orx_config_util::VectorToString ("Position", 0, buffer);
	m_widgetManager->SetText ("ObjPos0", buffer);
	orx_config_util::VectorToString ("Position", 1, buffer);
	m_widgetManager->SetText ("ObjPos1", buffer);
	orx_config_util::VectorToString ("Position", 2, buffer);
	m_widgetManager->SetText ("ObjPos2", buffer);
	// Repeat
	orx_config_util::VectorToString ("Repeat", 0, buffer);
	m_widgetManager->SetText ("ObjRepeat0", buffer);
	orx_config_util::VectorToString ("Repeat", 1, buffer);
	m_widgetManager->SetText ("ObjRepeat1", buffer);
	orx_config_util::VectorToString ("Repeat", 2, buffer);
	m_widgetManager->SetText ("ObjRepeat2", buffer);
	// Rotation
	orx_config_util::FloatToString (orxConfig_GetFloat ("Rotation"), buffer);
	m_widgetManager->SetText ("ObjRotation", buffer);
	// Speed
	orx_config_util::VectorToString ("Speed", 0, buffer);
	m_widgetManager->SetText ("ObjSpeedX", buffer);
	orx_config_util::VectorToString ("Speed", 1, buffer);
	m_widgetManager->SetText ("ObjSpeedY", buffer);
	orx_config_util::VectorToString ("Speed", 2, buffer);
	m_widgetManager->SetText ("ObjSpeedZ", buffer);
	// Scale
	orx_config_util::VectorToString ("Scale", 0, buffer);
	m_widgetManager->SetText ("ObjScale0", buffer);
	orx_config_util::VectorToString ("Scale", 1, buffer);
	m_widgetManager->SetText ("ObjScale1", buffer);
	orx_config_util::VectorToString ("Scale", 2, buffer);
	m_widgetManager->SetText ("ObjScale2", buffer);
	// ShaderList
	//! @todo ShaderList
	// SoundList
	//! @todo SoundList
	// Spawner
	const orxSTRING spawner = orx_config_util::ListToString ("Spawner");
	m_widgetManager->SetText ("ObjSpawner", spawner);
	// Smoothing
	orx_config_util::BoolToString (orxConfig_GetBool ("Smoothing"), buffer);
	m_widgetManager->SetText ("ObjSmoothing", buffer);
	// UseParentSpace
	orx_config_util::BoolToString (orxConfig_GetBool ("UseParentSpace"),
				       buffer);
	m_widgetManager->SetText ("ObjUseParentSpace", buffer);
	// UseRelativeSpeed
	orx_config_util::BoolToString (orxConfig_GetBool ("UseRelativeSpeed"),
				       buffer);
	m_widgetManager->SetText ("ObjUseRelativeSpeed", buffer);

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
	orxFLOAT animFreq;
	orxString_ToFloat (GetText ("ObjAnimFreq"), &animFreq, orxNULL);
	orxConfig_SetFloat ("AnimationFrequency", animFreq);
    }
    else if (orxString_Compare (widgetName, "ObjAnimSet") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjAutoScroll") == 0)
    {
	const orxSTRING autoScroll = GetText ("ObjAutoScroll");
	orxConfig_SetString ("AutoScroll", autoScroll);
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
    else if (orxString_Compare (widgetName, "ObjDepthScale") == 0)
    {
	const orxSTRING depthScaleStr = GetText ("ObjDepthScale");
	orxBOOL depthScaleBool;
	orxString_ToBool (depthScaleStr, &depthScaleBool, orxNULL);
	orxConfig_SetBool ("DepthScale", depthScaleBool);
    }
    else if (orxString_Compare (widgetName, "ObjGraphic") == 0)
    {
	const orxSTRING graphic = GetText ("ObjGraphic");
	orxConfig_SetString ("Graphic", graphic);
    }
    else if (orxString_Compare (widgetName, "ObjFlip") == 0)
    {
	const orxSTRING flip = GetText ("ObjFlip");
	orxConfig_SetString ("Flip", flip);
    }
    else if (orxString_Compare (widgetName, "ObjFXList") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjLifeTime") == 0)
    {
	orxFLOAT lifeTime;
	orxString_ToFloat (GetText ("ObjLifeTime"), &lifeTime, orxNULL);
	orxConfig_SetFloat ("LifeTime", lifeTime);
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
	orxFLOAT XFloat;
	orxFLOAT YFloat;
	orxFLOAT ZFloat;
	orxString_ToFloat (GetText ("ObjRepeat0"), &XFloat, orxNULL);
	orxString_ToFloat (GetText ("ObjRepeat1"), &YFloat, orxNULL);
	orxString_ToFloat (GetText ("ObjRepeat2"), &ZFloat, orxNULL);
	orxVECTOR repeat = { XFloat, YFloat, ZFloat };
	orxConfig_SetVector ("Repeat", &repeat);
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
    else if (orxString_SearchString (widgetName, "ObjScale") > 0)
    {
	orxFLOAT XFloat;
	orxFLOAT YFloat;
	orxFLOAT ZFloat;
	orxString_ToFloat (GetText ("ObjScale0"), &XFloat, orxNULL);
	orxString_ToFloat (GetText ("ObjScale1"), &YFloat, orxNULL);
	orxString_ToFloat (GetText ("ObjScale2"), &ZFloat, orxNULL);
	orxVECTOR scale = { XFloat, YFloat, ZFloat };
	orxConfig_SetVector ("Scale", &scale);
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