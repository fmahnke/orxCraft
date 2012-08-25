/**
 * @file OrxCraft.h
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#ifndef ORXCRAFT_H
#define ORXCRAFT_H

//! Includes
// #define __NO_SCROLLED__
/*
 *  Uncomment above define to prevent the embedded editor (ScrollEd) from
 *  being compiled
 */
#include "Scroll.h"

#include <vector>
#include <string>

class DialogManager;

class ScrollGUICEGUI;

using std::vector;

//! Main OrxCraft program class
class OrxCraft : public Scroll<OrxCraft>
{
public:
    OrxCraft ();

    //! Get names of currently loaded objects.
    inline vector<const orxSTRING>& GetObjectList () { return m_objectList; }
    //! Get names of currently loaded FXSlots
    inline vector<const orxSTRING>& GetFXSlotList () { return m_fxSlotList; }
    //! Set selected FXSlot in FXSlot Editor.
    void SetSelectedFXSlot (const orxSTRING name);

    //! Get names of currently loaded Graphics.
    inline vector<const orxSTRING>& GetGraphicList () { return m_graphicList; }

    /*!
     * Get an Scroll bound object with specified name.
     *
     * @return an object if found, orxNULL otherwise.
     */
    ScrollObject * GetObjectByName (const orxSTRING name) const;

    //! Setup loaded config section lists and create objects.
    void SetupConfig ();
    //! Save the orxCraft user configuration to a file.
    orxSTATUS SaveEditorConfig () const;
    //! Save the currently open project to disk.
    orxSTATUS SaveProject() const;

    //! Indicate properties have been changed and objects need to be updated
    //! to reflect that change.
    void NeedObjectUpdate ();

private:
    //! Initialize the editor: parse command line parameters, load user
    //! settings, load objects, create GUI.
    virtual orxSTATUS Init ();
    //! Fast loop.
    virtual orxSTATUS Run ();
    //! Called on exit to clean up.
    virtual void      Exit ();
    //! Binds orx objects to their ScrollObjects.
    virtual void      BindObjects ();
    //! Main loop executed on main clock ticks.
    virtual void      Update (const orxCLOCK_INFO &_rstInfo);

    //! Load config file for editing.
    void InitConfig ();
    //! Load from config user settings.
    void LoadUserSettings ();

    //! Mouse button push callback.
    void OnMouseDown ();
    //! Mouse button release callback.
    void OnMouseUp ();
    //! Key press callback.
    void OnKeyPress (const orxSTRING key);
    
    //! Auto save current project state to a project.ini.swp files.
    orxSTATUS SaveBackup() const;
    //TODO AddActionDisplay should be in a GUI class
    //! Display a visual notification of an action on screen.
    orxSTATUS AddActionDisplay(
    	    const orxSTRING _zAction //!< [in] String to display.
    	    ) const;

    //! Handler for orx events.
    static orxSTATUS orxFASTCALL EventHandler (const orxEVENT *_pstEvent);
    //! Filter out user settings to save.
    static orxBOOL orxFASTCALL SaveConfigFilter
	(const orxSTRING _zSectionName,
	 const orxSTRING _zKeyName,
	 const orxSTRING _zFileName,
	 orxBOOL _bUseEncryption);
    //! Filter out project contents to save.
    static orxBOOL orxFASTCALL SaveProjectFilter
	(const orxSTRING _zSectionName,
	 const orxSTRING _zKeyName,
	 const orxSTRING _zFileName,
	 orxBOOL _bUseEncryption);
    //! Process command line parameters.
    static orxSTATUS orxFASTCALL ProcessParams(
	    orxU32 _u32ParamCount, const orxSTRING _azParams[]);

    //! Windowed part of the GUI.
    ScrollGUICEGUI	    *m_gui;
    //! Dialog factory object.
    DialogManager	    *m_dialogManager;
    /// Currently loaded config objects.
    vector<const orxSTRING> m_objectList;
    /// Currently loaded config graphics.
    vector<const orxSTRING> m_graphicList;
    /// Currently loaded FXSlots.
    vector<const orxSTRING> m_fxSlotList;

    //! Modified project flag: reload object.
    bool m_dirty;
    //! Modified project flag: requires save upon exit.
    bool m_dirty_save;
    //! Modified project flag: used for auto save suppresion.
    bool m_dirty_autosave;
    //! Editor execution time.
    orxFLOAT m_localTime;
    //! Last auto save time stamp.
    orxFLOAT m_autoSaveTimeStamp;
    //! Interval used for auot saves.
    orxFLOAT m_autoSaveInterval;
    //! Name of currently open project file
    static std::string m_projectFileName;
};

#endif // ORXCRAFT_H

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
