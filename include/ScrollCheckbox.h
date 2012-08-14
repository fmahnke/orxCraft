#ifndef __SCROLL_CHECKBOX_H__
#define __SCROLL_CHECKBOX_H__
/**
 * @file ScrollCheckbox.h
 * @date 2012-05-07
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollWidget.h"

class ScrollFrameWindow;

/**
 *  Interface for a Checkbox widget.
 */
class ScrollCheckbox : public ScrollWidget
{
public:
    explicit ScrollCheckbox (ScrollFrameWindow *dialog) :
	ScrollWidget (dialog)
    {
    }; 

    virtual void SetSelected (const orxBOOL select) = 0;
    virtual const orxBOOL IsSelected () const = 0;

};

#endif  // __SCROLL_CHECKBOX_H__
