/*
 * PORT.c
 *
 * Created: 12/2/2023 6:24:55 PM
 *  Author: Dell
 */ 
#include "std_types.h"
#include "std_math.h"
#include "PORT_priv.h"
#include "PORT_cfg.h"
#include "PORT.h"

#if (config_type==postcomp_config)
extern const PORT_enuPinopt_t PORT_Pincfg[32];
#endif

void PORT_vidInit(void)
{
/*pre_compile configuration*/
#if config_type==precomp_config
    /*One/Two/Three/Four Port config.*/
	#if (Num_of_Ports==One_Port || Num_of_Ports==Two_Ports || Num_of_Ports==Three_Ports || Num_of_Ports==Four_Ports)
	
	//PIN0
	 #if DIO_PIN0==INPUT_PU
	 #define PIN0_DIR PORT_LOW
	 #define PIN0_PORT PORT_HIGH
	 #elif DIO_PIN0==INPUT_HI
	 #define PIN0_DIR PORT_LOW
	 #define PIN0_PORT PORT_LOW 
	 #elif DIO_PIN0==OUTPUT_HIGH
	 #define PIN0_DIR PORT_HIGH
	 #define PIN0_PORT PORT_HIGH
	 #elif DIO_PIN0==OUTPUT_LOW
	 #define PIN0_DIR PORT_HIGH
	 #define PIN0_PORT PORT_LOW
	 #else 
	 #error "invalid_config"
	 #endif
	 
	 //PIN 1
	 #if DIO_PIN1==INPUT_PU
	 #define PIN1_DIR PORT_LOW
	 #define PIN1_PORT PORT_HIGH
	 #elif DIO_PIN1==INPUT_HI
	 #define PIN1_DIR PORT_LOW
	 #define PIN1_PORT PORT_LOW
	 #elif DIO_PIN1==OUTPUT_HIGH
	 #define PIN1_DIR PORT_HIGH
	 #define PIN1_PORT PORT_HIGH
	 #elif DIO_PIN1==OUTPUT_LOW
	 #define PIN1_DIR PORT_HIGH
	 #define PIN1_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 2
	 #if DIO_PIN2==INPUT_PU
	 #define PIN2_DIR PORT_LOW
	 #define PIN2_PORT PORT_HIGH 
	 #elif DIO_PIN2==INPUT_HI
	 #define PIN2_DIR PORT_LOW
	 #define PIN2_PORT PORT_LOW
	 #elif DIO_PIN2==OUTPUT_HIGH
	 #define PIN2_DIR PORT_HIGH
	 #define PIN2_PORT PORT_HIGH
	 #elif DIO_PIN2==OUTPUT_LOW
	 #define PIN2_DIR PORT_HIGH
	 #define PIN2_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 3
	 #if DIO_PIN3==INPUT_PU
	 #define PIN3_DIR PORT_LOW
	 #define PIN3_PORT PORT_HIGH
	 #elif DIO_PIN3==INPUT_HI
	 #define PIN3_DIR PORT_LOW
	 #define PIN3_PORT PORT_LOW
	 #elif DIO_PIN3==OUTPUT_HIGH
	 #define PIN3_DIR PORT_HIGH
	 #define PIN3_PORT PORT_HIGH
	 #elif DIO_PIN3==OUTPUT_LOW
	 #define PIN3_DIR PORT_HIGH
	 #define PIN3_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 4
	 #if DIO_PIN4==INPUT_PU
	 #define PIN4_DIR PORT_LOW
	 #define PIN4_PORT PORT_HIGH
	 #elif DIO_PIN4==INPUT_HI
	 #define PIN4_DIR PORT_LOW
	 #define PIN4_PORT PORT_LOW
	 #elif DIO_PIN4==OUTPUT_HIGH
	 #define PIN4_DIR PORT_HIGH
	 #define PIN4_PORT PORT_HIGH
	 #elif DIO_PIN4==OUTPUT_LOW
	 #define PIN4_DIR PORT_HIGH
	 #define PIN4_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 5
	 #if DIO_PIN5==INPUT_PU
	 #define PIN5_DIR PORT_LOW
	 #define PIN5_PORT PORT_HIGH
	 #elif DIO_PIN5==INPUT_HI
	 #define PIN5_DIR PORT_LOW
	 #define PIN5_PORT PORT_LOW
	 #elif DIO_PIN5==OUTPUT_HIGH
	 #define PIN5_DIR PORT_HIGH
	 #define PIN5_PORT PORT_HIGH
	 #elif DIO_PIN5==OUTPUT_LOW
	 #define PIN5_DIR PORT_HIGH
	 #define PIN5_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 6
	 #if DIO_PIN6==INPUT_PU
	 #define PIN6_DIR PORT_LOW
	 #define PIN6_PORT PORT_HIGH
	 #elif DIO_PIN6==INPUT_HI
	 #define PIN6_DIR PORT_LOW
	 #define PIN6_PORT PORT_LOW
	 #elif DIO_PIN6==OUTPUT_HIGH
	 #define PIN6_DIR PORT_HIGH
	 #define PIN6_PORT PORT_HIGH
	 #elif DIO_PIN6==OUTPUT_LOW
	 #define PIN6_DIR PORT_HIGH
	 #define PIN6_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 7
	 #if DIO_PIN7==INPUT_PU
	 #define PIN7_DIR PORT_LOW
	 #define PIN7_PORT PORT_HIGH
	 #elif DIO_PIN7==INPUT_HI
	 #define PIN7_DIR PORT_LOW
	 #define PIN7_PORT PORT_LOW
	 #elif DIO_PIN7==OUTPUT_HIGH
	 #define PIN7_DIR PORT_HIGH
	 #define PIN7_PORT PORT_HIGH
	 #elif DIO_PIN7==OUTPUT_LOW
	 #define PIN7_DIR PORT_HIGH
	 #define PIN7_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 DDRA= CONCAT(PIN7_DIR,PIN6_DIR,PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR);
	 PORTA= CONCAT(PIN7_PORT,PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT);
	#endif
	/*Two/Three/Four Port config.*/
	#if (Num_of_Ports==Two_Ports || Num_of_Ports==Three_Ports || Num_of_Ports==Four_Ports)
	 //PIN8
	 #if DIO_PIN8==INPUT_PU
	 #define PIN8_DIR PORT_LOW
	 #define PIN8_PORT PORT_HIGH
	 #elif DIO_PIN8==INPUT_HI
	 #define PIN8_DIR PORT_LOW
	 #define PIN8_PORT PORT_LOW
	 #elif DIO_PIN8==OUTPUT_HIGH
	 #define PIN8_DIR PORT_HIGH
	 #define PIN8_PORT PORT_HIGH
	 #elif DIO_PIN8==OUTPUT_LOW
	 #define PIN8_DIR PORT_HIGH
	 #define PIN8_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 9
	 #if DIO_PIN9==INPUT_PU
	 #define PIN9_DIR PORT_LOW
	 #define PIN9_PORT PORT_HIGH
	 #elif DIO_PIN9==INPUT_HI
	 #define PIN9_DIR PORT_LOW
	 #define PIN9_PORT PORT_LOW
	 #elif DIO_PIN9==OUTPUT_HIGH
	 #define PIN9_DIR PORT_HIGH
	 #define PIN9_PORT PORT_HIGH
	 #elif DIO_PIN9==OUTPUT_LOW
	 #define PIN9_DIR PORT_HIGH
	 #define PIN9_PORT PORT_LOW
	/* #else
	 #error "invalid_config"*/
	 #endif
	 
	 //PIN 10
	 #if DIO_PIN10==INPUT_PU
	 #define PIN10_DIR PORT_LOW
	 #define PIN10_PORT PORT_HIGH
	 #elif DIO_PIN10==INPUT_HI
	 #define PIN10_DIR PORT_LOW
	 #define PIN10_PORT PORT_LOW
	 #elif DIO_PIN10==OUTPUT_HIGH
	 #define PIN10_DIR PORT_HIGH
	 #define PIN10_PORT PORT_HIGH
	 #elif DIO_PIN10==OUTPUT_LOW
	 #define PIN10_DIR PORT_HIGH
	 #define PIN10_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 11
	 #if DIO_PIN11==INPUT_PU
	 #define PIN11_DIR PORT_LOW
	 #define PIN11_PORT PORT_HIGH
	 #elif DIO_PIN11==INPUT_HI
	 #define PIN11_DIR PORT_LOW
	 #define PIN11_PORT PORT_LOW
	 #elif DIO_PIN11==OUTPUT_HIGH
	 #define PIN11_DIR PORT_HIGH
	 #define PIN11_PORT PORT_HIGH
	 #elif DIO_PIN11==OUTPUT_LOW
	 #define PIN11_DIR PORT_HIGH
	 #define PIN11_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 12
	 #if DIO_PIN12==INPUT_PU
	 #define PIN12_DIR PORT_LOW
	 #define PIN12_PORT PORT_HIGH
	 #elif DIO_PIN12==INPUT_HI
	 #define PIN12_DIR PORT_LOW
	 #define PIN12_PORT PORT_LOW
	 #elif DIO_PIN12==OUTPUT_HIGH
	 #define PIN12_DIR PORT_HIGH
	 #define PIN12_PORT PORT_HIGH
	 #elif DIO_PIN12==OUTPUT_LOW
	 #define PIN12_DIR PORT_HIGH
	 #define PIN12_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 13
	 #if DIO_PIN13==INPUT_PU
	 #define PIN13_DIR PORT_LOW
	 #define PIN13_PORT PORT_HIGH
	 #elif DIO_PIN13==INPUT_HI
	 #define PIN13_DIR PORT_LOW
	 #define PIN13_PORT PORT_LOW
	 #elif DIO_PIN13==OUTPUT_HIGH
	 #define PIN13_DIR PORT_HIGH
	 #define PIN13_PORT PORT_HIGH
	 #elif DIO_PIN13==OUTPUT_LOW
	 #define PIN13_DIR PORT_HIGH
	 #define PIN13_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 14
	 #if DIO_PIN14==INPUT_PU
	 #define PIN14_DIR PORT_LOW
	 #define PIN14_PORT PORT_HIGH
	 #elif DIO_PIN14==INPUT_HI
	 #define PIN14_DIR PORT_LOW
	 #define PIN14_PORT PORT_LOW
	 #elif DIO_PIN14==OUTPUT_HIGH
	 #define PIN14_DIR PORT_HIGH
	 #define PIN14_PORT PORT_HIGH
	 #elif DIO_PIN14==OUTPUT_LOW
	 #define PIN14_DIR PORT_HIGH
	 #define PIN14_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 15
	 #if DIO_PIN15==INPUT_PU
	 #define PIN15_DIR PORT_LOW
	 #define PIN15_PORT PORT_HIGH
	 #elif DIO_PIN15==INPUT_HI
	 #define PIN15_DIR PORT_LOW
	 #define PIN15_PORT PORT_LOW
	 #elif DIO_PIN15==OUTPUT_HIGH
	 #define PIN15_DIR PORT_HIGH
	 #define PIN15_PORT PORT_HIGH
	 #elif DIO_PIN15==OUTPUT_LOW
	 #define PIN15_DIR PORT_HIGH
	 #define PIN15_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	DDRB= CONCAT(PIN15_DIR,PIN14_DIR,PIN13_DIR,PIN12_DIR,PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR);
	PORTB= CONCAT(PIN15_PORT,PIN14_PORT,PIN13_PORT,PIN12_PORT,PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT);
#endif
	/*Three/Four Port config.*/
	#if (Num_of_Ports==Three_Ports || Num_of_Ports==Four_Ports)
	 //PIN16
	 #if DIO_PIN16==INPUT_PU
	 #define PIN16_DIR PORT_LOW
	 #define PIN16_PORT PORT_HIGH
	 #elif DIO_PIN16==INPUT_HI
	 #define PIN16_DIR PORT_LOW
	 #define PIN16_PORT PORT_LOW
	 #elif DIO_PIN16==OUTPUT_HIGH
	 #define PIN16_DIR PORT_HIGH
	 #define PIN16_PORT PORT_HIGH
	 #elif DIO_PIN16==OUTPUT_LOW
	 #define PIN16_DIR PORT_HIGH
	 #define PIN16_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 17
	 #if DIO_PIN17==INPUT_PU
	 #define PIN17_DIR PORT_LOW
	 #define PIN17_PORT PORT_HIGH
	 #elif DIO_PIN17==INPUT_HI
	 #define PIN17_DIR PORT_LOW
	 #define PIN17_PORT PORT_LOW
	 #elif DIO_PIN17==OUTPUT_HIGH
	 #define PIN17_DIR PORT_HIGH
	 #define PIN17_PORT PORT_HIGH
	 #elif DIO_PIN17==OUTPUT_LOW
	 #define PIN17_DIR PORT_HIGH
	 #define PIN17_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 18
	 #if DIO_PIN18==INPUT_PU
	 #define PIN18_DIR PORT_LOW
	 #define PIN18_PORT PORT_HIGH
	 #elif DIO_PIN18==INPUT_HI
	 #define PIN18_DIR PORT_LOW
	 #define PIN18_PORT PORT_LOW
	 #elif DIO_PIN18==OUTPUT_HIGH
	 #define PIN18_DIR PORT_HIGH
	 #define PIN18_PORT PORT_HIGH
	 #elif DIO_PIN18==OUTPUT_LOW
	 #define PIN18_DIR PORT_HIGH
	 #define PIN18_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 19
	 #if DIO_PIN19==INPUT_PU
	 #define PIN19_DIR PORT_LOW
	 #define PIN19_PORT PORT_HIGH
	 #elif DIO_PIN19==INPUT_HI
	 #define PIN19_DIR PORT_LOW
	 #define PIN19_PORT PORT_LOW
	 #elif DIO_PIN19==OUTPUT_HIGH
	 #define PIN19_DIR PORT_HIGH
	 #define PIN19_PORT PORT_HIGH
	 #elif DIO_PIN19==OUTPUT_LOW
	 #define PIN19_DIR PORT_HIGH
	 #define PIN19_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 20
	 #if DIO_PIN20==INPUT_PU
	 #define PIN20_DIR PORT_LOW
	 #define PIN20_PORT PORT_HIGH
	 #elif DIO_PIN20==INPUT_HI
	 #define PIN20_DIR PORT_LOW
	 #define PIN20_PORT PORT_LOW
	 #elif DIO_PIN20==OUTPUT_HIGH
	 #define PIN20_DIR PORT_HIGH
	 #define PIN20_PORT PORT_HIGH
	 #elif DIO_PIN20==OUTPUT_LOW
	 #define PIN20_DIR PORT_HIGH
	 #define PIN20_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 21
	 #if DIO_PIN21==INPUT_PU
	 #define PIN21_DIR PORT_LOW
	 #define PIN21_PORT PORT_HIGH
	 #elif DIO_PIN21==INPUT_HI
	 #define PIN21_DIR PORT_LOW
	 #define PIN21_PORT PORT_LOW
	 #elif DIO_PIN21==OUTPUT_HIGH
	 #define PIN21_DIR PORT_HIGH
	 #define PIN21_PORT PORT_HIGH
	 #elif DIO_PIN21==OUTPUT_LOW
	 #define PIN21_DIR PORT_HIGH
	 #define PIN21_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 22
	 #if DIO_PIN22==INPUT_PU
	 #define PIN22_DIR PORT_LOW
	 #define PIN22_PORT PORT_HIGH
	 #elif DIO_PIN22==INPUT_HI
	 #define PIN22_DIR PORT_LOW
	 #define PIN22_PORT PORT_LOW
	 #elif DIO_PIN22==OUTPUT_HIGH
	 #define PIN22_DIR PORT_HIGH
	 #define PIN22_PORT PORT_HIGH
	 #elif DIO_PIN22==OUTPUT_LOW
	 #define PIN22_DIR PORT_HIGH
	 #define PIN22_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 23
	 #if DIO_PIN23==INPUT_PU
	 #define PIN23_DIR PORT_LOW
	 #define PIN23_PORT PORT_HIGH
	 #elif DIO_PIN23==INPUT_HI
	 #define PIN23_DIR PORT_LOW
	 #define PIN23_PORT PORT_LOW
	 #elif DIO_PIN23==OUTPUT_HIGH
	 #define PIN23_DIR PORT_HIGH
	 #define PIN23_PORT PORT_HIGH
	 #elif DIO_PIN23==OUTPUT_LOW
	 #define PIN23_DIR PORT_HIGH
	 #define PIN23_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	
	DDRC= CONCAT(PIN23_DIR,PIN22_DIR,PIN21_DIR,PIN20_DIR,PIN19_DIR,PIN18_DIR,PIN17_DIR,PIN16_DIR);
	PORTC= CONCAT(PIN23_PORT,PIN22_PORT,PIN21_PORT,PIN20_PORT,PIN19_PORT,PIN18_PORT,PIN17_PORT,PIN16_PORT);
 #endif	
 
	/*Four Port config.*/
	#if (Num_of_Ports==Four_Ports)
	 //PIN24
	 #if DIO_PIN24==INPUT_PU
	 #define PIN24_DIR PORT_LOW
	 #define PIN24_PORT PORT_HIGH
	 #elif DIO_PIN24==INPUT_HI
	 #define PIN24_DIR PORT_LOW
	 #define PIN24_PORT PORT_LOW
	 #elif DIO_PIN24==OUTPUT_HIGH
	 #define PIN24_DIR PORT_HIGH
	 #define PIN24_PORT PORT_HIGH
	 #elif DIO_PIN24==OUTPUT_LOW
	 #define PIN24_DIR PORT_HIGH
	 #define PIN24_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 25
	 #if DIO_PIN25==INPUT_PU
	 #define PIN25_DIR PORT_LOW
	 #define PIN25_PORT PORT_HIGH
	 #elif DIO_PIN25==INPUT_HI
	 #define PIN25_DIR PORT_LOW
	 #define PIN25_PORT PORT_LOW
	 #elif DIO_PIN25==OUTPUT_HIGH
	 #define PIN25_DIR PORT_HIGH
	 #define PIN25_PORT PORT_HIGH
	 #elif DIO_PIN25==OUTPUT_LOW
	 #define PIN25_DIR PORT_HIGH
	 #define PIN25_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 26
	 #if DIO_PIN26==INPUT_PU
	 #define PIN26_DIR PORT_LOW
	 #define PIN26_PORT PORT_HIGH
	 #elif DIO_PIN26==INPUT_HI
	 #define PIN26_DIR PORT_LOW
	 #define PIN26_PORT PORT_LOW
	 #elif DIO_PIN26==OUTPUT_HIGH
	 #define PIN26_DIR PORT_HIGH
	 #define PIN26_PORT PORT_HIGH
	 #elif DIO_PIN26==OUTPUT_LOW
	 #define PIN26_DIR PORT_HIGH
	 #define PIN26_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 27
	 #if DIO_PIN27==INPUT_PU
	 #define PIN27_DIR PORT_LOW
	 #define PIN27_PORT PORT_HIGH
	 #elif DIO_PIN27==INPUT_HI
	 #define PIN27_DIR PORT_LOW
	 #define PIN27_PORT PORT_LOW
	 #elif DIO_PIN27==OUTPUT_HIGH
	 #define PIN27_DIR PORT_HIGH
	 #define PIN27_PORT PORT_HIGH
	 #elif DIO_PIN27==OUTPUT_LOW
	 #define PIN27_DIR PORT_HIGH
	 #define PIN27_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 28
	 #if DIO_PIN28==INPUT_PU
	 #define PIN28_DIR PORT_LOW
	 #define PIN28_PORT PORT_HIGH
	 #elif DIO_PIN28==INPUT_HI
	 #define PIN28_DIR PORT_LOW
	 #define PIN28_PORT PORT_LOW
	 #elif DIO_PIN28==OUTPUT_HIGH
	 #define PIN28_DIR PORT_HIGH
	 #define PIN28_PORT PORT_HIGH
	 #elif DIO_PIN28==OUTPUT_LOW
	 #define PIN28_DIR PORT_HIGH
	 #define PIN28_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 29
	 #if DIO_PIN29==INPUT_PU
	 #define PIN29_DIR PORT_LOW
	 #define PIN29_PORT PORT_HIGH
	 #elif DIO_PIN29==INPUT_HI
	 #define PIN29_DIR PORT_LOW
	 #define PIN29_PORT PORT_LOW
	 #elif DIO_PIN29==OUTPUT_HIGH
	 #define PIN29_DIR PORT_HIGH
	 #define PIN29_PORT PORT_HIGH
	 #elif DIO_PIN29==OUTPUT_LOW
	 #define PIN29_DIR PORT_HIGH
	 #define PIN29_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 30
	 #if DIO_PIN30==INPUT_PU
	 #define PIN30_DIR PORT_LOW
	 #define PIN30_PORT PORT_HIGH
	 #elif DIO_PIN30==INPUT_HI
	 #define PIN30_DIR PORT_LOW
	 #define PIN30_PORT PORT_LOW
	 #elif DIO_PIN30==OUTPUT_HIGH
	 #define PIN30_DIR PORT_HIGH
	 #define PIN30_PORT PORT_HIGH
	 #elif DIO_PIN30==OUTPUT_LOW
	 #define PIN30_DIR PORT_HIGH
	 #define PIN30_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 //PIN 31
	 #if DIO_PIN31==INPUT_PU
	 #define PIN31_DIR PORT_LOW
	 #define PIN31_PORT PORT_HIGH
	 #elif DIO_PIN31==INPUT_HI
	 #define PIN31_DIR PORT_LOW
	 #define PIN31_PORT PORT_LOW
	 #elif DIO_PIN31==OUTPUT_HIGH
	 #define PIN31_DIR PORT_HIGH
	 #define PIN31_PORT PORT_HIGH
	 #elif DIO_PIN31==OUTPUT_LOW
	 #define PIN31_DIR PORT_HIGH
	 #define PIN31_PORT PORT_LOW
	 #else
	 #error "invalid_config"
	 #endif
	 
	 DDRD= CONCAT(PIN31_DIR,PIN30_DIR,PIN29_DIR,PIN28_DIR,PIN27_DIR,PIN26_DIR,PIN25_DIR,PIN24_DIR);
	 PORTD= CONCAT(PIN31_PORT,PIN30_PORT,PIN29_PORT,PIN28_PORT,PIN27_PORT,PIN26_PORT,PIN25_PORT,PIN24_PORT);
	#endif
	//wrong port config.
	#if (!(Num_of_Ports==One_Port ) && !(Num_of_Ports==Two_Ports) && !(Num_of_Ports==Three_Ports) && !(Num_of_Ports==Four_Ports))
     #error "invalid option"
    #endif
#endif
/*post_compile configuration*/
#if config_type==postcomp_config
for(u8 i=0;i<Num_of_Pins;i++)
{
	PORT_enuPortnum_t Loc_enumPortNum=i/8;
	u8 Loc_u8PinNum=i%8;
	switch(Loc_enumPortNum)
	{
		case PORT_enuPORTA:
		switch(PORT_Pincfg[i])
		{
			case PORT_enuINPUT_PU:
			CLR_BIT(DDRA,Loc_u8PinNum);
			SET_BIT(PORTA,Loc_u8PinNum);
			break;
			case PORT_enuINPUT_HI:
			CLR_BIT(DDRA,Loc_u8PinNum);
			CLR_BIT(PORTA,Loc_u8PinNum);
			break;
			case PORT_enuOUTPUT_HIGH:
			SET_BIT(DDRA,Loc_u8PinNum);
			SET_BIT(PORTA,Loc_u8PinNum);
			break;
			case PORT_enuOUTPUT_LOW:
			SET_BIT(DDRA,Loc_u8PinNum);
			CLR_BIT(PORTA,Loc_u8PinNum);
			break;	
		}
		break;
		case PORT_enuPORTB:
		switch(PORT_Pincfg[i])
		{
			case PORT_enuINPUT_PU:
			CLR_BIT(DDRB,Loc_u8PinNum);
			SET_BIT(PORTB,Loc_u8PinNum);
			break;
			case PORT_enuINPUT_HI:
			CLR_BIT(DDRB,Loc_u8PinNum);
			CLR_BIT(PORTB,Loc_u8PinNum);
			break;
			case PORT_enuOUTPUT_HIGH:
			SET_BIT(DDRB,Loc_u8PinNum);
			SET_BIT(PORTB,Loc_u8PinNum);
			break;
			case PORT_enuOUTPUT_LOW:
			SET_BIT(DDRB,Loc_u8PinNum);
			CLR_BIT(PORTB,Loc_u8PinNum);
			break;
		}
		break;
		case PORT_enuPORTC:
		switch(PORT_Pincfg[i])
		{
			case PORT_enuINPUT_PU:
			CLR_BIT(DDRC,Loc_u8PinNum);
			SET_BIT(PORTC,Loc_u8PinNum);
			break;
			case PORT_enuINPUT_HI:
			CLR_BIT(DDRC,Loc_u8PinNum);
			CLR_BIT(PORTC,Loc_u8PinNum);
			break;
			case PORT_enuOUTPUT_HIGH:
			SET_BIT(DDRC,Loc_u8PinNum);
			SET_BIT(PORTC,Loc_u8PinNum);
			break;
			case PORT_enuOUTPUT_LOW:
			SET_BIT(DDRC,Loc_u8PinNum);
			CLR_BIT(PORTC,Loc_u8PinNum);
			break;
		}
		break;
		case PORT_enuPORTD:
		switch(PORT_Pincfg[i])
		{
			case PORT_enuINPUT_PU:
			CLR_BIT(DDRD,Loc_u8PinNum);
			SET_BIT(PORTD,Loc_u8PinNum);
			break;
			case PORT_enuINPUT_HI:
			CLR_BIT(DDRD,Loc_u8PinNum);
			CLR_BIT(PORTD,Loc_u8PinNum);
			break;
			case PORT_enuOUTPUT_HIGH:
			SET_BIT(DDRD,Loc_u8PinNum);
			SET_BIT(PORTD,Loc_u8PinNum);
			break;
			case PORT_enuOUTPUT_LOW:
			SET_BIT(DDRD,Loc_u8PinNum);
			CLR_BIT(PORTD,Loc_u8PinNum);
			break;
		}
		break;
	}
}
#endif	
}

