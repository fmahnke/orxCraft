#ifndef __ConfigType_H__
#define __ConfigType_H__
/**
 * @file ConfigType.h
 * @date 2012-05-09
 * @author fritz@fritzmahnke.com
 *
 */

#include "orx/orx.h"

class ConfigType
{
public:
    static void FloatToString (orxFLOAT inFloat, orxSTRING outString);

    static const orxSTRING ListToString (const orxSTRING prop);

    static void VectorToString (const orxSTRING prop, orxU32 elementNum,
				orxSTRING outString);
};
#endif // __ConfigType_H__