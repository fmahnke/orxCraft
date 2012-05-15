/**
 * @file InfoWindow.h
 * @date 2012-06-04
 * @author fritz@fritzmahnke.com
 *
 */
#ifndef __InfoWindow_H__
#define __InfoWindow_H__

#include "ScrollFrameWindow.h"

class InfoWindow : public ScrollFrameWindow
{
public:
    virtual void Init (const orxSTRING widgetName);
    virtual const orxSTRING GetName ();
    virtual void HandleMouseClick   (const orxSTRING widgetName);
    virtual void HandleTextAccepted (const orxSTRING widgetName);
};

#endif	// __InfoWindow_H__