/*
 * KPD.h
 *
 * Created: 1/8/2024 12:29:32 AM
 *  Author: Dell
 */ 


#ifndef KPD_H_
#define KPD_H_

#include "KPD_cfg.h"

/**
 * @brief :  Configure the Keypad Port,Pin, and Direction.
 * @param :  none
 * @return:  none
 */
void KPD_enuInit(void);

/**
 * @brief	  :	Function to get the pressed key value from the configured keypad
 * @param[in] : none
 * @param[out]: Add_u8KeyValue-> pointer to the value of the pressed key
 * @return	  : KPD_enumError_t-> Error status
 */
KPD_enumError_t	KPD_enuGetKeyValue(u8* Add_u8KeyValue);



#endif /* KPD_H_ */