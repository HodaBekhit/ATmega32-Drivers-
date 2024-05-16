/*
 * switch.h
 *
 * Created: 12/12/2023 11:02:36 PM
 *  Author: Dell
 */ 


#ifndef switch_H_
#define switch_H_

#include "std_types.h"
#include "switch_priv.h"

void Switch_init(void);
Switch_enum_Error_t Switch_enu_read( u8 Copyu8switch_name, Switch_enumLogicState_t* Add_Pu8SwitchValue);

#endif /* switch_H_ */