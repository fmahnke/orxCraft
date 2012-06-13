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
    //! Initialize control with a list of items
    void         Init (const vector<orxSTRING> &items);
    virtual void GetRow(Rocket::Core::StringList& row, const Rocket::Core::String& table, int row_index, const Rocket::Core::StringList& columns);
    virtual int  GetNumRows(const Rocket::Core::String& table);

private:
    vector<orxSTRING> m_items;
};

#endif  // ROCKETLISTDATASOURCE_H__