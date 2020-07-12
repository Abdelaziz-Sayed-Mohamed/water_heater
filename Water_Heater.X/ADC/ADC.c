/*
 * ADC.c
 *
 *  Created on: Jul 7, 2020
 *      Author: Abdelaziz Sayed
 */

#include "ADC.h"
#include"../Temperature/Temperature.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"


void ADC_Init(void)
{

    TRISAbits.TRISA2=1; //A2 Input Pin
    ADCON1bits.ADFM=1;//Right Justified
    /*Configure Clock Conversion as FOSC/16*/
    ADCON0bits.ADCS0=1 ;
    ADCON0bits.ADCS1=0;
    ADCON1bits.ADCS2=1 ;

    /*Configure ADC Channel 2 (A2)*/
    ADCON0bits.CHS0=0;
    ADCON0bits.CHS1=1;
    ADCON0bits.CHS2=0;

   /*Configure Pin A2 as Analog */
    ADCON1bits.PCFG0=0;
    ADCON1bits.PCFG1=1;
    ADCON1bits.PCFG2=0;
    ADCON1bits.PCFG3=0;

    ADCON0bits.ADON=1;//Enable ADC Module
    ADCON0bits.GO_DONE=0; //Stop Conversion
    ADC_Info.ADC_INIT_FLAG=1;
}

void ADC_Start_Conv(void)
{
	if (ADC_Info.ADC_INIT_FLAG==1)
	{
	    _ADC_START_CONV ;  //Start Conversion
	    ADC_Info.ADC_START_FLAG=1;
	}
}

void ADC_Conv_MainFunction(void)
{
	if(ADC_Info.ADC_INIT_FLAG==1 && ADC_Info.ADC_START_FLAG==1 && Mode.Select_Mode==Normal_Mode)
	{
	    if(_IS_CONV_DONE)
	    {
	   	 ADC_Value_Ready_CallBack();
	   	_ADC_START_CONV;

	    }
	}
}

void ADC_Value_Ready_CallBack(void)
{
  uint16_t ADC_Value=(ADRESH<<8)|(ADRESL);
  Temperature_Calc(ADC_Value);

}
