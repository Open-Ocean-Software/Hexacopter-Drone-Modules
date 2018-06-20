
#ifndef R_PIEZO_H
#define R_PIEZO_H

#define REGID_PIEZO 0x0E
#define REG_PIEZO_DEFAULT 0x00
#define Reg_Piezo_Get() (RegisterGet(REGID_PIEZO))
#define Reg_Piezo_GetValue() (RegisterGetValue(REGID_PIEZO))
#define Reg_Piezo_Set(v) (RegisterSet(REGID_PIEZO, v))
#define Reg_Piezo_SetValue(v) (RegisterSetValue(REGID_PIEZO, v))
#define Reg_Piezo_Reset() (RegisterSet(REGID_PIEZO, REG_PIEZO_DEFAULT))

#endif
