/*
 * ADC.h
 *
 *  Created on: Jul 7, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef ADC_H_
#define ADC_H_
#include "../Config.h"
#define ADC_RESOLUTION       0.4882

#define _ADC_START_CONV       ADCON0bits.GO_DONE=1
#define _IS_CONV_DONE         ADCON0bits.GO_DONE==0


typedef struct _ADC_t
{
  	uint8_t ADC_INIT_FLAG  :1;
	uint8_t ADC_START_FLAG :1;

}ADC_t;

ADC_t ADC_Info;

void ADC_Init(void);
void ADC_Start_Conv(void);
void ADC_Conv_Main(void);
void ADC_Value_Ready_CallBack(void);
void ADC_Conv_MainFunction(void);

#endif /* ADC_H_ */
