/*
 * Timer.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */
#include "Timer.h"
uint32_t Tick_Num=0;

void Timer0_Init(void)
{
	    /*Configure Timer 0*/
	    OPTION_REGbits.T0CS=0;  //Internal Instruction Cycle Clock
	    OPTION_REGbits.PSA=0;   //Prescaler Assign To Timer 0

	    /*Select Prescaler 1:256*/
	    OPTION_REGbits.PS0=1;
	    OPTION_REGbits.PS1=1;
	    OPTION_REGbits.PS2=1;
        
        /*Configure Interrupts*/
        INTCONbits.TMR0IE=1; //Enable Timer 0 Interrupt
        INTCONbits.PEIE=1;   //Enable Peripheral Interrupt
        INTCONbits.GIE=1;    //Enable All Global Interrupt
        
	    TMR0=Reload_Timer0;  //Preload Timer 0 to Get 20ms Per OverFlow
        RESET_TIMER0_FLAG; //Clear Timer 0 Interrupt Flag

}

void Timer0_CallBack(void)
{
	Tick_Num++;                         //Increment Tick_Num every interrupt
	Scheduler_ActivateTask(Tick_Num );
}

