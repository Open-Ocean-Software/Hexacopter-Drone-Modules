
#include "Presets.h"

struct Preset Presets [PRESET_LIST_COUNT] = { PRESET_LIST };

struct Preset *FindPreset (unsigned char id)
{
    for (unsigned char i = 0; i < PRESET_LIST_COUNT; i++) {
        if (Presets[i].Id == id) {
            return &(Presets[i]);
        }
    }
    return 0;
}

unsigned char PresetExists (unsigned char id)
{
    for (unsigned char i = 0; i < PRESET_LIST_COUNT; i++) {
        if (Presets[i].Id == id) {
            return 0x01;
        }
    }
    return 0x00;
}
