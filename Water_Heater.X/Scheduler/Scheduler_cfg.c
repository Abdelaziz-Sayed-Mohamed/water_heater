/*
 * Scheduler_cfg.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */


#include "Scheduler_cfg.h"
#include "Tasks.h"

#define Task1Periodms   			(20UL)    	/*Task 1 Peroid in ms*/
#define Task2Periodms  				(100UL) 	/*Task 2 Peroid in ms*/
#define Task3Periodms   			(500UL) 	/*Task 3 Peroid in ms*/

uint8_t Scheduler_ActivationFlags[NumberOfTasks] ;

const Scheduler_Intity_t Scheduler_Intitys[NumberOfTasks]={
	{.fuction_ptr = &Scheduler_Task1 , .Peroid = Task1Periodms   } ,
	{.fuction_ptr = &Scheduler_Task2 , .Peroid = Task2Periodms   } ,
	{.fuction_ptr = &Scheduler_Task3 , .Peroid = Task3Periodms   }
};
