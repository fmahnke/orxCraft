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

    //! Get names of currently loaded objects
    inline vector<const orxSTRING>& GetObjectList () { return m_objectList; }
    //! Get names of currently loaded FXSlots
    inline vector<const orxSTRING>& GetFXSlotList () { return m_fxSlotList; }
    //! Set selected FXSlot in FXSlot Editor
    void SetSelectedFXSlot (const orxSTRING name);

    //! Get names of currently loaded Graphics
    inline vector<const orxSTRING>& GetGraphicList () { return m_graphicList; }

    ScrollObject * GetObjectByName (const orxSTRING name) const;

    //! Setup loaded config section lists and create objects
    void SetupConfig ();
    //! Save the editor configuration to a file
    orxSTATUS SaveEditorConfig () const;

    /** 
     *  Indicate properties have been changed and objects need to be updated
     *  to reflect that change.
     */
    void NeedObjectUpdate ();

private:
    virtual orxSTATUS Init ();
    virtual orxSTATUS Run ();
    virtual void      Exit ();
    virtual void      BindObjects ();
    virtual void      Update (const orxCLOCK_INFO &_rstInfo);

    /** Load config file for editing */
    void InitConfig ();
    /** Load from config user settings */
    void UserSettings ();

    void OnMouseDown ();
    void OnMouseUp ();
    void OnKeyPress (const orxSTRING key);
    
    orxSTATUS SaveBackup() const;
    orxSTATUS AddActionDisplay(const orxSTRING _zAction) const;

    static orxSTATUS orxFASTCALL EventHandler (const orxEVENT *_pstEvent);
    static orxBOOL orxFASTCALL SaveConfigFunction
	(const orxSTRING _zSectionName,
         const orxSTRING _zKeyName,
	 const orxSTRING _zFileName,
	 orxBOOL _bUseEncryption);
    /** Process command line parameters */
    static orxSTATUS orxFASTCALL ProcessParams(
	    orxU32 _u32ParamCount, const orxSTRING _azParams[]);

    ScrollGUICEGUI	    *m_gui;

    DialogManager	    *m_dialogManager;
    /// Currently loaded config objects
    vector<const orxSTRING> m_objectList;
    /// Currently loaded config graphics
    vector<const orxSTRING> m_graphicList;
    /// Currently loaded FXSlots
    vector<const orxSTRING> m_fxSlotList;

    bool m_dirty;
    bool m_dirty_save;
    bool m_dirty_autosave;
    orxFLOAT m_localTime;
    orxFLOAT m_autoSaveTimeStamp;
    orxFLOAT m_autoSaveInterval;
    static std::string m_projectFileName;
};

#endif // ORXCRAFT_H

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
