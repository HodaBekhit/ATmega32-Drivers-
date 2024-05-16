/*
 * LCD.c
 *
 * Created: 1/2/2024 11:20:37 AM
 *  Author: Dell
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_types.h"
#include "std_math.h"
#include "LCD_priv.h"
#include "LCD_cfg.h"
#include "LCD.h"
#include "DIO.h"

extern LCD_StrCgf_t LCD[];

 void LCD_init(void )
 {
	 /******************* 8 BIT MODE *************************/
	 #if LCD_BitMode==_8_BitMode
	/*Wait for more than 30ms after V DD rises to 4.5V*/
	 _delay_ms(40);
	/*Function Set : DL=1: 8bit data length, N=1: 2 lines, F=0: Font size:5x8*/
	LCD_enuWriteCommand(LCD_FUNCSET_8BIT);
	/*Wait for more than 39us*/
	_delay_ms(1);
	/*Display ON/OFF Control: D=1:Display ON, C=1: Cursor ON, B=0:CursorBlink OFF*/
	LCD_enuWriteCommand(LCD_DISPON_CURSON_BLOFF);
	/*Wait for more than 39us*/
	_delay_ms(1);
	/*Display Clear*/
	LCD_enuWriteCommand(LCD_CLR);
	/*Wait for more than 1.53ms*/
	_delay_ms(2);
	/* Entry Mode Set: I/D = 1 : +1 (Increment Mode), S = 0 : No Display Shift operation*/
	LCD_enuWriteCommand(LCD_ENTRYMODE);
	_delay_ms(1);
	
	/******************* 4 BIT MODE *************************/
	#elif LCD_BitMode==_4_BitMode
	/*Wait for more than 30ms after V DD rises to 4.5V*/
	_delay_ms(40);
	/*Function Set : DL=0: 4bit data length, N=1: 2 lines, F=0: Font size:5x8*/
	LCD_enuWriteCommand(0x20);
	LCD_enuWriteCommand(0x20);
	LCD_enuWriteCommand(0x80);
	/*Wait for more than 39us*/
	_delay_ms(1);
	/*Display ON/OFF Control: D=1:Display ON, C=1: Cursor ON, B=0:CursorBlink OFF*/
	LCD_enuWriteCommand(0x00);
	LCD_enuWriteCommand(0xE0);
	/*Wait for more than 39us*/
	_delay_ms(1);
	/*Display Clear*/
	LCD_enuWriteCommand(0x00);
	LCD_enuWriteCommand(0x10);
	/*Wait for more than 1.53ms*/
	_delay_ms(2);
	/* Entry Mode Set: I/D = 1 : +1 (Increment Mode), S = 0 : No Display Shift operation*/
	LCD_enuWriteCommand(0x00);
	LCD_enuWriteCommand(0x60);
    _delay_ms(1);
	#endif
	
 }
 
 LCD_enumError_t LCD_enuWriteData(u8 Copy_u8Data)
 {
	 /* set the error state initially to OK*/
	 LCD_enumError_t Loc_enuErrorState= LCD_enuOk;
	  u8 Loc_u8LCDCounter=0;
	  /* RS=1: data mode*/
	  DIO_enumSetPin(LCD[LCD_RS].PORT,LCD[LCD_RS].PIN,DIO_enumLogicHigh);
	  /*RW=0: Write mode*/
	  DIO_enumSetPin(LCD[LCD_RW].PORT,LCD[LCD_RW].PIN,DIO_enumLogicLow);
	  
	  /******************* 8 BIT MODE: write data on pins DB0 ~ DB7 *************************/
	   #if LCD_BitMode==_8_BitMode
	  for(Loc_u8LCDCounter=LCD_DB0;Loc_u8LCDCounter<=LCD_DB7;Loc_u8LCDCounter++)
	  {
		  u8 Loc_u8DataBit_iter=0;
		  DIO_enumSetPin(LCD[Loc_u8LCDCounter].PORT,LCD[Loc_u8LCDCounter].PIN,GET_BIT(Copy_u8Data,Loc_u8DataBit_iter));
		  Loc_u8DataBit_iter++;
	  }
	  
	  /******************* 4 BIT MODE: write data on pins DB4 ~ DB7 *************************/
	  #elif LCD_BitMode==_4_BitMode
	  for(Loc_u8LCDCounter=LCD_DB4;Loc_u8LCDCounter<=LCD_DB7;Loc_u8LCDCounter++)
	  {
		  u8 Loc_u8DataBit_iter=4;
		  DIO_enumSetPin(LCD[Loc_u8LCDCounter].PORT,LCD[Loc_u8LCDCounter].PIN,GET_BIT(Copy_u8Data,Loc_u8DataBit_iter));
		  Loc_u8DataBit_iter++;
	  }
	  #endif
	  /*set enable signal to high for 2ms to send command*/ 
	  DIO_enumSetPin(LCD[LCD_E].PORT,LCD[LCD_E].PIN,DIO_enumLogicHigh);
	  _delay_ms(2);
	  DIO_enumSetPin(LCD[LCD_E].PORT,LCD[LCD_E].PIN,DIO_enumLogicLow);
	  
	 return Loc_enuErrorState;
 }
 
 LCD_enumError_t LCD_enuWriteCommand(u8 Copy_u8Command)
 {
	 /* set the error state initially to OK*/
	 LCD_enumError_t Loc_enuErrorState= LCD_enuOk;
	 u8 Loc_u8LCDCounter=0;
	 /* RS=1: command mode*/
	 DIO_enumSetPin(LCD[LCD_RS].PORT,LCD[LCD_RS].PIN,DIO_enumLogicLow);
	 /*RW=0: Write mode*/
	 DIO_enumSetPin(LCD[LCD_RW].PORT,LCD[LCD_RW].PIN,DIO_enumLogicLow);
	 /******************* 8 BIT MODE: write command on pins DB0 ~ DB7 *************************/
	 #if LCD_BitMode==_8_BitMode
	 for(Loc_u8LCDCounter=LCD_DB0;Loc_u8LCDCounter<=LCD_DB7;Loc_u8LCDCounter++)
	 {
		 u8 Loc_u8CommBit_iter=0;
		 DIO_enumSetPin(LCD[Loc_u8LCDCounter].PORT,LCD[Loc_u8LCDCounter].PIN,GET_BIT(Copy_u8Command,Loc_u8CommBit_iter));
		 Loc_u8CommBit_iter++;
	 }
	 
	 /******************* 4 BIT MODE: write command on pins DB4 ~ DB7 *************************/
	 #elif LCD_BitMode==_4_BitMode
	 for(Loc_u8LCDCounter=LCD_DB4;Loc_u8LCDCounter<=LCD_DB7;Loc_u8LCDCounter++)
	 {
		 u8 Loc_u8CommBit_iter=4;
		 DIO_enumSetPin(LCD[Loc_u8LCDCounter].PORT,LCD[Loc_u8LCDCounter].PIN,GET_BIT(Copy_u8Data,Loc_u8CommBit_iter));
		 Loc_u8CommBit_iter++;
	 }
	 #endif
	 /*set enable signal to high for 2ms to send command*/
	 DIO_enumSetPin(LCD[LCD_E].PORT,LCD[LCD_E].PIN,DIO_enumLogicHigh);
	 _delay_ms(2);
	 DIO_enumSetPin(LCD[LCD_E].PORT,LCD[LCD_E].PIN,DIO_enumLogicLow);
	 
	 return Loc_enuErrorState;
 }
 
 LCD_enumError_t LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y)
 {
	 /* set the error state initially to OK*/
	 LCD_enumError_t Loc_enuErrorState= LCD_enuOk; 
	 u8 Loc_u8DDRAM_ADD=0;
	 /* set the error state to LCD_enuWrongPosition if the user entered invalid x and y number*/
	 if (Copy_u8X>1 || Copy_u8Y>15)
	 {
		 Loc_enuErrorState=LCD_enuWrongPosition;
	 }
	 /* set the DDRAM position*/
	 else
	 {
		 if(Copy_u8X==FirstLine)
		 {
			 Loc_u8DDRAM_ADD=Copy_u8Y;
		 }
		 else if(Copy_u8X==SecondLine)
		 {
			 Loc_u8DDRAM_ADD=Copy_u8Y+0x40;
		 }
		 else
		 {
			 //Do Nothing
		 }
	      /*set pointer to DDRAM*/
		  LCD_enuWriteCommand(Loc_u8DDRAM_ADD+128);
  }
  return Loc_enuErrorState;
 }
 
 LCD_enumError_t LCD_enuWriteNumber(u16 Copy_u8Number)
 {
	/* set the error state initially to OK*/
	LCD_enumError_t Loc_enuErrorState= LCD_enuOk;
	u16 arr[32]={0},i=32;
	while(Copy_u8Number!=0)
	{
		arr[i-1]=(Copy_u8Number%10);
		Copy_u8Number=Copy_u8Number/10;
		i--;
	}
	for(;i<=31;i++)
	{
		LCD_enuWriteData(arr[i]+'0');
	}
	return Loc_enuErrorState;
 }
 LCD_enumError_t LCD_enuWriteString(u8* Copy_pchPattern, u8 Copy_u8Length)
 {
	 /* set the error state initially to OK*/
	 LCD_enumError_t Loc_enuErrorState= LCD_enuOk;
	 if(Copy_pchPattern==NULLPTR)
	 {
		 Loc_enuErrorState=LCD_enuNullPtr;
	 }
	 else
	 {
		/*write string*/
		 u8 Loc_u8iter;
		 for(Loc_u8iter=0;Loc_u8iter<Copy_u8Length;Loc_u8iter++)
		 {
			LCD_enuWriteData(Copy_pchPattern[Loc_u8iter]);
		 }
     }
	 return Loc_enuErrorState;
 }
 
 LCD_enumError_t LCD_enuDisplaySpecialPattern(u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y)
 {
	 /* set the error state initially to OK*/
	 LCD_enumError_t Loc_enuErrorState= LCD_enuOk;
	 
	 if(Copy_pu8Pattern==NULLPTR)
	 {
		 Loc_enuErrorState=LCD_enuNullPtr;
	 }
	 else if(Copy_u8CGRAMBlockNumber>7)
	 {
		 Loc_enuErrorState=LCD_WrongBlockNum;
	 }
	 
	 /* set the error state to LCD_enuWrongPosition if the user entered invalid x and y number*/
	else if (Copy_u8X>1 || Copy_u8Y>15)
	 {
		 Loc_enuErrorState=LCD_enuWrongPosition;
	 }
	 else
	 {
	    /*get the location in the CGRAM*/
		u8 Loc_u8CGRAMLocation=Copy_u8CGRAMBlockNumber*8;
		/*set pointer to CGRAM*/
		LCD_enuWriteCommand(Loc_u8CGRAMLocation+64);
		/*assign the pattern argument in the CGRAM*/
		u8 Loc_u8iter;
		for(Loc_u8iter=0;Loc_u8iter<8;Loc_u8iter++)
		{
			LCD_enuWriteData(Copy_pu8Pattern[Loc_u8iter]);
		}
		/*set the LCD pointer to the DDRAM*/
		LCD_enuGotoDDRAM_XY(Copy_u8X,Copy_u8Y);
		/*Display the pattern in the LCD in loc(x,y)*/
		LCD_enuWriteData(Copy_u8CGRAMBlockNumber);
	 }
	 return Loc_enuErrorState;
 }
