
#ifndef ADDON_H
#define ADDON_H

#include "Config.h"

typedef struct
{
    unsigned char Id;
    unsigned char Address;
    unsigned int Status;
    unsigned int Control;
} Addon;

/**
 * Initializes a new addon with initialized arguments.
 * @param  id   The Id of the addon.
 * @param  addr The address of the addon's module.
 * @return      The new addon.
 */
#define InitializeAddOn(id, addr) { .Id = id, .Address = addr, .Status = 0x0000, .Control = CONFIG_ADDON_DEFAULTCONTROL }

#endif
