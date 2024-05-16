/*
 * EXTI_cfg.c
 *
 * Created: 12/24/2023 7:33:32 PM
 *  Author: Dell
 */ 

#include "EXTI_priv.h"

EXTI_StrCfg_t EXTI[3]=
{
	[INT0]={.EXTI_EN_DIS=EXTI_enable , .EXTI_MODE= INT0_FE },
	[INT1]={.EXTI_EN_DIS=EXTI_enable , .EXTI_MODE=INT1_FE },
	[INT2]={.EXTI_EN_DIS=EXTI_enable , .EXTI_MODE=INT2_RE }
};