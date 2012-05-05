#ifndef __OrxCraft_H_
#define __OrxCraft_H_

//! Includes
#define __NO_SCROLLED__ // Uncomment this define to prevent the embedded editor (ScrollEd) from being compiled
#include "Scroll.h"

#include "InfoWindow.h"

typedef struct
{
    orxLINKLIST_NODE orxLinkListNode;
    orxOBJECT *orxObject;
} configObject;

typedef struct
{
    orxLINKLIST_NODE orxLinkListNode;
    orxGRAPHIC *orxGraphic;
} configGraphic;

//! OrxCraft class
class OrxCraft : public Scroll<OrxCraft>
{
public:
    inline ScrollObject * GetSelectedObject () { return m_selectedObject; }
 
    OrxCraft ();

private:
  virtual orxSTATUS Init ();
  virtual orxSTATUS Run ();
  virtual void      Exit ();
  virtual void      BindObjects ();
  virtual void      Update(const orxCLOCK_INFO &_rstInfo);

  void SetupConfig ();

  ScrollObject *m_selectedObject;
  orxLINKLIST   m_objectList;
  orxLINKLIST   m_graphicList;
};
#endif // __OrxCraft_H_
