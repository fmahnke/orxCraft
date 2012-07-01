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

#include <vector>

class ScrollFrameWindow;

/**
 *  Renders GUI items and sends input from Scroll to them.
 */
class ScrollGUICEGUI
{
public:
    /** C-tor */
    ScrollGUICEGUI ();
    /** D-tor */
    ~ScrollGUICEGUI ();

    void Init ();
    void InputMouseMove ();
    void InputMouseDown ();
    void InputMouseUp ();
    void InputKeyPress (const orxSTRING orxKey);

    class CEGUIScrollObject : public ScrollObject
    {
	virtual void    OnCreate ();
	virtual void    OnDelete ();
	virtual orxBOOL OnRender ();
	/** Calculate and render the editor grid */
	void DrawGrid ();
    };

private:

    CEGUI::OpenGLRenderer *m_glRenderer;
    std::vector<ScrollFrameWindow *> m_frameWindows;
};

#endif  // SCROLLGUICEGUI_H_