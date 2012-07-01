/**
 * @file DialogManager.h
 * @date 2012-05-11
 * @author fritz@fritzmahnke.com
 *
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