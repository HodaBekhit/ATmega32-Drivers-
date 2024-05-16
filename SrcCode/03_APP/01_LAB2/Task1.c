/*
 * DIO_NewDriver.c
 *
 * Created: 12/2/2023 6:23:56 PM
 * Author : Dell
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "PORT.h"
#include "PORT_cfg.h"
#include "DIO.h"


int main(void)
{
	/*Port Config*/
	PORT_vidInit();
	while (1)
	{
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicHigh);
		_delay_ms(1000);
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicLow);
		_delay_ms(1000);
		DIO_enumSetPin(DIO_enumPortB,DIO_enumPin1,DIO_enumLogicHigh);
		_delay_ms(1000);
		DIO_enumSetPin(DIO_enumPortB,DIO_enumPin1,DIO_enumLogicLow);
		_delay_ms(1000);
	}
	
}

