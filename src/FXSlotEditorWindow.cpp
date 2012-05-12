/**
 * @file FXSlotEditorWindow.cpp
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "OrxCraft.h"
#include "FXSlotEditorWindow.h"
#include "WidgetManager.h"
#include "ConfigType.h"

void FXSlotEditorWindow::Init (const orxSTRING widgetName)
{
    m_widgetManager = new WidgetManager ();
    m_widgetManager->Init (widgetName, this);
    strcpy (m_windowName, widgetName);

    SetupFields ();
}

void FXSlotEditorWindow::SetupFields ()
{
    orxConfig_PushSection ("FXSlotEditorWindow");

    vector<const orxSTRING> propList;
    int counter = orxConfig_GetListCounter ("Type");
    for (int i = 0; i < counter; i++)
    {
	// Get and store next property
	const orxSTRING property = orxConfig_GetListString ("Type", i);
	propList.push_back (property);
    }
    // Fill field with list of properties
    m_widgetManager->FillList ("FXSlotType", propList);
    propList.clear ();

    counter = orxConfig_GetListCounter ("Curve");
    for (int i = 0; i < counter; i++)
    {
	// Get and store next property
	const orxSTRING property = orxConfig_GetListString ("Curve", i);
	propList.push_back (property);
    }
    // Fill field with list of properties
    m_widgetManager->FillList ("FXSlotCurve", propList);
    propList.clear ();

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
    const orxSTRING type = ConfigType::ListToString ("Type");
    m_widgetManager->SetText ("FXSlotType", type);
    // Curve
    const orxSTRING curve = ConfigType::ListToString ("Curve");
    m_widgetManager->SetText ("FXSlotCurve", curve);
    // StartTime
    ConfigType::FloatToString (orxConfig_GetFloat ("StartTime"), buffer);
    m_widgetManager->SetText ("FXSlotStartTime", buffer);
    // EndTime
    /** @todo EndTime control */
    // StartValue
    ConfigType::VectorToString ("StartValue", 0, buffer);
    m_widgetManager->SetText ("FXSlotStartValue0", buffer);
    ConfigType::VectorToString ("StartValue", 1, buffer);
    m_widgetManager->SetText ("FXSlotStartValue1", buffer);
    ConfigType::VectorToString ("StartValue", 2, buffer);
    m_widgetManager->SetText ("FXSlotStartValue2", buffer);
    // EndValue
    ConfigType::VectorToString ("EndValue", 0, buffer);
    m_widgetManager->SetText ("FXSlotEndValue0", buffer);
    ConfigType::VectorToString ("EndValue", 1, buffer);
    m_widgetManager->SetText ("FXSlotEndValue1", buffer);
    ConfigType::VectorToString ("EndValue", 2, buffer);
    m_widgetManager->SetText ("FXSlotEndValue2", buffer);
    // Phase
    ConfigType::FloatToString (orxConfig_GetFloat ("Phase"), buffer);
    m_widgetManager->SetText  ("FXSlotPhase", buffer);
    // Period
    ConfigType::FloatToString (orxConfig_GetFloat ("Period"), buffer);
    m_widgetManager->SetText ("FXSlotPeriod", buffer);
    // Absolute
    /** @todo Absolute */
    // Acceleration
    ConfigType::FloatToString (orxConfig_GetFloat ("Acceleration"), buffer);
    m_widgetManager->SetText  ("FXSlotAcceleration", buffer);
    // Amplification
    ConfigType::FloatToString (orxConfig_GetFloat ("Amplification"), buffer);
    m_widgetManager->SetText ("FXSlotAmplification", buffer);
    // Pow
    ConfigType::FloatToString (orxConfig_GetFloat ("Pow"), buffer);
    m_widgetManager->SetText ("FXSlotPow", buffer);
    // UseRotation
    /** @todo UseRotation */
    // UseScale
    /** @todo UseScale */
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

    // Update config
    if (orxString_Compare (widgetName, "FXSlotType") == 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotCurve") == 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotStartTime") == 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotEndTime") == 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotStartValue") > 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotEndValue") > 0) 
    {
	orxFLOAT newXFloat;
	orxFLOAT newYFloat;
	orxFLOAT newZFloat;
	orxString_ToFloat (GetText ("FXSlotEndValue0"), &newXFloat, orxNULL);
	orxString_ToFloat (GetText ("FXSlotEndValue1"), &newYFloat, orxNULL);
	orxString_ToFloat (GetText ("FXSlotEndValue2"), &newZFloat, orxNULL);
	orxVECTOR newPosition = { newXFloat, newYFloat, newZFloat };
	orxConfig_SetVector ("EndValue", &newPosition);
    }
    else if (orxString_Compare (widgetName, "FXSlotPhase") == 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotPeriod") == 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotAbsolute") == 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotAcceleration") == 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotAmplification") == 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotPow") == 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotUseRotation") == 0)
    {
    }
    else if (orxString_Compare (widgetName, "FXSlotUseScale") == 0)
    {
    }

    orxConfig_PopSection ();

    orxConfig_Save ("sampleconfig.ini", false, orxNULL);

    OrxCraft::GetInstance ().NeedObjectUpdate ();
}