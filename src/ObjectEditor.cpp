/**
 * @file ObjectEditor.cpp
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#include "ObjectEditor.h"
#include "OrxCraft.h"
#include "orx_config_util.h"

#include "ScrollFrameWindow.h"

// Temporary, until factory is built
#include "CEGUI.h"

#include "CEGUICombobox.h"
#include "CEGUIEditbox.h"
#include "CEGUIListbox.h"
#include "CEGUIPushButton.h"

using CEGUI::Combobox;
using CEGUI::Listbox;
using CEGUI::Window;

ObjectEditor::ObjectEditor () :
    m_object (NULL),
    m_objConfigName (NULL),
    m_objAlpha (NULL),
    m_objAngVelocity (NULL),
    m_objPosX (NULL),
    m_objPosY (NULL),
    m_objPosZ (NULL),
    m_objFXList (NULL),
    m_objChildList (NULL),
    m_objAnimFreq (NULL),
    m_objAnimSet (NULL),
    m_objAutoScroll (NULL),
    m_objBlendMode (NULL),
    m_objBody (NULL),
    m_objChildJointList (NULL),
    m_objClock (NULL),
    m_objDepthScale (NULL),
    m_objGraphic (NULL),
    m_objFlip (NULL),
    m_objLifeTime (NULL),
    m_objParentCam (NULL),
    m_objRepeatX (NULL),
    m_objRepeatY (NULL),
    m_objRepeatZ (NULL),
    m_objRotation (NULL),
    m_objScaleX (NULL),
    m_objScaleY (NULL),
    m_objScaleZ (NULL),
    m_objSpeedX (NULL),
    m_objSpeedY (NULL),
    m_objSpeedZ (NULL),
    m_objSmoothing (NULL),
    m_objShaderList (NULL),
    m_objSoundList (NULL),
    m_objSpawner (NULL),
    m_objUseParentSpace (NULL),
    m_objUseRelativeSpeed (NULL),
    m_objColorR (NULL),
    m_objColorG (NULL),
    m_objColorB (NULL)
{
}

void ObjectEditor::Init (const orxSTRING widgetName)
{
    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *window = rootWindow->getChild (widgetName);
    
    int counter = window->getChildCount ();
    for (int i = 0; i < counter; i++)
    {
	const orxSTRING type = window->getChildAtIdx (i)->getType ().c_str ();
	const orxSTRING name = window->getChildAtIdx (i)->getName ().c_str ();
	if (orxString_Compare (type, "TaharezLook/Checkbox") == 0)
	{
	    orxASSERT (false);
	    /*
	    CEGUICheckbox *checkbox = new CEGUICheckbox (this);
	    checkbox->Init (name);
	    m_widgetList.push_back (checkbox);
	    */
	}
	else if (orxString_Compare (type, "TaharezLook/Combobox") == 0)
	{
	    CEGUICombobox *combobox = new CEGUICombobox (this);
	    combobox->Init (name);
	    m_widgetList.push_back (combobox);
	}
	else if (orxString_Compare (type, "TaharezLook/Editbox") == 0)
	{
	    CEGUIEditbox *editbox = new CEGUIEditbox (this);
	    editbox->Init (name);
	    m_widgetList.push_back (editbox);
	}
	else if (orxString_Compare (type, "TaharezLook/Listbox") == 0)
	{
	    CEGUIListbox *listbox = new CEGUIListbox (this);
	    listbox->Init (name);
	    m_widgetList.push_back (listbox);
	}
	else if (orxString_Compare (type, "TaharezLook/Button") == 0)
	{
	    CEGUIPushButton *pushbutton = new CEGUIPushButton (this);
	    pushbutton->Init (name);
	    m_widgetList.push_back (pushbutton);
	}
    }
    m_objConfigName = FindEditbox ("ObjectConfigName");
    m_objAlpha = FindEditbox ("ObjAlpha");
    m_objAngVelocity = FindEditbox ("ObjAngularVelocity");
    m_objPosX = FindEditbox ("ObjPos0");
    m_objPosY = FindEditbox ("ObjPos1");
    m_objPosZ = FindEditbox ("ObjPos2");
    m_objFXList = FindEditbox ("ObjFXList");
    m_objChildList = FindListbox ("ChildList");
    m_objAnimFreq = FindEditbox ("ObjAnimFreq");
    m_objAnimSet = FindEditbox ("ObjAnimSet");
    m_objAutoScroll = FindCombobox ("ObjAutoScroll");
    m_objBlendMode = FindCombobox ("ObjBlendMode");
    m_objBody = FindEditbox ("ObjBody");
    m_objChildJointList = FindListbox ("ObjChildJointList");
    m_objClock = FindEditbox ("ObjClock");
    m_objDepthScale = FindCombobox ("ObjDepthScale");
    m_objGraphic = FindCombobox ("ObjGraphic");
    m_objFlip = FindCombobox ("ObjFlip");
    m_objLifeTime = FindEditbox ("ObjLifeTime");
    m_objParentCam = FindEditbox ("ObjParentCam");
    m_objRepeatX = FindEditbox ("ObjRepeat0");
    m_objRepeatY = FindEditbox ("ObjRepeat1");
    m_objRepeatZ = FindEditbox ("ObjRepeat2");
    m_objRotation = FindEditbox ("ObjRotation");
    m_objScaleX = FindEditbox ("ObjScale0");
    m_objScaleY = FindEditbox ("ObjScale1");
    m_objScaleZ = FindEditbox ("ObjScale2");
    m_objSpeedX = FindEditbox ("ObjSpeedX");
    m_objSpeedY = FindEditbox ("ObjSpeedY");
    m_objSpeedZ = FindEditbox ("ObjSpeedZ");
    m_objSmoothing = FindCombobox ("ObjSmoothing");
    m_objShaderList = FindEditbox ("ObjShaderList");
    m_objSoundList = FindEditbox ("ObjSoundList");
    m_objSpawner = FindEditbox ("ObjSpawner");
    m_objUseParentSpace = FindCombobox ("ObjUseParentSpace"); 
    m_objUseRelativeSpeed = FindCombobox ("ObjUseRelativeSpeed");
    m_objColorR = FindEditbox ("ObjColor0");
    m_objColorG = FindEditbox ("ObjColor1");
    m_objColorB = FindEditbox ("ObjColor2");

    SetupFields ();
}

