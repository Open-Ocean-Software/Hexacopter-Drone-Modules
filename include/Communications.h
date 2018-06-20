
#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

/**
 * Prompts the SPI reader to read the next communication into the registers.
 * @return  The success value.
 */
unsigned char ReadCommunications (void);

/**
 * Prompts the SPI writer to write the next communication string.
 * @param  val The communication string.
 * @return     The success value.
 */
unsigned char WriteCommunications (unsigned char *val);

#endif
