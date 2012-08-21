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

#ifndef __SCROLLFRAMEWINDOW_H__
#define __SCROLLFRAMEWINDOW_H__
/**
 * @file ScrollFrameWindow.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */
#include <vector>
using std::vector;

#include "Scroll.h"
#include "ScrollWidget.h"

class ScrollEditbox;
class ScrollCombobox;
class ScrollListbox;

/**
 *  Interface for a Window.
 */
class ScrollFrameWindow
{
public:
    //! C-tor
    ScrollFrameWindow ();
    
    /** Find a widget by its name */
    ScrollWidget * FindWidget (const orxSTRING widgetName) const;
    ScrollEditbox * FindEditbox (const orxSTRING widgetName) const;
    ScrollCombobox * FindCombobox (const orxSTRING widgetName) const;
    ScrollListbox * FindListbox (const orxSTRING widgetName) const;

    /** Initialize the window */
    virtual void Init (const orxSTRING widgetName) = 0;
    /** Get the window's name */
    virtual const orxSTRING GetName () = 0;
    /** Left mouse click event handler */
    virtual void OnMouseClick   (const orxSTRING widgetName) = 0;
    /** Text accepted (pressed Enter key) event handler */
    virtual void OnTextAccepted (const orxSTRING widgetName) = 0;

    virtual void AddWidget (ScrollWidget *widget);

protected:
    //! D-tor
    virtual ~ScrollFrameWindow ()
    {
	vector<ScrollWidget *>::iterator iter;
	for (iter = m_widgetList.begin ();
	    iter != m_widgetList.end ();
	    ++iter)
	{
	    delete *iter;
	}
    };

    vector<ScrollWidget *> m_widgetList;
};

#endif  // __SCROLLFRAMEWINDOW_H__

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
