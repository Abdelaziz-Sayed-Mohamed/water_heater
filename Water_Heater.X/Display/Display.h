/*
 * Display.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_
#include"../Config.h"


#define Display_Zero     0b00111111
#define Display_One      0b00000110
#define Display_Two      0b01011011
#define Display_Three    0b01001111
#define Display_Four     0b01100110
#define Display_Five     0b01101101
#define Display_Six      0b01111101
#define Display_Seven    0b00000111
#define Display_Eight    0b01111111
#define Display_Nine     0b01101111


void Display_Init(void);
void Display_MainFunction(void);
void Display_Blink(uint16_t Times_Ms,uint16_t Task_Peroid);
#endif /* DISPLAY_H_ */
