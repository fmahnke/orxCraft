#ifndef ROCKETLISTBOX_H__
#define ROCKETLISTBOX_H__
/**
 * @file RocketListbox.h
 * @date 2012-06-11
 * @author fritz@fritzmahnke.com
 *
 * libRocket implementation of a Listbox
 */

#include "ScrollListbox.h"

#include <vector>

class WidgetManager;

using std::vector;

//! libRocket Implementation of a Listbox
class RocketListbox : public ScrollListbox
{
public:
    explicit RocketListbox (WidgetManager *manager);
    virtual void Init (const orxSTRING widgetName);
    void SetDataTableName (const orxSTRING tableName);
    void Fill (const orxSTRING colName,
	       const vector<const orxSTRING> &listItems);

protected:
    virtual ~RocketListbox ();

private:
    orxSTRING m_dataTableName;
};
#endif  // ROCKETLISTBOX_H__
