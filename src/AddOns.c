
#include "AddOns.h"

AddOn AddOns [ADDONLIST_COUNT] = { ADDONLIST };

AddOn *FindAddOn (unsigned char id)
{
    for (unsigned char i = 0; i < ADDONLIST_COUNT; i++) {
        if (AddOns[i].Id == id) {
            return &(AddOns[i]);
        }
    }
    return 0x00;
}

unsigned char AddOnExists (unsigned char id)
{
    for (unsigned char i = 0; i < ADDONLIST_COUNT; i++) {
        if (AddOns[i].Id == id) {
            return 0x01;
        }
    }
    return 0x00;
}
