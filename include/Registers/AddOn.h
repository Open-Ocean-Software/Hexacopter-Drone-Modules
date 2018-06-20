
#ifndef R_ADDON_H
#define R_ADDON_H

#include "../Config.h"

#define REGID_ADDON 0x03
#define REG_ADDON_DEFAULT 0x00
#define Reg_AddOn_Get() (RegisterGet(REGID_ADDON))
#define Reg_AddOn_GetValue() (RegisterGetValue(REGID_ADDON))
#define Reg_AddOn_Set(v) (RegisterSet(REGID_ADDON, v))
#define Reg_AddOn_SetValue(v) (RegisterSetValue(REGID_ADDON, v))
#define Reg_AddOn_Reset() (RegisterSet(REGID_ADDON, REG_ADDON_DEFAULT))

#define REG_ADDON_FLAG_PASSTHRU CONFIG_ADDON_PASSTHRUMASK
#define Reg_AddOn_GetPassThru() (RegisterFlagGetValue(REGID_ADDON, REG_ADDON_FLAG_PASSTHRU) != 0x0)
#define Reg_AddOn_SetPassThru(e) (RegisterFlagSet(REGID_ADDON, REG_ADDON_FLAG_PASSTHRU, (e != 0x0)))
#define Reg_AddOn_Toggle_PassThru() (RegisterFlagToggle(REGID_ADDON, REG_ADDON_FLAG_PASSTHRU))

#define REG_CONTROL_FLAG_CODE CONFIG_ADDON_VALUEMASK
#define Reg_AddOn_GetCode() (RegisterFlagGetValue(REGID_CONTROL, REG_CONTROL_FLAG_CODE) != 0x0)
#define Reg_AddOn_SetCode(e) (RegisterFlagSet(REGID_CONTROL, REG_CONTROL_FLAG_CODE, (e != 0x0)))
#define Reg_AddOn_Toggle_Code() (RegisterFlagToggle(REGID_CONTROL, REG_CONTROL_FLAG_CODE))



#define REGID_ADDON_CTRL_L 0x04
#define REG_ADDON_CTRL_L_DEFAULT 0x00
#define Reg_AddOnCtrlL_Get() (RegisterGet(REGID_ADDON_CTRL_L))
#define Reg_AddOnCtrlL_GetValue() (RegisterGetValue(REGID_ADDON_CTRL_L))
#define Reg_AddOnCtrlL_Set(v) (RegisterSet(REGID_ADDON_CTRL_L, v))
#define Reg_AddOnCtrlL_SetValue(v) (RegisterSetValue(REGID_ADDON_CTRL_L, v))
#define Reg_AddOnCtrlL_Reset() (RegisterSet(REGID_ADDON_CTRL_H, REG_ADDON_CTRL_L_DEFAULT))
#define REGID_ADDON_CTRL_H 0x05
#define REG_ADDON_CTRL_H_DEFAULT 0x00
#define Reg_AddOnCtrlH_Get() (RegisterGet(REGID_ADDON_CTRL_H))
#define Reg_AddOnCtrlH_GetValue() (RegisterGetValue(REGID_ADDON_CTRL_H))
#define Reg_AddOnCtrlH_Set(v) (RegisterSet(REGID_ADDON_CTRL_H, v))
#define Reg_AddOnCtrlH_SetValue(v) (RegisterSetValue(REGID_ADDON_CTRL_H, v))
#define Reg_AddOnCtrlH_Reset() (RegisterSet(REGID_ADDON_CTRL_H, REG_ADDON_CTRL_H_DEFAULT))


#define REGID_ADDON_STAT_L 0x06
#define REG_ADDON_STAT_L_DEFAULT 0x00
#define Reg_AddOnStatL_Get() (RegisterGet(REGID_ADDON_STAT_L))
#define Reg_AddOnStatL_GetValue() (RegisterGetValue(REGID_ADDON_STAT_L))
#define Reg_AddOnStatL_Set(v) (RegisterSet(REGID_ADDON_STAT_L, v))
#define Reg_AddOnStatL_SetValue(v) (RegisterSetValue(REGID_ADDON_STAT_L, v))
#define Reg_AddOnStatL_Reset() (RegisterSet(REGID_ADDON_STAT_H, REG_ADDON_STAT_L_DEFAULT))
#define REGID_ADDON_STAT_H 0x07
#define REG_ADDON_STAT_H_DEFAULT 0x00
#define Reg_AddOnStatH_Get() (RegisterGet(REGID_ADDON_STAT_H))
#define Reg_AddOnStatH_GetValue() (RegisterGetValue(REGID_ADDON_STAT_H))
#define Reg_AddOnStatH_Set(v) (RegisterSet(REGID_ADDON_STAT_H, v))
#define Reg_AddOnStatH_SetValue(v) (RegisterSetValue(REGID_ADDON_STAT_H, v))
#define Reg_AddOnStatH_Reset() (RegisterSet(REGID_ADDON_STAT_H, REG_ADDON_STAT_H_DEFAULT))

#endif
