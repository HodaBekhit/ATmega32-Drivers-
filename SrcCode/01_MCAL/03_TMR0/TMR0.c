/*
 * TMR0.c
 *
 * Created: 2/24/2024 2:14:35 PM
 *  Author: Dell
 */ 

#include "Timers_priv.h"
#include "TMR0_cfg.h"

/*** masks ***/
#define WGM_MASK 0x48
#define CS_MASK 0x07
#define COM_MASK 0x30

void (*TMR0_OF_ISR) (void) = NULLPTR;
void (*TMR0_CTC_ISR) (void) = NULLPTR;

/*** TIMER0 preload values, this values are the results of preload calculation , assumimg that prescalar = 1024 ***/
const u8 TMR0_PRELOAD_VALUES[NUM_OF_SUPPORTED_PERIODS]={
	[_100MS_TICK_TIME]=243,
	[_500MS_TICK_TIME]=190,
	[_1S_TICK_TIME]=124,
	[_2S_TICK_TIME]=247,
	[_5S_TICK_TIME]=106
	};
	
/*** TIMER0 No of overflows, this values are the results of overflow calculation , assumimg that prescalar = 1024 ***/	
const u8 TMR0_NUM_OF_OVERFLOW[NUM_OF_SUPPORTED_PERIODS]={
	[_100MS_TICK_TIME]=4,
	[_500MS_TICK_TIME]=16,
	[_1S_TICK_TIME]=31,
	[_2S_TICK_TIME]=62,
	[_5S_TICK_TIME]=153
};
/*** TIMER0 ocr0 values, this values are the results of ocr0 calculation , assumimg that prescalar = 1024 ***/
const u8 TMR0_OCR0_VALUES[NUM_OF_SUPPORTED_PERIODS]={
	[_100MS_TICK_TIME]=195,
	[_500MS_TICK_TIME]=255,
	[_1S_TICK_TIME]=255,
	[_2S_TICK_TIME]=255,
	[_5S_TICK_TIME]=255
};

/*** TIMER0 No of compare match, assumimg that prescalar = 1024 ***/
const u8 TMR0_NUM_OF_COMPAREMATCH[NUM_OF_SUPPORTED_PERIODS]={
	[_100MS_TICK_TIME]=4,
	[_500MS_TICK_TIME]=16,
	[_1S_TICK_TIME]=31,
	[_2S_TICK_TIME]=62,
	[_5S_TICK_TIME]=153
};

u8 TMR0_RequiredTime;

void TMR0_voidInitPreCompile(void)
{
	u8 Loc_u8RegisterValue;
	/*TMR0 MODE*/
	Loc_u8RegisterValue=TCCR0;
	Loc_u8RegisterValue&=~(WGM_MASK);
	Loc_u8RegisterValue|=TMR0_MODE;
	TCCR0=Loc_u8RegisterValue;
	/*TMR0 Compare Match Output Mode*/
	Loc_u8RegisterValue=TCCR0;
	Loc_u8RegisterValue&=~(COM_MASK);
	Loc_u8RegisterValue|=TMR0_OC0;
	TCCR0=Loc_u8RegisterValue;
	
}

TMR0_enuErrorStatus_t TMR0_voidInitPostCompile(TMR0Config_t *Copy_strTimerConfig)
{
	TMR0_enuErrorStatus_t RET_TMR0_ERROR=TMR0_OK;
	u8 Loc_u8RegisterValue;
	/*TMR0 MODE*/
	Loc_u8RegisterValue=TCCR0;
	Loc_u8RegisterValue&=~(WGM_MASK);
	Loc_u8RegisterValue|=Copy_strTimerConfig->TMR0_WGM;
	TCCR0=Loc_u8RegisterValue;
	/*TMR0 Compare Match Output Mode*/
	Loc_u8RegisterValue=TCCR0;
	Loc_u8RegisterValue&=~(COM_MASK);
	Loc_u8RegisterValue|=Copy_strTimerConfig->TMR0_COM;
	TCCR0=Loc_u8RegisterValue;
	/*TMR0 CLOCK SOURCE 
	Loc_u8RegisterValue=TCCR0;
	Loc_u8RegisterValue&=~(CS_MASK);
	Loc_u8RegisterValue|=Copy_strTimerConfig->TMR0_CLOCKSOURCE;
	TCCR0=Loc_u8RegisterValue;*/
	return RET_TMR0_ERROR;
	
}

