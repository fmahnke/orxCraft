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
    explicit ScrollCheckbox (ScrollFrameWindow *manager) :
	m_manager (manager)
    {
    }; 
protected:
    virtual void SignalCheckStateChanged () = 0;
    ScrollFrameWindow *m_manager;
};

#endif  // __SCROLL_CHECKBOX_H__

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