void ObjectEditor::SetupFields ()
{
    vector<const orxSTRING> propList =
	OrxCraft::GetInstance ().GetGraphicList ();

    //m_widgetManager->FillList ("ObjGraphic", propList);

    orxConfig_PushSection ("ObjectEditor");

    // Fill combo boxes
    propList.clear ();
    orx_config_util::GetListIntoVector ("AutoScroll", propList);
    //m_widgetManager->FillList ("ObjAutoScroll", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("BlendMode", propList);
    //m_widgetManager->FillList ("ObjBlendMode", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("DepthScale", propList);
    //m_widgetManager->FillList ("ObjDepthScale", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("Flip", propList);
    //m_widgetManager->FillList ("ObjFlip", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("Smoothing", propList);
    //m_widgetManager->FillList ("ObjSmoothing", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("UseParentSpace", propList);
    //m_widgetManager->FillList ("ObjUseParentSpace", propList);

    propList.clear ();
    orx_config_util::GetListIntoVector ("UseRelativeSpeed", propList);
    //m_widgetManager->FillList ("ObjUseRelativeSpeed", propList);

    orxConfig_PopSection ();
}

const orxSTRING ObjectEditor::GetName ()
{
    return "ObjectEditor";
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
	m_objConfigName->SetText (name);

	orxConfig_PushSection (name);

	// Alpha
	orx_config_util::FloatToString (orxConfig_GetFloat ("Alpha"), buffer);
	m_objAlpha->SetText (buffer);
	// AngularVelocity
	orx_config_util::FloatToString (orxConfig_GetFloat ("AngularVelocity"), buffer);
	m_objAngVelocity->SetText (buffer);
	// AnimationFrequency
	orx_config_util::FloatToString (orxConfig_GetFloat ("AnimationFrequency"), buffer);
	m_objAnimFreq->SetText (buffer);
	// AnimationSet
	const orxSTRING aS = orx_config_util::ListToString ("AnimationSet");
	m_objAnimSet->SetText (aS);
	// AutoScroll
	const orxSTRING aSc = orx_config_util::ListToString ("AutoScroll");
	orxASSERT (false);
	// BlendMode
	const orxSTRING bl = orx_config_util::ListToString ("BlendMode");
	orxASSERT (false);
	// Body
	const orxSTRING body = orx_config_util::ListToString ("Body");
	m_objBody->SetText (body);
	// ChildList
	/** @todo ChildList */
	// ChildJointList
	/** @todo ChildJointList */
	// Clock
	const orxSTRING clock = orx_config_util::ListToString ("Clock");
	m_objClock->SetText (clock);
	// Color
	orx_config_util::VectorToString ("Color", 0, buffer);
	m_objColorR->SetText (buffer);
	orx_config_util::VectorToString ("Color", 1, buffer);
	m_objColorG->SetText (buffer);
	orx_config_util::VectorToString ("Color", 2, buffer);
	m_objColorB->SetText (buffer);
	// DepthScale
	orx_config_util::BoolToString (orxConfig_GetBool ("DepthScale"), buffer);
	orxASSERT (false);
	// Graphic
	const orxSTRING graphic = orx_config_util::ListToString ("Graphic");
	orxASSERT (false);
	// Flip
	const orxSTRING flip = orx_config_util::ListToString ("Flip");
	orxASSERT (false);
	// FXList
	const orxSTRING fxList = orx_config_util::ListToString ("FXList");
	m_objFXList->SetText (fxList);
	// LifeTime
	orx_config_util::FloatToString (orxConfig_GetFloat ("LifeTime"), buffer);
	m_objLifeTime->SetText (buffer);
	// ParentCamera
	const orxSTRING parentCam = orx_config_util::ListToString ("ParentCamera");
	m_objParentCam->SetText (parentCam);
	// Position
	orx_config_util::VectorToString ("Position", 0, buffer);
	m_objPosX->SetText (buffer);
	orx_config_util::VectorToString ("Position", 1, buffer);
	m_objPosY->SetText (buffer);
	orx_config_util::VectorToString ("Position", 2, buffer);
	m_objPosZ->SetText (buffer);
	// Repeat
	orx_config_util::VectorToString ("Repeat", 0, buffer);
	m_objRepeatX->SetText (buffer);
	orx_config_util::VectorToString ("Repeat", 1, buffer);
	m_objRepeatY->SetText (buffer);
	orx_config_util::VectorToString ("Repeat", 2, buffer);
	m_objRepeatZ->SetText (buffer);
	// Rotation
	orx_config_util::FloatToString (orxConfig_GetFloat ("Rotation"), buffer);
	m_objRotation->SetText (buffer);
	// Speed
	orx_config_util::VectorToString ("Speed", 0, buffer);
	m_objSpeedX->SetText (buffer);
	orx_config_util::VectorToString ("Speed", 1, buffer);
	m_objSpeedY->SetText (buffer);
	orx_config_util::VectorToString ("Speed", 2, buffer);
	m_objSpeedZ->SetText (buffer);
	// Scale
	orx_config_util::VectorToString ("Scale", 0, buffer);
	m_objScaleX->SetText (buffer);
	orx_config_util::VectorToString ("Scale", 1, buffer);
	m_objScaleY->SetText (buffer);
	orx_config_util::VectorToString ("Scale", 2, buffer);
	m_objScaleZ->SetText (buffer);
	// ShaderList
	//! @todo ShaderList
	// SoundList
	//! @todo SoundList
	// Spawner
	const orxSTRING spawner = orx_config_util::ListToString ("Spawner");
	m_objSpawner->SetText (spawner);
	// Smoothing
	orx_config_util::BoolToString (orxConfig_GetBool ("Smoothing"), buffer);
	orxASSERT (false);
	// UseParentSpace
	orx_config_util::BoolToString (orxConfig_GetBool ("UseParentSpace"),
				       buffer);
	orxASSERT (false);
	// UseRelativeSpeed
	orx_config_util::BoolToString (orxConfig_GetBool ("UseRelativeSpeed"),
				       buffer);
	orxASSERT (false);

	orxConfig_PopSection ();
    }
}

