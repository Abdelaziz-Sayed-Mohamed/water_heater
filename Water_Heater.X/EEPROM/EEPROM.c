/*
 * File:   EEPROM.c
 * Author: Abdalaziz Sayed
 *
 * Created on July 17, 2020, 2:08 AM
 */

#include"EEPROM.h"
#include"../WaterHeater_Mode/WaterHeater_Mode_Cfg.h"
#include"../Temperature/Temperature.h"

uint8_t EEPROM_Data=0;



/****************************************************************************************/
/*    Function Name           : Get_EEPROM_Data          			                    */
/*    Function Description    : Get stored data from eeprom and set
 *                             Temperature.Set_Temp if data valid                       */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void Get_EEPROM_Data(void)
{
 #if EEPROM  
    
 EEPROM_Data=EEPROM_Read(EEPROM_DATA_ADDR);

 if((EEPROM_Data<=MAX_SET_TEMP)&&(EEPROM_Data>=MIN_SET_TEMP )&& IS_Value_Vaild )
 {
   Temperature.Set_Temp=EEPROM_Data; 
 }
 else
 {
   Temperature.Set_Temp=DEFAULT_SET_TEMP;
 }    
 
#endif
}


/****************************************************************************************/
/*    Function Name           : Set_EEPROM_Data          			                    */
/*    Function Description    : set data to eeprom if setting mode done                 */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void Set_EEPROM_Data(void)
{
#if EEPROM

 if(IS_Store_Set_Temp_Ready)
 {       
    EEPROM_Data=Temperature.Set_Temp;
    EEPROM_Write(EEPROM_Data,EEPROM_DATA_ADDR);
    Reset_Store_Set_Temp_Flag; 
 }   
#endif
 
}

/****************************************************************************************/
/*    Function Name           : EEPROM_Write          			                        */
/*    Function Description    : write data in eeprom ins specific address               */                                          
/*    Parameter In            : Data,Addr                                               */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void EEPROM_Write(uint8_t Data,uint8_t Addr)
{
 I2c_Start();
 I2c_Write(SlaveAddr);
 I2c_WaitAck();
 I2c_Write(Addr);
 I2c_WaitAck();
 I2c_Write(Data);
 I2c_WaitAck();
 I2c_Stop();
 
}


/****************************************************************************************/
/*    Function Name           : EEPROM_Read          			                        */
/*    Function Description    : Read data from eeprom from specific address             */                                          
/*    Parameter In            : Addr                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : Data                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
uint8_t EEPROM_Read(uint8_t Addr)
{
  static uint8_t Data;
  I2c_Start();
  I2c_Write(SlaveAddr);
  I2c_WaitAck();
  I2c_Write(Addr); 
  I2c_WaitAck();
  I2c_Start();
  I2c_Write(SlaveAddr+1);
  I2c_WaitAck();
  Data=I2c_Read();
  I2c_Send_NAck();
  I2c_Stop();
  return Data;
}