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

#ifndef __FXSLOTEDITORWINDOW_H__
#define __FXSLOTEDITORWINDOW_H__
/**
 * @file FXSlotEditorWindow.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollFrameWindow.h"

class ScrollCombobox;
class ScrollEditbox;
class ScrollListbox;
class ScrollCheckbox;

class FXSlotEditorWindow : public ScrollFrameWindow
{
public:
    FXSlotEditorWindow ();

    virtual void Init (const orxSTRING widgetName);

    //! Initialize control items 
    void SetupFields  ();
    //! Update all fields on the window using current values from config 
    void UpdateFields () const;

    virtual const orxSTRING GetName ();
    //! Get the text of a widget
    const orxSTRING GetText (const orxSTRING widgetName) const;
    //! Set the FXSlot being edited
    void SetContext (const orxSTRING sectionName);

    virtual void OnMouseClick   (const orxSTRING widgetName);
    virtual void OnTextAccepted (const orxSTRING widgetName);

private:
    char m_context[255];

    ScrollCombobox *m_fxsType;
    ScrollCombobox *m_fxsCurve;
    ScrollEditbox *m_fxsStartTime;
    ScrollEditbox *m_fxsEndTime;
    ScrollEditbox *m_fxsStartValue0;
    ScrollEditbox *m_fxsStartValue1;
    ScrollEditbox *m_fxsStartValue2;
    ScrollEditbox *m_fxsEndValue0;
    ScrollEditbox *m_fxsEndValue1;
    ScrollEditbox *m_fxsEndValue2;
    ScrollEditbox *m_fxsPhase;
    ScrollEditbox *m_fxsPeriod;
    ScrollEditbox *m_fxsAcceleration;
    ScrollEditbox *m_fxsAmplification;
    ScrollEditbox *m_fxsPow;

    ScrollCheckbox *m_fxsAbsolute;
    ScrollCombobox *m_fxsUseRotation;
    ScrollCombobox *m_fxsUseScale;
    
    ScrollCombobox *m_fxsConfigName;

};

#endif  // __FXSLOTEDITORWINDOW_H__

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
