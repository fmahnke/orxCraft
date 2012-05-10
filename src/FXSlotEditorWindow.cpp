/**
 * @file FXSlotEditorWindow.cpp
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "OrxCraft.h"

#include "FXSlotEditorWindow.h"

#include "WidgetManager.h"

#include "orxConfigTypeHelper.h"

void FXSlotEditorWindow::Init (const orxSTRING widgetName)
{
    m_widgetManager = new WidgetManager ();
    m_widgetManager->Init (widgetName, this);
    strcpy (m_windowName, widgetName);
}
/*
bool SaveFunction (const orxSTRING _zSectionName, const orxSTRING _zKeyName, const orxSTRING _zFileName, orxBOOL _bUseEncryption)
{
}
*/

void FXSlotEditorWindow::HandleTextAccepted (const orxSTRING widgetName)
{
    orxASSERT (widgetName != orxNULL);
    orxASSERT (m_context != orxNULL);

    // Push config section of edited object
    orxConfig_PushSection (m_context);

    // Update config
    if (orxString_Compare (widgetName, "FXSlotEndValue0") == 0 ||
	orxString_Compare (widgetName, "FXSlotEndValue1") == 0 ||
	orxString_Compare (widgetName, "FXSlotEndValue2") == 0)
    {
	const orxSTRING newX = GetText ("FXSlotEndValue0");
	const orxSTRING newY = GetText ("FXSlotEndValue1");
	const orxSTRING newZ = GetText ("FXSlotEndValue2");
	orxFLOAT newXFloat;
	orxFLOAT newYFloat;
	orxFLOAT newZFloat;
	orxString_ToFloat (newX,  &newXFloat, orxNULL);
	orxString_ToFloat (newY,  &newYFloat, orxNULL);
	orxString_ToFloat (newZ,  &newZFloat, orxNULL);
	orxVECTOR newPosition = { newXFloat, newYFloat, newZFloat };
	orxConfig_SetVector ("EndValue", &newPosition);
    }

    orxConfig_PopSection ();

    orxConfig_Save ("sampleconfig.ini", false, orxNULL);

    OrxCraft::GetInstance ().NeedObjectUpdate ();
}

const orxSTRING FXSlotEditorWindow::GetName ()
{
    return m_windowName;
}

/**
 *  Update all fields on this window using the current values from config
 */
void FXSlotEditorWindow::UpdateFields () const
{
    char buffer[255];

    // Config name
    m_widgetManager->SetText ("FXSlotConfigName", m_windowName);

    orxConfig_PushSection (m_context);

    // Type
    // Curve
    // StartTime

    OrxConfigTypeHelper::FloatToString (orxConfig_GetFloat ("StartTime"), buffer);
    m_widgetManager->SetText ("FXSlotStartTime", buffer);

    // StartValue

    OrxConfigTypeHelper::VectorToString ("EndValue", 0, buffer);
    m_widgetManager->SetText ("FXSlotEndValue0", buffer);
    OrxConfigTypeHelper::VectorToString ("EndValue", 1, buffer);
    m_widgetManager->SetText ("FXSlotEndValue1", buffer);
    OrxConfigTypeHelper::VectorToString ("EndValue", 2, buffer);
    m_widgetManager->SetText ("FXSlotEndValue2", buffer);
#if 0
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
#endif
    orxConfig_PopSection ();
}

const orxSTRING FXSlotEditorWindow::GetText (const orxSTRING widgetName) const
{
    return m_widgetManager->GetText (widgetName);
}

void FXSlotEditorWindow::SetContext (const orxSTRING sectionName)
{
    strcpy (m_context, sectionName);
    UpdateFields ();
}

