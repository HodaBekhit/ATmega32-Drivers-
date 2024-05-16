/*
 * PORT_cfg.h
 *
 * Created: 12/2/2023 6:26:09 PM
 *  Author: Dell
 */ 


#ifndef PORT_CFG_H_
#define PORT_CFG_H_

#include "std_types.h"

/*configuration types options: precomp_config , or postcomp_config*/
#define config_type postcomp_config

/*Port Numbers options: One_Port,Two_Ports,Three_Ports, Four_Ports */
#define Num_of_Ports Four_Ports

#if (config_type==precomp_config)
/*Pin Types options: INPUT_PU,INPUT_HI,OUTPUT_LOW, and OUTPUT_HIGH*/

#if (Num_of_Ports==One_Port || Num_of_Ports==Two_Ports || Num_of_Ports==Three_Ports || Num_of_Ports==Four_Ports)
#define DIO_PIN0 OUTPUT_LOW
#define DIO_PIN1 OUTPUT_LOW
#define DIO_PIN2 INPUT_PU
#define DIO_PIN3 INPUT_PU
#define DIO_PIN4 INPUT_PU
#define DIO_PIN5 INPUT_PU
#define DIO_PIN6 INPUT_PU
#define DIO_PIN7 INPUT_PU
#endif
#if (Num_of_Ports==Two_Ports || Num_of_Ports==Three_Ports || Num_of_Ports==Four_Ports)
#define DIO_PIN8 OUTPUT_LOW
#define DIO_PIN9 OUTPUT_LOW
#define DIO_PIN10 INPUT_PU
#define DIO_PIN11 INPUT_PU
#define DIO_PIN12 INPUT_PU
#define DIO_PIN13 INPUT_PU
#define DIO_PIN14 INPUT_PU
#define DIO_PIN15 INPUT_PU
#endif
#if (Num_of_Ports==Three_Ports || Num_of_Ports==Four_Ports)
#define DIO_PIN16 OUTPUT_LOW
#define DIO_PIN17 OUTPUT_LOW
#define DIO_PIN18 OUTPUT_LOW
#define DIO_PIN19 OUTPUT_LOW
#define DIO_PIN20 INPUT_PU
#define DIO_PIN21 INPUT_PU
#define DIO_PIN22 INPUT_PU
#define DIO_PIN23 INPUT_PU
#endif
#if (Num_of_Ports==Four_Ports)
#define DIO_PIN24 INPUT_PU
#define DIO_PIN25 INPUT_PU
#define DIO_PIN26 INPUT_PU
#define DIO_PIN27 INPUT_PU
#define DIO_PIN28 INPUT_PU
#define DIO_PIN29 INPUT_PU
#define DIO_PIN30 INPUT_PU
#define DIO_PIN31 INPUT_PU
#endif
#if (!(Num_of_Ports==One_Port ) && !(Num_of_Ports==Two_Ports) && !(Num_of_Ports==Three_Ports) && !(Num_of_Ports==Four_Ports))
#error "invalid option"
#endif

#endif

/*post_compilation configuration*/
#if (config_type==postcomp_config)
/*Pin Numbers options:8,16,24,32*/
#define Num_of_Pins 32

typedef enum
{
	PORT_enuINPUT_PU,
	PORT_enuINPUT_HI,
	PORT_enuOUTPUT_HIGH,
	PORT_enuOUTPUT_LOW
}PORT_enuPinopt_t;

typedef enum
{
	PORT_enuPORTA,
	PORT_enuPORTB,
	PORT_enuPORTC,
	PORT_enuPORTD
	}PORT_enuPortnum_t;
#endif
 
 typedef enum
 {
	Ok,
	Nok,
	Ptr_NOk,
	Port_NOK,
	CFG_NOK,
	PIN_NOK
	 }Error_state_t; /*enum to define the states of the errors*/
 typedef struct 
 {
	 PORT_enuPortnum_t PORT; /* PORT_enuPORTA, PORT_enuPORTB, PORT_enuPORTC, PORT_enuPORTD*/
	 u8 PIN; /* 0,1,2,3,4,5,6,7 */
	 PORT_enuPinopt_t config; /* PORT_enuINPUT_PU, PORT_enuINPUT_HI, PORT_enuOUTPUT_HIGH, PORT_enuOUTPUT_LOW*/
	 } Port_Strcfg_t; 

#endif /* PORT_CFG_H_ */