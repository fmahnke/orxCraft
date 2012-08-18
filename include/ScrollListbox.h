#ifndef SCROLL_LISTBOX_H_
#define SCROLL_LISTBOX_H_
/**
 * @file ScrollListbox.h
 * @date 2012-05-10
 * @author fritz@fritzmahnke.com
 *
 */

#include <vector>
#include "ScrollWidget.h"

using std::vector;

/**
 *  Base class for a Listbox widget.
 */
class ScrollListbox : public ScrollWidget
{
public:
    explicit ScrollListbox (ScrollFrameWindow *dialog) :
	 ScrollWidget (dialog)
    {
    }

    virtual void Fill (const vector<const orxSTRING> &listItems) = 0;

protected:
    virtual ~ScrollListbox () { }
};

#endif  // SCROLL_LISTBOX_H_

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