/*********** PORT_SetCfg function was added for the LED and Switch drivers ****************/

Error_state_t PORT_SetCfg(Port_Strcfg_t *AddPortCfg,u8 length)
{
	Error_state_t Ret_Error =Ok;
	if(AddPortCfg==NULLPTR)
	{
		Ret_Error=Ptr_NOk;
	}
	
	else
	{
		for(u8 i=0;i<length;i++)
	{
	switch (AddPortCfg[i].PORT)	
	{
		case PORT_enuPORTA:
		switch(AddPortCfg[i].config)
		{
			case PORT_enuINPUT_PU:
			CLR_BIT(DDRA,AddPortCfg[i].PIN);
			SET_BIT(PORTA,AddPortCfg[i].PIN);
			break;
			case PORT_enuINPUT_HI:
			CLR_BIT(DDRA,AddPortCfg[i].PIN);
			CLR_BIT(PORTA,AddPortCfg[i].PIN);
			break;
			case PORT_enuOUTPUT_HIGH:
			SET_BIT(DDRA,AddPortCfg[i].PIN);
			SET_BIT(PORTA,AddPortCfg[i].PIN);
			break;
			case PORT_enuOUTPUT_LOW:
			SET_BIT(DDRA,AddPortCfg[i].PIN);
			CLR_BIT(PORTA,AddPortCfg[i].PIN);
			break;
		}
		break;
		case PORT_enuPORTB:
		switch(AddPortCfg[i].config)
		{
			case PORT_enuINPUT_PU:
			CLR_BIT(DDRB,AddPortCfg[i].PIN);
			SET_BIT(PORTB,AddPortCfg[i].PIN);
			break;
			case PORT_enuINPUT_HI:
			CLR_BIT(DDRB,AddPortCfg[i].PIN);
			CLR_BIT(PORTB,AddPortCfg[i].PIN);
			break;
			case PORT_enuOUTPUT_HIGH:
			SET_BIT(DDRB,AddPortCfg[i].PIN);
			SET_BIT(PORTB,AddPortCfg[i].PIN);
			break;
			case PORT_enuOUTPUT_LOW:
			SET_BIT(DDRB,AddPortCfg[i].PIN);
			CLR_BIT(PORTB,AddPortCfg[i].PIN);
			break;
		}
		break;
		case PORT_enuPORTC:
		switch(AddPortCfg[i].config)
		{
			case PORT_enuINPUT_PU:
			CLR_BIT(DDRC,AddPortCfg[i].PIN);
			SET_BIT(PORTC,AddPortCfg[i].PIN);
			break;
			case PORT_enuINPUT_HI:
			CLR_BIT(DDRC,AddPortCfg[i].PIN);
			CLR_BIT(PORTC,AddPortCfg[i].PIN);
			break;
			case PORT_enuOUTPUT_HIGH:
			SET_BIT(DDRC,AddPortCfg[i].PIN);
			SET_BIT(PORTC,AddPortCfg[i].PIN);
			break;
			case PORT_enuOUTPUT_LOW:
			SET_BIT(DDRC,AddPortCfg[i].PIN);
			CLR_BIT(PORTC,AddPortCfg[i].PIN);
			break;
		}
		break;
		case PORT_enuPORTD:
		switch(AddPortCfg[i].config)
		{
			case PORT_enuINPUT_PU:
			CLR_BIT(DDRD,AddPortCfg[i].PIN);
			SET_BIT(PORTD,AddPortCfg[i].PIN);
			break;
			case PORT_enuINPUT_HI:
			CLR_BIT(DDRD,AddPortCfg[i].PIN);
			CLR_BIT(PORTD,AddPortCfg[i].PIN);
			break;
			case PORT_enuOUTPUT_HIGH:
			SET_BIT(DDRD,AddPortCfg[i].PIN);
			SET_BIT(PORTD,AddPortCfg[i].PIN);
			break;
			case PORT_enuOUTPUT_LOW:
			SET_BIT(DDRD,AddPortCfg[i].PIN);
			CLR_BIT(PORTD,AddPortCfg[i].PIN);
			break;
		}
		break;
	}
		
	}
	
	
}
return Ret_Error;
}
