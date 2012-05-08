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
    void ObjectEditor::SetText (const orxSTRING widgetName,
	                        const orxSTRING text);

    void ObjectEditor::SetTextFromConfigFloat (const orxSTRING widgetName,
	                                       const orxSTRING prop);
    void ObjectEditor::SetTextFromConfigStringList (const orxSTRING widgetName,
						    const orxSTRING prop);
    void ObjectEditor::SetTextFromConfigVector (const orxSTRING widgetName,
					        const orxSTRING prop,
						orxU32 elementNum);
    void SetObject (ScrollObject *object);
    void UpdateFields ();

private:
    CEGUI::Window *m_window;
    ScrollObject *m_object;
};

#endif  // __ObjectEditor_H__