/*
 * PORT.h
 *
 * Created: 12/2/2023 6:25:51 PM
 *  Author: Dell
 */ 


#ifndef PORT_H_
#define PORT_H_
#include "PORT_cfg.h"

void PORT_vidInit(void);

Error_state_t PORT_SetCfg(Port_Strcfg_t *AddPortCfg,u8 length);



#endif /* PORT_H_ */