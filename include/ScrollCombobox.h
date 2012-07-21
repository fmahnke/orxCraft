#ifndef SCROLLCOMBOBOX_H_
#define SCROLLCOMBOBOX_H_
/**
 * @file ScrollCombobox.h
 * @date 2012-05-11
 * @author fritz@fritzmahnke.com
 *
 */

#include <vector>
#include "ScrollWidget.h"

using std::vector;

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

    virtual void SelectItem (const orxSTRING itemText) = 0;

    /** Fill the box with a list */
    virtual void Fill (const vector<const orxSTRING> &listItems) = 0;
};

#endif  // SCROLLCOMBOBOX_H_