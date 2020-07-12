/*
 *Average.c
 *
 *  Created on: Jul 7, 2020
 *      Author: Abdelaziz Sayed
 */
#include "Average.h"
static uint8_t Average_Nvalues = AVERAGE_BUFFER_SIZE ;
static uint32_t temb_val[AVERAGE_BUFFER_SIZE];
uint32_t Avrage_buffer=0;

void Average_Value(uint8_t Value,uint8_t *Avrage_Values)
{
	
    Avrage_buffer=0;
	temb_val[Average_Nvalues]=Value;

	Average_Nvalues= (Average_Nvalues+1)%AVERAGE_BUFFER_SIZE;

	for(uint8_t index=0;index<AVERAGE_BUFFER_SIZE;index++)
	{
		Avrage_buffer+=temb_val[index];
	}


   *Avrage_Values=Avrage_buffer/AVERAGE_BUFFER_SIZE;
}
