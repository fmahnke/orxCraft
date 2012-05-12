/**
 * @file ObjectEditor.h
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#ifndef __ObjectEditor_H__
#define __ObjectEditor_H__

#include "ScrollFrameWindow.h"

class ScrollObject;

class ObjectEditor : public ScrollFrameWindow
{
public:
    ObjectEditor ();

    // Scroll events
    virtual void Init (const orxSTRING widgetName);

    virtual const orxSTRING GetName ();

    void UpdateObject ();
    const orxSTRING GetText (const orxSTRING widgetName) const;

    /// Update widget text explicitly
    void SetText (const orxSTRING widgetName,
	                        const orxSTRING text) const;

    /// Set the ScrollObject used by this instance
    void SetObject (ScrollObject *object);

    /// Update all widgets to show current ScrollObject config values
    void UpdateFields () const;

    virtual void HandleMouseClick   (const orxSTRING widgetName);
    virtual void HandleTextAccepted (const orxSTRING widgetName);

private:
    ScrollObject *m_object;
};

#endif  // __ObjectEditor_H__