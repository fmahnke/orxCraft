/**
 * @file ScrollGUICEGUI.h
 * @date 2012-06-08
 * @author fritz@fritzmahnke.com
 *
 * The CEGUI implementation of a Scroll GUI
 */
#ifndef __SCROLLGUICEGUI_H__
#define __SCROLLGUICEGUI_H__

#include "Scroll.h"

#include "CEGUI.h"
#include "RendererModules/OpenGL/CEGUIOpenGLRenderer.h"

/**
 *  Renders GUI items and sends input from Scroll to them.
 */
class ScrollGUICEGUI : public ScrollObject
{
public:
    ScrollGUICEGUI ();

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

#endif  // __SCROLLGUICEGUI_H__