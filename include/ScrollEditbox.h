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
    explicit ScrollEditbox (ScrollFrameWindow *dialog) :
	ScrollWidget (dialog)
    {
    }

    virtual const orxSTRING GetText () = 0;
    virtual void SetText (const orxSTRING text) = 0;
};

#endif  // __SCROLL_EDITBOX_H__

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
