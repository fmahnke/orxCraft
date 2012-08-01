/**
 * @file ScrollFrameWindow.cpp
 * @date 2012-07-01
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollFrameWindow.h"

#include "ScrollCombobox.h"
#include "ScrollEditbox.h"
#include "ScrollListbox.h"

ScrollFrameWindow::ScrollFrameWindow ()
{
}

ScrollWidget * ScrollFrameWindow::FindWidget (const orxSTRING widgetName) const
{
    ScrollWidget *theWidget = NULL;
    vector<ScrollWidget *>::const_iterator widgIter;
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

ScrollEditbox * ScrollFrameWindow::FindEditbox (
    const orxSTRING widgetName) const
{
    ScrollEditbox *theWidget = NULL;
    vector<ScrollWidget *>::const_iterator widgIter;
    for (widgIter = m_widgetList.begin (); widgIter != m_widgetList.end ();
	 ++widgIter)
    {
	if (orxString_Compare ((*widgIter)->GetName (), widgetName) == 0)
	{
	    theWidget = reinterpret_cast<ScrollEditbox *> (*widgIter);
	    break;
	}
    }
	 
    return theWidget;
}

ScrollCombobox * ScrollFrameWindow::FindCombobox (
    const orxSTRING widgetName) const
{
    ScrollCombobox *theWidget = NULL;
    vector<ScrollWidget *>::const_iterator widgIter;
    for (widgIter = m_widgetList.begin (); widgIter != m_widgetList.end ();
	 ++widgIter)
    {
	if (orxString_Compare ((*widgIter)->GetName (), widgetName) == 0)
	{
	    theWidget = reinterpret_cast<ScrollCombobox *> (*widgIter);
	    break;
	}
    }
	 
    return theWidget;
}

ScrollListbox * ScrollFrameWindow::FindListbox (const orxSTRING widgetName) const
{
    ScrollListbox *theWidget = NULL;
    vector<ScrollWidget *>::const_iterator widgIter;
    for (widgIter = m_widgetList.begin (); widgIter != m_widgetList.end ();
	 ++widgIter)
    {
	if (orxString_Compare ((*widgIter)->GetName (), widgetName) == 0)
	{
	    theWidget = reinterpret_cast<ScrollListbox *> (*widgIter);
	    break;
	}
    }
	 
    return theWidget;
}

void ScrollFrameWindow::AddWidget (ScrollWidget *widget)
{
    m_widgetList.push_back (widget);
}

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
