/**
 * @file CEGUIEditbox.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollEditbox.h"

#include "CEGUI.h"

class ObjectEditor;

class CEGUIEditbox : public ScrollEditbox
{
public:
    explicit CEGUIEditbox (ObjectEditor *manager);
    virtual void Init (const orxSTRING widgetName);
private:
    bool OnTextAccepted (const CEGUI::EventArgs &e);

    CEGUI::Editbox *m_ceEditbox;
};