/**
 * @file ScrollGUI.h
 * @date 2012-05-04
 * @author fritz@fritzmahnke.com
 *
 * @todo As of now, ScrollGUI is specific to a CEGUI representation of
 * the user interface. This class should be abstracted so the code does
 * not depend on a CEGUI implementation of user interface.
 */
#ifndef __SCROLLGUI_H__
#define __SCROLLGUI_H__

#include "Scroll.h"

#include "CEGUI.h"
#include "RendererModules/OpenGL/CEGUIOpenGLRenderer.h"

/**
 *  Renders GUI items and sends input from Scroll to them.
 */
class ScrollGUI : public ScrollObject
{
public:
    ScrollGUI ();

    void Input ();
    void InputMouseDown ();
    void InputMouseUp ();
    void InputKeyPress (const orxSTRING orxKey);

private:
    virtual void    OnCreate ();
    virtual void    OnDelete ();
    virtual orxBOOL OnRender ();

    /** Calculate and render the editor grid */
    void DrawGrid ();

    CEGUI::OpenGLRenderer *m_glRenderer;
};

#endif  // __SCROLLGUI_H__