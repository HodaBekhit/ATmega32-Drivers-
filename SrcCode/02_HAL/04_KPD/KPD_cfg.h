/*
 * KPD_cfg.h
 *
 * Created: 1/8/2024 12:30:27 AM
 *  Author: Dell
 */ 


#ifndef KPD_CFG_H_
#define KPD_CFG_H_

#include "DIO.h"

/*Define the number of rows and columns for the keypad*/
#define Num_of_Rows 4
#define Num_of_Columns 4

/*Define an enumeration for error types in the keypad*/
typedef enum
{
	KPD_enuOK,        // No error, operation successful
	KPD_enuNullPtr    // Null pointer error
} KPD_enumError_t;

/*Define a structure to hold configuration information for a single key port and pin*/
typedef struct
{
	DIO_enumPorts_t PORT;    // Port of the pin
	DIO_enumPins_t PIN;      // Pin number
	DIO_enumConfig_t CFG;    // Configuration of the pin
} KPD_StrPortPinCfg_t;

/*Define a structure to hold configuration information for the entire keypad*/
typedef struct
{
	KPD_StrPortPinCfg_t Columns[Num_of_Columns];  // Configuration for keypad columns
	KPD_StrPortPinCfg_t Rows[Num_of_Rows];        // Configuration for keypad rows
} KPD_StrCfg_t;


#endif /* KPD_CFG_H_ */