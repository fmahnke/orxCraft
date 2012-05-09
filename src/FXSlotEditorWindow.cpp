/**
 * @file FXSlotEditorWindow.cpp
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "FXSlotEditorWindow.h"

#include "CEGUI.h"

#include "CEGUICheckbox.h"
#include "CEGUIEditbox.h"

#include "WidgetManager.h"

using CEGUI::Window;
using CEGUI::Checkbox;
using CEGUI::Editbox;

void FXSlotEditorWindow::Init (const orxSTRING widgetName)
{
    strcpy (m_windowName, widgetName);
    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *window = rootWindow->getChild (widgetName);
    
    int counter = window->getChildCount ();
    for (int i = 0; i < counter; i++)
    {
	const orxSTRING type = window->getChildAtIdx (i)->getType ().c_str ();
	const orxSTRING name = window->getChildAtIdx (i)->getName ().c_str ();
	if (orxString_Compare (type, "TaharezLook/Checkbox") == 0)
	{
	    CEGUICheckbox *checkbox = new CEGUICheckbox (this);
	    checkbox->Init (name);
	    m_widgetList.push_back (checkbox);
	}
	else if (orxString_Compare (type, "TaharezLook/Editbox") == 0)
	{
	    CEGUIEditbox *editbox = new CEGUIEditbox (this);
	    editbox->Init (name);
	    m_widgetList.push_back (editbox);
	}
    }
}

void FXSlotEditorWindow::HandleTextAccepted (const orxSTRING widgetName)
{
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
    WidgetManager::SetText (m_windowName, "FXSlotConfigName", m_windowName);

    orxConfig_PushSection (m_windowName);

    // StartTime
    const orxSTRING startTime = orxConfig_GetString ("StartTime");
    WidgetManager::SetText (m_windowName, "FXSlotStartTime", startTime);
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

void FXSlotEditorWindow::SetContext (const orxSTRING sectionName)
{
    strcpy (m_context, sectionName);
    UpdateFields ();
}

