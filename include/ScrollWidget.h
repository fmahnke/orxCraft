#ifndef __SCROLL_WIDGET_H__
#define __SCROLL_WIDGET_H__
/**
 * @file ScrollWidget.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "orx/orx.h"

class WidgetManager;

/**
 *  Interface for a widget.
 */
class ScrollWidget
{
public:    
    /** Widget C-tor */
    ScrollWidget (WidgetManager *manager) :
	m_widgetName (NULL),
	m_manager    (manager)
    {
    };

    /** Initialize the widget */
    virtual void Init (const orxSTRING widgetName) = 0;

    /** Get the name of the widget */
    inline const orxSTRING GetName () { return m_widgetName; }

protected:
    /** Widget D-tor */
    virtual ~ScrollWidget ()
    {
	delete [] m_widgetName;
    };

    char          *m_widgetName;
    WidgetManager *m_manager;
};

#endif  // __SCROLLWIDGET_H__