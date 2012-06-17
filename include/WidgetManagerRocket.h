#ifndef __WIDGETMANAGERROCKET_H__
#define __WIDGETMANAGERROCKET_H__
/**
 * @file WidgetManagerRocket.h
 * @date 2012-06-09
 * @author fritz@fritzmahnke.com
 *
 * libRocket implementation of Widget Manager
 */

#include "orx/orx.h"

#include "WidgetManager.h"

class RocketDataSource;
class ScrollFrameWindow;
class ScrollWidget;

namespace Rocket
{
namespace Core
{

class Element;

}   // namespace Rocket
}   // namespace Core

using std::vector;

/**
 *  Each window can have an instance of the widget manager.
 *
 *  The widget manager is responsible for receiving messages from widgets
 *  and passing them to the appropriate windows. It is also responsible for
 *  receiving messages from windows and using them to change the states of
 *  widgets.
 */
class WidgetManagerRocket : public WidgetManager
{
public:
    //! C-tor
    WidgetManagerRocket ();
    //! D-tor
    ~WidgetManagerRocket ();

    void Init (const orxSTRING widgetName, ScrollFrameWindow *scrollWindow);
    //! Add all child widgets of a root widget to the widget list
    void AddWidgetRecursive (const Rocket::Core::Element *root);

    ScrollWidget * FindWidget (const orxSTRING widgetName) const;

    const orxSTRING GetWindowName () const;

    const orxSTRING GetSelectedItem (const orxSTRING widgetName) const;

    const orxSTRING GetText (const orxSTRING widgetName) const;
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
    //! Data source for all widgets
    RocketDataSource  *m_dataSource;
};

#endif  // __WIDGETMANAGERROCKET_H__