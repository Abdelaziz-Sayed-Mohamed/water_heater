/*
 * Interrupt.c
 *
 *  Created on: Jul 8, 2020
 *      Author: Abdelaziz Sayed
 */
#include "Interrupt.h"

void __interrupt() myISR(void)
{
    
	if(IS_EXTI_ON_OFF_FLAG)    //Check if EXTI flag is seted 
	{   
        RESET_EXTI_ON_OFF_FLAG;
		Interrupt_CallBack.ExtiCallBack();
	}
	else if(IS_TIMER0_FLAG)    //Check if TMR0 flag is seted
	{   
        RESET_TIMER0_FLAG;
        TMR0=Reload_Timer0;
        
		Interrupt_CallBack.Timer0CallBack();
	}
}

