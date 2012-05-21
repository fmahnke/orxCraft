/**
 * @file OrxCraft.h
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 */
#ifndef __OrxCraft_H_
#define __OrxCraft_H_

//! Includes
//#define __NO_SCROLLED__ // Uncomment this define to prevent the embedded editor (ScrollEd) from being compiled
#include "Scroll.h"

#include <vector>

class InfoWindow;
class ObjectEditor;
class FXSlotEditorWindow;
class ScrollGUI;

// Inputs
static const orxSTRING inputQuit       = "Quit";
static const orxSTRING inputLeftMB     = "LeftClick";
static const orxSTRING inputLeftArrow  = "LeftArrow";
static const orxSTRING inputRightArrow = "RightArrow";
static const orxSTRING inputUpArrow    = "UpArrow";
static const orxSTRING inputDownArrow  = "DownArrow";

using std::vector;

//! Main OrxCraft program class
class OrxCraft : public Scroll<OrxCraft>
{
public:
    OrxCraft ();

    //! Get names of currently loaded objects
    inline vector<const orxSTRING>& GetObjectList () { return m_objectList; }
    //! Get selected object in Object Editor
    inline ScrollObject * GetSelectedObject () { return m_selectedObject; }
    //! Set selected object in Object Editor
    void SetSelectedObject (const orxSTRING name); 

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
    void SaveEditorConfig ();

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

    void OnMouseDown ();
    void OnMouseUp ();
    void OnKeyPress (const orxSTRING key);
    static orxSTATUS orxFASTCALL EventHandler (const orxEVENT *_pstEvent);

    static orxBOOL orxFASTCALL SaveConfigFunction
	(const orxSTRING _zSectionName,
         const orxSTRING _zKeyName,
	 const orxSTRING _zFileName,
	 orxBOOL _bUseEncryption);

    ScrollGUI               *m_scrollGUI;
    InfoWindow              *m_infoWindow;
    ObjectEditor            *m_objectEditor;
    FXSlotEditorWindow      *m_fxSlotEditorWindow;
    ScrollObject            *m_selectedObject;
    /// Currently loaded config objects
    vector<const orxSTRING> m_objectList;
    /// Currently loaded config graphics
    vector<const orxSTRING> m_graphicList;
    /// Currently loaded FXSlots
    vector<const orxSTRING> m_fxSlotList;

    bool m_dirty;
};
#endif // __OrxCraft_H_
