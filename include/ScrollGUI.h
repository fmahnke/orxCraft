/**
 * @file ScrollGUI.h
 * @date 2012-06-04
 * @author fritz@fritzmahnke.com
 *
 */
#ifndef __SCROLLGUI_H__
#define __SCROLLGUI_H__

#include "Scroll.h"

#include "CEGUI.h"
#include "RendererModules/OpenGL/CEGUIOpenGLRenderer.h"

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