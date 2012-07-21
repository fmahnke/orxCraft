/**
 * @file RocketListbox.cpp
 * @date 2012-06-12
 * @author fritz@fritzmahnke.com
 *
 */

#include "RocketListbox.h"
#include "WidgetManager.h"
#include "RocketDataSource.h"

RocketListbox::RocketListbox (WidgetManager *manager) :
    ScrollListbox   (manager),
    m_dataTableName (NULL),
    m_dataSource    (NULL),
    m_selection     (NULL)
{
}

void RocketListbox::Init (const orxSTRING widgetName)
{
    orxASSERT (widgetName != orxNULL);

    const orxSTRING windowName = m_manager->GetWindowName ();
    
    m_widgetName = new char[strlen (widgetName) + 1];
    strcpy (m_widgetName, widgetName);
}

void RocketListbox::SetDataSource (RocketDataSource *dataSource)
{
    orxASSERT (dataSource != orxNULL);

    m_dataSource = dataSource;
}

void RocketListbox::SetDataTableName (const orxSTRING tableName)
{
    orxASSERT (tableName != orxNULL);

    // Allocate a string
    int length = orxString_GetLength (tableName);
    m_dataTableName = new orxCHAR [length + 1];
    // Copy to data table name
    orxString_Copy (m_dataTableName, tableName);
}

void RocketListbox::Fill (const orxSTRING colName,
			  const vector<const orxSTRING> &listItems)
{
    orxASSERT (colName != orxNULL);
    orxASSERT (! listItems.empty());

    // Update the associated data source
    m_dataSource->SetColumn (m_dataTableName, colName, listItems);
}

const orxSTRING RocketListbox::GetSelectedItems () const
{
    return m_selection;
}

void RocketListbox::SetSelectedItems (const orxSTRING text)
{
    orxASSERT (text != orxNULL);

    int length = orxString_GetLength (text);

    if (m_selection != orxNULL)
    {
	delete [] m_selection;
    }
    m_selection = new orxCHAR [length + 1];
    orxString_NCopy (m_selection, text, 10);
}

RocketListbox::~RocketListbox ()
{
    delete [] m_dataTableName;
}
