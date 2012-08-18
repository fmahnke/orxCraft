/**
 * @file orx_config_util.cpp
 * @date 2012-05-10
 * @author fritz@fritzmahnke.com
 *
 */

#include "orx_config_util.h"

namespace orx_config_util
{

void BoolToString (orxBOOL inBool, orxSTRING outString)
{
    if (inBool)
    {
	sprintf (outString, "%s", "true");
    }
    else
    {
	sprintf (outString, "%s", "false");
    }
}

void FloatToString (const orxFLOAT inFloat,
					   orxSTRING outString)
{
    sprintf (outString, "%f", inFloat);
}

const orxSTRING ListToString (const orxSTRING prop)
{
    orxASSERT (prop != orxNULL);

    char newBuffer[2048];
    char buffer[2048];
    buffer[0] = '\0';
    const char *separator = " # ";

    orxS32 counter = orxConfig_GetListCounter (prop);
    for (int i = 0; i < counter; i++)
    {
	const orxSTRING propAsString = orxConfig_GetListString (prop, i);
	sprintf (newBuffer, "%s", propAsString);
	// At least one more property after this one?
	if (i + 1 < counter)
	{
	    strcat (newBuffer, separator);
	}
	strcat (buffer, newBuffer);
    }

    return buffer;
}

void GetListIntoVector (const orxSTRING key, vector<const orxSTRING> &list)
{
    orxASSERT (key != orxNULL);
    
    int counter = orxConfig_GetListCounter (key);
    // Iterate over all list items
    for (int i = 0; i < counter; i++)
    {
	// Get and store next item
	const orxSTRING property = orxConfig_GetListString (key, i);
	list.push_back (property);
    }
}

void VectorToString (const orxSTRING prop,
				 orxU32 elementNum, orxSTRING outString)
{
    orxASSERT (elementNum < 3);

    orxVECTOR propertyAsVector;
    orxConfig_GetVector (prop, &propertyAsVector);

    switch (elementNum)
    {
    case 0:
	sprintf (outString, "%f", propertyAsVector.fX);
	break;
    case 1:
	sprintf (outString, "%f", propertyAsVector.fY);
	break;
    case 2:
	sprintf (outString, "%f", propertyAsVector.fZ);
    }
}

}   // namespace orx_config_util

// vim: tabstop=8 shiftwidth=4 softtabstop=4 noexpandtab
