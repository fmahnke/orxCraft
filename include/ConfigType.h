#ifndef __ConfigType_H__
#define __ConfigType_H__
/**
 * @file ConfigType.h
 * @date 2012-05-09
 * @author fritz@fritzmahnke.com
 *
 */

#include "orx/orx.h"

/** Facility to help interacting with Orx config files */
class ConfigType
{
public:
    /** Convert an Orx float to an Orx string */
    static void FloatToString (orxFLOAT inFloat, orxSTRING outString);
    /** Convert an Orx config list to an Orx string */
    static const orxSTRING ListToString (const orxSTRING prop);
    /** Convert an Orx config vector to an Orx string */
    static void VectorToString (const orxSTRING prop, orxU32 elementNum,
				orxSTRING outString);
};
#endif // __ConfigType_H__