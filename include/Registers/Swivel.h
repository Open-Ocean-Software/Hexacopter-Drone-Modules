
#ifndef R_SWIVEL_H
#define R_SWIVEL_H

#define REGID_SWIVELX 0x0C
#define REG_SWIVELX_DEFAULT 0x00
#define Reg_SwivelX_Get() (RegisterGet(REGID_SWIVELX))
#define Reg_SwivelX_GetValue() (RegisterGetValue(REGID_SWIVELX))
#define Reg_SwivelX_Set(v) (RegisterSet(REGID_SWIVELX, v))
#define Reg_SwivelX_SetValue(v) (RegisterSetValue(REGID_SWIVELX, v))
#define Reg_SwivelX_Reset() (RegisterSet(REGID_SWIVELX, REG_SWIVELX_DEFAULT))


#define REGID_SWIVELY 0x0D
#define REG_SWIVELY_DEFAULT 0x00
#define Reg_SwivelY_Get() (RegisterGet(REGID_SWIVELY))
#define Reg_SwivelY_GetValue() (RegisterGetValue(REGID_SWIVELY))
#define Reg_SwivelY_Set(v) (RegisterSet(REGID_SWIVELY, v))
#define Reg_SwivelY_SetValue(v) (RegisterSetValue(REGID_SWIVELY, v))
#define Reg_SwivelY_Reset() (RegisterSet(REGID_SWIVELY, REG_SWIVELY_DEFAULT))

#endif
