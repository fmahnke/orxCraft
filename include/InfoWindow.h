#ifndef __InfoWindow_H__
#define __InfoWindow_H__

#include "Scroll.h"

class InfoWindow : public ScrollObject
{
private:
    virtual void     OnCreate ();
    virtual void     OnDelete ();
    virtual orxBOOL  OnRender ();
    virtual void     Update(const orxCLOCK_INFO &_rstInfo);
};

#endif	// __InfoWindow_H__