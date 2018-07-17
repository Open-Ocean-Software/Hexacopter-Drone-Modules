
#ifndef TWIMANAGER_H
#define TWIMANAGER_H

/**
 * Writes one byte to the TWI slave.
 * @param  addr The address of the slave.
 * @param  data The data sent to the slave.
 * @return      Success
 */
unsigned char TWIWriteByte (unsigned char addr, unsigned char data);

/**
 * Writes multiple bytes to the TWI slave.
 * @param  addr The address of the slave.
 * @param  data The data sent to the slave.
 * @param  len  The amount of data sent to the slave.
 * @return      Success
 */
unsigned char TWIWriteBytes (unsigned char addr, unsigned char *data, int len);

/**
 * Reads one byte from the TWI slave.
 * @param  addr The address of the slave.
 * @param  data The data to be received from the slave.
 * @return      Success
 */
unsigned char TWIReadByte (unsigned char addr, unsigned char *data);

/**
 * Reads multiple bytes from the TWI slave.
 * @param  addr The address of the slave.
 * @param  data The data to be received from the slave.
 * @param  len  The amount of data to be received from the slave.
 * @return      Success
 */
unsigned char TWIReadBytes (unsigned char addr, unsigned char *data, int len);

#endif
