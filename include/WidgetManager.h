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

class WidgetManager
{
public:
    static CEGUI::Window * FindWidget (const orxSTRING windowName,
				       const orxSTRING widgetName);
    static const orxSTRING GetText (const orxSTRING widgetName);

    /// Update widget text explicitly
    static void SetText (const orxSTRING windowName, const orxSTRING widgetName,
	                 const orxSTRING text);


    /// Update widget text from an Orx config string
    static void SetTextFromConfigStringList (const orxSTRING widgetName,
						    const orxSTRING prop);
    /// Update widget text from an Orx config vector
    static void SetTextFromConfigVector (const orxSTRING widgetName,
					        const orxSTRING prop,
						orxU32 elementNum);
};

#endif  // __SCROLL_WINDOW_H__