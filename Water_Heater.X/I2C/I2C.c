/*
 * File:   I2C.c
 * Author: Abdalaziz Sayed
 *
 * Created on July 17, 2020, 2:08 AM
 */

#include "I2C.h"

void I2c_Init(void)
{
    SSPADD = (_XTAL_FREQ/(4*I2c_Clock))-1; //Configure I2c Clock Speed
    /*Configure MCU is a Muster*/
    SSPM0=0;
    SSPM1=0;
    SSPM2=0;
    SSPM3=1;
 
    SSPEN=1; //Enable I2c Module
       
}

void I2c_Start(void)
{
    SEN=1;          //Init Start condition
    while(SEN);     //Wait for Start Condition to Complete(Auto Cleared by H.W)
    SSPIF=0;        //Clear Interrupt Flag    
}


uint8_t I2c_Read(void)
{
    uint8_t data;
    RCEN=1;            //Receive data Byte From Slave
    while(!BF);        //Wait for Receive Complete
    data= SSPBUF;      //Get Data From Buffer
    return data;
}

void I2c_Send_NAck(void)
{
    ACKDT=1;          //Prepare TO send NAck
    ACKEN=1;          //Enable NAck Send
    while(ACKEN);     //Wait To NAck Complete
    
}

void I2c_Stop(void)
{
    PEN=1;          //Init Stop condition
    while(PEN);        //Wait for Stop Condition to Complete(Auto Cleared by H.W)
    SSPIF=0;        //Clear Interrupt Flag
}

void I2c_Write(uint8_t data)
{
    SSPBUF=data;             //Send 8 bits data
            
}

void I2c_WaitAck(void)
{
    while(!SSPIF);           //Wait For ACK
    SSPIF=0;                 //Clear Interrupt Flag 
}


