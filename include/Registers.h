
#ifndef REGISTERS_H
#define REGISTERS_H

#include "Register.h"

///////////////////
// Add Registers //
///////////////////
#include "Registers/Control.h"
#include "Registers/Preset.h"
#include "Registers/AddOn.h"
#include "Registers/Gimbal.h"
#include "Regsiters/LandingGear.h"
#include "Registers/Swivel.h"
#include "Registers/Piezo.h"
#include "Registers/Winch.h"
#include "Registers/Projectiles.h"

////////////////////////
// Register Registers //
////////////////////////
#define REGISTERLIST    InitializeRegister(REGID_CONTROL, REG_CONTROL_DEFAULT), \
                        InitializeRegister(REGID_PRESET, REG_PRESET_DEFAULT), \
                        InitializeRegister(REGID_ADDON, REG_ADDON_DEFAULT), \
                        InitializeRegister(REGID_ADDON_CTRL_L, REG_ADDON_CTRL_L_DEFAULT), \
                        InitializeRegister(REGID_ADDON_CTRL_H, REG_ADDON_CTRL_H_DEFAULT), \
                        InitializeRegister(REGID_ADDON_STAT_L, REG_ADDON_STAT_L_DEFAULT), \
                        InitializeRegister(REGID_ADDON_STAT_H, REG_ADDON_STAT_H_DEFAULT), \
                        InitializeRegister(REGID_GIMBALX, REG_GIMBALX_DEFAULT), \
                        InitializeRegister(REGID_GIMBALY, REG_GIMBALY_DEFAULT), \
                        InitializeRegister(REGID_GIMBALZ, REG_GIMBALZ_DEFAULT), \
                        InitializeRegister(REGID_LANDINGGEAR, REG_LANDINGGEAR_DEFAULT), \
                        InitializeRegister(REGID_SWIVELX, REG_SWIVELX_DEFAULT), \
                        InitializeRegister(REGID_SWIVELY, REG_SWIVELY_DEFAULT), \
                        InitializeRegister(REGID_PIEZO, REG_PIEZO_DEFAULT), \
                        InitializeRegister(REGID_WINCH, REG_WINCH_DEFAULT), \
                        InitializeRegister(REGID_PROJECTILES, REG_PROJECTILES_DEFAULT)

#define REGISTERLIST_COUNT 16



extern Register Registers [];

/**
 * Gets the first register with the ID.
 * @param  id The ID to match.
 * @return    A pointer to the register.
 */
Register *FindRegister (unsigned char id);

/**
 * Checks if the register exists.
 * @param  id The ID to match.
 * @return    A success value.
 */
unsigned char RegisterExists (unsigned char id);

#endif
