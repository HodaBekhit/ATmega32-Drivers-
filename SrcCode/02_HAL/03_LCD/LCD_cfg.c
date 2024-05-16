/*
 * LCD_cfg.c
 *
 * Created: 1/2/2024 11:20:55 AM
 *  Author: Dell
 */ 

#include "DIO.h"
#include "LCD_priv.h"
#include "LCD_cfg.h"

   /* Configure the corresponding port and pin for each LCD pin
   PORT options: DIO_enumPortA / DIO_enumPortB / DIO_enumPortC / DIO_enumPortD
   PIN options: DIO_enumPin0/ DIO_enumPin1/ DIO_enumPin2/ DIO_enumPin3/ DIO_enumPin4/ DIO_enumPin5/ DIO_enumPin6/ DIO_enumPin7 */
  LCD_StrCgf_t LCD[]={
	[LCD_RS]={.PORT=DIO_enumPortC, .PIN=DIO_enumPin0},
	[LCD_RW]={.PORT=DIO_enumPortC , .PIN=DIO_enumPin1},
	[LCD_E]={.PORT= DIO_enumPortC, .PIN=DIO_enumPin2},
	[LCD_DB0]={.PORT=DIO_enumPortD , .PIN=DIO_enumPin0},
	[LCD_DB1]={.PORT=DIO_enumPortD , .PIN=DIO_enumPin1},
	[LCD_DB2]={.PORT=DIO_enumPortD , .PIN=DIO_enumPin2},
	[LCD_DB3]={.PORT=DIO_enumPortD , .PIN=DIO_enumPin3},
	[LCD_DB4]={.PORT=DIO_enumPortD , .PIN=DIO_enumPin4},
	[LCD_DB5]={.PORT=DIO_enumPortD , .PIN=DIO_enumPin5},
	[LCD_DB6]={.PORT=DIO_enumPortD , .PIN=DIO_enumPin6},
	[LCD_DB7]={.PORT=DIO_enumPortD , .PIN=DIO_enumPin7}
};