void ObjectEditor::OnMouseClick (const orxSTRING widgetName)
{
    orxASSERT (false);
}

void ObjectEditor::OnTextAccepted (const orxSTRING widgetName)
{
    orxASSERT (widgetName != orxNULL);
    orxASSERT (m_object != orxNULL);

    // Push config section of edited object
    orxConfig_PushSection (m_object->GetModelName ());

    // Update config
    if (orxString_Compare (widgetName, "ObjAlpha") == 0)
    {
	const orxSTRING alpha = m_objAlpha->GetText ();
	orxConfig_SetString ("Alpha", alpha);
    }
    else if (orxString_Compare (widgetName, "ObjAngularVelocity") == 0)
    {
	const orxSTRING angularVelocity = m_objAngVelocity->GetText ();
	orxConfig_SetString ("AngularVelocity", angularVelocity);
    }
    else if (orxString_Compare (widgetName, "ObjAnimFreq") == 0)
    {
	orxFLOAT animFreq;
	orxString_ToFloat (m_objAnimFreq->GetText (), &animFreq, orxNULL);
	orxConfig_SetFloat ("AnimationFrequency", animFreq);
    }
    else if (orxString_Compare (widgetName, "ObjAnimSet") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjAutoScroll") == 0)
    {
	orxASSERT (false);
	//const orxSTRING autoScroll = GetText ("ObjAutoScroll");
	//orxConfig_SetString ("AutoScroll", autoScroll);
    }
    else if (orxString_Compare (widgetName, "ObjBlendMode") == 0)
    {
	orxASSERT (false);
	//const orxSTRING blendMode = GetText ("ObjBlendMode");
	//orxConfig_SetString ("BlendMode", blendMode);
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
	orxString_ToFloat (m_objColorR->GetText (), &newRFloat, orxNULL);
	orxString_ToFloat (m_objColorG->GetText (), &newGFloat, orxNULL);
	orxString_ToFloat (m_objColorB->GetText (), &newBFloat, orxNULL);
	orxVECTOR newColor = { newRFloat, newGFloat, newBFloat };
	orxConfig_SetVector ("Color", &newColor);
    }
    else if (orxString_Compare (widgetName, "ObjDepthScale") == 0)
    {
	orxASSERT (false);
	//const orxSTRING depthScaleStr = GetText ("ObjDepthScale");
	//orxBOOL depthScaleBool;
	//orxString_ToBool (depthScaleStr, &depthScaleBool, orxNULL);
	//orxConfig_SetBool ("DepthScale", depthScaleBool);
    }
    else if (orxString_Compare (widgetName, "ObjGraphic") == 0)
    {
	orxASSERT (false);
	//const orxSTRING graphic = GetText ("ObjGraphic");
	//orxConfig_SetString ("Graphic", graphic);
    }
    else if (orxString_Compare (widgetName, "ObjFlip") == 0)
    {
	orxASSERT (false);
	//const orxSTRING flip = GetText ("ObjFlip");
	//orxConfig_SetString ("Flip", flip);
    }
    else if (orxString_Compare (widgetName, "ObjFXList") == 0)
    {
	orxASSERT (false);
    }
    else if (orxString_Compare (widgetName, "ObjLifeTime") == 0)
    {
	orxFLOAT lifeTime;
	orxString_ToFloat (m_objLifeTime->GetText (), &lifeTime, orxNULL);
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
	orxString_ToFloat (m_objPosX->GetText (), &newXFloat, orxNULL);
	orxString_ToFloat (m_objPosY->GetText (), &newYFloat, orxNULL);
	orxString_ToFloat (m_objPosZ->GetText (), &newZFloat, orxNULL);
	orxVECTOR newPosition = { newXFloat, newYFloat, newZFloat };
	orxConfig_SetVector ("Position", &newPosition);
    }
    else if (orxString_SearchString (widgetName, "ObjRepeat") > 0)
    {
	orxFLOAT XFloat;
	orxFLOAT YFloat;
	orxFLOAT ZFloat;
	orxString_ToFloat (m_objRepeatX->GetText (), &XFloat, orxNULL);
	orxString_ToFloat (m_objRepeatY->GetText (), &YFloat, orxNULL);
	orxString_ToFloat (m_objRepeatZ->GetText (), &ZFloat, orxNULL);
	orxVECTOR repeat = { XFloat, YFloat, ZFloat };
	orxConfig_SetVector ("Repeat", &repeat);
    }
    else if (orxString_Compare (widgetName, "ObjRotation") == 0)
    {
	const orxSTRING rotation = m_objRotation->GetText ();
	orxConfig_SetString ("Rotation", rotation);
    }
    else if (orxString_SearchString (widgetName, "ObjSpeed") > 0)
    {
	orxFLOAT newXFloat;
	orxFLOAT newYFloat;
	orxFLOAT newZFloat;
	orxString_ToFloat (m_objSpeedX->GetText (), &newXFloat, orxNULL);
	orxString_ToFloat (m_objSpeedY->GetText (), &newYFloat, orxNULL);
	orxString_ToFloat (m_objSpeedZ->GetText (), &newZFloat, orxNULL);
	orxVECTOR newSpeed = { newXFloat, newYFloat, newZFloat };
	orxConfig_SetVector ("Speed", &newSpeed);
    }
    else if (orxString_SearchString (widgetName, "ObjScale") > 0)
    {
	orxFLOAT XFloat;
	orxFLOAT YFloat;
	orxFLOAT ZFloat;
	orxString_ToFloat (m_objScaleX->GetText (), &XFloat, orxNULL);
	orxString_ToFloat (m_objScaleY->GetText (), &YFloat, orxNULL);
	orxString_ToFloat (m_objScaleZ->GetText (), &ZFloat, orxNULL);
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