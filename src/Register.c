
#include "Register.h"
#include "Registers.h"

unsigned char RegisterSetValue (unsigned char id, unsigned char value)
{
    if (!RegisterExists(id)) {
        return 0x00;
    }
    struct Register *reg = FindRegister(id);
    reg->Value = value;
    return 0x01;
}

unsigned char TryRegisterGetValue (unsigned char id, unsigned char *value)
{
    if (!RegisterExists(id)) {
        return 0x00;
    }
    struct Register *reg = FindRegister(id);
    *value = reg->Value;
    return 0x01;
}

unsigned char RegisterGetValue (unsigned char id)
{
    if (!RegisterExists(id)) {
        return 0x00;
    }
    struct Register *reg = FindRegister(id);
    return reg->Value;
}

struct Register *RegisterSet (unsigned char id, unsigned char value)
{
    if (!RegisterExists(id)) {
        return 0;
    }
    struct Register *reg = FindRegister(id);
    reg->Value = value;
    return reg;
}

struct Register *RegisterGet (unsigned char id)
{
    if (!RegisterExists(id)) {
        return 0;
    }
    struct Register *reg = FindRegister(id);
    return reg;
}

struct Register *RegisterReset (unsigned char id)
{
    if (!RegisterExists(id)) {
        return 0;
    }
    struct Register *reg = FindRegister(id);
    reg->Value = reg->DefaultValue;
    return reg;
}

struct Register *RegisterFlagToggle (unsigned char id, unsigned char mask)
{
    if (!RegisterExists(id)) {
        return 0;
    }
    struct Register *reg = FindRegister(id);
    reg->Value ^= mask;
    return reg;
}

struct Register *RegisterFlagSet (unsigned char id, unsigned char mask, unsigned char value)
{
    if (!RegisterExists(id)) {
        return 0;
    }
    struct Register *reg = FindRegister(id);
    reg->Value &= ~mask;
    value &= mask;
    reg->Value |= value;
    return reg;
}

struct Register *RegisterFlagGet (unsigned char id, unsigned char mask, unsigned char *value)
{
    if (!RegisterExists(id)) {
        return 0;
    }
    struct Register *reg = FindRegister(id);
    *value = (reg->Value & mask);
    return reg;
}

unsigned char RegisterFlagGetValue (unsigned char id, unsigned char mask)
{
    if (!RegisterExists(id)) {
        return 0x00;
    }
    struct Register *reg = FindRegister(id);
    unsigned char val = (reg->Value & mask);
    return val;
}
