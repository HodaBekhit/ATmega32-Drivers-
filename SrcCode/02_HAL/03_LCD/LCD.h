/*
 * LCD.h
 *
 * Created: 1/2/2024 11:17:19 AM
 *  Author: Dell
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_cfg.h"

/**
 *@brief  : Function to initialize the LCD ( display/ cursor /lines/ font /..)
 *@param  : none
 *@return : none                                                                   
 */
 void LCD_init(void );
 /**
 *@brief  : Function to write a command in LCD
 *@param  :  Copy_u8command, The command to be sent to the LCD.
 *@return : Error State                                                                     
 */
 LCD_enumError_t LCD_enuWriteCommand(u8 Copy_u8Command);
 /**
 *@brief  : Function to write a data in LCD
 *@param  :  Copy_u8Data, The data to be sent to the LCD.
 *@return : Error State                                                                     
 */
 LCD_enumError_t LCD_enuWriteData(u8 Copy_u8Data);
 /**
 *@brief  : Function to set the DDRAM at specific location
 *@param  : Copy_u8X: LCD row ( 0 or 1) , Copy_u8Y: LCD column ( 0 ~ 15 )
 *@return : Error State                                                                     
 */
 LCD_enumError_t LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y);
 /**
 *@brief  : Function to display number on LCD 
 *@param  : Copy_u8Number: number to be displayed 
 *@return : Error State                                                                     
 */
 LCD_enumError_t LCD_enuWriteNumber(u16 Copy_u8Number);
 /**
 *@brief  : Function to write string on LCD
 *@param  : Copy_pchPattern: pinter to the array that holds the string characters, Copy_u8Length: string length
 *@return : Error State                                                                     
 */
 LCD_enumError_t LCD_enuWriteString(u8* Copy_pchPattern, u8 Copy_u8Length);
 /**
 *@brief  : Function to display special character on LCD
 *@param  :  Copy_pu8Pattern: Pointer to the array that holds the special character, Copy_u8CGRAMBlockNumber: CGRAM block that hold the character
             Copy_u8X: LCD row ( 0 or 1) , Copy_u8Y: LCD column ( 0 ~ 15 )
 *@return : Error State                                                                     
 */
 LCD_enumError_t LCD_enuDisplaySpecialPattern(u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y);




#endif /* LCD_H_ */