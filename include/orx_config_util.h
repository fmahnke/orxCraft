#ifndef ORX_CONFIG_UTIL_H
#define ORX_CONFIG_UTIL_H
/**
 * @file orx_config_util.h
 * @date 2012-05-09
 * @author fritz@fritzmahnke.com
 *
 */

#include "orx/orx.h"

#include <vector>
using std::vector;

/**
 *  Facility to help interacting with Orx config files. All the functions
 *  below are designed to work with an Orx config section that has been
 *  previously pushed onto the stack.
 */
namespace orx_config_util
{
/** Convert an Orx bool to an Orx string */
void BoolToString (orxBOOL inBool, orxSTRING outString);
/** Convert an Orx float to an Orx string */
void FloatToString (orxFLOAT inFloat, orxSTRING outString);
/** Convert an Orx config list to an Orx string */
const orxSTRING ListToString (const orxSTRING prop);
/** Get all items in an Orx config list into a std::vector */
void GetListIntoVector (const orxSTRING key, vector<const orxSTRING> &list);
/** Convert an Orx config vector to an Orx string */
void VectorToString (const orxSTRING prop, orxU32 elementNum,
		     orxSTRING outString);
}   // namespace orx_config_util

#endif // ORX_CONFIG_UTIL_H

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
