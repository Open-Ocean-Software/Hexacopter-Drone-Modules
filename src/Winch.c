
#include "Modules.h"

void Handler_Winch_Pos (Module *mod, unsigned char t)
{
    if (Reg_Control_GetEnabledMotors()) {
        unsigned char pos = Reg_Winch_GetPos();
        if (pos && (*mod).SavedValue == 0x00) {
            *((*mod).Port) |= (*mod).Mask;
            (*mod).SavedValue = 0x01;
        } else if (!pos && (*mod).SavedValue == 0x01) {
            *((*mod).Port) &= ~((*mod).Mask);
            (*mod).SavedValue = 0x00;
        }
    }
}

void Handler_Winch_Neg (Module *mod, unsigned char t)
{
    if (Reg_Control_GetEnabledMotors()) {
        unsigned char neg = Reg_Winch_GetNeg();
        if (neg && (*mod).SavedValue == 0x00) {
            *((*mod).Port) |= (*mod).Mask;
            (*mod).SavedValue = 0x01;
        } else if (!neg && (*mod).SavedValue == 0x01) {
            *((*mod).Port) &= ~((*mod).Mask);
            (*mod).SavedValue = 0x00;
        }
    }
}
