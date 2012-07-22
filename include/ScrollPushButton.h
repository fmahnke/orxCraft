#ifndef __SCROLL_PUSH_BUTTON_H__
#define __SCROLL_PUSH_BUTTON_H__
/**
 * @file ScrollPushButton.h
 * @date 2012-05-20
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollWidget.h"

class WidgetManager;

/**
 *  Base class for a Push Button widget.
 */
class ScrollPushButton : public ScrollWidget
{
public:
    explicit ScrollPushButton (WidgetManager *manager) :
	ScrollWidget (manager)
    {
    };
};

#endif  // __SCROLL_PUSH_BUTTON_H__