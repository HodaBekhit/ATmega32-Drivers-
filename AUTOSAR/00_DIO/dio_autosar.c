/*
 * dio_autosar.c
 *
 * Created: 12/23/2023 8:40:50 AM
 *  Author: Dell
 */ 
#include "std_types.h"
#include "std_math.h"
#include "dio_autosar.h"
#include "Dio_priv.h"

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	u8 Loc_u8DIO_Error;
	u8 Loc_u8DIOPort;
	u8 Loc_u8DIOPin;
	if(ChannelId>DIO_PinsNum)
	{
		Loc_u8DIO_Error=DIO_E_PARAM_INVALID_CHANNEL_ID;
		/*report the to the Loc_u8DIO_Error Det_ReportError function
		but, what should we return to Dio_LevelType at this case?! */
		 
	}
	else
	{
		Loc_u8DIOPort = ChannelId / DIO_RegSize;
		Loc_u8DIOPin = ChannelId % DIO_RegSize;

		switch (Loc_u8DIOPort)
		{
			/*PORT A*/
			case DIO_PORTA:
			return GET_BIT(PINA, Loc_u8DIOPin);
			break;

			case DIO_PORTB:
			return GET_BIT(PINB, Loc_u8DIOPin);
			break;

			case DIO_PORTC:
	     	return GET_BIT(PINC, Loc_u8DIOPin);
			break;

			case DIO_PORTD:
			return GET_BIT(PIND, Loc_u8DIOPin);
			break;

			default:
			break;
		}
	}
}

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
{
	u8 Loc_u8DIO_Error;
	u8 Loc_u8DIOPort;
	u8 Loc_u8DIOPin;
	if(ChannelId>DIO_PinsNum)
	{
		Loc_u8DIO_Error=DIO_E_PARAM_INVALID_CHANNEL_ID;
		/*report the to the Loc_u8DIO_Error Det_ReportError function
		but, what should we return to Dio_LevelType at this case?! */ 
	}
	else
	{
		Loc_u8DIOPort = ChannelId / DIO_RegSize;
		Loc_u8DIOPin = ChannelId % DIO_RegSize;

		switch (Loc_u8DIOPort)
		{
			/*PORT A*/
			case DIO_PORTA:
			if (Level == STD_HIGH)
			{
				SET_BIT(PORTA, Loc_u8DIOPin);
			}

			else if(Level == STD_LOW)
			{
				CLR_BIT(PORTA, Loc_u8DIOPin);
			}
			break;
             /*PORT B*/
			case DIO_PORTB:
			if (Level == STD_HIGH)
			{
				SET_BIT(PORTB, Loc_u8DIOPin);
			}

			else if(Level == STD_LOW)
			{
				CLR_BIT(PORTB, Loc_u8DIOPin);
			}
			break;
            /*PORT C*/
			case DIO_PORTC:
	     	if (Level == STD_HIGH)
	     	{
		     	SET_BIT(PORTC, Loc_u8DIOPin);
	     	}

	     	else if(Level == STD_LOW)
	     	{
		     	CLR_BIT(PORTC, Loc_u8DIOPin);
	     	}
			break;
             /*PORT D*/
			case DIO_PORTD:
			if (Level == STD_HIGH)
			{
				SET_BIT(PORTD, Loc_u8DIOPin);
			}

			else if(Level == STD_LOW)
			{
				CLR_BIT(PORTD, Loc_u8DIOPin);
			}
			break;

			default:
			break;
		}
	}
	
}
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	u8 Loc_u8DIO_Error;

	if(PortId>=4)
	{
		Loc_u8DIO_Error=DIO_E_PARAM_INVALID_PORT_ID;
		/*report the to the Loc_u8DIO_Error Det_ReportError function
		but, what should we return to Dio_LevelType at this case?! */
		 
	}
	else
	{
			switch (PortId)
		{
			/*PORT A*/
			case DIO_PORTA:
			return PINA;
			break;

			case DIO_PORTB:
			return PINB;
			break;

			case DIO_PORTC:
	     	return PINC;
			break;

			case DIO_PORTD:
			return PIND;
			break;

			default:
			break;
		}
	}
	
}
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
	u8 Loc_u8DIO_Error;

	if(PortId>=4)
	{
		Loc_u8DIO_Error=DIO_E_PARAM_INVALID_PORT_ID;
		/*report the to the Loc_u8DIO_Error Det_ReportError function
		but, what should we return to Dio_LevelType at this case?! */
		 
	}
	else
	{
		switch (PortId)
		{
			/*PORT A*/
			case DIO_PORTA:
			ASSIGN_REG(PORTA,Level);
			break;
             /*PORT B*/
			case DIO_PORTB:
			ASSIGN_REG(PORTB,Level);
			break;
            /*PORT C*/
			case DIO_PORTC:
	     	ASSIGN_REG(PORTC,Level);
			break;
             /*PORT D*/
			case DIO_PORTD:
			ASSIGN_REG(PORTD,Level);
			break;

			default:
			break;
		}
	}
	
}
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
	
}
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level)
{
	
}
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
	/* Description: Function to get the version information of this module.*/
}
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	u8 Loc_u8DIO_Error;
	u8 Loc_u8DIOPort;
	u8 Loc_u8DIOPin;
	if(ChannelId>DIO_PinsNum)
	{
		Loc_u8DIO_Error=DIO_E_PARAM_INVALID_CHANNEL_ID;
		/*report the to the Loc_u8DIO_Error Det_ReportError function
		but, what should we return to Dio_LevelType at this case?! */
		 
	}
	else
	{
		Loc_u8DIOPort = ChannelId / DIO_RegSize;
		Loc_u8DIOPin = ChannelId % DIO_RegSize;

		switch (Loc_u8DIOPort)
		{
			/*PORT A*/
			case DIO_PORTA:
		      TGL_BIT(PINA, Loc_u8DIOPin);
			  return GET_BIT(PINA,Loc_u8DIOPin);
			break;

			case DIO_PORTB:
			TGL_BIT(PINB, Loc_u8DIOPin);
			return GET_BIT(PINB, Loc_u8DIOPin);
			break;

			case DIO_PORTC:
			TGL_BIT(PINC, Loc_u8DIOPin);
	     	return GET_BIT(PINC, Loc_u8DIOPin);
			break;

			case DIO_PORTD:
			TGL_BIT(PIND, Loc_u8DIOPin);
			return GET_BIT(PIND, Loc_u8DIOPin);
			break;

			default:
			break;
		}
	}
}
void Dio_MaskedWritePort(Dio_PortType PortId,Dio_PortLevelType Level,Dio_PortLevelType Mask)
{
	/*If Mask has a bit set to 1, the corresponding bit in PORTX will be cleared (set to 0) if the corresponding bit in Level is 0,
	 and it will be set to 1 if the corresponding bit in Level is 1.
	If Mask has a bit set to 0, the corresponding bit in PORTX  will remain unchanged, regardless of the value of the corresponding bit in Level.*/
	u8 Loc_u8DIO_Error;

	if(PortId>=4)
	{
		Loc_u8DIO_Error=DIO_E_PARAM_INVALID_PORT_ID;
		/*report the to the Loc_u8DIO_Error Det_ReportError function
		but, what should we return to Dio_LevelType at this case?! */
		 
	}
	else
	{
		u8 temp;
		switch (PortId)
		{
			/*PORT A*/
			case DIO_PORTA:
			temp = (PORTA & ~(Mask)) | (Mask & Level);
			PORTA = temp;
			break;
             /*PORT B*/
			case DIO_PORTB:
		    temp = (PORTB & ~(Mask)) | (Mask & Level);
			PORTB = temp;
			break;
            /*PORT C*/
			case DIO_PORTC:
	     	temp = (PORTC & ~(Mask)) | (Mask & Level);
	     	PORTC= temp;
			break;
             /*PORT D*/
			case DIO_PORTD:
			temp = (PORTD & ~(Mask)) | (Mask & Level);
			PORTD = temp;
			break;

			default:
			break;
		}
	}
	
}