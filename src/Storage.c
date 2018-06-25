
#include "Registers.h"
#include "Storage.h"
#include "Config.h"

#include <avr/io.h>

unsigned char LoadRegisterValue (unsigned char id)
{
    unsigned char value;
    TryLoadRegisterValue(id, &value);
    return value;
}

unsigned char eepromRead (unsigned int addr)
{
    // Wait for previous write
    while (EECR & (1 << EEWE)) ;
    // Set address
    EEAR = addr;
    // Start read
    EECR |= (1 << EERE);
    // Return data
    return EEDR;
}

void eepromWrite (unsigned int addr, unsigned char data)
{
    // Wait for previous write
    while (EECR & (1 << EEWE)) ;
    // Set address and data
    EEAR = addr;
    EEDR = data;
    // Enable master write
    EECR |= (1 << EEMWE);
    // Start write
    EECR |= (1 << EEWE);
}

void handleEEPROMInit (void)
{
    if (eepromRead(CONFIG_STORAGE_EEPROMSTARTINDEX) != CONFIG_STORAGE_EEPROMSTARTCODE) {
        eepromWrite(CONFIG_STORAGE_EEPROMSTARTINDEX, CONFIG_STORAGE_EEPROMSTARTCODE);
        eepromWrite(CONFIG_STORAGE_EEPROMSTARTINDEX + 1, CONFIG_STORAGE_EEPROMENDCODE);
    }
}

unsigned char TryLoadRegisterValue (unsigned char id, unsigned char *value)
{
    unsigned char dataIndex;
    unsigned char regid;
    handleEEPROMInit();
    for (unsigned char i = 0; i < REGISTERLIST_COUNT; i++) {
        dataIndex = (CONFIG_STORAGE_EEPROMSTARTINDEX + 1) + i * CONFIG_STORAGE_EEPROMDATASIZE;
        regid = eepromRead(dataIndex);
        if (regid == CONFIG_STORAGE_EEPROMENDCODE) {
            *value = 0x00;
            return 0x00;
        }
        if (regid == id) {
            *value = eepromRead(dataIndex + 1);
            return 0x01;
        }
    }
    *value = 0x00;
    return 0x00;
}

unsigned char SaveRegisterValue (unsigned char id, unsigned char value)
{
    unsigned char dataIndex;
    unsigned char regid;
    handleEEPROMInit();
    for (unsigned char i = 0; i < REGISTERLIST_COUNT; i++) {
        dataIndex = CONFIG_STORAGE_EEPROMSTARTINDEX + i * CONFIG_STORAGE_EEPROMDATASIZE;
        regid = eepromRead(dataIndex);
        if (regid == CONFIG_STORAGE_EEPROMENDCODE) {
            eepromWrite(dataIndex, id);
            eepromWrite(dataIndex + 1, value);
            eepromWrite(dataIndex + CONFIG_STORAGE_EEPROMDATASIZE, CONFIG_STORAGE_EEPROMENDCODE);
            return 0x01;
        }
        if (regid == id) {
            eepromWrite(dataIndex + 1, value);
            return 0x01;
        }
    }
    return 0x00;
}

unsigned char LoadRegisters (struct Register *reg, unsigned char count)
{
    unsigned char success = 0;
    unsigned char val;
    for (unsigned char i = 0; i < count; i++) {
        if (TryLoadRegisterValue(reg[i].Id, &val)) {
            reg[i].Value = val;
            success++;
        }
    }
    return success;
}

unsigned char SaveRegisters (struct Register *reg, unsigned char count)
{
    unsigned char success = 0;
    for (unsigned char i = 0; i < count; i++) {
        if (SaveRegisterValue(reg->Id, reg->Value)) {
            success++;
        }
    }
    return success;
}

unsigned char ResetRegisters (struct Register *reg, unsigned char count)
{
    unsigned char success = 0;
    for (unsigned char i = 0; i < count; i++) {
        if (SaveRegisterValue(reg->Id, reg->DefaultValue)) {
            success++;
        }
    }
    return success;
}
