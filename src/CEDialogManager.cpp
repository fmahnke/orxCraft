/**
 * @file CEDialogManager.cpp
 * @date 2012-07-01
 * @author fritz@fritzmahnke.com
 *
 * CEGUI implementation of the Dialog Manager.
 * 
 * @todo Make sure dialogs get destroyed on program quit
 */

#include "CEDialogManager.h"

#include "CEGUI.h"

#include "ScrollFrameWindow.h"

// Dialogs
#include "ObjectEditor.h"
#include "FXSlotEditorWindow.h"

#include "CEGUICombobox.h"
#include "CEGUIEditbox.h"
#include "CEGUIListbox.h"
#include "CEGUIPushButton.h"

void CEDialogManager::MakeDialog (const orxSTRING dialogName)
{
    orxASSERT (dialogName != orxNULL);

    ScrollFrameWindow *dialog = orxNULL;

    CEGUI::Window *windowRoot = NULL;

    if (orxString_Compare (dialogName, "ObjectEditor") == 0)
    {
	dialog = new ObjectEditor ();
	windowRoot = CEGUI::WindowManager::getSingleton().loadWindowLayout(
	    "ObjectEditor.layout");
    }
    else if (orxString_Compare (dialogName, "FXSlotEditor") == 0)
    {
	dialog = new FXSlotEditorWindow ();
	windowRoot = CEGUI::WindowManager::getSingleton().loadWindowLayout(
	    "FXSlotEditor.layout");
    }
    else
    {
	orxASSERT (false);
    }

    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window* window = windowRoot->getChildAtIdx (0); 
    rootWindow->addChildWindow (window);   
    
    int counter = window->getChildCount ();
    for (int i = 0; i < counter; i++)
    {
	CEGUI::Window* widget = window->getChildAtIdx (i);
	const orxSTRING type = widget->getType ().c_str ();
	if (orxString_Compare (type, "TaharezLook/TabControl") == 0)
	{
	    //TabControl
	    int c_counter = widget->getChildCount ();
	    for (int j = 0; j < c_counter; j++) {
		// Container - Pane, ScrollBar and other stuff
		CEGUI::Window* container = widget->getChildAtIdx (j);
		int t_counter = container->getChildCount ();
		for(int k = 0; k < t_counter; k++) {
		    // The actual Tab
		    CEGUI::Window* tab = container->getChildAtIdx(k);
			const orxSTRING type = tab->getType ().c_str ();
			// Tabs are of type "DefaultWindow"
			if (orxString_Compare (type, "DefaultWindow") != 0)
			    continue;
		    int w_counter = tab->getChildCount ();
		    for(int l = 0; l < w_counter; l++) {
			// Widget inside a Tab
			CEGUI::Window* sub_widget = tab->getChildAtIdx(l);
			LinkWidgetToDialog(sub_widget, dialog);
		    }
		}
	    }
	} else {
	    LinkWidgetToDialog(widget, dialog);
	}
    }

    dialog->Init (dialogName);
}

void CEDialogManager::LinkWidgetToDialog(CEGUI::Window* widget, ScrollFrameWindow* dialog)
{
    const orxSTRING type = widget->getType ().c_str ();
	const orxSTRING name = widget->getName ().c_str ();
    if (orxString_Compare (type, "TaharezLook/Checkbox") == 0)
    {
	orxASSERT (false);
	/*
	CEGUICheckbox *checkbox = new CEGUICheckbox (this);
	checkbox->Init (name);
	m_widgetList.push_back (checkbox);
	*/
    }
    else if (orxString_Compare (type, "TaharezLook/Combobox") == 0)
    {
	CEGUICombobox *combobox = new CEGUICombobox (dialog);
	combobox->Init (widget);
	dialog->AddWidget (combobox);
    }
    else if (orxString_Compare (type, "TaharezLook/Editbox") == 0)
    {
	CEGUIEditbox *editbox = new CEGUIEditbox (dialog);
	editbox->Init (widget);
	dialog->AddWidget (editbox);
    }
    else if (orxString_Compare (type, "TaharezLook/Listbox") == 0)
    {
	CEGUIListbox *listbox = new CEGUIListbox (dialog);
	listbox->Init (widget);
	dialog->AddWidget (listbox);
    }
    else if (orxString_Compare (type, "TaharezLook/Button") == 0)
    {
	CEGUIPushButton *pushbutton = new CEGUIPushButton (dialog);
	pushbutton->Init (widget);
	dialog->AddWidget (pushbutton);
    }
}

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
