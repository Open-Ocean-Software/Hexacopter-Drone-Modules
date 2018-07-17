
#include "Module.h"
#include "Helpers/PWMHelper.h"
#include "Registers.h"

void PWMHandlerHelper (Module *mod, unsigned char t)
{
    unsigned char regval = FindRegister((*mod).RegisterAddress)->Value;
    if (t > regval && (*mod).SavedValue == 0x01) {
        *((*mod).Port) &= ~((*mod).Mask);
        (*mod).SavedValue = 0x00;
    } else if (t < regval && (*mod).SavedValue == 0x00) {
        *((*mod).Port) |= (*mod).Mask;
        (*mod).SavedValue = 0x01;
    }
}
