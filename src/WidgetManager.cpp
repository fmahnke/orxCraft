/**
 * @file WidgetManager.cpp
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "WidgetManager.h"

CEGUI::Window * WidgetManager::FindWidget (const orxSTRING windowName,
				           const orxSTRING widgetName)
{
    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *window = rootWindow->getChild (windowName);
    CEGUI::Window *widget = window->getChild (widgetName);
    return widget;
}

const orxSTRING WidgetManager::GetText (const orxSTRING widgetName)
{
    return orxNULL;
}

void WidgetManager::SetText (const orxSTRING windowName, const orxSTRING widgetName,
			    const orxSTRING text)
{
    FindWidget (windowName, widgetName)->setText (text);
}



void SetTextFromConfigStringList (const orxSTRING widgetName,
						const orxSTRING prop)
{
}

void SetTextFromConfigVector (const orxSTRING widgetName,
					    const orxSTRING prop,
					    orxU32 elementNum)
{
}