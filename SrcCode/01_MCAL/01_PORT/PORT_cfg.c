/*
 * PORT_cfg.c
 *
 * Created: 12/2/2023 6:25:23 PM
 *  Author: Dell
 */ 
#include "PORT_cfg.h"
#include "PORT_priv.h"

#if (config_type==postcomp_config)
const PORT_enuPinopt_t PORT_Pincfg[32]=
{
	PORT_enuOUTPUT_LOW, /*PIN 0*/
	PORT_enuOUTPUT_LOW, /*PIN 1*/
	PORT_enuOUTPUT_LOW, /*PIN 2*/
	PORT_enuOUTPUT_LOW, /*PIN 3*/
	PORT_enuOUTPUT_LOW, /*PIN 4*/
	PORT_enuOUTPUT_LOW, /*PIN 5*/
	PORT_enuOUTPUT_LOW, /*PIN 6*/
	PORT_enuOUTPUT_LOW, /*PIN 7*/
	PORT_enuOUTPUT_LOW, /*PIN 8*/
	PORT_enuOUTPUT_LOW, /*PIN 9*/
	PORT_enuOUTPUT_LOW, /*PIN 10*/
	PORT_enuOUTPUT_LOW, /*PIN 11*/
	PORT_enuOUTPUT_LOW, /*PIN 12*/
	PORT_enuOUTPUT_LOW, /*PIN 13*/
	PORT_enuOUTPUT_LOW, /*PIN 14*/
	PORT_enuOUTPUT_LOW, /*PIN 15*/
	PORT_enuOUTPUT_LOW, /*PIN 16*/
	PORT_enuOUTPUT_LOW, /*PIN 17*/
	PORT_enuOUTPUT_LOW, /*PIN 18*/
	PORT_enuOUTPUT_LOW, /*PIN 19*/
	PORT_enuOUTPUT_LOW, /*PIN 20*/
	PORT_enuOUTPUT_LOW, /*PIN 21*/
	PORT_enuOUTPUT_LOW, /*PIN 22*/
	PORT_enuOUTPUT_LOW, /*PIN 23*/
	PORT_enuOUTPUT_LOW, /*PIN 24*/
	PORT_enuOUTPUT_LOW, /*PIN 25*/
	PORT_enuOUTPUT_LOW, /*PIN 26*/
	PORT_enuOUTPUT_LOW, /*PIN 27*/
	PORT_enuOUTPUT_LOW, /*PIN 28*/
	PORT_enuOUTPUT_LOW, /*PIN 29*/
	PORT_enuOUTPUT_LOW, /*PIN 30*/
	PORT_enuOUTPUT_LOW /*PIN 31*/		
};
#endif