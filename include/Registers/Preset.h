
#ifndef R_PRESET_H
#define R_PRESET_H

#include "../Config.h"

#define REGID_PRESET 0x02
#define REG_PRESET_DEFAULT 0x00
#define Reg_Preset_Get() (RegisterGet(REGID_PRESET))
#define Reg_Preset_GetValue() (RegisterGetValue(REGID_PRESET))
#define Reg_Preset_Set(v) (RegisterSet(REGID_PRESET, v))
#define Reg_Preset_SetValue(v) (RegisterSetValue(REGID_PRESET, v))
#define Reg_Preset_Reset() (RegisterSet(REGID_PRESET, REG_PRESET_DEFAULT))

#define REG_PRESET_FLAG_PERSIST CONFIG_PRESETS_PERSISTMASK
#define Reg_Preset_GetPersist() (RegisterFlagGetValue(REGID_PRESET, REG_PRESET_FLAG_PERSIST) != 0x0)
#define Reg_Preset_SetPersist(e) (RegisterFlagSet(REGID_PRESET, REG_PRESET_FLAG_PERSIST, (e != 0x0)))
#define Reg_Preset_Toggle_Persist() (RegisterFlagToggle(REGID_PRESET, REG_PRESET_FLAG_PERSIST))

#define REG_PRESET_FLAG_CODE CONFIG_PRESETS_VALUEMASK
#define Reg_Preset_GetCode() (RegisterFlagGetValue(REGID_PRESET, REG_PRESET_FLAG_CODE))
#define Reg_Preset_SetCode(e) (RegisterFlagSet(REGID_PRESET, REG_PRESET_FLAG_CODE, e))

#endif
