/*
 * interrupt.c
 *
 * Created: 12/24/2023 7:31:57 PM
 * Author : Dell
 */ 

#include "std_math.h"
#include "std_types.h"
#include "LED_priv.h"
#include "LED_cfg.h"
#include "LED.h"
#include "switch_priv.h"
#include "switch_cfg.h"
#include "switch.h"
#include "EXTI.h"



int main(void)
{
    LED_init();
	Switch_init();
	EXTI_void_Init();
	
    while (1) 
    {
		LED_enumSetValue(LED1,LED_enu_ON);
    }
	return 0;
}

void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	LED_enumSetValue(LED2,LED_enu_ON);
	LED_enumSetValue(LED3,LED_enu_OFF);
	LED_enumSetValue(LED4,LED_enu_OFF);
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	LED_enumSetValue(LED2, LED_enu_OFF);
	LED_enumSetValue(LED3, LED_enu_ON);
	LED_enumSetValue(LED4, LED_enu_OFF);
}


void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	LED_enumSetValue(LED2,LED_enu_OFF);
	LED_enumSetValue(LED3,LED_enu_OFF);
	LED_enumSetValue(LED4,LED_enu_ON);
}