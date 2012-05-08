/**
 * @file CEGUICheckbox.h
 * @date 2012-05-07
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollCheckbox.h"

#include "CEGUI.h"

class ObjectEditor;

class CEGUICheckbox : public ScrollCheckbox
{
public:
    explicit CEGUICheckbox (ObjectEditor *manager);
    virtual void Init (const orxSTRING widgetName);
private:
    virtual void SignalCheckStateChanged ();
    bool OnCheckStateChanged (const CEGUI::EventArgs &e);

};