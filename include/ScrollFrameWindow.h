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
#include "WidgetManager.h"

/**
 *  Interface for a Window.
 */
class ScrollFrameWindow
{
public:
    //! C-tor
    ScrollFrameWindow () :
	m_widgetManager (NULL) { };
    /** Initialize the window */
    virtual void Init (const orxSTRING widgetName) = 0;
    /** Get the window's name */
    virtual const orxSTRING GetName () = 0;
    /** Left mouse click event handler */
    virtual void HandleMouseClick   (const orxSTRING widgetName) = 0;
    /** Text accepted (pressed Enter key) event handler */
    virtual void HandleTextAccepted (const orxSTRING widgetName) = 0;
protected:
    //! D-tor
    virtual ~ScrollFrameWindow ()
    {
	delete m_widgetManager;
    };

    WidgetManager *m_widgetManager;
};

#endif  // __SCROLLFRAMEWINDOW_H__