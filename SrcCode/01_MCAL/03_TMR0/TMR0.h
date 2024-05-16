/*
 * TMR0.h
 *
 * Created: 2/24/2024 1:48:24 PM
 *  Author: Dell
 */ 


#ifndef TMR0_H_
#define TMR0_H_

#include "std_types.h"

/*** Waveform Generation Mode ***/
#define TMR0_Normal 0x00
#define TMR0_CTC 0x08
#define TMR0_PWM_PhaseCorrect 0x40
#define TMR0_FastPWM 0x48

/*** Compare Output Mode, non-PWM Mode ***/
#define TMR0_OC0_DISCONNECTED 0x00
#define TMR0_OC0_TOGGLE 0x10
#define TMR0_OC0_CLEAR 0x20
#define TMR0_OC0_SET 0x30

/*** Compare Output Mode, Fast PWM Mode ***/
#define TMR0_FastPWM_NonInverting 0x20
#define TMR0_FastPWM_Inverting 0x30
 
/*** Compare Output Mode, Phase Correct PWM Mode ***/
#define TMR0_PhaseCorrectPWM_NonInverting 0x20
#define TMR0_PhaseCorrectPWM_Inverting 0x30

/**** Clock Select ***/
#define TMR0_NOCLOCKSOURCE      0x00
#define TMR0_NOPRESCALAR        0x01
#define TMR0_PRESCALAR_8        0x02
#define TMR0_PRESCALAR_64       0x03
#define TMR0_PRESCALAR_256      0x04
#define TMR0_PRESCALAR_1024     0x05
#define TMR0_EXTCLK_FALLING     0x06
#define TMR0_EXTCLK_RISING      0x07


/*** Desired Time ***/
#define _100MS_TICK_TIME 0
#define _500MS_TICK_TIME 1
#define _1S_TICK_TIME 2
#define _2S_TICK_TIME 3
#define _5S_TICK_TIME 4
#define NUM_OF_SUPPORTED_PERIODS 5

/*** Duty Cycles ***/
#define _25_DUTY_CYCLE 0
#define _50_DUTY_CYCLE 1
#define _75_DUTY_CYCLE 2
#define _100_DUTY_CYCLE 3
#define NUM_OF_SUPPORTED_DUTY_CYCLES 4

/*** TMR0 Configuration parameters ***/
typedef struct  
{
	u8 TMR0_WGM;
	u8 TMR0_COM;
	u8 TMR0_CLOCKSOURCE;
}TMR0Config_t;

/*** TMR0 Error status ***/
typedef enum
{
	TMR0_OK,
	TMR0_NOK
}TMR0_enuErrorStatus_t;


/**** Functions Prototypes ****/

/**
 * @brief Initialize the Timer 0 (TMR0) driver with pre-compiled settings.
 * 
 * This function performs the initialization of the TMR0 module with a predefined configuration.
 * It should be called before any other TMR0-related functions to ensure the timer is set up correctly.
 */
void TMR0_voidInitPreCompile(void);

/**
 * @brief Initialize the Timer 0 (TMR0) driver with user-provided configuration.
 * 
 * @param Copy_strTimerConfig Pointer to a TMR0Config_t structure that contains the desired timer configuration.
 * @return TMR0_enuErrorStatus_t Error status of the initialization process.
 * 
 * This function allows for post-compilation initialization of the TMR0 module, enabling the user to
 * specify a configuration at run-time. 
 */
TMR0_enuErrorStatus_t TMR0_voidInitPostCompile(TMR0Config_t *Copy_strTimerConfig);

/**
 * @brief Set the desired tick time and interrupt source for Timer 0.
 * 
 * @param Copy_u8DesiredTime The desired tick time, which can be one of the predefined constants:
 *        100MS_TICK_TIME, 500MS_TICK_TIME, 1S_TICK_TIME, 2S_TICK_TIME, 5S_TICK_TIME.
 * @param Copy_u8InterruptSource The interrupt source, which can be either OVERFLOW or COMPARE_MATCH.
 * @return TMR0_enuErrorStatus_t Error status of the tick time setting process.
 * 
 * This function configures the tick time for the TMR0 module and specifies whether an interrupt should
 * be generated on an overflow or a compare match event. It returns an error status to indicate the success
 * or nature of any failure in setting the tick time.
 */
TMR0_enuErrorStatus_t TMR0_enuSetTickTimeMS(u8 Copy_u8DesiredTime, u8 Copy_u8InterruptSource);

/**
 * @brief Start Timer 0 to begin counting.
 * 
 * @return TMR0_enuErrorStatus_t Error status of the start process.
 * 
 * This function activates TMR0 to start counting based on the previously configured settings.
 * It returns an error status to indicate the success or nature of any failure in starting the timer.
 */
TMR0_enuErrorStatus_t TMR0_enuStart(void);

/**
 * @brief Set the duty cycle for Timer 0 in Fast PWM mode.
 * 
 * @param Copy_u8DutyCycle The desired duty cycle value.
 * @param Copy_u8PWMType The PWM type, which can be either INVERTED or NON_INVERTED.
 * @return TMR0_enuErrorStatus_t Error status of the duty cycle setting process.
 * 
 * This function configures the duty cycle for TMR0 when operating in Fast PWM mode. The duty cycle and PWM type
 * are specified by the user. It returns an error status to indicate success or the nature of any failure in setting
 * the duty cycle.
 */
TMR0_enuErrorStatus_t TMR0_enuSetDutyCycleFastPWM(u8 Copy_u8DutyCycle, u8 Copy_u8PWMType);

/**
 * @brief Set the duty cycle for Timer 0 in Phase Correct PWM mode.
 * 
 * @param Copy_u8DutyCycle The desired duty cycle value.
 * @param Copy_u8PWMType The PWM type, which can be either INVERTED or NON_INVERTED.
 * @return TMR0_enuErrorStatus_t Error status of the duty cycle setting process.
 * 
 * This function configures the duty cycle for TMR0 when operating in Phase Correct PWM mode. It allows
 * for finer control of the PWM waveform compared to Fast PWM mode. It returns an error status to indicate
 * the success or nature of any failure in setting the duty cycle.
 */
TMR0_enuErrorStatus_t TMR0_enuSetDutyCyclePhaseCorrection(u8 Copy_u8DutyCycle, u8 Copy_u8PWMType);

TMR0_enuErrorStatus_t TMR0_enuSetCallBack(u8 Copy_u8InterruptSource, void (*fun)(void));




#endif /* TMR0_H_ */