/*
 * EXTI.h
 *
 * Created: 12/24/2023 7:34:07 PM
 *  Author: Dell
 */ 


#ifndef EXTI_H_
#define EXTI_H_

/** functions prototypes **/

/*initialization functions for the three INT PINS*/
 void EXTI_void_Init(void);
 void EXTI_vidRegisterEXTI0Cbf (void (*arg) (void));
 void EXTI_vidRegisterEXTI1Cbf (void (*arg) (void));
 void EXTI_vidRegisterEXTI2Cbf (void (*arg) (void));





#endif /* EXTI_H_ */