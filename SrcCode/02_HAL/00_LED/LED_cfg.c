/*
 * LED_cfg.c
 *
 * Created: 12/12/2023 11:04:17 PM
 *  Author: Dell
 */ 
#include "LED_priv.h"
#include "LED_cfg.h"


LED_StrCfg_t LEDS[NUM_OF_LEDS] =
{
	[LED1]={ .PORT= LED_enu_PortA, .PIN= LED_enu_Pin3 , .Active_State=LED_enu_ActiveHigh, .ON_OFF= LED_enu_OFF}
	
		
	};