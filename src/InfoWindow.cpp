#include "InfoWindow.h"

#include "OrxCraft.h"

InfoWindow::InfoWindow () :
    m_infoWindow (NULL),
    m_listBox (NULL)
{
}

void InfoWindow::OnCreate ()
{
    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    m_infoWindow = rootWindow->getChild ("InfoWindow");
    m_listBox = new ListBox
	((CEGUI::Listbox *) m_infoWindow->getChild ("SectionList"));
    m_infoWindow->subscribeEvent (CEGUI::Window::EventMouseClick,
	CEGUI::Event::Subscriber (&InfoWindow::OnMouseClick, this));
    //m_listBox->box->subscribeEvent (CEGUI::Listbox::EventSelectionChanged,
	//CEGUI::Event::Subscriber (&InfoWindow::OnSelectionChanged, this));
    m_listBox->Fill (OrxCraft::GetInstance ().GetObjectList ());
}

bool InfoWindow::OnMouseClick (const CEGUI::EventArgs &e)
{
    return true;
}

bool InfoWindow::OnSelectionChanged (const CEGUI::EventArgs &e)
{
    return true;
}

void InfoWindow::OnDelete ()
{
    delete m_listBox;
    m_listBox = NULL;
}

void InfoWindow::Update(const orxCLOCK_INFO &_rstInfo)
{
}

