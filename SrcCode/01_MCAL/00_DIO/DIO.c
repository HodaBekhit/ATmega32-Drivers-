/*
 * DIO.c
 *
 * Created: 12/2/2023 6:27:11 PM
 *  Author: Dell
 */ 

#include "std_types.h"
#include "std_math.h"
#include "PORT_cfg.h"
#include "PORT_priv.h"
#include "DIO.h"

/*pre_compile configuration*/
/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enuErrors_Status=DIO_enumOk;
	if (Copy_enumPortNum>Num_of_Ports)
	{
		Ret_enuErrors_Status=DIO_enumWrongPort;
	}
	else if (Copy_enumPinNum>Num_of_Pins)
	{
		Ret_enuErrors_Status=DIO_enumWrongPin;
	}
	
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			CLR_BIT(PORTA,Copy_enumPinNum);
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			SET_BIT(PORTA,Copy_enumPinNum);
			break;
			case DIO_enumPortB:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			CLR_BIT(PORTB,Copy_enumPinNum);
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			SET_BIT(PORTB,Copy_enumPinNum);
			break;
			case DIO_enumPortC:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			CLR_BIT(PORTC,Copy_enumPinNum);
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			SET_BIT(PORTC,Copy_enumPinNum);
			break;
			case DIO_enumPortD:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			CLR_BIT(PORTD,Copy_enumPinNum);
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			SET_BIT(PORTD,Copy_enumPinNum);
			break;	
		}
		Ret_enuErrors_Status=DIO_enumOk;
	}
	return Ret_enuErrors_Status;
}

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enuErrors_Status=DIO_enumOk;
	if (Copy_enumPortNum>Num_of_Ports)
	{
		Ret_enuErrors_Status=DIO_enumWrongPort;
	}
	
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			PORTA=0x00;
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			PORTA=0xFF;
			break;
			case DIO_enumPortB:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			PORTB=0x00;
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			PORTB=0xFF;
			break;
			case DIO_enumPortC:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			PORTC=0x00;
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			PORTC=0xFF;
			break;
			case DIO_enumPortD:
			if(Copy_enumLogicState==DIO_enumLogicLow)
			PORTD=0x00;
			else if(Copy_enumLogicState==DIO_enumLogicHigh)
			PORTD=0xFF;
			break;
		}
		Ret_enuErrors_Status=DIO_enumOk;
	}
	return Ret_enuErrors_Status;
}
	
/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	DIO_enumError_t Ret_enuErrors_Status=DIO_enumOk;
	if (Copy_enumPortNum>Num_of_Ports)
	{
		Ret_enuErrors_Status=DIO_enumWrongPort;
	}
	else if (Copy_enumPinNum>Num_of_Pins)
	{
		Ret_enuErrors_Status=DIO_enumWrongPin;
	}
	else if (Add_Pu8PinValue==NULLPTR)
	{
		Ret_enuErrors_Status=DIO_enumNullPointer;
	}
	
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			*Add_Pu8PinValue=GET_BIT(PINA,Copy_enumPinNum);
			break;
			case DIO_enumPortB:
			*Add_Pu8PinValue=GET_BIT(PINB,Copy_enumPinNum);
			break;
			case DIO_enumPortC:
			*Add_Pu8PinValue=GET_BIT(PINC,Copy_enumPinNum);
			break;
			case DIO_enumPortD:
			*Add_Pu8PinValue=GET_BIT(PIND,Copy_enumPinNum);
			break;	
		}
		Ret_enuErrors_Status=DIO_enumOk;	
	}
	return Ret_enuErrors_Status;
}


