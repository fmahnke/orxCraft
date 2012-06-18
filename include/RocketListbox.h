#ifndef ROCKETLISTBOX_H_
#define ROCKETLISTBOX_H_
/**
 * @file RocketListbox.h
 * @date 2012-06-11
 * @author fritz@fritzmahnke.com
 *
 * libRocket implementation of a Listbox
 */

#include "ScrollListbox.h"

#include <vector>

class RocketDataSource;
class WidgetManager;

using std::vector;

//! libRocket Implementation of a Listbox
class RocketListbox : public ScrollListbox
{
public:
    explicit RocketListbox (WidgetManager *manager);
    virtual void Init (const orxSTRING widgetName);
    //! Set the data source used by this list box
    void SetDataSource (RocketDataSource *dataSource);
    //! Set the name of the data table used by this list box
    void SetDataTableName (const orxSTRING tableName);
    //! Fill the specified column with a list of items
    void Fill (const orxSTRING colName,
	       const vector<const orxSTRING> &listItems);
    const orxSTRING GetSelectedItems () const;
    void            SetSelectedItems (const orxSTRING text);

protected:
    virtual ~RocketListbox ();

private:
    orxSTRING             m_dataTableName;
    RocketDataSource     *m_dataSource;
    orxSTRING             m_selection;
};
#endif  // ROCKETLISTBOX_H_
