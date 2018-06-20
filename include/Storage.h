
#ifndef STORAGE_H
#define STORAGE_H

unsigned char LoadRegisterValue (unsigned char id);
unsigned char TryLoadRegisterValue (unsigned char id, unsigned char *value);

unsigned char SaveRegisterValue (unsigned char id, unsigned char value);

unsigned char LoadRegisters (Register *reg, unsigned char count);
unsigned char SaveRegisters (Register *reg, unsigned char count);
unsigned char ResetRegisters (Register *reg, unsigned char count);

#endif
