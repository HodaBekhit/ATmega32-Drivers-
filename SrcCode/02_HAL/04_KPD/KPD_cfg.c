/*
 * KPD_cfg.c
 *
 * Created: 1/8/2024 12:30:08 AM
 *  Author: Dell
 */ 
#include "std_types.h"
#include "KPD_cfg.h"

/*Initialize the keypad configuration structure with port and pin configurations for columns and rows*/
KPD_StrCfg_t KPD =
{
	// Configuration for keypad columns
	.Columns[0] = {.PORT = DIO_enumPortB, .PIN = DIO_enumPin4},
	.Columns[1] = {.PORT = DIO_enumPortB, .PIN = DIO_enumPin5},
	.Columns[2] = {.PORT = DIO_enumPortB, .PIN = DIO_enumPin6},
	.Columns[3] = {.PORT = DIO_enumPortB, .PIN = DIO_enumPin7},
	
	// Configuration for keypad rows
	.Rows[0] = {.PORT = DIO_enumPortB, .PIN = DIO_enumPin3},
	.Rows[1] = {.PORT = DIO_enumPortB, .PIN = DIO_enumPin2},
	.Rows[2] = {.PORT = DIO_enumPortB, .PIN = DIO_enumPin1},
	.Rows[3] = {.PORT = DIO_enumPortB, .PIN = DIO_enumPin0}
};

/*Define the symbols mapped to each key in the keypad*/
u8 KPD_u8symbols[Num_of_Rows][Num_of_Columns] =
{
	{'7', '8', '9', '/'},   // Row 0
	{'4', '5', '6', '*'},   // Row 1
	{'1', '2', '3', '-'},   // Row 2
	{'c', '0', '=', '+'}    // Row 3
};
