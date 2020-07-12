
#include "../I2C/I2C.h"
#include"EEPROM.h"
#include"../WaterHeater_Mode/WaterHeater_Mode_Cfg.h"
#include"../Temperature/Temperature.h"

uint8_t EEPROM_Data=0;

void Get_EEPROM_Data(void)
{
    
 Start_EEPROM_Connection;   
 EEPROM_Data=e2pext_r(EEPROM_DATA_ADDR);
 uint8_t Flag=(EEPROM_Data>>7)&1;
 uint8_t Temp=(EEPROM_Data)&~(1<<7);

 if(IS_Flag_Was_Seted && ((Temp<=MAX_SET_TEMP)||(Temp>=MIN_SET_TEMP)))
 {
   Temperature.Set_Temp=Temp; 
 }
 else
 {
    Temperature.Set_Temp=DEFAULT_SET_TEMP;
 }    

}


void Set_EEPROM_Data(void)
{
static unsigned char ah;
static unsigned char al;
static unsigned char nt;
#ifdef EEPROM

if(IS_Store_Set_Temp_Ready)
{       
     EEPROM_Data=Temperature.Set_Temp|(1<<7);
   
     ah=(EEPROM_DATA_ADDR&0x0100)>>8;
     al=EEPROM_DATA_ADDR&0x00FF;
     nt=0;
   
     do
     {
       i2c_start();
       if(ah)
       { 
         i2c_wb(0xA2);
       }
       else
       {
         i2c_wb(0xA0);
       }
       i2c_wb(al);
       i2c_wb(EEPROM_Data);
       i2c_stop();
   
       nt++;
     }
     while((EEPROM_Data != e2pext_r(EEPROM_DATA_ADDR))&&(nt < 10));
}     
#endif
}

unsigned char e2pext_r(unsigned int addr)
{
  unsigned char ret;
  unsigned char ah;
  unsigned char al;

  ah=(addr&0x0100)>>8;
  al=addr&0x00FF;

  i2c_start();	
  if(ah)
  {
    i2c_wb(0xA2);
  }
  else
  {
    i2c_wb(0xA0);
  }
  i2c_wb(al);

  i2c_start();
  if(ah)
  {
    i2c_wb(0xA3);
  }
  else
  {
    i2c_wb(0xA1);
  }
  ret=i2c_rb(1);
  i2c_stop();

  return ret;	
}