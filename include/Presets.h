
#ifndef PRESETS_H
#define PRESETS_H

#include "Preset.h"
#include "Registers.h"

/////////////////
// Add Presets //
/////////////////
#include "Presets/Acknowledge.h"
#include "Presets/Beep.h"
#include "Presets/Corrected.h"
#include "Presets/Crash.h"
#include "Presets/Error.h"
#include "Presets/Ready.h"
#include "Presets/Siren.h"
#include "Presets/Warning.h"

//////////////////////
// Register Presets //
//////////////////////
#define PRESET_LIST     InitializePreset(PRESET_ACKNOWLEDGE, PRESET_ACKNOWLEDGE_DURATION, PRESET_ACKNOWLEDGE_HANDLER), \
                        InitializePreset(PRESET_BEEP, PRESET_BEEP_DURATION, PRESET_BEEP_HANDLER), \
                        InitializePreset(PRESET_CORRECTED, PRESET_CORRECTED_DURATION, PRESET_CORRECTED_HANDLER), \
                        InitializePreset(PRESET_CRASH, PRESET_CRASH_DURATION, PRESET_CRASH_HANDLER), \
                        InitializePreset(PRESET_ERROR, PRESET_ERROR_DURATION, PRESET_ERROR_HANDLER), \
                        InitializePreset(PRESET_READY, PRESET_READY_DURATION, PRESET_READY_HANDLER), \
                        InitializePreset(PRESET_SIREN, PRESET_SIREN_DURATION, PRESET_SIREN_HANDLER), \
                        InitializePreset(PRESET_WARNING, PRESET_WARNING_DURATION, PRESET_WARNING_HANDLER)

#define PRESET_LIST_COUNT 8



extern Preset Presets [];

/**
 * Gets the first preset matching the ID.
 * @param  id The ID to match.
 * @return    A pointer to the preset.
 */
Preset *FindPreset (unsigned char id);

/**
 * Checks if the preset exists.
 * @param  id The ID to match
 * @return    A success value.
 */
unsigned char PresetExists (unsigned char id);

#endif
