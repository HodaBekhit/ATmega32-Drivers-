/*
 * LED_cfg.h
 *
 * Created: 12/12/2023 11:02:53 PM
 *  Author: Dell
 */ 


#ifndef LED_CFG_H_
#define LED_CFG_H_

#include "std_types.h"
#include "LED_priv.h"

#define NUM_OF_LEDS 1

#define LED1 0


typedef struct 
{
    LED_enum_Port_t	PORT;
	LED_enum_Pin_t PIN;
	LED_enum_ActiveState_t Active_State;
    LED_enum_LogicState_t	ON_OFF;
	
}LED_StrCfg_t;




#endif /* LED_CFG_H_ */