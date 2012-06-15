/**
 * @file RocketListDataSource.cpp
 * @date 2012-06-11
 * @author fritz@fritzmahnke.com
 *
 */

#include "RocketListDataSource.h"

RocketListDataSource::RocketListDataSource (const orxSTRING name) :
    Rocket::Controls::DataSource (name)
{
}

void RocketListDataSource::Init (const orxSTRING colName,
				 const vector<const orxSTRING> &items)
{
    for (unsigned int i = 0; i < items.size (); i++)
    {
	m_items.push_back (items.at (i));
	NotifyRowAdd (colName, i, 1);
    }
}


void RocketListDataSource::GetRow(Rocket::Core::StringList& row,
                                  const Rocket::Core::String& table,
				  int row_index,
				  const Rocket::Core::StringList& columns)
{
    row.push_back (m_items.at (row_index));
}

int RocketListDataSource::GetNumRows(const Rocket::Core::String& table)
{
    return m_items.size ();
}