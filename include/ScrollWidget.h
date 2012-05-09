#ifndef __SCROLL_WIDGET_H__
#define __SCROLL_WIDGET_H__
/**
 * @file ScrollWidget.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "orx/orx.h"

/**
 *  Interface for a widget.
 */
class ScrollWidget
{
public:
    virtual void Init (const orxSTRING widgetName) = 0;
protected:
    virtual ~ScrollWidget () { };
};

#endif  // __SCROLL_CHECKBOX_H__