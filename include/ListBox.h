/**
 * @file ListBox.h
 * @date 2012-06-04
 * @author fritz@fritzmahnke.com
 *
 */
#ifndef __LISTBOX_H__
#define __LISTBOX_H__

#include <vector>

#include "orx/orx.h"
#include "CEGUI.h"

using std::vector;

class ListBox
{
public:
    //ListBox ();
    explicit ListBox (CEGUI::Listbox *ceListBox);
    ~ListBox ();

    void AddItem (const orxSTRING itemText);
    void Fill    (vector<const orxSTRING> &itemTexts);

    bool OnSelectionChanged (const CEGUI::EventArgs &e);

private:
    CEGUI::Listbox *m_box;
    vector<CEGUI::ListboxTextItem *> items;
};

#endif  // __LISTBOX_H__