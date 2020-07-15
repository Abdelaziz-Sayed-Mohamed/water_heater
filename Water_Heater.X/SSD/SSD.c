/*
 * SSD.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#include "SSD_Cfg.h"
#include "SSD.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"
#include"../gpio/gpio.h"
#include"../Temperature/Temperature.h"


void SSD_Init(void)
{
	RESET_PIN(DIGIT1_PORT,DIGIT1_PIN) ;
	RESET_PIN(DIGIT2_PORT,DIGIT2_PIN) ;
	_7SEGMENT_PORT=SSD_Zero;
}



void SSD_MainFunction(void) //This Function should be Mapped On 20ms Task To can Blink 2 Digit 7Segment Every 1 Sec If Setting Mode Enabled
{
 static uint8_t Digit_1=0;
 static uint8_t Digit_2=0;
 static uint8_t Tempreture=0;
 static uint8_t SSD=0;
 static uint8_t Enable_Digit_Selector=1;
 
  /*Select What Will SSDing*/
  if(Mode.Select_Mode==Normal_Mode)
  {
	  Tempreture=Temperature.Average_Value;
	  Enable_SSD=Enable_SSD_On;
  }
  else if(Mode.Select_Mode==Setting_Mode)
  {
	  Tempreture=Temperature.Set_Temp;
  }
  else if(Mode.Select_Mode==Off_Mode)
  {
	 RESET_PIN(DIGIT1_PORT,DIGIT1_PIN) ;
	 RESET_PIN(DIGIT2_PORT,DIGIT2_PIN) ;
     _7SEGMENT_PORT=Turn_Off_7seg_Port;
  }


 if(Mode.Select_Mode!=Off_Mode)
 {
	 if(Enable_SSD==Enable_SSD_On)
	 {
         Digit_1=Tempreture%10;         //Digit 1 value
         Digit_2=Tempreture/10;         //Digit 2 value 
         
         Toggle_Enable_Digit_Selector;  //Switch between tow digits
          
         if(IS_Digit_1_Enabled)         //Enable Digit 1 and disable digit 2
         {
  	       SSD=Digit_1;
           RESET_PIN(DIGIT2_PORT,DIGIT2_PIN);
           SET_PIN(DIGIT1_PORT,DIGIT1_PIN)  ;

         }
         else if(IS_Digit_2_Enabled)    //Enable Digit 2 and disable digit 1
         {
  	       SSD=Digit_2;
  	       RESET_PIN(DIGIT1_PORT,DIGIT1_PIN);
  	       SET_PIN(DIGIT2_PORT,DIGIT2_PIN);

         }



         switch(SSD)
         {
          case 0:
             _7SEGMENT_PORT=SSD_Zero;
             break;

          case 1:
             _7SEGMENT_PORT=SSD_One;
             break;

          case 2:
             _7SEGMENT_PORT=SSD_Two;
             break;

          case 3:
             _7SEGMENT_PORT=SSD_Three;
             break;

          case 4:
             _7SEGMENT_PORT=SSD_Four;
             break;

          case 5:
             _7SEGMENT_PORT=SSD_Five;
             break;

          case 6:
             _7SEGMENT_PORT=SSD_Six;
             break;

          case 7:
             _7SEGMENT_PORT=SSD_Seven;
             break;

          case 8:
             _7SEGMENT_PORT=SSD_Eight;
             break;

          case 9:
             _7SEGMENT_PORT=SSD_Nine;
             break;

         }
	 }

	 if(Mode.Select_Mode==Setting_Mode)   //If system in setting mode Tow digits will Blinking every 1 Sec
	 {
		 SSD_Blink(SSD_Blink_Time,SSD_Blink_TaskPeroid);

	 }
  }

}


void SSD_Blink(uint16_t Times_Ms,uint16_t Task_Peroid) 
{
  static uint8_t Counter=1;

  if(Counter*Task_Peroid==Times_Ms)
  {
      if(Enable_SSD==Enable_SSD_On)
      {
    	  Enable_SSD=Enable_SSD_Off;
    	   RESET_PIN(DIGIT1_PORT,DIGIT1_PIN) ;
	       RESET_PIN(DIGIT2_PORT,DIGIT2_PIN) ;
      }
      else if(Enable_SSD==Enable_SSD_Off)
      {
    	  Enable_SSD=Enable_SSD_On;
      }
        ResetSSDCounter;
  }
  Counter++;
}

