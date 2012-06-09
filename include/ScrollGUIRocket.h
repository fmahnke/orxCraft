/**
 * @file ScrollGUIRocket.h
 * @date 2012-06-08
 * @author fritz@fritzmahnke.com
 *
 * The libRocket implementation of a Scroll GUI.
 */
#ifndef __SCROLLGUIROCKET_H__
#define __SCROLLGUIROCKET_H__

#include "Scroll.h"
#include "Rocket/Core.h"

/**
 *  Renders GUI items and sends input from Scroll to them.
 */
class ScrollGUIRocket : public ScrollObject
{
public:
    class OrxSystemInterface : public Rocket::Core::SystemInterface
    {
    public:
	virtual float GetElapsedTime ()
	{
	    const orxCLOCK *mainClock = orxClock_FindFirst (orx2F (-1.0),
							    orxCLOCK_TYPE_CORE);
	    const orxCLOCK_INFO *info = orxClock_GetInfo (mainClock);
	    return info->fTime;
	};
    };

    ScrollGUIRocket ();

    static inline Rocket::Core::Context *GetContext ()
    {
	return m_context;
    }
    void Input ();
    void InputMouseDown ();
    void InputMouseUp ();
    void InputKeyPress (const orxSTRING orxKey);

private:
    virtual void    OnCreate ();
    virtual void    OnDelete ();
    virtual orxBOOL OnRender ();
    virtual void    Update(const orxCLOCK_INFO &_rstInfo);

    Rocket::Core::RenderInterface *m_renderInterface;
    Rocket::Core::SystemInterface *m_sysInterface;
    Rocket::Core::ElementDocument *m_document;
    static Rocket::Core::Context *m_context;
};

#endif  // __SCROLLGUIROCKET_H__