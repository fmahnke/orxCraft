/**
 * @file RocketListener.h
 * @date 2012-06-09
 * @author fritz@fritzmahnke.com
 *
 * Event listener for libRocket
 */
#ifndef __ROCKETLISTENER_H__
#define __ROCKETLISTENER_H__

#include "Rocket/Core.h"

class RocketListener : public Rocket::Core::EventListener
{
    /// Process the incoming Event
    virtual void ProcessEvent (Rocket::Core::Event &event);
};

#endif	// __ROCKETLISTENER_H__