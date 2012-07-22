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

    virtual void HandleMouseClick   (const orxSTRING widgetName);
    virtual void HandleTextAccepted (const orxSTRING widgetName);

private:
    char m_context[255];
    char m_windowName[255];
};

#endif  // __FXSLOTEDITORWINDOW_H__