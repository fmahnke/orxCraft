#ifndef __SCROLLCOMBOBOX_H__
#define __SCROLLCOMBOBOX_H__
/**
 * @file ScrollCombobox.h
 * @date 2012-05-11
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollWidget.h"

/**
 *  Base class for a Combobox (drop down list) widget.
 */
class ScrollCombobox : public ScrollWidget
{
public:
    //! C-tor
    explicit ScrollCombobox (ScrollFrameWindow *dialog) :
	 ScrollWidget (dialog)
    {
    }

};

#endif  // __SCROLLCOMBOBOX_H__