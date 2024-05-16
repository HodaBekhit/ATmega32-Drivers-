/*
 * PORT_priv.h
 *
 * Created: 12/3/2023 10:12:29 AM
 *  Author: Dell
 */ 


#ifndef PORT_PRIV_H_
#define PORT_PRIV_H_

#define HELPER(p7,p6,p5,p4,p3,p2,p1,p0) 0b##p7##p6##p5##p4##p3##p2##p1##p0
#define CONCAT(p7,p6,p5,p4,p3,p2,p1,p0) HELPER(p7,p6,p5,p4,p3,p2,p1,p0)

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


#define precomp_config 1
#define postcomp_config 2

#define One_Port 1
#define Two_Ports 2
#define Three_Ports 3
#define Four_Ports 4

#define PORT_LOW 0
#define PORT_HIGH 1

#define INPUT_PU 1
#define INPUT_HI 2
#define OUTPUT_LOW 3
#define OUTPUT_HIGH 4




#endif /* PORT_PRIV_H_ */