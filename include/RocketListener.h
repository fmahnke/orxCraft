#ifndef ROCKETLISTENER_H_
#define ROCKETLISTENER_H_
/**
 * @file RocketListener.h
 * @date 2012-06-09
 * @author fritz@fritzmahnke.com
 *
 * Event listener for libRocket
 */
#include "Rocket/Core.h"

class WidgetManager;

class RocketListener : public Rocket::Core::EventListener
{
public:
    RocketListener (WidgetManager *manager) :
	m_widgetManager (manager) { }
    /// Process the incoming Event
    virtual void ProcessEvent (Rocket::Core::Event &event);

private:
    WidgetManager *m_widgetManager;
};

#endif	// ROCKETLISTENER_H_