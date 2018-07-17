
#include "Modules.h"
#include "Helpers/PWMHelper.h"

void Handler_Swivel (Module *mod, unsigned char t)
{
    if (Reg_Control_GetEnabledMotors()) {
        PWMHandlerHelper(mod, t);
    }
}
