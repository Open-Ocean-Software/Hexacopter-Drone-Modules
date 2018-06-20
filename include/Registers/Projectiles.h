
#ifndef R_PROJECTILES_H
#define R_PROJECTILES_H

#define REGID_PROJECTILES 0x10
#define REG_PROJECTILES_DEFAULT 0x00
#define Reg_Projectiles_Get() (RegisterGet(REGID_PROJECTILES))
#define Reg_Projectiles_GetValue() (RegisterGetValue(REGID_PROJECTILES))
#define Reg_Projectiles_Set(v) (RegisterSet(REGID_PROJECTILES, v))
#define Reg_Projectiles_SetValue(v) (RegisterSetValue(REGID_PROJECTILES, v))
#define Reg_Projectiles_Reset() (RegisterSet(REGID_PROJECTILES, REG_PROJECTILES_DEFAULT))

#endif
