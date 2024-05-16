/*
 * switch.c
 *
 * Created: 12/12/2023 11:03:59 PM
 *  Author: Dell
 */ 
#include "std_types.h"
#include "PORT_cfg.h"
#include "PORT.h"
#include "DIO.h"
#include "switch.h"
#include "switch_cfg.h"
#include "switch_priv.h"

extern Switch_StrCfg_t switchs[NUM_OF_switchs];

void Switch_init(void)
{	
	u8 Loc_counter;
	Port_Strcfg_t Currentswitchs[NUM_OF_switchs];
for(Loc_counter=0; Loc_counter < NUM_OF_switchs ; Loc_counter++)
{
	Currentswitchs[Loc_counter].PORT=switchs[Loc_counter].PORT;
	Currentswitchs[Loc_counter].PIN=switchs[Loc_counter].PIN;
	Currentswitchs[Loc_counter].config= switchs[Loc_counter].Active_State;
}
 PORT_SetCfg(Currentswitchs,  NUM_OF_switchs);

}

 Switch_enum_Error_t Switch_enu_read( u8 Copyu8switch_name, Switch_enumLogicState_t* Add_Pu8SwitchValue)
 {
	
	 Switch_enum_Error_t Ret_Switch_Error=Switch_enu_Ok;
	 if(Copyu8switch_name>NUM_OF_switchs)
	 {
		 Ret_Switch_Error=Switch_enu_WrongName;
	 }
	 else if (Add_Pu8SwitchValue==NULLPTR)
	 {
		 Ret_Switch_Error=Switch_enu_NullPtr;
	 }
	 else
	 {
	    DIO_enumReadState(switchs[Copyu8switch_name].PORT,switchs[Copyu8switch_name].PIN, Add_Pu8SwitchValue );
	 }
	
	return  Ret_Switch_Error;
 }