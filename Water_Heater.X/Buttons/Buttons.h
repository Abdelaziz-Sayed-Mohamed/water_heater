/*
 * Buttons.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "../Config.h"
#define _IS_EXTI_ON_OFF_FLAG     INTCONbits.INTF
#define _RESET_EXTI_ON_OFF_FLAG  INTCONbits.INTF=0

#define Button_Pressed              0
#define Button_NotPressed           1
void Read_UP_DOWN_BUTTONS(void);
void On_Off_Init(void);
void EXTI_On_Off_CallBack(void);
#endif /* BUTTONS_H_ */
