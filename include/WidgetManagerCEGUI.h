#ifndef WIDGETMANAGERCEGUI_H_
#define WIDGETMANAGERCEGUI_H_
/**
 * @file WidgetManagerCEGUI.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 * CEGUI implementation of Widget Manager
 */

#include <vector>
#include "orx/orx.h"
#include "CEGUI.h"
#include "WidgetManager.h"

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
class WidgetManagerCEGUI : public WidgetManager
{
public:
    WidgetManagerCEGUI () :
        m_scrollWindow (NULL),
	m_window (NULL)
    {
    };
    void Init (const orxSTRING widgetName, ScrollFrameWindow *scrollWindow);
    ScrollWidget * FindWidget (const orxSTRING widgetName) const;

    virtual const orxSTRING GetWindowName () const;

    virtual const orxSTRING GetSelectedItem (const orxSTRING widgetName) const;
    virtual void            SetSelectedItem (const orxSTRING widgetName,
					     const orxSTRING selectedItem);

    virtual const orxSTRING GetText (const orxSTRING widgetName) const;
    /// Update widget text explicitly
    virtual int SetEditText (const orxSTRING widgetName, const orxSTRING text);

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
};

#endif  // WIDGETMANAGERCEGUI_H_