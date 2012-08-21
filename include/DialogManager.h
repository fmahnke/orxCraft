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

/**
 * @file DialogManager.h
 * @date 2012-05-11
 * @author fritz@fritzmahnke.com
 *
 * The Dialog Manager is responsible for creating the program's various user
 * interfaces and their widgets (controls). The DialogManager base class is the
 * interface inherited by concrete implementations.
 */
#ifndef DIALOGMANAGER_H_
#define DIALOGMANAGER_H_

#include "Scroll.h"

class DialogManager
{
public:
    virtual void MakeDialog (const orxSTRING dialogName) = 0;
};

#endif	// DIALOGMANAGER_H_

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
