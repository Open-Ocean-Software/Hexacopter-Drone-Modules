
#include "Modules.h"
#include "Helpers/PWMHelper.h"

void Handler_Gimbal (Module *mod, unsigned char t)
{
    if (Reg_Control_GetEnabledMotors()) {
        PWMHandlerHelper(mod, t);
    }
}
