#ifndef __SCROLL_WINDOW_H__
#define __SCROLL_WINDOW_H__
/**
 * @file ScrollFrameWindow.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollWidget.h"

#include <vector>

using std::vector;

/**
 *  Base class for a Window widget.
 */
class ScrollFrameWindow : public ScrollWidget
{
public:
    ScrollFrameWindow () { };
    virtual void Init (const orxSTRING widgetName);
    virtual void HandleTextAccepted (const orxSTRING widgetName) = 0;
protected:
    vector<ScrollWidget *> m_widgetList;
};

#endif  // __SCROLL_WINDOW_H__