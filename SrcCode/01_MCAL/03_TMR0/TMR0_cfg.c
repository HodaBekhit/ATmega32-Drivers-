/*
 * TMR0_cfg.c
 *
 * Created: 2/24/2024 2:36:48 PM
 *  Author: Dell
 */ 

#include "TMR0.h"
TMR0Config_t TIMER0={
	.TMR0_WGM=TMR0_Normal ,
	.TMR0_COM= TMR0_OC0_DISCONNECTED ,
	.TMR0_CLOCKSOURCE=TMR0_PRESCALAR_1024,
};