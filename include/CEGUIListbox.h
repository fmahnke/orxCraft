#ifndef __SCROLL_CEGUILISTBOX_H__
#define __SCROLL_CEGUILISTBOX_H__
/**
 * @file CEGUIListbox.h
 * @date 2012-05-10
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollListbox.h"

#include "CEGUI.h"

class WidgetManager;

class CEGUIListbox : public ScrollListbox
{
public:
    explicit CEGUIListbox (WidgetManager *manager);
    virtual void Init (const orxSTRING widgetName);

private:
    bool OnMouseClick (const CEGUI::EventArgs &e);
};
#endif  // __SCROLL_CEGUILISTBOX_H__