/*
 * Interrupt.c
 *
 *  Created on: Jul 8, 2020
 *      Author: Abdelaziz Sayed
 */
#include "Interrupt.h"
#include"../Timer/Timer.h"
#include"../Buttons/Buttons.h"

void __interrupt() myISR(void)
{
	if(IS_EXTI_ON_OFF_FLAG)
	{   
        RESET_EXTI_ON_OFF_FLAG;
		EXTI_On_Off_CallBack();
		
	}
	else if(IS_TIMER0_FLAG)
	{   
        RESET_TIMER0_FLAG;
        TMR0=Reload_Timer0;
		Timer0_CallBack();
		
	}
}