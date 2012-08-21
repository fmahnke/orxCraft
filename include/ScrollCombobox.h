/*
 *  Copyright (c) 2012 The orxCraft Project
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *     1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *  
 *     2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *  
 *     3. This notice may not be removed or altered from any source
 *     distribution.
 */

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
    //! Get the text of the selected item
    virtual const orxSTRING GetSelectedItem () const = 0;

    /** Fill the box with a list */
    virtual void Fill (const vector<const orxSTRING> &listItems) = 0;
};

#endif  // SCROLLCOMBOBOX_H_

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
