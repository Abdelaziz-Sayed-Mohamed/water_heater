

#include "Scheduler_cfg.h"
#include "Tasks.h"

#define Task1Periodms   			(20UL)    	/*in ms*/
#define Task2Periodms  				(100UL) 	/*in ms*/
#define Task3Periodms   			(200UL) 	/*in ms*/

uint8_t Scheduler_ActivationFlags[NumberOfTasks] ;

const Scheduler_Intity_t Scheduler_Intitys[NumberOfTasks]={
	{.fuction_ptr = &Scheduler_Task1 , .Peroid = Task1Periodms   } ,
	{.fuction_ptr = &Scheduler_Task2 , .Peroid = Task2Periodms   } ,
	{.fuction_ptr = &Scheduler_Task3 , .Peroid = Task3Periodms   }
};
