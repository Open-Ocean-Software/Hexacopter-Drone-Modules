
#ifndef REGISTER_H
#define REGISTER_H

typedef struct
{
    unsigned char Id;
    unsigned char Value;
    unsigned char DefaultValue;
} Register;

/**
 * Create a new, unique register.
 * @param  id         The ID of the register.
 * @param  defaultval The default value of the reigster.
 * @return            The new register.
 */
#define InitializeRegister(id, defaultval) { id, 0x00, defaultval }

/**
 * Set the value of a register.
 * @param  id    The ID of the register.
 * @param  value The value to be set.
 * @return       The success value.
 */
unsigned char RegisterSetValue (unsigned char id, unsigned char value);

/**
 * Get the value of the register.
 * @param  id    The ID of the register.
 * @param  value A reference to the value.
 * @return       The success value.
 */
unsigned char TryRegisterGetValue (unsigned char id, unsigned char *value);

/**
 * Get the value of the register.
 * @param  id The ID of the register.
 * @return    The value of the register.
 */
unsigned char RegisterGetValue (unsigned char id);


/**
 * Sets the register.
 * @param  id    The ID of the register.
 * @param  value The value of the register.
 * @return       The active register.
 */
Register *RegisterSet (unsigned char id, unsigned char value);

/**
 * Gets the register.
 * @param  id The ID of the register.
 * @return    The active register.
 */
Register *RegisterGet (unsigned char id);

/**
 * Resets the register.
 * @param  id The ID of the register.
 * @return    The active register.
 */
Register *RegisterReset (unsigned char id);


/**
 * Toggles the register's flags.
 * @param  id   The ID of the register.
 * @param  mask The mask to be toggled.
 * @return      The active register.
 */
Register *RegisterFlagToggle (unsigned char id, unsigned char mask);

/**
 * Sets the register's flags.
 * @param  id    The ID of the register.
 * @param  mask  The mask to be set.
 * @param  value The value to be set.
 * @return       The active register.
 */
Register *RegisterFlagSet (unsigned char id, unsigned char mask, unsigned char value);

/**
 * Gets the register's flags.
 * @param  id    The ID of the register.
 * @param  mask  The mask to be returned.
 * @param  value A reference to the value.
 * @return       The active register.
 */
Register *RegisterFlagGet (unsigned char id, unsigned char mask, unsigned char *value);

/**
 * Gets the value of the register flags.
 * @param  id   The ID of the regsiter.
 * @param  mask The mask to be returned.
 * @return      The value of the register.
 */
unsigned char RegisterFlagGetValue (unsigned char id, unsigned char mask);

#endif
