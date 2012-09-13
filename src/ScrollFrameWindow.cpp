/*
 *  Copyright (c) 2012 The orxCraft Project
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *     1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *  
 *     2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *  
 *     3. This notice may not be removed or altered from any source
 *     distribution.
 */

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

ScrollCheckbox * ScrollFrameWindow::FindCheckbox (
    const orxSTRING widgetName) const
{
    ScrollCheckbox *theWidget = NULL;
    vector<ScrollWidget *>::const_iterator widgIter;
    for (widgIter = m_widgetList.begin (); widgIter != m_widgetList.end ();
	 ++widgIter)
    {
	if (orxString_Compare ((*widgIter)->GetName (), widgetName) == 0)
	{
	    theWidget = reinterpret_cast<ScrollCheckbox *> (*widgIter);
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
