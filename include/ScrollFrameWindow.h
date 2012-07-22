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