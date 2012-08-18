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

    ScrollCombobox *m_fxsAbsolute;
    ScrollCombobox *m_fxsUseRotation;
    ScrollCombobox *m_fxsUseScale;
    
    ScrollCombobox *m_fxsConfigName;

};

#endif  // __FXSLOTEDITORWINDOW_H__

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
