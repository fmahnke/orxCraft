#ifndef __SCROLL_LISTBOX_H__
#define __SCROLL_LISTBOX_H__
/**
 * @file ScrollListbox.h
 * @date 2012-05-10
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollWidget.h"

/**
 *  Base class for a Listbox widget.
 */
class ScrollListbox : public ScrollWidget
{
public:
    explicit ScrollListbox (WidgetManager *manager) :
	 ScrollWidget (manager)
    {
    };
};

#endif  // __SCROLL_LISTBOX_H__