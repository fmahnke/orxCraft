#ifndef __CEGUIPUSHBUTTON_H__
#define __CEGUIPUSHBUTTON_H__
/**
 * @file CEGUIPushButton.h
 * @date 2012-05-20
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollPushButton.h"

#include "CEGUI.h"

class ScrollFrameWindow;

/** CEGUI Implementation of a Push Button */
class CEGUIPushButton : public ScrollPushButton
{
public:
    explicit CEGUIPushButton (ScrollFrameWindow *dialog);
    virtual void Init (const orxSTRING widgetName);
    virtual void Init (CEGUI::Window* widget);

    virtual void SetText (const orxSTRING text);

private:
    bool OnClicked (const CEGUI::EventArgs &e);

    CEGUI::PushButton *m_cePushButton;
};
#endif  // __CEGUIBUTTON_H__

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
