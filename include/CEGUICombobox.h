#ifndef __CEGUICOMBOBOX_H__
#define __CEGUICOMBOBOX_H__
/**
 * @file CEGUICombobox.h
 * @date 2012-05-11
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollCombobox.h"
#include "CEGUI.h"

class WidgetManager;

using std::vector;

/** CEGUI implementation of a Combobox */
class CEGUICombobox : public ScrollCombobox
{
public:
    /** C-tor */
    explicit CEGUICombobox (WidgetManager *manager);
    /** Initialize the Combobox */
    virtual void Init (const orxSTRING widgetName);
    /** Fill the box with a list */
    void Fill (const vector<const orxSTRING> &listItems);

private:
    bool OnSelectionAccepted (const CEGUI::EventArgs &e);

    CEGUI::Combobox *m_ceCombobox;
    vector<CEGUI::ListboxTextItem *> m_items;
};
#endif  // __CEGUICOMBOBOX_H__