/*
 * switch_cfg.c
 *
 * Created: 12/12/2023 11:04:17 PM
 *  Author: Dell
 */ 
#include "switch_priv.h"
#include "switch_cfg.h"
#include "PORT_cfg.h"

Switch_StrCfg_t switchs[NUM_OF_switchs] =
{
	[switch1]={ .PORT=switch_enumPortA , .PIN=switch_enumPin0 , .Active_State=switch_enum_INPUTPU},
	[switch2]={ .PORT=switch_enumPortA , .PIN=switch_enumPin1 , .Active_State=switch_enum_INPUTPU},
	[switch3]={ .PORT=switch_enumPortA , .PIN=switch_enumPin2 , .Active_State=switch_enum_INPUTPU}
		
	};