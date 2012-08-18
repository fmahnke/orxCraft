#ifndef __SCROLL_CEGUICHECKBOX_H__
#define __SCROLL_CEGUICHECKBOX_H__
/**
 * @file CEGUICheckbox.h
 * @date 2012-05-07
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollCheckbox.h"

#include "CEGUI.h"

class ScrollFrameWindow;

//! CEGUI implementation of a Checkbox
class CEGUICheckbox : public ScrollCheckbox
{
public:
    explicit CEGUICheckbox (ScrollFrameWindow *manager);
    virtual void Init (const orxSTRING widgetName);
private:
    virtual void SignalCheckStateChanged ();
    bool OnCheckStateChanged (const CEGUI::EventArgs &e);

};
#endif  //  __SCROLL_CEGUICHECKBOX_H__

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
