/*
 * Buttons.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "../Config.h"
#define IS_EXTI_ON_OFF_FLAG     INTCONbits.INTF
#define RESET_EXTI_ON_OFF_FLAG  INTCONbits.INTF=0

#define Button_Pressed              0
#define Button_NotPressed           1

typedef struct _BUTTONS_T
{ 
  uint8_t  UpFlag   :1;
  uint8_t  DownFlag :1;
}_BUTTONS_t  ;

_BUTTONS_t Buttons;


#define Set_UpButton_Flag      Buttons.UpFlag=1
#define Set_DownButton_Flag    Buttons.DownFlag=1
#define Reset_UpButton_Flag    Buttons.UpFlag=0
#define Reset_DownButton_Flag  Buttons.DownFlag=0
void Buttons_MainFunction(void);
void On_Off_Init(void);
void EXTI_On_Off_CallBack(void);
#endif /* BUTTONS_H_ */
