/*
 * SSD.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef SSD_H_
#define SSD_H_
#include"../Config.h"
#include"SSD_Cfg.h"


#define SSD_Zero                        0b00111111
#define SSD_One                         0b00000110
#define SSD_Two                         0b01011011
#define SSD_Three                       0b01001111
#define SSD_Four                        0b01100110
#define SSD_Five                        0b01101101
#define SSD_Six                         0b01111101
#define SSD_Seven                       0b00000111
#define SSD_Eight                       0b01111111
#define SSD_Nine                        0b01101111
#define SSD_Nothing                      10

#define Toggle_Enable_Digit_Selector    Enable_Digit_Selector^=1
#define IS_Digit_1_Enabled              Enable_Digit_Selector==0
#define IS_Digit_2_Enabled              Enable_Digit_Selector==1
#define ResetSSDCounter                 Counter =1
#define Turn_Off_7seg_Port              0
extern uint8_t Counter;
typedef enum _Enable_SSD_t
{
	Enable_SSD_Off=0,
	Enable_SSD_On=1,
}Enable_SSD_t;

Enable_SSD_t  Enable_SSD;

void SSD_Init(void);
void SSD_MainFunction(void);
void SSD_SelectDisplay(void);
void SSD_SelectDigit(void);
void SSD_Blink(uint16_t Times_Ms);
#endif /* SSD_H_ */
