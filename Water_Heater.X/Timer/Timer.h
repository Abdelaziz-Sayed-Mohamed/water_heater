/*
 * Timer.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef TIMER_H_
#define TIMER_H_
#include"../Config.h"
#include"../Scheduler/Scheduler.h"

#define IS_TIMER0_FLAG      INTCONbits.TMR0IF
#define RESET_TIMER0_FLAG   INTCONbits.TMR0IF=0
#define Reload_Timer0        100
void Timer0_CallBack(void);
void Timer0_Init(void);

#endif /* TIMER_H_ */
