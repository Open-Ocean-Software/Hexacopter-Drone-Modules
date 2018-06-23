
#ifndef P_ACKNOWLEDGE_H
#define P_ACKNOWLEDGE_H

#define PRESET_ACKNOWLEDGE 0x01
#define PRESET_ACKNOWLEDGE_DURATION 1.0
#define PRESET_ACKNOWLEDGE_HANDLER Preset_Acknowledge_Handler

void Preset_Acknowledge_Handler (double t);

#endif
