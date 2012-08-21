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

#ifndef __SCROLL_WIDGET_H__
#define __SCROLL_WIDGET_H__
/**
 * @file ScrollWidget.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "Scroll.h"

class ScrollFrameWindow;

/**
 *  Base class for any type of user interface widget
 */
class ScrollWidget
{
public:    
    /** Let's make ScrollCheckbox happy for now (Conrad) */
    ScrollWidget () :
	m_widgetName (NULL),
	m_manager    (NULL)
    {
    };
    /** Widget C-tor */
    explicit ScrollWidget (ScrollFrameWindow *dialog) :
	m_widgetName (NULL),
	m_manager    (dialog)
    {
    }

    /** Initialize the widget */
    virtual void Init (const orxSTRING widgetName) = 0;

    /** Get the name of the widget */
    inline const orxSTRING GetName () { return m_widgetName; }

    /** Widget D-tor */
    virtual ~ScrollWidget ()
    {
	delete [] m_widgetName;
    }

protected:
    char              *m_widgetName;
    ScrollFrameWindow *m_manager;
};

#endif  // __SCROLLWIDGET_H__

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
