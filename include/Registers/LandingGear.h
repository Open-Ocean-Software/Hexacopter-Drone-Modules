
#ifndef R_LANDINGGEAR_H
#define R_LANDINGGEAR_H

#define REGID_LANDINGGEAR 0x0B
#define REG_LANDINGGEAR_DEFAULT 0x00
#define Reg_LandingGear_Get() (RegisterGet(REGID_LANDINGGEAR))
#define Reg_LandingGear_GetValue() (RegisterGetValue(REGID_LANDINGGEAR))
#define Reg_LandingGear_Set(v) (RegisterSet(REGID_LANDINGGEAR, v))
#define Reg_LandingGear_SetValue(v) (RegisterSetValue(REGID_LANDINGGEAR, v))
#define Reg_LandingGear_Reset() (RegisterSet(REGID_LANDINGGEAR, REG_LANDINGGEAR_DEFAULT))

#endif
