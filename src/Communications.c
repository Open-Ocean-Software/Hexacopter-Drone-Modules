
#include "Communications.h"
#include "Registers.h"
#include "Config.h"

#include <avr/io.h>
#include <string.h>

void spiSendByte (char data)
{
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
}

void spiSendBytes (unsigned char *data)
{
    for (unsigned char i = 0; i < CONFIG_COMMUNICATIONS_MESSAGELENGTH; i++) {
        spiSendByte((char)data[i]);
    }
}

unsigned char spiReceiveByte (void)
{
    while (!(SPSR & (1 << SPIF)));
    return SPDR;
}

void spiReceiveBytes (unsigned char *data)
{
    unsigned char str [CONFIG_COMMUNICATIONS_MESSAGELENGTH];
    for (unsigned char i = 0; i < CONFIG_COMMUNICATIONS_MESSAGELENGTH; i++) {
        str[i] = spiReceiveByte();
    }
    data = str;
}

void spiInitialize (void)
{
    // Set MISO output, all others input.
    DDRB |= (1 << PB4);
    DDRB &= ~((1 << PB2) | (1 << PB3) | (1 << PB5));
    // Enable SPI
    SPCR = (1 << SPE);
}

unsigned char ReadCommunications (void)
{
    unsigned char buffer [CONFIG_COMMUNICATIONS_MESSAGELENGTH];
    spiReceiveBytes(buffer);

    unsigned char addr = (buffer[0] & CONFIG_COMMUNICATIONS_ADDRESSMASK);
    unsigned char util = buffer[1];

    if (!RegisterExists(addr)) {
        return 0x00;
    }

    if ((buffer[0] & CONFIG_COMMUNICATIONS_MODEMASK) == CONFIG_COMMUNICATIONS_READMODE) {
        unsigned char val;
        if (TryRegisterGetValue(addr, &val)) {
            unsigned char msg [CONFIG_COMMUNICATIONS_MESSAGELENGTH];
            msg[0] = addr;
            msg[1] = (val & util);
            return (WriteCommunications(msg) != 0x00);
        } else {
            return 0x00;
        }
    } else if ((buffer[0] & CONFIG_COMMUNICATIONS_MODEMASK) == CONFIG_COMMUNICATIONS_WRITEMODE) {
        return (RegisterSetValue(addr, util) != 0x00);
    } else {
        return 0x00;
    }
}

unsigned char WriteCommunications (unsigned char *val)
{
    unsigned char buffer [CONFIG_COMMUNICATIONS_MESSAGELENGTH];
    memcpy(buffer, val, CONFIG_COMMUNICATIONS_MESSAGELENGTH);
    spiSendBytes(buffer);
    return 0x01;
}
