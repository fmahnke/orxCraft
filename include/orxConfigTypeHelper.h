#ifndef __ORXCONFIGTYPEHELPER_H__
#define __ORXCONFIGTYPEHELPER_H__
/**
 * @file orxConfigTypeHelper.h
 * @date 2012-05-09
 * @author fritz@fritzmahnke.com
 *
 */

#include "orx/orx.h"

class OrxConfigTypeHelper
{
public:
    static void FloatToString (orxFLOAT inFloat
					  , orxSTRING outString);

    static const orxSTRING ListToString (
					        const orxSTRING prop);

    static void VectorToString (const orxSTRING prop,
					             orxU32 elementNum, orxSTRING outString);
};
#endif // __ORXCONFIGTYPEHELPER_H__