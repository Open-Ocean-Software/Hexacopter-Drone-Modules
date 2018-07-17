
#ifndef ADDONS_H
#define ADDONS_H

#include "AddOn.h"

#include <avr/io.h>

////////////////
// Add AddOns //
////////////////
#include "AddOns/Dropper.h"

/////////////////////
// Register AddOns //
/////////////////////
#define ADDONLIST   InitializeAddOn(ADDON_DROPPER_CODE, ADDON_DROPPER_ADDRESS)

#define ADDONLIST_COUNT 1



extern AddOn AddOns [];

/**
 * Gets the first addon matching the ID.
 * @param  id The ID to match.
 * @return    A pointer to the addon.
 */
AddOn *FindAddOn (unsigned char id);

/**
 * Checks if the addon exists.
 * @param  id The ID to match.
 * @return    A success value.
 */
unsigned char AddOnExists (unsigned char id);

#endif
