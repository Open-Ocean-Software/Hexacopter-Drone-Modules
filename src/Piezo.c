
#include "Modules.h"
#include "Helpers/PWMHelper.h"

void Handler_Piezo (Module *mod, unsigned char t)
{
    if (Reg_Control_GetEnabledPiezo()) {
        PWMHandlerHelper(mod, t);
    }
}
