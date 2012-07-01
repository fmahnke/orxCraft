/**
 * @file CEDialogManager.h
 * @date 2012-07-01
 * @author fritz@fritzmahnke.com
 *
 */

#include "DialogManager.h"

class CEDialogManager : public DialogManager
{
public:
    virtual void MakeDialog (const orxSTRING dialogName);
};