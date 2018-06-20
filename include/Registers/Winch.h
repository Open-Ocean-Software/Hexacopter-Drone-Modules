
#ifndef R_WINCH_H
#define R_WINCH_H

#define REGID_WINCH 0x0F
#define REG_WINCH_DEFAULT 0x00
#define Reg_Winch_Get() (RegisterGet(REGID_WINCH))
#define Reg_Winch_GetValue() (RegisterGetValue(REGID_WINCH))
#define Reg_Winch_Set(v) (RegisterSet(REGID_WINCH, v))
#define Reg_Winch_SetValue(v) (RegisterSetValue(REGID_WINCH, v))
#define Reg_Winch_Reset() (RegisterSet(REGID_WINCH, REG_WINCH_DEFAULT))


#define REG_WINCH_FLAG_POS 0x01
#define Reg_Winch_GetPos() (RegisterFlagGetValue(REGID_WINCH, REG_WINCH_FLAG_POS) != 0x0)
#define Reg_Winch_SetPos(e) (RegisterFlagSet(REGID_WINCH, REG_WINCH_FLAG_POS, (e != 0x0)))
#define Reg_Winch_Toggle_Pos() (RegisterFlagToggle(REGID_WINCH, REG_WINCH_FLAG_POS))

#define REG_CONTROL_FLAG_NEG 0x02
#define Reg_Control_GetNeg() (RegisterFlagGetValue(REGID_CONTROL, REG_CONTROL_FLAG_NEG) != 0x0)
#define Reg_Control_SetNeg(e) (RegisterFlagSet(REGID_CONTROL, REG_CONTROL_FLAG_NEG, (e != 0x0)))
#define Reg_Control_Toggle_Neg() (RegisterFlagToggle(REGID_CONTROL, REG_CONTROL_FLAG_NEG))

#endif
