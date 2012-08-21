/*
 *  Copyright (c) 2012 The orxCraft Project
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *     1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *  
 *     2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *  
 *     3. This notice may not be removed or altered from any source
 *     distribution.
 */

/**
 * @file ObjectEditor.h
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#ifndef OBJECTEDITOR_H_
#define OBJECTEDITOR_H_

#include "ScrollFrameWindow.h"

class ScrollObject;
class ScrollCombobox;
class ScrollEditbox;
class ScrollListbox;

class ObjectEditor : public ScrollFrameWindow
{
public:
    //! C-tor
    ObjectEditor ();

    virtual void Init (const orxSTRING widgetName);

    //! Initialize control items
    void SetupFields  ();
    //! Update all widgets to show current ScrollObject config values
    void UpdateFields () const;

    virtual const orxSTRING GetName ();
    
    const orxSTRING GetText (const orxSTRING widgetName) const;
    //! Set the ScrollObject being edited
    void SetObject (ScrollObject *object);

    virtual void OnMouseClick   (const orxSTRING widgetName);
    virtual void OnTextAccepted (const orxSTRING widgetName);

private:
    ScrollObject *m_object;

    ScrollCombobox *m_objConfigName;
    ScrollEditbox *m_objAlpha;
    ScrollEditbox *m_objAngVelocity;
    ScrollEditbox *m_objPosX;
    ScrollEditbox *m_objPosY;
    ScrollEditbox *m_objPosZ;
    ScrollEditbox *m_objFXList;
    ScrollListbox *m_objChildList;
    ScrollEditbox *m_objAnimFreq;
    ScrollEditbox *m_objAnimSet;
    ScrollCombobox *m_objAutoScroll;
    ScrollCombobox *m_objBlendMode;
    ScrollEditbox *m_objBody;
    ScrollListbox *m_objChildJointList;
    ScrollEditbox *m_objClock;
    ScrollCombobox *m_objDepthScale;
    ScrollCombobox *m_objGraphic;
    ScrollCombobox *m_objFlip;
    ScrollEditbox *m_objLifeTime;
    ScrollEditbox *m_objParentCam;
    ScrollEditbox *m_objRepeatX;
    ScrollEditbox *m_objRepeatY;
    ScrollEditbox *m_objRepeatZ;
    ScrollEditbox *m_objRotation;
    ScrollEditbox *m_objScaleX;
    ScrollEditbox *m_objScaleY;
    ScrollEditbox *m_objScaleZ;
    ScrollEditbox *m_objSpeedX;
    ScrollEditbox *m_objSpeedY;
    ScrollEditbox *m_objSpeedZ;
    ScrollCombobox *m_objSmoothing;
    ScrollEditbox *m_objShaderList;
    ScrollEditbox *m_objSoundList;
    ScrollEditbox *m_objSpawner;
    ScrollCombobox *m_objUseParentSpace;
    ScrollCombobox *m_objUseRelativeSpeed;
    ScrollEditbox *m_objColorR;
    ScrollEditbox *m_objColorG;
    ScrollEditbox *m_objColorB;
};

#endif  // OBJECTEDITOR_H_

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
