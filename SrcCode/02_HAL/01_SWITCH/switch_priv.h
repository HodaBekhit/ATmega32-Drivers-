/*
 * switch_priv.h
 *
 * Created: 12/12/2023 11:03:29 PM
 *  Author: Dell
 */ 


#ifndef switch_PRIV_H_
#define switch_PRIV_H_

typedef enum
{
	switch_enumPortA ,
	switch_enumPortB ,
	switch_enumPortC ,
	switch_enumPortD 
	} Switch_enu_PortNum_t;

typedef enum
{
	switch_enumPin0,
	switch_enumPin1,
	switch_enumPin2,
	switch_enumPin3,
	switch_enumPin4,
	switch_enumPin5,
	switch_enumPin6,
	switch_enumPin7
	} Switch_enu_PinNum_t ;

typedef enum
{
   switch_enum_INPUTPU, /* input pull up */
   switch_enum_INPUTPD /* input pull dowm */
   
	} Switch_enu_ActiveState_t ;
	
typedef enum
{
	switch_enum_ON, /* switch off */
	switch_enum_OFF /* switch on */
	
} Switch_enumLogicState_t ;
	
typedef enum
{
	Switch_enu_Ok,
	Switch_enu_Nok,
	Switch_enu_NullPtr,
	Switch_enu_WrongName
} Switch_enum_Error_t;


#endif /* switch_PRIV_H_ */