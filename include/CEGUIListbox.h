#ifndef __CEGUILISTBOX_H__
#define __CEGUILISTBOX_H__
/**
 * @file CEGUIListbox.h
 * @date 2012-05-10
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollListbox.h"

#include "CEGUI.h"

class WidgetManager;

using std::vector;

/** CEGUI Implementation of a Listbox */
class CEGUIListbox : public ScrollListbox
{
public:
    explicit CEGUIListbox (WidgetManager *manager);
    virtual void Init (const orxSTRING widgetName);
    void Fill (const vector<const orxSTRING> &listItems);

     //bool OnSelectionChanged (const CEGUI::EventArgs &e);
private:
    bool OnMouseClick (const CEGUI::EventArgs &e);

    CEGUI::Listbox *m_ceListbox;
    vector<CEGUI::ListboxTextItem *> m_items;
};
#endif  // __CEGUILISTBOX_H__