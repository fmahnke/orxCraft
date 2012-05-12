#ifndef __FXSLOTEDITORWINDOW_H__
#define __FXSLOTEDITORWINDOW_H__
/**
 * @file FXSlotEditorWindow.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollFrameWindow.h"

class FXSlotEditorWindow : public ScrollFrameWindow
{
public:
    /** Initialize window */
    virtual void Init (const orxSTRING widgetName);

    /** Initialize control items */
    void SetupFields  ();
    /** Update all fields on the window using current values from config */
    void UpdateFields () const;

    /** Get the window's name */
    virtual const orxSTRING GetName ();
    /** Get the text of a widget */
    const orxSTRING GetText (const orxSTRING widgetName) const;
    /** Set the FXSlot in use by this window */
    void SetContext (const orxSTRING sectionName);

    /** Left mouse click event handler */
    virtual void HandleMouseClick   (const orxSTRING widgetName);
    /** Text accepted (pressed Enter key) event handler */
    virtual void HandleTextAccepted (const orxSTRING widgetName);

private:
    char m_context[255];
    char m_windowName[255];

};

#endif  // __FXSLOTEDITORWINDOW_H__