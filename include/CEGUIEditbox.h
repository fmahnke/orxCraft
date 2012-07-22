#ifndef __SCROLL_CEGUIEDITBOX_H__
#define __SCROLL_CEGUIEDITBOX_H__
/**
 * @file CEGUIEditbox.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollEditbox.h"

#include "CEGUI.h"

class WidgetManager;

/** CEGUI Implementation of an Editbox */
class CEGUIEditbox : public ScrollEditbox
{
public:
    explicit CEGUIEditbox (WidgetManager *manager);
    virtual void Init (const orxSTRING widgetName);

    void SetText (const orxSTRING windowName, const orxSTRING widgetName,
		  const orxSTRING text);
private:
    bool OnTextAccepted (const CEGUI::EventArgs &e);
};
#endif  // __SCROLL_CEGUIEDITBOX_H__