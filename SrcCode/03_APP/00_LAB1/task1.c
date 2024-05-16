/*
 * MCAL.c
 *
 * Created: 11/26/2023 9:11:25 PM
 * Author : Dell
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../MCAL/DIO.h"


int main(void)
{
	//DIO_enumError_t dio_error;
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin0,DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin1,DIO_enumOutput);
    /* Replace with your application code */
    while (1) 
    {
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicHigh);
		_delay_ms(100);
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicLow);
		_delay_ms(100);
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicHigh);
		_delay_ms(100);
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicLow);
		_delay_ms(100);
    }
	
}

