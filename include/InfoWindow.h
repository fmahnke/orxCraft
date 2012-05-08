/**
 * @file InfoWindow.h
 * @date 2012-06-04
 * @author fritz@fritzmahnke.com
 *
 */
#ifndef __InfoWindow_H__
#define __InfoWindow_H__

#include "Scroll.h"

#include "CEGUI.h"
#include "ListBox.h"

class InfoWindow : public ScrollObject
{
public:
    InfoWindow ();
private:
    // Scroll events
    virtual void     OnCreate ();
    virtual void     OnDelete ();
    virtual void     Update(const orxCLOCK_INFO &_rstInfo);

    // Other events
    bool OnMouseClick       (const CEGUI::EventArgs &e);
    bool OnSelectionChanged (const CEGUI::EventArgs &e);

    CEGUI::Window    *m_infoWindow;
    ListBox          *m_listBox;
};

#endif	// __InfoWindow_H__