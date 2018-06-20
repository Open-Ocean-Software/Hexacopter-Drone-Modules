
#ifndef R_GIMBAL_H
#define R_GIMBAL_H

#define REGID_GIMBALX 0x08
#define REG_GIMBALX_DEFAULT 0x00
#define Reg_GimbalX_Get() (RegisterGet(REGID_GIMBALX))
#define Reg_GimbalX_GetValue() (RegisterGetValue(REGID_GIMBALX))
#define Reg_GimbalX_Set(v) (RegisterSet(REGID_GIMBALX, v))
#define Reg_GimbalX_SetValue(v) (RegisterSetValue(REGID_GIMBALX, v))
#define Reg_GimbalX_Reset() (RegisterSet(REGID_GIMBALX, REG_GIMBALX_DEFAULT))


#define REGID_GIMBALY 0x09
#define REG_GIMBALY_DEFAULT 0x00
#define Reg_GimbalY_Get() (RegisterGet(REGID_GIMBALY))
#define Reg_GimbalY_GetValue() (RegisterGetValue(REGID_GIMBALY))
#define Reg_GimbalY_Set(v) (RegisterSet(REGID_GIMBALY, v))
#define Reg_GimbalY_SetValue(v) (RegisterSetValue(REGID_GIMBALY, v))
#define Reg_GimbalY_Reset() (RegisterSet(REGID_GIMBALY, REG_GIMBALY_DEFAULT))


#define REGID_GIMBALZ 0x0A
#define REG_GIMBALZ_DEFAULT 0x00
#define Reg_GimbalZ_Get() (RegisterGet(REGID_GIMBALZ))
#define Reg_GimbalZ_GetValue() (RegisterGetValue(REGID_GIMBALZ))
#define Reg_GimbalZ_Set(v) (RegisterSet(REGID_GIMBALZ, v))
#define Reg_GimbalZ_SetValue(v) (RegisterSetValue(REGID_GIMBALZ, v))
#define Reg_GimbalZ_Reset() (RegisterSet(REGID_GIMBALZ, REG_GIMBALZ_DEFAULT))

#endif
