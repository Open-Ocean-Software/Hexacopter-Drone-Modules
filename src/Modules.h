
#include "Modules.h"

Module Modules [MODULELIST_COUNT] = { MODULELIST };

void InitializeModules (void)
{
    for (unsigned char i = 0; i < MODULELIST_COUNT; i++) {
        *(Components[i].DDRegister) &= ~Components[i].Mask;
        *(Components[i].Port) &= ~Components[i].Mask;
    }
}
