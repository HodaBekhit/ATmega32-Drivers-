
/*
 * Task2.c
 *
 * Created: 12/8/2023 10:52:52 PM
 *  Author: Dell
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_types.h"
#include "std_math.h"
#include "PORT.h"
#include "PORT_cfg.h"
#include "DIO.h"

int main(void)
{
	/*Port Config*/
	PORT_vidInit();
	DIO_enumLogicState_t state;
	u8 count=0;
    while (1) 
    {    DIO_enumReadState(DIO_enumPortC,DIO_enumPin5,&state);
		if(state==DIO_enumLogicLow)
		{   _delay_ms(50);
			if(state==DIO_enumLogicLow)
			{ count++;
			}
		}
		count=count%16;
		
			DIO_enumSetPin(DIO_enumPortC,DIO_enumPin0,GET_BIT(count,DIO_enumPin0));
			DIO_enumSetPin(DIO_enumPortC,DIO_enumPin1,GET_BIT(count,DIO_enumPin1));
			DIO_enumSetPin(DIO_enumPortC,DIO_enumPin2,GET_BIT(count,DIO_enumPin2));
			DIO_enumSetPin(DIO_enumPortC,DIO_enumPin3,GET_BIT(count,DIO_enumPin3));
			
    }
	}
	

