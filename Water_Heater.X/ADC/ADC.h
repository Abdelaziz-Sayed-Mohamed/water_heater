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

#define ADC_START_CONV       ADCON0bits.GO_DONE=1
#define IS_ADC_STARTED       ADC_Info.ADC_START_FLAG==1
#define IS_CONV_DONE         ADCON0bits.GO_DONE==0
#define IS_ADC_INIT          ADC_Info.ADC_INIT_FLAG==1
#define SET_ADC_INIT_FLAG    ADC_Info.ADC_INIT_FLAG=1
#define SET_ADC_START_FLAG   ADC_Info.ADC_START_FLAG=1


typedef struct _ADC_t
{
  	uint8_t ADC_INIT_FLAG  :1;
	uint8_t ADC_START_FLAG :1;

}ADC_t;

ADC_t ADC_Info;

void ADC_Init(void);
void ADC_Start_Conv(void);
void ADC_Value_Ready_CallBack(void);
void ADC_Get_Value(uint16_t *Buffer);

#endif /* ADC_H_ */
