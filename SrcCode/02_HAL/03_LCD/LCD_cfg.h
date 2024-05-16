/*
 * LCD_cfg.h
 *
 * Created: 1/2/2024 11:20:18 AM
 *  Author: Dell
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "DIO.h"

/*********** LCD common instruction for 8 bit mode **********/

/* Clears entire display and sets DDRAM address to 00H.*/
#define LCD_HOME  0x02

/* Sets DDRAM address to 00H in AC and returns shifted display to its original position. 
 The contents of DDRAM remain unchanged. */
#define LCD_ENTRYMODE  0x06

/* Set display (D) OFF, cursor OFF(C), and blinking(B) OFF.*/
#define LCD_DISPOFF  0x08

/* Set display (D) ON, cursor ON(C), and blinking(B) OFF.*/
#define LCD_DISPON_CURSON_BLOFF  0x0E

/* Set display (D) ON, cursor ON(C), and blinking(B) ON.*/
#define LCD_DISPON_CURSON_BLON 0x0F

/* Set display (D) ON, cursor OFF(C), and blinking(B) OFF.*/
#define LCD_DISPON_CURSOFF_BLOFF  0x0C

/* Sets numbers of display line (N: 2-line), and display font type (F:5x8dots)*/
#define LCD_FUNCSET_8BIT  0x38

/* first position on DDRAM*/
#define LCD_SETCURSOR  0x80

/* first position on CGRAM*/
#define LCD_CGRAM_ADD       0x40

/********** LCD current working mode *********/
/* options : _4_BitMode, or _8_BitMode*/
#define LCD_BitMode _8_BitMode

/*********** LCD configuration stuct *********/
typedef struct
{
	DIO_enumPorts_t PORT; 
	DIO_enumPins_t PIN;
	}LCD_StrCgf_t;

/********* LCD error types********/
typedef enum
{
 LCD_enuOk,            /* Operation successful */
 LCD_enuNullPtr ,      /*Null Pointer*/
 LCD_enuWrongPosition, /*wrong x,y position at DDRAM*/
 LCD_WrongBlockNum     /*Wrong block number at CGRAM*/	
} LCD_enumError_t;



#endif /* LCD_CFG_H_ */