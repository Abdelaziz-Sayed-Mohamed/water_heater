/*
 * Display.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_
#include"../Config.h"
void Display_Init(void);
void Display_MainFunction(void);
void Display_Blink(uint16_t Times_Ms,uint16_t Task_Peroid);
void Display_Off(void);
#endif /* DISPLAY_H_ */
