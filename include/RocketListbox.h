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
class RocketListDataSource;

using std::vector;

/** libRocket Implementation of a Listbox */
class RocketListbox : public ScrollListbox
{
public:
    explicit RocketListbox (WidgetManager *manager);
    virtual void Init (const orxSTRING widgetName);
    void Fill (const vector<const orxSTRING> &listItems);

private:
    RocketListDataSource *m_dataSource;

protected:
    virtual ~RocketListbox ();
};
#endif  // ROCKETLISTBOX_H__
