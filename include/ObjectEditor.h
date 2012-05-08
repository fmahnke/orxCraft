/**
 * @file ObjectEditor.h
 * @date 2012-06-04
 * @author fritz@fritzmahnke.com
 *
 */
#ifndef __ObjectEditor_H__
#define __ObjectEditor_H__

#include "Scroll.h"

#include "CEGUI.h"

class ObjectEditor : public ScrollObject
{
public:
    ObjectEditor ();

    // Scroll events
    virtual void     OnCreate ();
    virtual void     OnDelete ();
    void             Update(const orxCLOCK_INFO &_rstInfo);

    // CEGUI events
    bool ObjectEditor::OnTextAccepted (const CEGUI::EventArgs &e);

    void ObjectEditor::UpdateObject ();

    const orxSTRING ObjectEditor::GetText (const orxSTRING widgetName) const;

    /// Update widget text explicitly
    void ObjectEditor::SetText (const orxSTRING widgetName,
	                        const orxSTRING text) const;

    /// Update widget text from an Orx config float
    void ObjectEditor::SetTextFromConfigFloat (const orxSTRING widgetName,
	                                       const orxSTRING prop) const;
    /// Update widget text from an Orx config string
    void ObjectEditor::SetTextFromConfigStringList (const orxSTRING widgetName,
						    const orxSTRING prop) const;
    /// Update widget text from an Orx config vector
    void ObjectEditor::SetTextFromConfigVector (const orxSTRING widgetName,
					        const orxSTRING prop,
						orxU32 elementNum) const;
    /// Set the ScrollObject used by this instance
    void SetObject (ScrollObject *object);

    /// Update all widgets to show current ScrollObject config values
    void UpdateFields () const;

private:
    CEGUI::Window *m_window;
    ScrollObject *m_object;
};

#endif  // __ObjectEditor_H__