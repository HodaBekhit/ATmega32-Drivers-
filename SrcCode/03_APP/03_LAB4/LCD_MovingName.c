/*
 * lcdmovename.c
 *
 * Created: 1/2/2024 8:28:34 PM
 * Author : Dell
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_types.h"
#include "DIO.h"
#include "PORT.h"
#include "LCD.h"


int main(void)
{
    PORT_vidInit();
    LCD_init();
    u8*name="Hoda Ahmed";
    LCD_enuWriteCommand(LCD_SETCURSOR);
	LCD_enuWriteString(name,10);
	_delay_ms(500);
	
    while (1) 
    {
	for(u8 i=0;i<16;i++)
		{
			LCD_enuWriteCommand(LCD_Display_RightShift);
			_delay_ms(350);
		}
		
		for(u8 i=0;i<16+10;i++)
		{
			LCD_enuWriteCommand(LCD_Display_LeftShift);
			_delay_ms(350);
		}
		for(u8 i=0;i<10;i++)
		{
			LCD_enuWriteCommand(LCD_Display_RightShift);
			_delay_ms(350);
		}

    }
	return 0;
}

