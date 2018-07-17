
#ifndef MODULES_H
#define MODULES_H

#include "Module.h"
#include "Registers.h"

#include <avr/io.h>

/////////////////
// Add Modules //
/////////////////
#include "Modules/Gimbal.h"
#include "Modules/LandingGear.h"
#include "Modules/Piezo.h"
#include "Modules/Projectiles.h"
#include "Modules/Swivel.h"
#include "Modules/Winch.h"

//////////////////////
// Register Modules //
//////////////////////
#define MODULELIST      InitializeModule(REGID_GIMBALX, DDR_GIMBAL_X, PORT_GIMBAL_X, MASK_GIMBAL_X, HANDLER_GIMBAL_X), \
                        InitializeModule(REGID_GIMBALY, DDR_GIMBAL_Y, PORT_GIMBAL_Y, MASK_GIMBAL_Y, HANDLER_GIMBAL_Y), \
                        InitializeModule(REGID_GIMBALZ, DDR_GIMBAL_Z, PORT_GIMBAL_Z, MASK_GIMBAL_Z, HANDLER_GIMBAL_Z), \
                        InitializeModule(REGID_LANDINGGEAR, DDR_LANDINGGEAR, PORT_LANDINGGEAR, MASK_LANDINGGEAR, HANDLER_LANDINGGEAR), \
                        InitializeModule(REGID_PIEZO, DDR_PIEZO, PORT_PIEZO, MASK_PIEZO, HANDLER_PIEZO), \
                        InitializeModule(REGID_PROJECTILES, DDR_PROJECTILES, PORT_PROJECTILES, MASK_PROJECTILES, HANDLER_PROJECTILES), \
                        InitializeModule(REGID_SWIVELX, DDR_SWIVEL_X, PORT_SWIVEL_X, MASK_SWIVEL_X, HANDLER_SWIVEL_X), \
                        InitializeModule(REGID_SWIVELY, DDR_SWIVEL_Y, PORT_SWIVEL_Y, MASK_SWIVEL_Y, HANDLER_SWIVEL_Y), \
                        InitializeModule(REGID_WINCH_POS, DDR_WINCH_POS, PORT_WINCH_POS, MASK_WINCH_POS, HANDLER_WINCH_POS), \
                        InitializeModule(RegID_WINCH_NEG, DDR_WINCH_NEG, PORT_WINCH_NEG, MASK_WINCH_NEG, HANDLER_WINCH_NEG)

#define MODULELIST_COUNT 10



extern Module Modules [];

/**
 * Initializes all modules.
 */
void InitializeModules (void);

#endif
