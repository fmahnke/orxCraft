/**
 * @file WidgetManagerRocket.cpp
 * @date 2012-06-09
 * @author fritz@fritzmahnke.com
 *
 */

#include "WidgetManagerRocket.h"
#include "Rocket/Core.h"
#include "ScrollFrameWindow.h"
#include "ScrollWidget.h"
#include "ScrollGUIRocket.h"

using Rocket::Core::Context;
using Rocket::Core::Element;

void WidgetManagerRocket::Init (const orxSTRING widgetName, ScrollFrameWindow *scrollWindow)
{
    m_scrollWindow = scrollWindow;
    strcpy (m_windowName, widgetName);
#if 0
    Context *context = ScrollGUIRocket::GetContext ();
    Element *root = context->GetRootElement ();
    Element *test = root->GetElementById ("testfield");
#endif
}

ScrollWidget * WidgetManagerRocket::FindWidget (const orxSTRING widgetName)
{
    ScrollWidget *theWidget = NULL;
    vector<ScrollWidget *>::iterator widgIter;
    for (widgIter = m_widgetList.begin (); widgIter != m_widgetList.end ();
	 ++widgIter)
    {
	if (orxString_Compare ((*widgIter)->GetName (), widgetName) == 0)
	{
	    theWidget = *widgIter;
	    break;
	}
    }
	 
    return theWidget;
}

const orxSTRING WidgetManagerRocket::GetText (const orxSTRING widgetName)
{
    return NULL;
}

const orxSTRING WidgetManagerRocket::GetWindowName ()
{
    return m_windowName;
}

const orxSTRING WidgetManagerRocket::GetSelectedItem (const orxSTRING widgetName)
{
    orxASSERT (widgetName != orxNULL);

    return NULL;
}

void WidgetManagerRocket::SetText (const orxSTRING widgetName, const orxSTRING text)
{
}

void WidgetManagerRocket::FillList (const orxSTRING widgetName,
			      const vector<const orxSTRING> &listItems)
{
}

void WidgetManagerRocket::OnMouseClick (const orxSTRING widgetName)
{
    m_scrollWindow->HandleMouseClick (widgetName);
}

void WidgetManagerRocket::OnTextAccepted (const orxSTRING widgetName)
{
    m_scrollWindow->HandleTextAccepted (widgetName);
}