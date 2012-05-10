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
    virtual void HandleTextAccepted (const orxSTRING widgetName);
    virtual const orxSTRING GetName ();
    void UpdateFields () const;
    const orxSTRING GetText (const orxSTRING widgetName) const;
    void SetContext (const orxSTRING sectionName);
private:
    char m_context[255];
    char m_windowName[255];
};

#endif  // __FXSLOTEDITORWINDOW_H__