/*
 *  Copyright (c) 2012 The orxCraft Project
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *     1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *  
 *     2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *  
 *     3. This notice may not be removed or altered from any source
 *     distribution.
 */

#ifndef __CEGUIPUSHBUTTON_H__
#define __CEGUIPUSHBUTTON_H__
/**
 * @file CEGUIPushButton.h
 * @date 2012-05-20
 * @author fritz@fritzmahnke.com
 *
 */

#include "ScrollPushButton.h"

#include "CEGUI.h"

class ScrollFrameWindow;

/** CEGUI Implementation of a Push Button */
class CEGUIPushButton : public ScrollPushButton
{
public:
    explicit CEGUIPushButton (ScrollFrameWindow *dialog);
    virtual void Init (const orxSTRING widgetName);
    virtual void Init (CEGUI::Window* widget);

    virtual void SetText (const orxSTRING text);

private:
    bool OnClicked (const CEGUI::EventArgs &e);

    CEGUI::PushButton *m_cePushButton;
};
#endif  // __CEGUIBUTTON_H__

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
