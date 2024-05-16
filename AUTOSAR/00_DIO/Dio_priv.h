/*
 * Dio_priv.h
 *
 * Created: 12/25/2023 9:46:06 AM
 *  Author: Dell
 */ 


#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define PORTA  *((volatile u8*)0x3B)
#define PINA   *((volatile u8*)0x39)
#define DDRA   *((volatile u8*)0x3A)

#define PORTB  *((volatile u8*)0x38)
#define PINB   *((volatile u8*)0x36)
#define DDRB   *((volatile u8*)0x37)

#define PORTC  *((volatile u8*)0x35)
#define PINC   *((volatile u8*)0x33)
#define DDRC   *((volatile u8*)0x34)

#define PORTD  *((volatile u8*)0x32)
#define PIND   *((volatile u8*)0x30)
#define DDRD   *((volatile u8*)0x31)

#define DIO_RegSize 	8
#define DIO_PinsNum		31



#endif /* DIO_PRIV_H_ */