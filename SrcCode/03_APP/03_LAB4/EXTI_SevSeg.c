/*
 * sevseg_exti.c
 *
 * Created: 1/3/2024 10:14:23 PM
 * Author : Dell
 */ 
#include "EXTI.h"
#include "switch.h"
#include "SevSeg.h"

void increment(void);
void decrement(void);


u8 Loc_Timer=0;

int main(void)
{
   Switch_init();
   EXTI_void_Init();
   SevSeg_init();
   
   
   EXTI_vidRegisterEXTI0Cbf(increment);
   EXTI_vidRegisterEXTI2Cbf(decrement);
  
    while (1) 
    {
		SevSeg_enumSetAllValue(Loc_Timer);
    }
}
void increment(void)
{
	/* Implementation */
	
		Loc_Timer++;
	
	
}


void decrement(void)
{
	/* Implementation */
	
		Loc_Timer--;
	
	
}

