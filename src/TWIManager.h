
#include "TWIManager.h"

#include <avr/io.h>

unsigned char twiTransmit (unsigned char data)
{
    TWDR = data;                                        // Set data
    TWCR = (1 << TWINT) | (1 << TWEN);                  // Enable transfer
    while (!(TWCR & (1 << TWINT))) ;                    // Wait for transfer
    if ((TWSR & 0xF8) != MT_SLA_ACK) {                  // Check acknowledge
        return 0x00;                                    // Throw error
    }
    return 0x01;                                        // Success
}

unsigned char twiReceive (unsigned char *data)
{
    while (!(TWCR & (1 << TWINT))) ;                    // Wait for data
    *data = TWDR;                                       // Set data
    TWCR &= (1 << TWEN);                                // Unset interrupt
}

unsigned char TWIWriteByte (unsigned char addr, unsigned char data)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);   // Send TWI start
    while (!(TWCR & (1 << TWINT))) ;                    // Wait for start
    if ((TWSR & 0xF8) != START) {                       // Check start condition
        return 0x00;
    }
    unsigned char stat = 0x01;
    stat &= twiTransmit(addr);                          // Transmit SLA+W
    stat &= twiTransmit(data);                          // Transmit DATA
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);   // Send TWI stop
    return stat;
}

unsigned char TWIWriteBytes (unsigned char addr, unsigned char *data, int len)
{
    if (len < 0) {
        return 0x00;
    } else if (len == 0) {
        return 0x01;
    }

    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);   // Send START or REPEATEDSTART
    while (!(TWCR & (1 << TWINT))) ;                    // Wait for start condition
    if ((TWSR & 0xF8) != START) {                       // Check start condition
        return 0x00;                                    // Throw error
    }
    unsigned char stat = 0x01;
    stat &= twiTransmit(addr);                          // Transmit SLA+W

    for (int i = 0; i < len; i++) {
        stat &= twiTransmit(data[i]);                   // Transmit DATA
        if (!stat) {
            return 0x00;
        }
    }
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);   // Send stop condition
    return 0x01;
}

unsigned char TWIReadByte (unsigned char addr, unsigned char *data)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);   // Send START
    while (!(TWCR & (1 << TWINT))) ;                    // Wait for start condition
    if ((TWSR & 0xF8) != START) {                       // Check start condition
        return 0x00;
    }
    unsigned char stat = 0x01;
    stat &= twiTransmit(0x80 | addr);                   // Transmit SLA+R
    stat &= twiReceive(data);                           // Receive data
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);   // Send TWI stop
    return stat;
}

unsigned char TWIReadBytes (unsigned char addr, unsigned char *data, int len)
{
    data = malloc(sizeof(unsigned char) * len);

    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);   // Send START
    while (!(TWCR & (1 << TWINT))) ;                    // Wait for start condition
    if ((TWSR & 0xF8) != START) {                       // Check start condition
        return 0x00;
    }
    unsigned char stat = 0x01;
    stat &= twiTransmit(0x80 | addr);                   // Transmit SLA+R

    for (int i = 0; i < len; i++) {
        stat &= twiReceive(&(data[i]));                 // Receive DATA
        if (!stat) {
            return 0x00;
        }
    }
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);   // Send stop condition
}
