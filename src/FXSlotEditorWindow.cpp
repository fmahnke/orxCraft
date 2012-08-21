/**
 * @file FXSlotEditorWindow.cpp
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "FXSlotEditorWindow.h"
#include "orxCraft.h"
#include "orx_config_util.h"

#include "ScrollCombobox.h"
#include "ScrollEditbox.h"

FXSlotEditorWindow::FXSlotEditorWindow () :
    m_fxsType (NULL),
    m_fxsCurve (NULL),
    m_fxsStartTime (NULL),
    m_fxsEndTime (NULL),
    m_fxsStartValue0 (NULL),
    m_fxsStartValue1 (NULL),
    m_fxsStartValue2 (NULL),
    m_fxsEndValue0 (NULL),
    m_fxsEndValue1 (NULL),
    m_fxsEndValue2 (NULL),
    m_fxsPhase (NULL),
    m_fxsPeriod (NULL),
    m_fxsAcceleration (NULL),
    m_fxsAmplification (NULL),
    m_fxsPow (NULL),
    m_fxsAbsolute (NULL),
    m_fxsUseRotation (NULL),
    m_fxsUseScale (NULL),
    m_fxsConfigName (NULL)
{
}

void FXSlotEditorWindow::Init (const orxSTRING widgetName)
{
    m_fxsType = FindCombobox ("FXSlotType");
    m_fxsCurve = FindCombobox ("FXSlotCurve");
    m_fxsStartTime = FindEditbox ("FXSlotStartTime");
    m_fxsEndTime = FindEditbox ("FXSlotEndTime");
    m_fxsStartValue0 = FindEditbox ("FXSlotStartValue0");
    m_fxsStartValue1 = FindEditbox ("FXSlotStartValue1");
    m_fxsStartValue2 = FindEditbox ("FXSlotStartValue2");
    m_fxsEndValue0 = FindEditbox ("FXSlotEndValue0");
    m_fxsEndValue1 = FindEditbox ("FXSlotEndValue1");
    m_fxsEndValue2 = FindEditbox ("FXSlotEndValue2");
    m_fxsPhase = FindEditbox ("FXSlotPhase");
    m_fxsPeriod = FindEditbox ("FXSlotPeriod");
    m_fxsAcceleration = FindEditbox ("FXSlotAcceleration");
    m_fxsAmplification = FindEditbox ("FXSlotAmplification");
    m_fxsPow = FindEditbox ("FXSlotPow");
    m_fxsAbsolute = FindCombobox ("FXSlotAbsolute");
    m_fxsUseRotation = FindCombobox ("FXSlotUseRotation");
    m_fxsUseScale = FindCombobox ("FXSlotUseScale");
    m_fxsConfigName = FindCombobox ("FXSlotConfigName");

    SetupFields ();

    SetContext ("FXS-Darken");
}

void FXSlotEditorWindow::SetupFields ()
{
    vector<const orxSTRING> propList;
    propList = OrxCraft::GetInstance ().GetFXSlotList ();
    m_fxsConfigName->Fill (propList);
    
    orxConfig_PushSection ("FXSlotEditorWindow");

    // Fill combo boxes

    orx_config_util::GetListIntoVector ("Type", propList);
    m_fxsType->Fill (propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("Curve", propList);
    m_fxsCurve->Fill (propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("Absolute", propList);
    m_fxsAbsolute->Fill (propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("UseRotation", propList);
    m_fxsUseRotation->Fill (propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("UseScale", propList);
    m_fxsUseScale->Fill (propList);

    orxConfig_PopSection ();
}

const orxSTRING FXSlotEditorWindow::GetName ()
{
    return "FXSlotEditor";
}

void FXSlotEditorWindow::UpdateFields () const
{
    char buffer[255];

    // Config name
    m_fxsConfigName->SelectItem (m_context);

    orxConfig_PushSection (m_context);

    // Type
    const orxSTRING type = orx_config_util::ListToString ("Type");
    m_fxsType->SelectItem (type);
    // Curve
    const orxSTRING curve = orx_config_util::ListToString ("Curve");
    m_fxsCurve->SelectItem (curve);
    // StartTime
    orx_config_util::FloatToString (orxConfig_GetFloat ("StartTime"), buffer);
    m_fxsStartTime->SetText (buffer);
    // EndTime
    orx_config_util::FloatToString (orxConfig_GetFloat ("EndTime"), buffer);
    m_fxsEndTime->SetText (buffer);
    // StartValue
    orx_config_util::VectorToString ("StartValue", 0, buffer);
    m_fxsStartValue0->SetText (buffer);
    orx_config_util::VectorToString ("StartValue", 1, buffer);
    m_fxsStartValue1->SetText (buffer);
    orx_config_util::VectorToString ("StartValue", 2, buffer);
    m_fxsStartValue2->SetText (buffer);
    // EndValue
    orx_config_util::VectorToString ("EndValue", 0, buffer);
    m_fxsEndValue0->SetText (buffer);
    orx_config_util::VectorToString ("EndValue", 1, buffer);
    m_fxsEndValue1->SetText (buffer);
    orx_config_util::VectorToString ("EndValue", 2, buffer);
    m_fxsEndValue2->SetText (buffer);
    // Phase
    orx_config_util::FloatToString (orxConfig_GetFloat ("Phase"), buffer);
    m_fxsPhase->SetText (buffer);
    // Period
    orx_config_util::FloatToString (orxConfig_GetFloat ("Period"), buffer);
    m_fxsPeriod->SetText (buffer);
    // Absolute
    orx_config_util::BoolToString (orxConfig_GetBool ("Absolute"), buffer);
    m_fxsAbsolute->SelectItem (buffer);
    // Acceleration
    orx_config_util::FloatToString (orxConfig_GetFloat ("Acceleration"), buffer);
    m_fxsAcceleration->SetText (buffer);
    // Amplification
    orx_config_util::FloatToString (orxConfig_GetFloat ("Amplification"), buffer);
    m_fxsAmplification->SetText (buffer);
    // Pow
    orx_config_util::FloatToString (orxConfig_GetFloat ("Pow"), buffer);
    m_fxsPow->SetText (buffer);
    // UseRotation
    orx_config_util::BoolToString (orxConfig_GetBool ("UseRotation"), buffer);
    m_fxsUseRotation->SelectItem (buffer);
    // UseScale
    orx_config_util::BoolToString (orxConfig_GetBool ("UseScale"), buffer);
    m_fxsUseScale->SelectItem (buffer);

    orxConfig_PopSection ();
}

const orxSTRING FXSlotEditorWindow::GetText (const orxSTRING widgetName) const
{
    orxASSERT (false);
    return orxNULL;
}

void FXSlotEditorWindow::SetContext (const orxSTRING sectionName)
{
    strcpy (m_context, sectionName);
    UpdateFields ();
}

void FXSlotEditorWindow::OnMouseClick (const orxSTRING widgetName)
{
    orxASSERT (false);
}

void FXSlotEditorWindow::OnTextAccepted (const orxSTRING widgetName)
{
    orxASSERT (widgetName != orxNULL);
    orxASSERT (m_context != orxNULL);

    if (orxString_Compare (widgetName, "FXSlotConfigName") == 0)
    {
	const orxSTRING name = m_fxsConfigName->GetSelectedItem ();
	//! @todo Better not to have this in the Scroll singleton
	SetContext (name);
    }

    // Push config section of edited object
    orxConfig_PushSection (m_context);

    // Update Orx config in memory from value entered in control
    if (orxString_Compare (widgetName, "FXSlotType") == 0)
    {
	const orxSTRING type = m_fxsType->GetSelectedItem ();
	orxConfig_SetString ("Type", type);
    }
    else if (orxString_Compare (widgetName, "FXSlotCurve") == 0)
    {
	const orxSTRING curve = m_fxsCurve->GetSelectedItem ();
	orxConfig_SetString ("Curve", curve);
    }
    else if (orxString_Compare (widgetName, "FXSlotStartTime") == 0)
    {
	orxFLOAT startTime;
	orxString_ToFloat (m_fxsStartTime->GetText (), &startTime, orxNULL);
	orxConfig_SetFloat ("StartTime", startTime);
    }
    else if (orxString_Compare (widgetName, "FXSlotEndTime") == 0)
    {
	orxFLOAT endTime;
	orxString_ToFloat (m_fxsEndTime->GetText (), &endTime, orxNULL);
	orxConfig_SetFloat ("EndTime", endTime);
    }
    else if (orxString_Compare (widgetName, "FXSlotStartValue") > 0)
    {
	orxFLOAT XFloat;
	orxFLOAT YFloat;
	orxFLOAT ZFloat;
	orxString_ToFloat (m_fxsStartValue0->GetText (), &XFloat, orxNULL);
	orxString_ToFloat (m_fxsStartValue1->GetText (), &YFloat, orxNULL);
	orxString_ToFloat (m_fxsStartValue2->GetText (), &ZFloat, orxNULL);
	orxVECTOR startValue = { {XFloat}, {YFloat}, {ZFloat} };
	orxConfig_SetVector ("StartValue", &startValue);
    }
    else if (orxString_Compare (widgetName, "FXSlotEndValue") > 0) 
    {
	orxFLOAT XFloat;
	orxFLOAT YFloat;
	orxFLOAT ZFloat;
	orxString_ToFloat (m_fxsEndValue0->GetText (), &XFloat, orxNULL);
	orxString_ToFloat (m_fxsEndValue1->GetText (), &YFloat, orxNULL);
	orxString_ToFloat (m_fxsEndValue2->GetText (), &ZFloat, orxNULL);
	orxVECTOR endValue = { {XFloat}, {YFloat}, {ZFloat} };
	orxConfig_SetVector ("EndValue", &endValue);
    }
    else if (orxString_Compare (widgetName, "FXSlotPhase") == 0)
    {
	orxFLOAT phase;
	orxString_ToFloat (m_fxsPhase->GetText (), &phase, orxNULL);
	orxConfig_SetFloat ("Phase", phase);
    }
    else if (orxString_Compare (widgetName, "FXSlotPeriod") == 0)
    {
	orxFLOAT period;
	orxString_ToFloat (m_fxsPeriod->GetText (), &period, orxNULL);
	orxConfig_SetFloat ("Period", period);
    }
    else if (orxString_Compare (widgetName, "FXSlotAbsolute") == 0)
    {
	orxBOOL absolute;
	orxString_ToBool (m_fxsAbsolute->GetSelectedItem (), &absolute,
		          orxNULL);
	orxConfig_SetBool ("Absolute", absolute);
    }
    else if (orxString_Compare (widgetName, "FXSlotAcceleration") == 0)
    {
	orxFLOAT accel;
	orxString_ToFloat (m_fxsAcceleration->GetText (), &accel, orxNULL);
	orxConfig_SetFloat ("Acceleration", accel);
    }
    else if (orxString_Compare (widgetName, "FXSlotAmplification") == 0)
    {
	orxFLOAT ampli;
	orxString_ToFloat (m_fxsAmplification->GetText (), &ampli, orxNULL);
	orxConfig_SetFloat ("Amplification", ampli);
    }
    else if (orxString_Compare (widgetName, "FXSlotPow") == 0)
    {
	orxFLOAT pow;
	orxString_ToFloat (m_fxsPow->GetText (), &pow, orxNULL);
	orxConfig_SetFloat ("Pow", pow);
    }
    else if (orxString_Compare (widgetName, "FXSlotUseRotation") == 0)
    {
	orxBOOL useRotation;
	orxString_ToBool (m_fxsUseRotation->GetSelectedItem (), &useRotation,
			  orxNULL);
	orxConfig_SetBool ("UseRotation", useRotation);
    }
    else if (orxString_Compare (widgetName, "FXSlotUseScale") == 0)
    {
	orxBOOL useScale;
	orxString_ToBool (m_fxsUseScale->GetSelectedItem (), &useScale,
			  orxNULL);
	orxConfig_SetBool ("UseScale", useScale);
    }

    orxConfig_PopSection ();

    OrxCraft::GetInstance ().NeedObjectUpdate ();
}

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
