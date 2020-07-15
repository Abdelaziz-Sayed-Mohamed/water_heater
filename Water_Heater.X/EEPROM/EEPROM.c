
#include "../I2C/I2C.h"
#include"EEPROM.h"
#include"../WaterHeater_Mode/WaterHeater_Mode_Cfg.h"
#include"../Temperature/Temperature.h"

uint8_t EEPROM_Data=0;

void Get_EEPROM_Data(void)
{
 #if EEPROM  
    
 Start_EEPROM_Connection;   
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


void Set_EEPROM_Data(void)
{
#if EEPROM

 if(IS_Store_Set_Temp_Ready)
 {       
    EEPROM_Data=Temperature.Set_Temp;
    EEPROM_Write(EEPROM_Data,EEPROM_DATA_ADDR);
    Reset_Store_Set_Temp_Flag;  
#endif
 }
}


void EEPROM_Write(uint8_t Data,uint8_t ADDR)
{
    I2c_Start();   
    I2c_Write(EEPROM_24c04_ADDR);
    I2c_Write(ADDR);
    I2c_Write(Data);
    I2c_Stop();

}


uint8_t EEPROM_Read(uint8_t addr)
{
  uint8_t ret;

  I2c_Start();	
  I2c_Write(EEPROM_24c04_ADDR); 
  I2c_Write(addr);
  I2c_Start();
  I2c_Write(EEPROM_24c04_ADDR+1);
  ret=I2c_Read();
  I2c_Stop();
  return ret;	
}