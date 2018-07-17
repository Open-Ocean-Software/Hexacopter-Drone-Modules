
#include "Controller.h"
#include "Config.h"
#include "Registers.h"
#include "Modules.h"
#include "Communications.h"
#include "Presets.h"
#include "Storage.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


void executeModules (void)
{
    double t;
    double cycleProg;
    for (unsigned char i = 0; i < MODULELIST_COUNT; i++) {
        t = ReadStopwatch();
        cycleProg = t - (double)((int)(t / CONFIG_CONTROLLER_PWMFREQUENCY));
        Module *mod = &Modules[i];
        mod->Handler(mod, (int)(t * CONFIG_CONTROLLER_CYCLEPRESCALER));
    }
}

void executePresets (void)
{
    static unsigned char presetCodeSave = 0x00;
    unsigned char presetCode = Reg_Preset_GetCode();
    if (presetCode == 0x00) {
        return;
    }
    if (!PresetExists(presetCode)) {
        return;
    }

    struct Preset *preset = FindPreset(presetCode);
    if (presetCode != presetCodeSave) {
        preset->StartTime = ReadStopwatch();
    }
    if (ReadStopwatch() - preset->StartTime >= preset->MaxDuration) {
        if (Reg_Preset_GetPersist()) {
            preset->StartTime = ReadStopwatch();
        } else {
            Reg_Preset_SetCode(0x00);
        }
    }

    preset->Callback(ReadStopwatch());
    presetCodeSave = presetCode;
}

void executeAddOn (void)
{
    unsigned char code = Reg_AddOn_GetCode();
    unsigned char addr;
    unsigned int *control;
    unsigned int *status;

    if (!Reg_AddOn_GetPassThru()) {
        if (AddOnExists(addr)) {
            AddOn *addon = FindAddOn(code);
            addr = addon->Address;
            control = &(addon->Control);
            status = &(addon->Status);
        } else {
            Reg_AddOn_Reset();
            return;
        }
    } else {
        addr = code;
    }

    *control = (Reg_AddOnCtrlH_GetValue() << 8) | Reg_AddOnCtrlL_GetValue();
    unsigned char addonctrlh = Reg_AddOnCtrlH_GetValue();
    unsigned char addonctrll = Reg_AddOnCtrlL_GetValue();
    unsigned char controlData = { addonctrlh, addonctrll };
    TWIWriteBytes(addr, controlData, sizeof(unsigned int));
    unsigned char statusData [sizeof(unsigned int)];
    TWIReadBytes(addr, statusData, sizeof(unsigned int));
    Reg_AddOnStatH_SetValue(statusData[0]);
    Reg_AddOnStatL_SetValue(statusData[1]);
    *status = (statusData[0] << 8) | statusData[1];
}

void executeExecutables (void)
{
    if (Reg_Control_GetReset()) {
        ResetRegisters(Registers, REGISTERLIST_COUNT);
    }
    if (Reg_AddOnCtrlL_GetValue() || Reg_AddOnCtrlH_GetValue()) {
        executeAddOns();
    }
}

void Activity (void)
{
    LoadRegisters(Registers, REGISTERLIST_COUNT);
    InitializeComponents();
    while (Reg_Control_GetEnabled()) {
        ReadCommunications();
        executeExecutables();
        executeModules();
        executePresets();
    }
    SaveRegisters(Registers, REGISTERLIST_COUNT);
}

void Standby (void)
{
    while (!Reg_Control_GetEnabled()) {
        _delay_ms(CONFIG_CONTROLLER_STANDBYTIMEOUT);
        ReadCommunications();
    }
}


double elapsedTime;

void InitializeStopwatch (void)
{
    // Resets the timer on overflow.
    TIMSK |= (1 << TOIE0);
    // F = F_CPU / 64
    TCCR0 &= (1 << CS02);
    TCCR0 |= (1 << CS01) | (1 << CS00);
    // Fc = 0.001s
    TCNT0 = (unsigned char)((double)CONFIG_F_CPU / (double)CONFIG_CONTROLLER_SWPRESCALER / (double)CONFIG_CONTROLLER_SWFREQUENCY);
    // Enable global interrupts
    sei();

    elapsedTime = 0.0;
}

void StopwatchHandler (void)
{
    elapsedTime += 1.0 / (double)CONFIG_CONTROLLER_SWFREQUENCY;
}

double ReadStopwatch (void)
{
    return elapsedTime;
}

void ResetStopwatch (void)
{
    elapsedTime = 0.0;
}
