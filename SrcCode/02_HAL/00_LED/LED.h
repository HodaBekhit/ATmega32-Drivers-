/*
 * LED.h
 *
 * Created: 12/12/2023 11:02:36 PM
 *  Author: Dell
 */ 


#ifndef LED_H_
#define LED_H_

#include "std_types.h"
#include "LED_priv.h"

void LED_init(void);
LED_enum_Error_t LED_enumSetValue(u8 Copy_u8LED_Name , u8 Copy_u8LEDValue );


#endif /* LED_H_ */