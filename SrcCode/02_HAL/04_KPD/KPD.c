/*
 * KPD.c
 *
 * Created: 1/8/2024 12:29:48 AM
 *  Author: Dell
 */ 
#include "KPD_cfg.h"
#include "PORT.h"

/* Declaration of external variables */
extern KPD_StrCfg_t KPD;                   
extern u8 KPD_u8symbols[Num_of_Rows][Num_of_Columns];

/**
 * @brief :  Configure the Keypad Port, Pin, and Direction.
 * @param :  none
 * @return:  none
 */
void KPD_enuInit(void)
{
	 // Temporary array to hold keypad configurations
    Port_Strcfg_t Current_KPD[Num_of_Columns];  
    u8 Loc_u8KPDIter;                            
    
    /* configure columns */
    for(Loc_u8KPDIter = 0; Loc_u8KPDIter < Num_of_Columns; Loc_u8KPDIter++)
    {
        // Copy column configurations from KPD structure to temporary array
        Current_KPD[Loc_u8KPDIter].PORT = KPD.Columns[Loc_u8KPDIter].PORT;
        Current_KPD[Loc_u8KPDIter].PIN = KPD.Columns[Loc_u8KPDIter].PIN;
        Current_KPD[Loc_u8KPDIter].config = DIO_enumOutputHigh; 
    }
    PORT_SetCfg(Current_KPD, Num_of_Columns);  
    
    /* configure rows */
    for(Loc_u8KPDIter = 0; Loc_u8KPDIter < Num_of_Rows; Loc_u8KPDIter++)
    {
        // Copy row configurations from KPD structure to temporary array
        Current_KPD[Loc_u8KPDIter].PORT = KPD.Rows[Loc_u8KPDIter].PORT;
        Current_KPD[Loc_u8KPDIter].PIN = KPD.Rows[Loc_u8KPDIter].PIN;
        Current_KPD[Loc_u8KPDIter].config = DIO_enumInputInternalPU; 
    }
    PORT_SetCfg(Current_KPD, Num_of_Rows); // Configure rows using temporary array
}

/**
 * @brief	  :	Function to get the pressed key value from the configured keypad
 * @param[in] : none
 * @param[out]: Add_u8KeyValue-> pointer to the value of the pressed key
 * @return	  : KPD_enumError_t-> Error status
 */
KPD_enumError_t KPD_enuGetKeyValue(u8* Add_u8KeyValue)
{
	// Initialize error status to OK
    KPD_enumError_t Loc_enuErrorState = KPD_enuOK; 
    
    if (Add_u8KeyValue == NULLPTR)
    {
		// Check for NULL pointer error
        Loc_enuErrorState = KPD_enuNullPtr; 
    }
    
    u8 Loc_u8ColCounter;
    u8 Loc_u8RowCounter;
    
    
    for (Loc_u8ColCounter = 0; Loc_u8ColCounter < Num_of_Columns; Loc_u8ColCounter++)
    {
        // Set current column pin low to scan rows
        DIO_enumSetPin(KPD.Columns[Loc_u8ColCounter].PORT, KPD.Columns[Loc_u8ColCounter].PIN, DIO_enumLogicLow);
        
        // Loop through each row
        for (Loc_u8RowCounter = 0; Loc_u8RowCounter < Num_of_Rows; Loc_u8RowCounter++)
        {
            DIO_enumLogicState_t DIO_u8PinValue;
            // Read the state of the current row pin
            DIO_enumReadState(KPD.Rows[Loc_u8RowCounter].PORT, KPD.Rows[Loc_u8RowCounter].PIN, &DIO_u8PinValue);
            
            // Check if the pin is low (key pressed)
            if (DIO_u8PinValue == DIO_enumLogicLow)
            {
                *Add_u8KeyValue = KPD_u8symbols[Loc_u8RowCounter][Loc_u8ColCounter]; // Get the symbol corresponding to the pressed key
                
                // Wait until key is released
                while (DIO_u8PinValue == DIO_enumLogicLow)
                {
                    DIO_enumReadState(KPD.Rows[Loc_u8RowCounter].PORT, KPD.Rows[Loc_u8RowCounter].PIN, &DIO_u8PinValue);
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        // Set current column pin high after scanning rows
        DIO_enumSetPin(KPD.Columns[Loc_u8ColCounter].PORT, KPD.Columns[Loc_u8ColCounter].PIN, DIO_enumLogicHigh);
    }
    
    return Loc_enuErrorState; 
}
