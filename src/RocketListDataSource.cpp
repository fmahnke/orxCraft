/**
 * @file RocketListDataSource.cpp
 * @date 2012-06-11
 * @author fritz@fritzmahnke.com
 *
 */

#include "RocketListDataSource.h"

void RocketListDataSource::Init (const vector<orxSTRING> &items)
{
    for (unsigned int i = 0; i < items.size (); i++)
    {
	m_items.push_back (items.at (i));
    }
}

void RocketListDataSource::GetRow(Rocket::Core::StringList& row,
                                  const Rocket::Core::String& table,
				  int row_index,
				  const Rocket::Core::StringList& columns)
{
    orxASSERT (false);
}

int RocketListDataSource::GetNumRows(const Rocket::Core::String& table)
{
    orxASSERT (false);
    return 0;
}