#include "I2C.h"
#include"../gpio/gpio.h"

void delay(void)
{
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
   
}


void i2c_start(void)
{
     
    
  SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  SET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
  RESET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
}

void i2c_stop(void)
{
  SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  RESET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
  SET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
}

void i2c_wb(unsigned char val)
{
  unsigned char i;
  RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  for(i=0;i<8;i++)
  {
    IDAT=((val>>(7-i))& 0x01);
    SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
    delay();
    RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  }	
  SET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
  SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  delay();
  RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
}

unsigned char i2c_rb(unsigned char ack)
{
  char i;
  unsigned char ret=0;

  RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  SET_PIN_DIRECTION(EEPROM_SDA_DIRECTION,EEPROM_SDA_PIN,INPUT);
  SET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  for(i=0;i<8;i++)
  {
    SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
    delay();
    ret|=(IDAT<<(7-i));
    RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  }
  SET_PIN_DIRECTION(EEPROM_SDA_DIRECTION,EEPROM_SDA_PIN,OUTPUT) ; 
  if(ack)
    RESET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  else
	SET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
  SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  delay();
  RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);

  return ret;
}




