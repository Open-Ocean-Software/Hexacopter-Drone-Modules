
#ifndef PRESET_H
#define PRESET_H

typedef void (*PresetCallback) (double t);

typedef struct
{
    unsigned char Id;
    double StartTime;
    double MaxDuration;
    PresetCallback Callback;
} Preset;

/**
 * Creates a new preset with initialized values.
 * @param  id       The ID of the preset.
 * @param  duration The duration of activity (< 0 to persist)
 * @param  callback The routine callback on system cycles.
 * @return          The new preset.
 */
#define InitializePreset(id, duration, callback) { id, 0.0, duration, &callback }

#endif
