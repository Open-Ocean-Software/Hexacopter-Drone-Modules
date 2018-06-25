
#include "Registers.h"

struct Register Registers [REGISTERLIST_COUNT] = { REGISTERLIST };

struct Register *FindRegister (unsigned char id)
{
    for (unsigned char i = 0; i < REGISTERLIST_COUNT; i++) {
        if (Registers[i].Id == id) {
            return &(Registers[i]);
        }
    }
    return 0;
}

unsigned char RegisterExists (unsigned char id)
{
    for (unsigned char i = 0; i < REGISTERLIST_COUNT; i++) {
        if (Registers[i].Id == id) {
            return 0x01;
        }
    }
    return 0x00;
}
