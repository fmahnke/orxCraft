/**
 * @file ConfigType.cpp
 * @date 2012-05-10
 * @author fritz@fritzmahnke.com
 *
 */

#include "ConfigType.h"

void ConfigType::FloatToString (const orxFLOAT inFloat,
					   orxSTRING outString)
{
    sprintf (outString, "%f", inFloat);
}

const orxSTRING ConfigType::ListToString (const orxSTRING prop)
{
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

void ConfigType::VectorToString (const orxSTRING prop,
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
