
#ifndef M_GIMBAL_H
#define M_GIMBAL_H

#define DDR_GIMBAL_X
#define PORT_GIMBAL_X
#define MASK_GIMBAL_X
#define HANDLER_GIMBAL_X Handler_Gimbal

#define DDR_GIMBAL_Y
#define PORT_GIMBAL_Y
#define MASK_GIMBAL_Y
#define HANDLER_GIMBAL_Y Handler_Gimbal

#define DDR_GIMBAL_Z
#define PORT_GIMBAL_Z
#define MASK_GIMBAL_Z
#define HANDLER_GIMBAL_Z Handler_Gimbal

void Handler_Gimbal (Module *mod, unsigned char t);

#endif
