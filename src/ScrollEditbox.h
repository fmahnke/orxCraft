#ifndef __SCROLL_EDITBOX_H__
#define __SCROLL_EDITBOX_H__
/**
 * @file ScrollEditbox.h
 * @date 2012-05-08
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollWidget.h"

class ObjectEditor;

/**
 *  Base class for an Editbox widget.
 */
class ScrollEditbox : public ScrollWidget
{
public:
    explicit ScrollEditbox (ObjectEditor *manager) :
	m_manager (manager)
    {
    };
protected:
    ObjectEditor *m_manager;
};

#endif  // __SCROLL_EDITBOX_H__