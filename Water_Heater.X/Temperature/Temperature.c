/*
 * Temperature.c
 *
 *  Created on: Jul 7, 2020
 *      Author: Abdelaziz Sayed
 */

#include "Temperature.h"
#include"../Average/Average.h"


/****************************************************************************************/
/*    Function Name           : Temperature_MainFunction          			            */
/*    Function Description    : Get adc value if iam in normal mode and then 
 *                              call Temperature_Calc() to convert adc value to volt    */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/

void Temperature_MainFunction(void)
{
  if(Mode.Select_Mode==Normal_Mode)
  {
   ADC_Get_Value(&Temperature.ADC_Value);
  }
  Temperature_Calc();
}


/****************************************************************************************/
/*    Function Name           : Temperature_Calc          			                    */
/*    Function Description    : Convert adc value from volt to Temp then call 
 *                              Average_Value to get average value                      */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void Temperature_Calc(void)
{
	Temperature.Temp_Value=Temperature.ADC_Value * ADC_RESOLUTION;                    //Convert ADC value to Temperature Value
	Average_Value(Temperature.Temp_Value, &Temperature.Average_Value);    //Get  Average_Value Of Temperature Values
	Temperature.Average_NValues=(Temperature.Average_NValues+1)%AVERAGE_BUFFER_SIZE;

	if(Temperature.Average_NValues==NValues) //At least 10 Values to start Display Temperature
	{
       Set_Average_Value_Ready_Flag;
	}

}
