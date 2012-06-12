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

#include <vector>

using Rocket::Core::RenderInterface;
using Rocket::Core::SystemInterface; 
using Rocket::Core::ElementDocument; 
using Rocket::Core::Context;

using std::vector;

class RocketListener;

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
    static inline RocketListener *GetListener ()
    {
	return &m_rocketListener;
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

    RenderInterface           *m_renderInterface;
    SystemInterface           *m_sysInterface;
    vector<ElementDocument *>  m_documents;
    static Context            *m_context;
    static RocketListener      m_rocketListener;
};

#endif  // __SCROLLGUIROCKET_H__