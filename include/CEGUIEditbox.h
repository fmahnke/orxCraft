#ifndef __SCROLL_CEGUIEDITBOX_H__
#define __SCROLL_CEGUIEDITBOX_H__
/**
 * @file CEGUIEditbox.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollEditbox.h"

#include "CEGUI.h"

class ScrollFrameWindow;

/** CEGUI Implementation of an Editbox */
class CEGUIEditbox : public ScrollEditbox
{
public:
    explicit CEGUIEditbox (ScrollFrameWindow *dialog);
    virtual void Init (const orxSTRING widgetName);

    virtual const orxSTRING GetText ();
    virtual void SetText (const orxSTRING text);
private:
    bool OnTextAccepted (const CEGUI::EventArgs &e);

    CEGUI::Editbox *m_ceEditbox;
};
#endif  // __SCROLL_CEGUIEDITBOX_H__

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
