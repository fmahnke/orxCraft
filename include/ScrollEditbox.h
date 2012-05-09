#ifndef __SCROLL_EDITBOX_H__
#define __SCROLL_EDITBOX_H__
/**
 * @file ScrollEditbox.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollWidget.h"

class ScrollFrameWindow;

/**
 *  Base class for an Editbox widget.
 */
class ScrollEditbox : public ScrollWidget
{
public:
    explicit ScrollEditbox (ScrollFrameWindow *manager) :
	m_manager (manager)
    {
    };
protected:
    ScrollFrameWindow *m_manager;
};

#endif  // __SCROLL_EDITBOX_H__