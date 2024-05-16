/*
 * EXTI_priv.h
 *
 * Created: 12/24/2023 7:34:26 PM
 *  Author: Dell
 */ 


#include "std_types.h"
#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

#define MCUCR *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR *((volatile u8*)0x5B)
#define GIFR *((volatile u8*)0x5A)
#define SREG *((volatile u8*)0x5F)

#define EXTI_enable 1
#define EXTI_disable 0

#define INT0_LOW 0x00
#define INT0_CH 0x01
#define INT0_FE 0x02
#define INT0_RE 0x03

#define INT1_LOW 0x00
#define INT1_CH 0x04
#define INT1_FE 0x08
#define INT1_RE 0x0C

#define INT2_FE 0x00
#define INT2_RE 0x40

#define INT0_MASK 0xFC
#define INT1_MASK 0xF3
#define INT2_MASK 0xBF


typedef enum
{
	INT0,
	INT1,
	INT2
	}EXTI_enumID_t;

typedef enum
{
	/**
	 *@brief : Everything Ok, Function Performed Correctly.
	 */
	EXTI_enumOk,             
	/**
	 *@brief : NULL Pointer is passed.
	 */
	EXTI_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	EXTI_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	EXTI_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	EXTI_enumWrongMode    
	
	}EXTI_enumError_t;
	
typedef struct 
{
	u8 EXTI_EN_DIS;
	u8 EXTI_MODE;
	}EXTI_StrCfg_t;

#endif /* EXTI_PRIV_H_ */