/*
 * LED_priv.h
 *
 * Created: 12/12/2023 11:03:29 PM
 *  Author: Dell
 */ 


#ifndef LED_PRIV_H_
#define LED_PRIV_H_

typedef enum
{
	LED_enu_PortA,
	LED_enu_PortB,
	LED_enu_PortC,
	LED_enu_PortD
} LED_enum_Port_t ;

typedef enum
{
	LED_enu_Pin0,
	LED_enu_Pin1,
	LED_enu_Pin2,
	LED_enu_Pin3,
	LED_enu_Pin4,
	LED_enu_Pin5,
	LED_enu_Pin6,
	LED_enu_Pin7
} LED_enum_Pin_t;

typedef enum
{
	LED_enu_ActiveLow,
	LED_enu_ActiveHigh
} LED_enum_ActiveState_t;

typedef enum
{
	LED_enu_Ok,
	LED_enu_WrongActiveState,
	LED_enu_WrongValue,
	LED_enu_WrongName
} LED_enum_Error_t;

typedef enum
{
	LED_enu_OFF,
	LED_enu_ON
} LED_enum_LogicState_t;

#endif /* LED_PRIV_H_ */