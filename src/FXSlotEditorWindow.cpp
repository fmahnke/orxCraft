/**
 * @file FXSlotEditorWindow.cpp
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "FXSlotEditorWindow.h"
#ifdef USE_LIBROCKET
#include "WidgetManagerRocket.h"
#else
#include "WidgetManagerCEGUI.h"
#endif
#include "OrxCraft.h"
#include "orx_config_util.h"

void FXSlotEditorWindow::Init (const orxSTRING widgetName)
{
#ifdef USE_LIBROCKET
    m_widgetManager = new WidgetManagerRocket ();
#else
    m_widgetManager = new WidgetManagerCEGUI ();
#endif
    m_widgetManager->Init (widgetName, this);
    strcpy (m_windowName, widgetName);

    SetupFields ();
}

void FXSlotEditorWindow::SetupFields ()
{
    orxConfig_PushSection ("FXSlotEditorWindow");

    // Fill combo boxes
    vector<const orxSTRING> propList;

    orx_config_util::GetListIntoVector ("Type", propList);
    m_widgetManager->FillList ("FXSlotType", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("Curve", propList);
    m_widgetManager->FillList ("FXSlotCurve", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("Absolute", propList);
    m_widgetManager->FillList ("FXSlotAbsolute", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("UseRotation", propList);
    m_widgetManager->FillList ("FXSlotUseRotation", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("UseScale", propList);
    m_widgetManager->FillList ("FXSlotUseScale", propList);

    orxConfig_PopSection ();
}

const orxSTRING FXSlotEditorWindow::GetName ()
{
    return m_windowName;
}

void FXSlotEditorWindow::UpdateFields () const
{
    char buffer[255];

    // Config name
    m_widgetManager->SetText ("FXSlotConfigName", m_context);

    orxConfig_PushSection (m_context);

    // Type
    const orxSTRING type = orx_config_util::ListToString ("Type");
    m_widgetManager->SetText ("FXSlotType", type);
    // Curve
    const orxSTRING curve = orx_config_util::ListToString ("Curve");
    m_widgetManager->SetText ("FXSlotCurve", curve);
    // StartTime
    orx_config_util::FloatToString (orxConfig_GetFloat ("StartTime"), buffer);
    m_widgetManager->SetText ("FXSlotStartTime", buffer);
    // EndTime
    orx_config_util::FloatToString (orxConfig_GetFloat ("EndTime"), buffer);
    m_widgetManager->SetText ("FXSlotEndTime", buffer);
    // StartValue
    orx_config_util::VectorToString ("StartValue", 0, buffer);
    m_widgetManager->SetText ("FXSlotStartValue0", buffer);
    orx_config_util::VectorToString ("StartValue", 1, buffer);
    m_widgetManager->SetText ("FXSlotStartValue1", buffer);
    orx_config_util::VectorToString ("StartValue", 2, buffer);
    m_widgetManager->SetText ("FXSlotStartValue2", buffer);
    // EndValue
    orx_config_util::VectorToString ("EndValue", 0, buffer);
    m_widgetManager->SetText ("FXSlotEndValue0", buffer);
    orx_config_util::VectorToString ("EndValue", 1, buffer);
    m_widgetManager->SetText ("FXSlotEndValue1", buffer);
    orx_config_util::VectorToString ("EndValue", 2, buffer);
    m_widgetManager->SetText ("FXSlotEndValue2", buffer);
    // Phase
    orx_config_util::FloatToString (orxConfig_GetFloat ("Phase"), buffer);
    m_widgetManager->SetText  ("FXSlotPhase", buffer);
    // Period
    orx_config_util::FloatToString (orxConfig_GetFloat ("Period"), buffer);
    m_widgetManager->SetText ("FXSlotPeriod", buffer);
    // Absolute
    orx_config_util::BoolToString (orxConfig_GetBool ("Absolute"), buffer);
    m_widgetManager->SetText ("FXSlotAbsolute", buffer);
    // Acceleration
    orx_config_util::FloatToString (orxConfig_GetFloat ("Acceleration"), buffer);
    m_widgetManager->SetText  ("FXSlotAcceleration", buffer);
    // Amplification
    orx_config_util::FloatToString (orxConfig_GetFloat ("Amplification"), buffer);
    m_widgetManager->SetText ("FXSlotAmplification", buffer);
    // Pow
    orx_config_util::FloatToString (orxConfig_GetFloat ("Pow"), buffer);
    m_widgetManager->SetText ("FXSlotPow", buffer);
    // UseRotation
    orx_config_util::BoolToString (orxConfig_GetBool ("UseRotation"), buffer);
    m_widgetManager->SetText ("FXSlotUseRotation", buffer);
    // UseScale
    orx_config_util::BoolToString (orxConfig_GetBool ("UseScale"), buffer);
    m_widgetManager->SetText ("FXSlotUseScale", buffer);

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

void FXSlotEditorWindow::HandleMouseClick (const orxSTRING widgetName)
{
    orxASSERT (false);
}

void FXSlotEditorWindow::HandleTextAccepted (const orxSTRING widgetName)
{
    orxASSERT (widgetName != orxNULL);
    orxASSERT (m_context != orxNULL);

    // Push config section of edited object
    orxConfig_PushSection (m_context);

    // Update Orx config in memory from value entered in control
    if (orxString_Compare (widgetName, "FXSlotType") == 0)
    {
	orxConfig_SetString ("Type", GetText ("FXSlotType"));
    }
    else if (orxString_Compare (widgetName, "FXSlotCurve") == 0)
    {
	orxConfig_SetString ("Curve", GetText ("FXSlotCurve"));
    }
    else if (orxString_Compare (widgetName, "FXSlotStartTime") == 0)
    {
	orxFLOAT startTime;
	orxString_ToFloat (GetText ("FXSlotStartTime"), &startTime, orxNULL);
	orxConfig_SetFloat ("StartTime", startTime);
    }
    else if (orxString_Compare (widgetName, "FXSlotEndTime") == 0)
    {
	orxFLOAT endTime;
	orxString_ToFloat (GetText ("FXSlotEndTime"), &endTime, orxNULL);
	orxConfig_SetFloat ("EndTime", endTime);
    }
    else if (orxString_Compare (widgetName, "FXSlotStartValue") > 0)
    {
	orxFLOAT XFloat;
	orxFLOAT YFloat;
	orxFLOAT ZFloat;
	orxString_ToFloat (GetText ("FXSlotStartValue0"), &XFloat, orxNULL);
	orxString_ToFloat (GetText ("FXSlotStartValue1"), &YFloat, orxNULL);
	orxString_ToFloat (GetText ("FXSlotStartValue2"), &ZFloat, orxNULL);
	orxVECTOR startValue = { XFloat, YFloat, ZFloat };
	orxConfig_SetVector ("StartValue", &startValue);
    }
    else if (orxString_Compare (widgetName, "FXSlotEndValue") > 0) 
    {
	orxFLOAT XFloat;
	orxFLOAT YFloat;
	orxFLOAT ZFloat;
	orxString_ToFloat (GetText ("FXSlotEndValue0"), &XFloat, orxNULL);
	orxString_ToFloat (GetText ("FXSlotEndValue1"), &YFloat, orxNULL);
	orxString_ToFloat (GetText ("FXSlotEndValue2"), &ZFloat, orxNULL);
	orxVECTOR endValue = { XFloat, YFloat, ZFloat };
	orxConfig_SetVector ("EndValue", &endValue);
    }
    else if (orxString_Compare (widgetName, "FXSlotPhase") == 0)
    {
	orxFLOAT phase;
	orxString_ToFloat (GetText ("FXSlotPhase"), &phase, orxNULL);
	orxConfig_SetFloat ("Phase", phase);
    }
    else if (orxString_Compare (widgetName, "FXSlotPeriod") == 0)
    {
	orxFLOAT period;
	orxString_ToFloat (GetText ("FXSlotPeriod"), &period, orxNULL);
	orxConfig_SetFloat ("Period", period);
    }
    else if (orxString_Compare (widgetName, "FXSlotAbsolute") == 0)
    {
	orxBOOL absolute;
	orxString_ToBool (GetText ("FXSlotAbsolute"), &absolute, orxNULL);
	orxConfig_SetBool ("Absolute", absolute);
    }
    else if (orxString_Compare (widgetName, "FXSlotAcceleration") == 0)
    {
	orxFLOAT accel;
	orxString_ToFloat (GetText ("FXSlotAcceleration"), &accel, orxNULL);
	orxConfig_SetFloat ("Acceleration", accel);
    }
    else if (orxString_Compare (widgetName, "FXSlotAmplification") == 0)
    {
	orxFLOAT ampli;
	orxString_ToFloat (GetText ("FXSlotAmplification"), &ampli, orxNULL);
	orxConfig_SetFloat ("Amplification", ampli);
    }
    else if (orxString_Compare (widgetName, "FXSlotPow") == 0)
    {
	orxFLOAT pow;
	orxString_ToFloat (GetText ("FXSlotPow"), &pow, orxNULL);
	orxConfig_SetFloat ("Pow", pow);
    }
    else if (orxString_Compare (widgetName, "FXSlotUseRotation") == 0)
    {
	orxBOOL useRotation;
	orxString_ToBool (GetText ("FXSlotUseRotation"), &useRotation, orxNULL);
	orxConfig_SetBool ("UseRotation", useRotation);
    }
    else if (orxString_Compare (widgetName, "FXSlotUseScale") == 0)
    {
	orxBOOL useScale;
	orxString_ToBool (GetText ("FXSlotUseScale"), &useScale, orxNULL);
	orxConfig_SetBool ("UseScale", useScale);
    }

    orxConfig_PopSection ();

    OrxCraft::GetInstance ().NeedObjectUpdate ();
}