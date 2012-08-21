/*
 *  Copyright (c) 2012 The orxCraft Project
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *     1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *  
 *     2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *  
 *     3. This notice may not be removed or altered from any source
 *     distribution.
 */

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

    ScrollGUICEGUI	    *m_gui;

    DialogManager	    *m_dialogManager;
    /// Currently loaded config objects
    vector<const orxSTRING> m_objectList;
    /// Currently loaded config graphics
    vector<const orxSTRING> m_graphicList;
    /// Currently loaded FXSlots
    vector<const orxSTRING> m_fxSlotList;

    bool m_dirty;
};

#endif // ORXCRAFT_H

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
