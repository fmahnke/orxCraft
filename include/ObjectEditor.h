/**
 * @file ObjectEditor.h
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#ifndef __OBJECTEDITOR_H__
#define __OBJECTEDITOR_H__

#include "ScrollFrameWindow.h"

class ScrollObject;

class ObjectEditor : public ScrollFrameWindow
{
public:
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

    virtual void HandleMouseClick   (const orxSTRING widgetName);
    virtual void HandleTextAccepted (const orxSTRING widgetName);

private:
    ScrollObject *m_object;
};

#endif  // __OBJECTEDITOR_H__