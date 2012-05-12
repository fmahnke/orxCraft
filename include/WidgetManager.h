#ifndef __WIDGETMANAGER_H__
#define __WIDGETMANAGER_H__
/**
 * @file WidgetManager.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "orx/orx.h"

#include "CEGUI.h"

class ScrollFrameWindow;
class ScrollWidget;

using std::vector;

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


    void FillList (const orxSTRING widgetName,
	           const vector<const orxSTRING> &listItems);

    void OnMouseClick   (const orxSTRING widgetName);
    void OnTextAccepted (const orxSTRING widgetName);

private:
    ScrollFrameWindow *m_scrollWindow;
    char m_windowName[255];
    CEGUI::Window *m_window;
    vector<ScrollWidget *> m_widgetList;
};

#endif  // __SCROLL_WINDOW_H__