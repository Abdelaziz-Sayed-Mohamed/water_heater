/*
 * Display.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#include "Display_Cfg.h"
#include "Display.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"
#include"../gpio/gpio.h"
#include"../Temperature/Temperature.h"

typedef enum _Enable_Display_t
{
	Enable_Display_Off=0,
	Enable_Display_On=1,
}Enable_Display_t;

Enable_Display_t  Enable_Display;

void Display_Init(void)
{

	TRISD=OUTPUT;
	TRISAbits.TRISA4=OUTPUT;
	TRISAbits.TRISA5=OUTPUT;
	RESET_PIN(_DIGIT1_PORT_,_DIGIT1_PIN_) ;
	RESET_PIN(_DIGIT2_PORT_,_DIGIT2_PIN_) ;
	_7SEGMENT_PORT_=0;
}



void Display_MainFunction(void) //This Function should be Mapped On 20ms Task To can Blink 2 Digit 7Segment Every 1 Sec If Setting Mode Enabled
{
 uint8_t Digit_1=0;
 uint8_t Digit_2=0;
 uint8_t Tempreture=0;
 uint8_t Display=0;
 static uint8_t Enable_Digit_Selector=1;

  if(Mode.Select_Mode==Normal_Mode)
  {
	  Tempreture=Temperature.Average_Value;
	  Enable_Display=Enable_Display_On;
  }
  else if(Mode.Select_Mode==Setting_Mode)
  {
	  Tempreture=Temperature.Set_Temp;
  }
  else if(Mode.Select_Mode==Off_Mode)
  {
	  Display_Off();
  }


 if(Mode.Select_Mode!=Off_Mode)
 {
	 if(Enable_Display==Enable_Display_On)
	 {
         Digit_1=Tempreture%10;
         Digit_2=Tempreture/10;
         Enable_Digit_Selector^=Enable_Digit_Selector;

         if(Enable_Digit_Selector==0)
         {
  	       Display=Digit_1;
           RESET_PIN(_DIGIT2_PORT_,_DIGIT2_PIN_);
           SET_PIN(_DIGIT1_PORT_,_DIGIT1_PIN_)  ;

         }
         else if(Enable_Digit_Selector==1)
         {
  	       Display=Digit_2;
  	       RESET_PIN(_DIGIT1_PORT_,_DIGIT1_PIN_);
  	       SET_PIN(_DIGIT2_PORT_,_DIGIT2_PIN_);

         }



         switch(Display)
         {
          case 0:
             _7SEGMENT_PORT_=0b00111111;
             break;

          case 1:
             _7SEGMENT_PORT_=0b00000110;
             break;

          case 2:
             _7SEGMENT_PORT_=0b01011011;
             break;

          case 3:
             _7SEGMENT_PORT_=0b01001111;
             break;

          case 4:
             _7SEGMENT_PORT_=0b01100110;
             break;

          case 5:
             _7SEGMENT_PORT_=0b01101101;
             break;

          case 6:
             _7SEGMENT_PORT_=0b01111101;
             break;

          case 7:
             _7SEGMENT_PORT_=0b01000111;
             break;

          case 8:
             _7SEGMENT_PORT_=0b01111111;
             break;

          case 9:
             _7SEGMENT_PORT_=0b01101111;
             break;

         }
	 }

	 if(Mode.Select_Mode==Setting_Mode)
	 {
		 Display_Blink(1000,20);

	 }
  }

}


void Display_Blink(uint16_t Times_Ms,uint16_t Task_Peroid)
{
  uint8_t static Counter=1;

  if(Counter*Task_Peroid==Times_Ms)
  {
      if(Enable_Display==Enable_Display_On)
      {
    	  Enable_Display=Enable_Display_Off;
    	  Display_Off();

      }
      else if(Enable_Display==Enable_Display_Off)
      {
    	  Enable_Display=Enable_Display_On;
      }
      Counter=1;
  }
  Counter++;
}


void Display_Off(void)
{

	RESET_PIN(_DIGIT1_PORT_,_DIGIT1_PIN_) ;
	RESET_PIN(_DIGIT2_PORT_,_DIGIT2_PIN_) ;

}

