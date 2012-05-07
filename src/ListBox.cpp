#include "ListBox.h"

#include "OrxCraft.h"

ListBox::ListBox (CEGUI::Listbox *ceListBox)
{ 
    m_box = ceListBox;
    m_box->subscribeEvent (CEGUI::Listbox::EventSelectionChanged,
	CEGUI::Event::Subscriber (&ListBox::OnSelectionChanged, this));
}

ListBox::~ListBox ()
{
    // Looks like CEGUI destroySystem() takes care of this for us.
    /*
    vector<CEGUI::ListboxTextItem *>::iterator delIter;
    delIter = items.begin ();
    while (delIter != items.end ())
    {
	delete *delIter;
	*delIter = NULL;
	++delIter;
    }
    */
}

void ListBox::AddItem (const orxSTRING itemText)
{
    items.push_back (new CEGUI::ListboxTextItem (itemText));
    m_box->addItem (items.back ());
}

void ListBox::Fill (vector<const orxSTRING> &itemText)
{
    for (unsigned int i = 0; i < itemText.size (); i++)
    {
	items.push_back (new CEGUI::ListboxTextItem (itemText.at (i)));
	m_box->addItem (items.back ());
    }
}

bool ListBox::OnSelectionChanged (const CEGUI::EventArgs &e)
{
    OrxCraft::GetInstance ().SetSelectedObject ("O-Soldier2");
    return true;
}