
#ifndef MODULE_H
#define MODULE_H

#include "Registers.h"

#include <stdint.h>

typedef struct
{
    unsigned char RegisterAddress;
    volatile uint8_t *DDRegister;
    volatile uint8_t *Port;
    unsigned char Mask;
    unsigned char SavedValue;
    void (*Handler)(Module *mod, unsigned char t);
} Module;

/**
 * Initializes a module with set properties.
 * @param  regaddr The data register's address.
 * @param  ddreg   The data-direction register's pointer.
 * @param  port    The register's port pointer.
 * @param  mask    The mask of pins to be initialized.
 * @param  handler The function called on system cycles.
 * @return         The initialized component.
 */
#define InitializeModule(regaddr, ddreg, port, mask, handler) { .RegisterAddress = regaddr, .DDRegister = &ddreg, .Port = &port, .Mask = mask, .Handler = &handler }

#endif