TMR0_enuErrorStatus_t TMR0_enuSetTickTimeMS(u8 Copy_u8DesiredTime, u8 Copy_u8InterruptSource)
{
	TMR0_enuErrorStatus_t RET_TMR0_ERROR=TMR0_OK;
	/*TMR0_RequiredTime will be used in ISR*/
	TMR0_RequiredTime=Copy_u8DesiredTime;
	switch(Copy_u8InterruptSource)
	{
		case TMR0_Normal:
		/*Set Preload Value*/
		TCNT0=TMR0_PRELOAD_VALUES[Copy_u8DesiredTime];
		/* enable overflow interrupt */
		 TIMSK|=(1<<TOIE0); 
		break;
		
		case TMR0_CTC:
		/*set ocr0 with value*/
		OCR0=TMR0_OCR0_VALUES[Copy_u8DesiredTime];
		/* enable compare match interrupt */
		TIMSK|=(1<<OCIE0);
		break;
	}
	/* Enable Global Interrupt*/
	SREG |= (1 << 7);
	return RET_TMR0_ERROR;
}

TMR0_enuErrorStatus_t TMR0_enuStart(void)
{
	TMR0_enuErrorStatus_t RET_TMR0_ERROR=TMR0_OK;
	/*Timer start counting once it given clock source*/
	u8 Loc_u8RegisterValue;
	
	/*TMR0 CLOCK SOURCE: prescalar 1024 in our case */
	Loc_u8RegisterValue=TCCR0;
	Loc_u8RegisterValue&=~(CS_MASK);
	Loc_u8RegisterValue|=TMR0_CLKSRC;
	TCCR0=Loc_u8RegisterValue;
	return RET_TMR0_ERROR;
}

TMR0_enuErrorStatus_t TMR0_enuSetDutyCycleFastPWM(u8 Copy_u8DutyCycle, u8 Copy_u8PWMType)
{
	TMR0_enuErrorStatus_t RET_TMR0_ERROR=TMR0_OK;
	
	switch(Copy_u8PWMType)
	{
		case TMR0_FastPWM_NonInverting:
		OCR0=(u8)(Copy_u8DutyCycle*255)/100;
		break;
		case TMR0_FastPWM_Inverting:
		OCR0=(u8)(255 - (Copy_u8DutyCycle * 255) / 100);
		break;
	}
	return RET_TMR0_ERROR;
}

TMR0_enuErrorStatus_t TMR0_enuSetDutyCyclePhaseCorrection(u8 Copy_u8DutyCycle, u8 Copy_u8PWMType)
{
	TMR0_enuErrorStatus_t RET_TMR0_ERROR=TMR0_OK;
	
	switch(Copy_u8PWMType)
	{
		case TMR0_FastPWM_NonInverting:
		OCR0=(Copy_u8DutyCycle*255)/100;
		break;
		case TMR0_FastPWM_Inverting:
		OCR0=(255-(Copy_u8DutyCycle*255))/100;
		break;
	}
	return RET_TMR0_ERROR;
	
}

TMR0_enuErrorStatus_t TMR0_enuSetCallBack(u8 Copy_u8InterruptSource, void (*fun)(void))
{
	TMR0_enuErrorStatus_t RET_TMR0_ERROR=TMR0_OK;
	switch(Copy_u8InterruptSource)
	{
		case TMR0_Normal:
		TMR0_OF_ISR=fun;
		break;
		
		case TMR0_CTC:
		TMR0_CTC_ISR=fun;
		break;
	}
	return RET_TMR0_ERROR;
}

/*** Timer/Counter0 Overflow ***/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u8 LOC_COUNTER=0;
	LOC_COUNTER++;
	if(LOC_COUNTER==TMR0_NUM_OF_OVERFLOW[TMR0_RequiredTime])
	{
		TCNT0=TMR0_PRELOAD_VALUES[TMR0_RequiredTime];
		LOC_COUNTER=0;
		/*action*/
		TMR0_OF_ISR();
		
	}
}

/*** Timer/Counter0 Compare Match ***/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u8 LOC_COUNTER=0;
	LOC_COUNTER++;
	if(LOC_COUNTER==TMR0_NUM_OF_COMPAREMATCH[TMR0_RequiredTime])
	{
		LOC_COUNTER=0;
		/*action*/
		TMR0_CTC_ISR();
		
	}
}