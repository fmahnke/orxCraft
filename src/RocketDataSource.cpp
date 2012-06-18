/**
 * @file RocketDataSource.cpp
 * @date 2012-06-11
 * @author fritz@fritzmahnke.com
 *
 */

#include "RocketDataSource.h"

RocketDataSource::RocketDataSource (const orxSTRING name) :
    Rocket::Controls::DataSource (name)
{
}

void RocketDataSource::SetColumn (const orxSTRING tableName,
				      const orxSTRING colName,
				      const vector<const orxSTRING> &items)
{
    orxASSERT (tableName != orxNULL);
    orxASSERT (colName != orxNULL);
    orxASSERT (items.size () > 0);

    int tableIndex = GetTableIndex (tableName);
    // Table doesn't exist?
    if (tableIndex == -1)
    {
	tableIndex = AddTable (tableName);
    }

    int columnIndex = GetColumnIndex (tableName, colName);
    // Column doesn't exist?
    if (columnIndex == -1)
    {
	columnIndex = AddColumn (tableName, colName);
    }

    if (m_items.size () < m_tableNames.size ())
    {
	m_items.resize (m_tableNames.size ());
    }
    if (m_items.at (tableIndex).size () < m_columnNames.size ())
    {
	m_items.at (tableIndex).resize (m_columnNames.size ());
    }
    m_items.at (tableIndex).at (columnIndex).clear ();
    m_items.at (tableIndex).at (columnIndex) = items;
    NotifyRowAdd (tableName, 0, items.size ());
}

void RocketDataSource::GetRow(Rocket::Core::StringList& row,
                                  const Rocket::Core::String& table,
				  int row_index,
				  const Rocket::Core::StringList& columns)
{
    int tableIndex = GetTableIndex (table.CString ());
    /*
     *  Haven't figured out why, but Rocket wants results for some
     *  #child_data_source column that isn't in our database.
     */
    for (unsigned int i = 0; i < columns.size () - 1; i++)
    {
	int columnIndex = GetColumnIndex (table.CString (),
					  columns.at (i).CString ());
	row.push_back (m_items.at (tableIndex).at (columnIndex).at (row_index));
    }
}

int RocketDataSource::GetNumRows(const Rocket::Core::String& table)
{
    int maxRowsInAnyColumn = 0;
    int tableIndex = GetTableIndex (table.CString ());
    for (unsigned int i = 0; i < m_columnNames.at (tableIndex).size (); i++)
    {
	int rowsInColumn = m_items.at (tableIndex).at (i).size ();
	if (rowsInColumn > maxRowsInAnyColumn)
	{
	    maxRowsInAnyColumn = rowsInColumn;
	}
    }
    return maxRowsInAnyColumn;
}

int RocketDataSource::AddTable (const orxSTRING tableName)
{
    orxASSERT (tableName != orxNULL);

    int tableIndex = GetTableIndex (tableName);
    // Table already exists?
    if (tableIndex != -1)
    {
	orxASSERT (false);
	tableIndex = -1;
    }
    else
    {
	// Index will be end of vector
	tableIndex = m_tableNames.size ();
	// Add to list of names
	m_tableNames.push_back (tableName);
    }
    return tableIndex;
}

int RocketDataSource::AddColumn (const orxSTRING tableName,
				     const orxSTRING columnName)
{
    orxASSERT (tableName != orxNULL);
    orxASSERT (columnName != orxNULL);

    int columnIndex = GetColumnIndex (tableName, columnName);
    // Column already exists?
    if (columnIndex != -1)
    {
	orxASSERT (false);
	columnIndex = -1;
    }
    else
    {
	// Have more tables than size in the column list?
	if (m_tableNames.size () > m_columnNames.size ())
	{
	    orxASSERT (m_tableNames.size () == m_columnNames.size () + 1);
	    // Expand the column list to match the table list
	    m_columnNames.resize (m_tableNames.size ());
	    columnIndex = m_columnNames.size () - 1;
	}
	else
	{
	    columnIndex = m_columnNames.size ();
	}
	m_columnNames.at (columnIndex).push_back (columnName);
    }
    return columnIndex;
}

int RocketDataSource::GetTableIndex (const orxSTRING tableName) const
{
    orxASSERT (tableName != orxNULL);

    unsigned int tableIndex = -1;
    for (unsigned int i = 0; i < m_tableNames.size (); i++)
    {
	// Found desired table?
	if (orxString_Compare (m_tableNames.at (i), tableName) == 0)
	{
	    tableIndex = i;
	    break;
	}
    }
    return tableIndex;
}

int RocketDataSource::GetColumnIndex (const orxSTRING tableName,
					  const orxSTRING columnName) const
{
    orxASSERT (tableName  != orxNULL);
    orxASSERT (columnName != orxNULL);

    int columnIndex = -1;
    unsigned int tableIndex = GetTableIndex (tableName);
    // Table exists?
    if (tableIndex != -1)
    {
	// Enough column names in the list to reach the tableIndex?
	if (m_columnNames.size () > tableIndex)
	{
	    vector<const orxSTRING> columnNames = m_columnNames.at (tableIndex);
	    for (unsigned int i = 0; i < columnNames.size (); i++)
	    {
		// Found desired column?
		if (orxString_Compare (columnNames.at (i), columnName) == 0)
		{
		    columnIndex = i;
		    break;
		}
	    }
	}
    }
    return columnIndex;
}
