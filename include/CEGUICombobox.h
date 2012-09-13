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

#ifndef __CEGUICOMBOBOX_H__
#define __CEGUICOMBOBOX_H__
/**
 * @file CEGUICombobox.h
 * @date 2012-05-11
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollCombobox.h"
#include "CEGUI.h"

class ScrollFrameWindow;

using std::vector;

/** CEGUI implementation of a Combobox */
class CEGUICombobox : public ScrollCombobox
{
public:
    /** C-tor */
    explicit CEGUICombobox (ScrollFrameWindow *dialog);
    /** Initialize the Combobox */
    virtual void Init (const orxSTRING widgetName);
    virtual void Init (CEGUI::Window* widget);
    /** Fill the box with a list */
    virtual void Fill (const vector<const orxSTRING> &listItems);

    virtual void SelectItem (const orxSTRING text);
    virtual const orxSTRING GetSelectedItem () const;

private:
    bool OnSelectionAccepted (const CEGUI::EventArgs &e);

    CEGUI::Combobox *m_ceCombobox;
    vector<CEGUI::ListboxTextItem *> m_items;
};
#endif  // __CEGUICOMBOBOX_H__

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
