/**
 * @file OrxCraft.h
 * @date 2012-06-04
 * @author fritz@fritzmahnke.com
 *
 */
#ifndef __OrxCraft_H_
#define __OrxCraft_H_

//! Includes
#define __NO_SCROLLED__ // Uncomment this define to prevent the embedded editor (ScrollEd) from being compiled
#include "Scroll.h"

#include <vector>

#include "ScrollGUI.h"
#include "InfoWindow.h"

class ObjectEditor;
class FXSlotEditorWindow;

// Inputs
static const orxSTRING inputQuit       = "Quit";
static const orxSTRING inputLeftMB     = "LeftClick";
static const orxSTRING inputLeftArrow  = "LeftArrow";
static const orxSTRING inputRightArrow = "RightArrow";
static const orxSTRING inputUpArrow    = "UpArrow";
static const orxSTRING inputDownArrow  = "DownArrow";

using std::vector;

//! OrxCraft class
class OrxCraft : public Scroll<OrxCraft>
{
public:
    OrxCraft ();

    inline vector<const orxSTRING> & GetObjectList () { return m_objectList; }
    inline ScrollObject * GetSelectedObject () { return m_selectedObject; }
    void SetSelectedObject (const orxSTRING name); 

    ScrollObject * GetObjectByName (const orxSTRING name) const;

    void SetupConfig ();
    void NeedObjectUpdate ();

private:
  virtual orxSTATUS Init ();
  virtual orxSTATUS Run ();
  virtual void      Exit ();
  virtual void      BindObjects ();
  virtual void      Update(const orxCLOCK_INFO &_rstInfo);


    void InitConfig ();

  void OnMouseDown ();
  void OnMouseUp ();
  void OnKeyPress (const orxSTRING key);
  static orxSTATUS orxFASTCALL EventHandler(const orxEVENT *_pstEvent);

  ScrollGUI                *m_scrollGUI;
  InfoWindow               *m_infoWindow;
  ObjectEditor             *m_objectEditor;
  FXSlotEditorWindow	   *m_fxSlotEditorWindow;
  ScrollObject             *m_selectedObject;
  vector<const orxSTRING>  m_objectList;
  vector<const orxSTRING>  m_graphicList;

  bool m_dirty;
};
#endif // __OrxCraft_H_
