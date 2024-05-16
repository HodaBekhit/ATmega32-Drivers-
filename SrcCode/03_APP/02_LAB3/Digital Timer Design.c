/*
 * Alarm.c
 *
 * Created: 12/19/2023 3:20:33 PM
 * Author : Dell
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "LED.h"
#include "LED_cfg.h"
#include "switch.h"
#include "switch_cfg.h"
#include "SevSeg.h"
#include "SevSeg_cfg.h"



int main(void)
{
    LED_init();
	Switch_init();
	SevSeg_init();
	Switch_enumLogicState_t Switch1_Value= switch_enum_OFF;
	Switch_enumLogicState_t Switch2_Value= switch_enum_OFF;
	Switch_enumLogicState_t Switch3_Value= switch_enum_OFF;
	u8 Loc_Counter=0;
	u8 Loc_Timer=0;
    while (1) 
    {
		Switch_enu_read(switch1,&Switch1_Value);
		Switch_enu_read(switch2,&Switch2_Value);
		Switch_enu_read(switch3,&Switch3_Value);
		
		if(Switch1_Value == switch_enum_ON)
		{
			_delay_ms(50);
			if(Switch1_Value == switch_enum_ON)
			{
				if (Loc_Timer <= 99)
				{
					Loc_Timer++;
				}
				SevSeg_enumSetAllValue(Loc_Timer);
				LED_enumSetValue(LED1,LED_enu_OFF);
			}
			while(Switch1_Value == switch_enum_ON)  /* wait until the switch is released*/
			{
				Switch_enu_read(switch1,&Switch1_Value);
			}
		}
		
		else if(Switch2_Value == switch_enum_ON)
		{
			_delay_ms(50);
			if(Switch2_Value == switch_enum_ON)
			{
				if (Loc_Timer > 0)
				{
					Loc_Timer--;
				}
				SevSeg_enumSetAllValue(Loc_Timer);
				LED_enumSetValue(LED1,LED_enu_OFF);
			}
			while(Switch2_Value == switch_enum_ON)  /* wait until the switch is released*/
			{
				Switch_enu_read(switch2,&Switch2_Value);
			}
		}
		
		else if(Switch3_Value == switch_enum_ON)
		{
			_delay_ms(50);
			if(Switch3_Value == switch_enum_ON)
			{
				for(Loc_Counter=Loc_Timer; Loc_Counter >= 0 ; Loc_Counter--)
				{
					Loc_Timer--;
					SevSeg_enumSetAllValue(Loc_Timer);
					if(Loc_Timer == 0)
					{
						LED_enumSetValue(LED1,LED_enu_ON);
						break;
					}
					_delay_ms(500);
				}
			}
			while(Switch3_Value == switch_enum_ON)  /* wait until the switch is released*/
			{
				Switch_enu_read(switch3,&Switch3_Value);
			}
		}
		else
		{
			SevSeg_enumSetAllValue(Loc_Timer);
		}

    }
	
}

