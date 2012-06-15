/**
 * @file RocketListbox.cpp
 * @date 2012-06-12
 * @author fritz@fritzmahnke.com
 *
 */

#include "RocketListbox.h"
#include "RocketListDataSource.h"
#include "WidgetManager.h"

RocketListbox::RocketListbox (WidgetManager *manager) :
    ScrollListbox (manager),
    m_dataSource (NULL)
{
}

void RocketListbox::Init (const orxSTRING widgetName)
{
    const orxSTRING windowName = m_manager->GetWindowName ();
    
    m_widgetName = new char[strlen (widgetName) + 1];
    strcpy (m_widgetName, widgetName);

    m_dataSource = new RocketListDataSource (widgetName);
    //m_dataSource = new RocketListDataSource ("objectsectionlist");
}

void RocketListbox::Fill (const orxSTRING colName,
			  const vector<const orxSTRING> &listItems)
{
    m_dataSource->Init (colName, listItems);
}

RocketListbox::~RocketListbox ()
{
    delete m_dataSource;
}