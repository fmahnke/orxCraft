#ifndef WIDGETMANAGER_H_
#define WIDGETMANAGER_H_
/**
 * @file WidgetManager.h
 * @date 2012-06-09
 * @author fritz@fritzmahnke.com
 *
 */

#include <vector>
#include "orx/orx.h"
#include "ScrollWidget.h"

class ScrollFrameWindow;

using std::vector;

/**
 *  Each window can have an instance of the widget manager.
 *
 *  The widget manager is responsible for receiving messages from widgets
 *  and passing them to the appropriate windows. It is also responsible for
 *  receiving messages from windows and using them to change the states of
 *  widgets.
 */
class WidgetManager
{
public:
    WidgetManager () :
        m_scrollWindow (NULL)
    {
    };
    virtual void Init (const orxSTRING widgetName,
		       ScrollFrameWindow *scrollWindow) = 0;
    virtual ScrollWidget * FindWidget (const orxSTRING widgetName) const = 0;

    virtual const orxSTRING GetWindowName () const = 0;

    virtual const orxSTRING GetSelectedItem (const orxSTRING widgetName) const = 0;
    virtual void            SetSelectedItem (const orxSTRING widgetName,
					     const orxSTRING selectedItem) = 0;

    virtual const orxSTRING GetText (const orxSTRING widgetName) const = 0;
    /// Update widget text explicitly
    virtual int   SetText (const orxSTRING widgetName, const orxSTRING text) = 0;

    //! Fill a list box
    virtual void FillList (const orxSTRING widgetName,
	                   const vector<const orxSTRING> &listItems) = 0;

    //! Handle a mouse click event from a widget
    virtual void OnMouseClick   (const orxSTRING widgetName) = 0;
    //! Handle a text accepted event from a widget
    virtual void OnTextAccepted (const orxSTRING widgetName) = 0;

    virtual ~WidgetManager ()
    {
	vector<ScrollWidget *>::iterator iter;
	for (iter = m_widgetList.begin ();
	    iter != m_widgetList.end ();
	    ++iter)
	{
	    delete *iter;
	}
    };

protected:
    vector<ScrollWidget *> m_widgetList;

private:
    ScrollFrameWindow *m_scrollWindow;
    char m_windowName[255];
};

#endif  // WIDGETMANAGER_H_