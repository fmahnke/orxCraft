#ifndef SCROLLGUICEGUI_H_
#define SCROLLGUICEGUI_H_
/**
 * @file ScrollGUICEGUI.h
 * @date 2012-06-08
 * @author fritz@fritzmahnke.com
 *
 * The CEGUI implementation of a Scroll GUI
 */
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

    void InputMouseMove ();
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

#endif  // SCROLLGUICEGUI_H_