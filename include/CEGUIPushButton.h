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

class WidgetManager;

/** CEGUI Implementation of a Push Button */
class CEGUIPushButton : public ScrollPushButton
{
public:
    explicit CEGUIPushButton (WidgetManager *manager);
    virtual void Init (const orxSTRING widgetName);

private:
    bool OnClicked (const CEGUI::EventArgs &e);
};
#endif  // __CEGUIBUTTON_H__