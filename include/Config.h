
#ifndef CONFIG_H
#define CONFIG_H

#define CONFIG_CONTROLLER_STANDBYTIMEOUT 0.25       // Time waited between system cycles on timeout
#define CONFIG_CONTROLLER_SWPRESCALER 64            // The prescaler for the stopwatch (F_CPU / VALUE) = clock frequency
#define CONFIG_CONTROLLER_SWFREQUENCY 1000          // The stopwatch clock frequency

#define CONFIG_COMMUNICATIONS_MODEMASK 0x80         // The R/W mask for communications
#define CONFIG_COMMUNICATIONS_READMODE 0x00         // The value of the masked communications address on read
#define CONFIG_COMMUNICATIONS_WRITEMODE 0x80        // The value of the masked communications address on write
#define CONFIG_COMMUNICATIONS_ADDRESSMASK 0x7F      // The remaining value of the communications address to be used as the register address
#define CONFIG_COMMUNICATIONS_MESSAGELENGTH 2       // The length of all communication messages [byte]

#define CONFIG_PRESETS_PERSISTMASK 0x80             // The persist mask for presets
#define CONFIG_PRESETS_VALUEMASK 0x7F               // The remaining value of the presets register to be used as the preset code

#define CONFIG_ADDON_PASSTHRUMASK 0x80
#define CONFIG_ADDON_VALUEMASK 0x7F

#define CONFIG_STORAGE_EEPROMSTARTINDEX 1
#define CONFIG_STORAGE_EEPROMDATASIZE 2
#define CONFIG_STORAGE_EEPROMSTARTCODE 0xFF
#define CONFIG_STORAGE_EEPROMENDCODE 0xFF

#define CONFIG_ADDON_DEFAULTENABLED 0x0
#define CONFIG_ADDON_DEFAULTCONTROL 0x0000

#define CONFIG_F_CPU 16000000UL                     // The frequency of the CPU [Hz]

#endif
