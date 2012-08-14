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
