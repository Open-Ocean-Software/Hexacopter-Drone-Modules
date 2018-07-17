
#ifndef M_WINCH_H
#define M_WINCH_H

#define DDR_WINCH_POS
#define PORT_WINCH_POS
#define MASK_WINCH_POS
#define HANDLER_WINCH_POS Handler_Winch_Pos

#define DDR_WINCH_NEG
#define PORT_WINCH_NEG
#define MASK_WINCH_NEG
#define HANDLER_WINCH_NEG Handler_Winch_Neg

void Handler_Winch_Pos (Module *mod, unsigned char t);
void Handler_Winch_Neg (Module *mod, unsigned char t);

#endif
