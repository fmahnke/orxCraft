#ifndef __SCROLL_CHECKBOX_H__
#define __SCROLL_CHECKBOX_H__
/**
 * @file ScrollCheckbox.h
 * @date 2012-05-07
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollWidget.h"

class ObjectEditor;

/**
 *  Interface for a Checkbox widget.
 */
class ScrollCheckbox : public ScrollWidget
{
public:
    explicit ScrollCheckbox (ObjectEditor *manager) :
	m_manager (manager)
    {
    };
protected:
    virtual void SignalCheckStateChanged () = 0;
    ObjectEditor *m_manager;
};

#endif  // __SCROLL_CHECKBOX_H__