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
