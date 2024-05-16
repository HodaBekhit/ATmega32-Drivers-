/*
 * TMR0_cfg.h
 *
 * Created: 2/24/2024 2:37:06 PM
 *  Author: Dell
 */ 


#ifndef TMR0_CFG_H_
#define TMR0_CFG_H_

#include "TMR0.h"

/*
 * Waveform Generation Mode (TMR0_MODE):
 * Choose the desired waveform generation mode for TIMER0.
 * Options:
 * - TMR0_Normal 
 * - TMR0_CTC
 * - TMR0_PWM_PhaseCorrect
 * - TMR0_FastPWM
 */
#define TMR0_MODE TMR0_Normal

/*
 * Compare Output Mode (TMR0_OC0):
 * Choose the desired compare output mode.
 * Options when not in PWM mode.:
 * - TMR0_OC0_DISCONNECTED
 * - TMR0_OC0_TOGGLE
 * - TMR0_OC0_CLEAR
 * - TMR0_OC0_SET
 * Options when in Fast PWM mode:
 * - TMR0_FastPWM_NonInverting
 * - TMR0_FastPWM_Inverting
 * Options when in Phase Correct PWM mode:
 * - TMR0_PhaseCorrectPWM_NonInverting
 * - TMR0_PhaseCorrectPWM_Inverting
 */
#define TMR0_OC0 TMR0_OC0_DISCONNECTED

/*
 * Clock Select (TMR0_CLKSRC):
 * Choose the clock source and prescaler for Timer0.
 * Options:
 * - TMR0_NOCLOCKSOURCE
 * - TMR0_NOPRESCALAR
 * - TMR0_PRESCALAR_8
 * - TMR0_PRESCALAR_64
 * - TMR0_PRESCALAR_256
 * - TMR0_PRESCALAR_1024
 * - TMR0_EXTCLK_FALLING
 * - TMR0_EXTCLK_RISING
 */
#define TMR0_CLKSRC TMR0_PRESCALAR_1024




#endif /* TMR0_CFG_H_ */