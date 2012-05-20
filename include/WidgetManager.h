#ifndef __WIDGETMANAGER_H__
#define __WIDGETMANAGER_H__
/**
 * @file WidgetManager.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 * @todo As of now, the WidgetManager is specific to CEGUI widgets. This
 * class should be decoupled from CEGUI so interacting with widgets does not
 * depend on a particular implementation of the widgets.
 */

#include "orx/orx.h"

#include "CEGUI.h"

class ScrollFrameWindow;
class ScrollWidget;

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
        m_scrollWindow (NULL),
	m_window (NULL)
    {
    };
    void Init (const orxSTRING widgetName, ScrollFrameWindow *scrollWindow);
    ScrollWidget * FindWidget (const orxSTRING widgetName);

    const orxSTRING GetWindowName ();

    const orxSTRING GetSelectedItem (const orxSTRING widgetName);

    const orxSTRING GetText (const orxSTRING widgetName);
    /// Update widget text explicitly
    void SetText (const orxSTRING widgetName, const orxSTRING text);

    //! Fill a list box
    void FillList (const orxSTRING widgetName,
	           const vector<const orxSTRING> &listItems);

    //! Handle a mouse click event from a widget
    void OnMouseClick   (const orxSTRING widgetName);
    //! Handle a text accepted event from a widget
    void OnTextAccepted (const orxSTRING widgetName);

private:
    ScrollFrameWindow *m_scrollWindow;
    char m_windowName[255];
    CEGUI::Window *m_window;
    vector<ScrollWidget *> m_widgetList;
};

#endif  // __SCROLL_WINDOW_H__