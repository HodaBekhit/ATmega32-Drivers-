/*
 * KPD.c
 *
 * Created: 1/8/2024 12:27:37 AM
 * Author : Dell
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_types.h"
#include "DIO.h"
#include "PORT.h"
#include "KPD.h"
#include "LCD.h"

int main(void)
{
	// Initialize ports
	PORT_vidInit();
	
	// Initialize LCD
	LCD_init();
	LCD_enuWriteCommand(LCD_SETCURSOR);
	
	// Initialize Keypad
	KPD_enuInit();
	
	// Declare variables
	u8 Loc_u8KeyValue = 0;          // Variable to store the pressed key value
	u8 Loc_u8Flag = 0;              // Flag to indicate whether the first or second number is being entered
	u32 Loc_u8FirstNum = 0;         // Variable to store the first number
	u32 Loc_u8SecondNum = 0;        // Variable to store the second number
	u8 Loc_u8Operator = 0;          // Variable to store the operator (+, -, *, /)
	f64 Loc_u8Result = 0;           // Variable to store the result of the arithmetic operation
	
	// Display a welcome message on the LCD
	LCD_enuWriteString("calculator_task", 15);
	_delay_ms(1000);
	
	// Clear the LCD
	LCD_enuWriteCommand(LCD_CLR);
	
	while (1)
	{
		// Get the pressed key value from the keypad
		KPD_enuGetKeyValue(&Loc_u8KeyValue);
		
		// Process the key value
		if ((Loc_u8KeyValue >= '0') && (Loc_u8KeyValue <= '9'))
		{
			// If the key pressed is a digit, display it on the LCD and update numbers accordingly
			LCD_enuWriteData(Loc_u8KeyValue);
			
			/* First Digit*/
			if (Loc_u8Flag == 0)
			{
				// Multiply the current value of Loc_u8FirstNum by 10 to shift its digits left
				Loc_u8FirstNum *= 10;

				// Add the value of the pressed key (converted to its numeric equivalent) to Loc_u8FirstNum
				Loc_u8FirstNum += Loc_u8KeyValue - '0';
			}
			
			/* Second Digit*/
			else
			{
				// Multiply the current value of Loc_u8SecondNum by 10 to shift its digits left
				Loc_u8SecondNum *= 10;
				
				// Add the value of the pressed key (converted to its numeric equivalent) to Loc_u8SecondNum
				Loc_u8SecondNum += Loc_u8KeyValue - '0';
			}
			
			/* Reset the Key value*/
			Loc_u8KeyValue = 0;
		}
		
		else if ((Loc_u8KeyValue == '+') || (Loc_u8KeyValue == '-') || (Loc_u8KeyValue == '/') || (Loc_u8KeyValue == '*'))
		{
			// If the key pressed is an operator, display it on the LCD and set the flag
			LCD_enuWriteData(Loc_u8KeyValue);
			Loc_u8Flag = 1;
			Loc_u8Operator = Loc_u8KeyValue;
			Loc_u8KeyValue = 0;
		}
		
		else if (Loc_u8KeyValue == '=')
		{
			// If the key pressed is '=', perform the operation and display the result on the LCD
			LCD_enuWriteData(Loc_u8KeyValue);
			
			switch (Loc_u8Operator)
			{
				case '+':
				Loc_u8Result = Loc_u8FirstNum + Loc_u8SecondNum;
				LCD_enuWriteNumber(Loc_u8Result);
				break;
				case '-':
				Loc_u8Result = Loc_u8FirstNum - Loc_u8SecondNum;
				LCD_enuWriteNumber(Loc_u8Result);
				break;
				case '*':
				Loc_u8Result = Loc_u8FirstNum * Loc_u8SecondNum;
				LCD_enuWriteNumber(Loc_u8Result);
				break;
				case '/':
				if (Loc_u8SecondNum != 0)
				{
					Loc_u8Result = Loc_u8FirstNum / Loc_u8SecondNum;
					LCD_enuWriteNumber(Loc_u8Result);
				}
				else
				{
					LCD_enuWriteCommand(LCD_CLR);
					LCD_enuWriteString("error:div. by 0", 15);
				}
				break;
			}
			
			Loc_u8KeyValue = 0;
			Loc_u8Flag = 0;
		}
		
		else if (Loc_u8KeyValue == 'c')
		{
			// If the key pressed is 'c', clear the LCD and reset variables
			LCD_enuWriteCommand(LCD_CLR);
			Loc_u8Flag = 0;
			Loc_u8KeyValue = 0;
			Loc_u8FirstNum = 0;
			Loc_u8SecondNum = 0;
			Loc_u8Operator = 0;
			Loc_u8Result = 0;
		}
		else
		{
			// Do nothing
		}
	}
	
	return 0;
}
