
#ifndef R_CONTROL_H
#define R_CONTROL_H

#define REGID_CONTROL 0x01
#define REG_CONTROL_DEFAULT 0x3F
#define Reg_Control_Get() (RegisterGet(REGID_CONTROL))
#define Reg_Control_GetValue() (RegisterGetValue(REGID_CONTROL))
#define Reg_Control_Set(v) (RegisterSet(REGID_CONTROL, v))
#define Reg_Control_SetValue(v) (RegisterSetValue(REGID_CONTROL, v))
#define Reg_Control_Reset() (RegisterSet(REGID_CONTROL, REG_CONTROL_DEFAULT))


#define REG_CONTROL_FLAG_ENABLE 0x01
#define Reg_Control_GetEnabled() (RegisterFlagGetValue(REGID_CONTROL, REG_CONTROL_FLAG_ENABLE) != 0x0)
#define Reg_Control_SetEnabled(e) (RegisterFlagSet(REGID_CONTROL, REG_CONTROL_FLAG_ENABLE, (e != 0x0)))
#define Reg_Control_Toggle_Enabled() (RegisterFlagToggle(REGID_CONTROL, REG_CONTROL_FLAG_ENABLE))

#define REG_CONTROL_FLAG_ENABLEMOTORS 0x02
#define Reg_Control_GetEnabledMotors() (RegisterFlagGetValue(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEMOTORS) != 0x0)
#define Reg_Control_SetEnabledMotors(e) (RegisterFlagSet(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEMOTORS, (e != 0x0)))
#define Reg_Control_Toggle_EnabledMotors() (RegisterFlagToggle(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEMOTORS))

#define REG_CONTROL_FLAG_ENABLENOTIFY 0x04
#define Reg_Control_GetEnabledNotify() (RegisterFlagGetValue(REGID_CONTROL, REG_CONTROL_FLAG_ENABLENOTIFY) != 0x0)
#define Reg_Control_SetEnabledNotify(e) (RegisterFlagSet(REGID_CONTROL, REG_CONTROL_FLAG_ENABLENOTIFY, (e != 0x0)))
#define Reg_Control_Toggle_EnabledNotify() (RegisterFlagToggle(REGID_CONTROL, REG_CONTROL_FLAG_ENABLENOTIFY))

#define REG_CONTROL_FLAG_ENABLEPIEZO 0x08
#define Reg_Control_GetEnabledPiezo() (RegisterFlagGetValue(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEPIEZO) != 0x0)
#define Reg_Control_SetEnabledPiezo(e) (RegisterFlagSet(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEPIEZO, (e != 0x0)))
#define Reg_Control_Toggle_EnabledPiezo() (RegisterFlagToggle(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEPIEZO))

#define REG_CONTROL_FLAG_ENABLEPROJECTILES 0x10
#define Reg_Control_GetEnabledProjectiles() (RegisterFlagGetValue(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEPROJECTILES) != 0x0)
#define Reg_Control_SetEnabledProjectiles(e) (RegisterFlagSet(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEPROJECTILES, (e != 0x0)))
#define Reg_Control_Toggle_EnabledProjectiles() (RegisterFlagToggle(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEPROJECTILES))

#define REG_CONTROL_FLAG_ENABLEADDONS 0x20
#define Reg_Control_GetEnabledAddOns() (RegisterFlagGetValue(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEADDONS) != 0x0)
#define Reg_Control_SetEnabledAddOns(e) (RegisterFlagSet(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEADDONS, (e != 0x0)))
#define Reg_Control_Toggle_EnabledAddOns() (RegisterFlagToggle(REGID_CONTROL, REG_CONTROL_FLAG_ENABLEADDONS))

#define REG_CONTROL_FLAG_ENLPM 0x40
#define Reg_Control_GetEnLPM() (RegisterFlagGetValue(REGID_CONTROL, REG_CONTROL_FLAG_ENLPM) != 0x0)
#define Reg_Control_SetEnLPM(e) (RegisterFlagSet(REGID_CONTROL, REG_CONTROL_FLAG_ENLPM, (e != 0x0)))
#define Reg_Control_Toggle_EnLPM() (RegisterFlagToggle(REGID_CONTROL, REG_CONTROL_FLAG_ENLPM))

#define REG_CONTROL_FLAG_RESET 0x80
#define Reg_Control_GetReset() (RegisterFlagGetValue(REGID_CONTROL, REG_CONTROL_FLAG_RESET) != 0x0)
#define Reg_Control_SetReset(e) (RegisterFlagSet(REGID_CONTROL, REG_CONTROL_FLAG_RESET, (e != 0x0)))
#define Reg_Control_Toggle_Reset() (RegisterFlagToggle(REGID_CONTROL, REG_CONTROL_FLAG_RESET))

#endif
