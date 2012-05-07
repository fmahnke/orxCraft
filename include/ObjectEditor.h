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

    void SetObject (ScrollObject *object);
    void Draw ();

private:
    CEGUI::Window *m_window;
    ScrollObject *m_object;
};

#endif  // __ObjectEditor_H__