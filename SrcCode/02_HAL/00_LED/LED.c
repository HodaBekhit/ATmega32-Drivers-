/*
 * LED.c
 *
 * Created: 12/12/2023 11:03:59 PM
 *  Author: Dell
 */ 
#include "std_types.h"
#include "PORT_cfg.h"
#include "PORT.h"
#include "DIO.h"
#include "LED.h"
#include "LED_cfg.h"

extern LED_StrCfg_t LEDS[NUM_OF_LEDS];

void LED_init(void)
{	
	u8 Loc_counter=0;
	Port_Strcfg_t CurrentLEDS[NUM_OF_LEDS];
	
for(Loc_counter=0; Loc_counter < NUM_OF_LEDS ; Loc_counter++)
{
	CurrentLEDS[Loc_counter].PORT=LEDS[Loc_counter].PORT;
	CurrentLEDS[Loc_counter].PIN=LEDS[Loc_counter].PIN;
	if ( ( LEDS[Loc_counter].Active_State==LED_enu_ActiveHigh && LEDS[Loc_counter].ON_OFF==LED_enu_ON) || ( LEDS[Loc_counter].Active_State==LED_enu_ActiveLow && LEDS[Loc_counter].ON_OFF==LED_enu_OFF) )
	{
		CurrentLEDS[Loc_counter].config= PORT_enuOUTPUT_HIGH;
	}
	else
	{
		CurrentLEDS[Loc_counter].config= PORT_enuOUTPUT_LOW;
	}
}
 PORT_SetCfg(CurrentLEDS,  NUM_OF_LEDS);

}

LED_enum_Error_t LED_enumSetValue(u8 Copy_u8LED_Name , u8 Copy_u8LEDValue )
{
	LED_enum_Error_t Ret_LedError=LED_enu_Ok;
	if(Copy_u8LED_Name>NUM_OF_LEDS)
	{
		Ret_LedError=LED_enu_WrongName;
	}
	else if( Copy_u8LEDValue > LED_enu_ON)
	{
		Ret_LedError=LED_enu_WrongValue;
	}
		
	else
	{
		if(LEDS[Copy_u8LED_Name].Active_State==LED_enu_ActiveHigh)
		{
			DIO_enumSetPin( LEDS[Copy_u8LED_Name].PORT, LEDS[Copy_u8LED_Name].PIN, (DIO_enumLogicState_t) Copy_u8LEDValue );
		}
		else if(LEDS[Copy_u8LED_Name].Active_State==LED_enu_ActiveLow)
		{
			DIO_enumSetPin( LEDS[Copy_u8LED_Name].PORT, LEDS[Copy_u8LED_Name].PIN, (DIO_enumLogicState_t) (!Copy_u8LEDValue ));
		}
		else
		{
			Ret_LedError=LED_enu_WrongActiveState;
		}
		
	}
	return Ret_LedError;
	
}
	