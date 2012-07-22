#ifndef SCROLL_LISTBOX_H_
#define SCROLL_LISTBOX_H_
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

protected:
    virtual ~ScrollListbox () { }
};

#endif  // SCROLL_LISTBOX_H_
