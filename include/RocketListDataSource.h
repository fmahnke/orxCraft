#ifndef ROCKETLISTDATASOURCE_H__
#define ROCKETLISTDATASOURCE_H__
/**
 * @file RocketListDataSource.h
 * @date 2012-06-11
 * @author fritz@fritzmahnke.com
 *
 * Data source for a list built with a libRocket DataGrid
 */

#include "Rocket/Controls/DataSource.h"
#include "Scroll.h"

#include <vector>

using std::vector;

class RocketListDataSource : public Rocket::Controls::DataSource
{
public:
    //! Construct data source and initialize data source name
    RocketListDataSource (const orxSTRING name);
    //! Set the items in a column
    void         SetColumn (const orxSTRING tableName,
			    const orxSTRING colName,
			    const vector<const orxSTRING> &items);
    virtual void GetRow(Rocket::Core::StringList& row,
			const Rocket::Core::String& table,
			int row_index,
			const Rocket::Core::StringList& columns);
    virtual int  GetNumRows(const Rocket::Core::String& table);

private:
    //! Add a new table to the data source
    int          AddTable       (const orxSTRING tableName);
    //! Add a new column to the data source
    int          AddColumn      (const orxSTRING tableName,
				 const orxSTRING columnName);
    int          GetTableIndex  (const orxSTRING tableName);
    int          GetColumnIndex (const orxSTRING tableName,
				 const orxSTRING columnName);
    vector<const orxSTRING> m_tableNames;
    vector<vector<const orxSTRING>> m_columnNames;
    vector<vector<vector<const orxSTRING>>> m_items;
};

#endif  // ROCKETLISTDATASOURCE_H__