
#include "Modules.h"
#include "Helpers/PWMHelper.h"

void Handler_Projectiles (Module *mod, unsigned char t)
{
    if (Reg_Control_GetEnabledProjectiles()) {
        PWMHandlerHelper(mod, t);
    }
}
