
#ifndef M_SWIVEL_H
#define M_SWIVEL_H

#define DDR_SWIVEL_X
#define PORT_SWIVEL_X
#define MASK_SWIVEL_X
#define HANDLER_SWIVEL_X Handler_Swivel

#define DDR_SWIVEL_Y
#define PORT_SWIVEL_Y
#define MASK_SWIVEL_Y
#define HANDLER_SWIVEL_Y Handler_Swivel

void Handler_Swivel (Module *mod, unsigned char t);

#endif
