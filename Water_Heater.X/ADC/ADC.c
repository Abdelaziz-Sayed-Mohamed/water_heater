/*
 * ADC.c
 *
 *  Created on: Jul 7, 2020
 *      Author: Abdelaziz Sayed
 */

#include "ADC.h"


/****************************************************************************************/
/*    Function Name           : ADC_Init          			                            */
/*    Function Description    : Init ADC With ch2 (A2)                                  */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/

void ADC_Init(void)
{

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

    ADCON0bits.ADON=1;    //Enable ADC Module
    ADCON0bits.GO_DONE=0; //Stop Conversion
    SET_ADC_INIT_FLAG;
}

/****************************************************************************************/
/*    Function Name           : ADC_Start_Conv          			                    */
/*    Function Description    : Check if adc init and start ADCON0bits.GO_DONE=1        */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/

void ADC_Start_Conv(void)
{    
	if (IS_ADC_INIT)
	{
	    ADC_START_CONV ;  //Start Conversion
	    SET_ADC_START_FLAG;
	}
}

/****************************************************************************************/
/*    Function Name           : ADC_Get_Value          			                        */
/*    Function Description    : Check if adc Started and Set adc value in buffer        */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/

void ADC_Get_Value(uint8_t *Buffer)
{
	if(IS_ADC_STARTED&&IS_CONV_DONE)
	{      
        *Buffer=(ADRESH<<8)|(ADRESL);
	   	ADC_START_CONV;   
	}
}


