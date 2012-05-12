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
    ScrollWidget (WidgetManager *manager) :
	m_widgetName (NULL),
	m_manager (manager)
    {
    };
    virtual void Init (const orxSTRING widgetName) = 0;

    inline const orxSTRING GetName () { return m_widgetName; }
protected:
    virtual ~ScrollWidget ()
    {
	delete [] m_widgetName;
    };

    WidgetManager *m_manager;
    char *m_widgetName;
};

#endif  // __SCROLL_CHECKBOX_H__