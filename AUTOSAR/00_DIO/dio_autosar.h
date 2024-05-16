/*
 * dio_autosar.h
 *
 * Created: 12/23/2023 8:41:30 AM
 *  Author: Dell
 */ 


#ifndef DIO_AUTOSAR_H_
#define DIO_AUTOSAR_H_

#include "std_types.h"

/*----------Development Errors-----------*/

/*Invalid channel requested*/
#define DIO_E_PARAM_INVALID_CHANNEL_ID 0x0A
/*Invalid port requested*/
#define DIO_E_PARAM_INVALID_PORT_ID 0x14
/*Invalid channel group requested*/
#define DIO_E_PARAM_INVALID_GROUP 0x1F
/*API service called with a NULL pointer*/
#define DIO_E_PARAM_POINTER 0x20


/*---------type definitions------------*/

/*Numeric ID of a DIO channel*/
typedef u8 Dio_ChannelType;

/*Numeric ID of a DIO port*/
typedef u8 Dio_PortType;

/*Type for the definition of a channel group, which consists of several adjoining channels within a port.*/
typedef struct  
{
	u8 mask ;
	u8 offset ;
	Dio_PortType port ;
}Dio_ChannelGroupType;

/*the possible levels a DIO channel can have (input or output) 
 (STD_LOW/STD_HIGH)*/
typedef u8 Dio_LevelType;

/*If the µC owns ports of different port widths (e.g. 4, 8,16...Bit),
Dio_PortLevelType inherits the size of the largest port.*/
typedef u8 Dio_PortLevelType;

#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3



/*---------functions definitions------------*/

/**
 *@brief  : Returns the value of the specified DIO channel.
 *@param  : ID of DIO channel
 *@return : Dio_LevelType
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/**
 *@brief  : Service to set a level of a channel.
 *@param  : ID of DIO channel
 *@return : None 
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);

/**
 *@brief  : Returns the level of all channels of that port.
 *@param  : ID of DIO Port
 *@return : Dio_PortLevelType
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/**
 *@brief  : Service to set a value of the port.
 *@param  : PortId:ID of DIO Port
            Level:Value to be written
 *@return : None
 */
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);

/**
 *@brief  : This Service reads a subset of the adjoining bits of a port.
 *@param  : Pointer to ChannelGroup
 *@return : Dio_PortLevelType
 */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

/**
 *@brief  : Service to set a subset of the adjoining bits of a port to a specified level.
 *@param  : ChannelGroupIdPtr:Pointer to ChannelGroup
            Level : Value to be written
 *@return : None
 */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);

/**
 *@brief  : Service to get the version information of this module.
 *@param  : VersionInfo:Pointer to where to store the version information of this module.
 *@return : None
 */
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);

/**
 *@brief  : Service to flip (change from 1 to 0 or from 0 to 1) the level
  of a channel and return the level of the channel after flip.
 *@param  : ID of DIO channel
 *@return : Dio_LevelType
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

/**
 *@brief  : Service to set the value of a given port with required mask.
 *@param  : PortId:ID of DIO Port
            Level:Value to be written
            Mask:Channels to be masked in the port
 *@return : None
 */
void Dio_MaskedWritePort(Dio_PortType PortId,Dio_PortLevelType Level,Dio_PortLevelType Mask);













#endif /* DIO_AUTOSAR_H_ */