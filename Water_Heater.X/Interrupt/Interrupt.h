/*
 * Interrupt.h
 *
 *  Created on: Jul 8, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include"../Config.h"
#include"../gpio/gpio.h"
#include"../Timer/Timer.h"
#include"../Buttons/Buttons.h"

typedef void (*CallBack_t)(void);

typedef struct _CallBack_t
{
  CallBack_t ExtiCallBack;
  CallBack_t Timer0CallBack;
  
}Interrupt_CallBack_t;

const Interrupt_CallBack_t   Interrupt_CallBack={
                                                  .ExtiCallBack=EXTI_On_Off_CallBack,
                                                  .Timer0CallBack=Timer0_CallBack
                                                };


#endif /* INTERRUPT_H_ */
