/*
 * EXTI.c
 *
 * Created: 12/24/2023 7:33:03 PM
 *  Author: Dell
 */ 

#include "std_types.h"
#include "std_math.h"
#include "EXTI_priv.h"

extern EXTI_StrCfg_t EXTI[3];

void (*EXTI0_ISR) (void) = NULLPTR;
void (*EXTI1_ISR) (void) = NULLPTR;
void (*EXTI2_ISR) (void) = NULLPTR;

void EXTI_void_Init(void)
{
	u8 Loc_EXTI_counter;
	for (Loc_EXTI_counter=0;Loc_EXTI_counter<3;Loc_EXTI_counter++)
	{
		if(EXTI[Loc_EXTI_counter].EXTI_EN_DIS==EXTI_enable )
		{
			u8 Loc_EXTI_Temp = 0;
			/* Enable Global Interrupt*/
			SREG |= (1 << 7);
			/*External Interrupt Enable, and control bits for interrupt sense control */
			switch(Loc_EXTI_counter)
			{
				case INT0:
				GICR|=(1<<6);
				Loc_EXTI_Temp = MCUCR;
				Loc_EXTI_Temp &= INT0_MASK;
				Loc_EXTI_Temp|=EXTI[INT0].EXTI_MODE ;
				MCUCR =Loc_EXTI_Temp;
				break;
				
				case INT1:
				GICR|=(1<<7);
				Loc_EXTI_Temp = MCUCR;
				Loc_EXTI_Temp &= INT1_MASK;
				Loc_EXTI_Temp|=EXTI[INT1].EXTI_MODE ;
				MCUCR =Loc_EXTI_Temp;
				break;
				
				case INT2:
				GICR|=(1<<5);
				Loc_EXTI_Temp = MCUCSR;
				Loc_EXTI_Temp &= INT2_MASK;
				Loc_EXTI_Temp|=EXTI[INT2].EXTI_MODE ;
				MCUCR =Loc_EXTI_Temp;
				break;
				default: 
				break;
			}
		}
		else if(EXTI[Loc_EXTI_counter].EXTI_EN_DIS==EXTI_disable)
		{
			//do nothing 
		}
	}
}




void EXTI_vidRegisterEXTI0Cbf (void (*arg) (void))
{
	if(arg == NULLPTR)
	{
		
	}
	else
	{
		EXTI0_ISR = arg;
	}
}

void EXTI_vidRegisterEXTI1Cbf (void (*arg) (void))
{
	if(arg == NULLPTR)
	{
		
	}
	else
	{
		EXTI1_ISR = arg;
	}
}


void EXTI_vidRegisterEXTI2Cbf (void (*arg) (void))
{
	if(arg == NULLPTR)
	{
		
	}
	else
	{
		EXTI2_ISR = arg;
	}
}



/* ISR of EXT0 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI0_ISR==NULLPTR)
	{
		
	}
	else
	{
		EXTI0_ISR();
	}
}


/* ISR of EXT1 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI1_ISR==NULLPTR)
	{
		
	}
	else
	{
		EXTI1_ISR();
	}
}


/* ISR of EXT2 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI2_ISR==NULLPTR)
	{
		
	}
	else
	{
		EXTI2_ISR();
	}
}