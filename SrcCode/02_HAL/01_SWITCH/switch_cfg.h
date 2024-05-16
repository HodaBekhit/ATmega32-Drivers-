/*
 * switch_cfg.h
 *
 * Created: 12/12/2023 11:02:53 PM
 *  Author: Dell
 */ 


#ifndef switch_CFG_H_
#define switch_CFG_H_

#include "std_types.h"

#define NUM_OF_switchs 3

#define switch1 0
#define switch2 1
#define switch3 2


typedef struct 
{
	Switch_enu_PortNum_t PORT;
	Switch_enu_PinNum_t PIN;
    Switch_enu_ActiveState_t Active_State; /*input pullup or input pulldown*/
	} Switch_StrCfg_t;




#endif /* switch_CFG_H_ */