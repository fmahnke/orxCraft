/**
 * @file RocketListbox.cpp
 * @date 2012-06-12
 * @author fritz@fritzmahnke.com
 *
 */

#include "RocketListbox.h"
#include "WidgetManager.h"

RocketListbox::RocketListbox (WidgetManager *manager) :
    ScrollListbox   (manager),
    m_dataTableName (NULL)
{
}

void RocketListbox::Init (const orxSTRING widgetName)
{
    orxASSERT (widgetName != orxNULL);

    const orxSTRING windowName = m_manager->GetWindowName ();
    
    m_widgetName = new char[strlen (widgetName) + 1];
    strcpy (m_widgetName, widgetName);
}

void RocketListbox::SetDataTableName (const orxSTRING tableName)
{
    orxASSERT (tableName != orxNULL);

    int length = orxString_GetLength (tableName);
    m_dataTableName = new orxCHAR [length + 1];
    orxString_Copy (m_dataTableName, tableName);
}

void RocketListbox::Fill (const orxSTRING colName,
			  const vector<const orxSTRING> &listItems)
{
}

RocketListbox::~RocketListbox ()
{
    delete [] m_dataTableName;
}