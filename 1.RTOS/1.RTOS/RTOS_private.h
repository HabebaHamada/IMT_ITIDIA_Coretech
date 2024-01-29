/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: RTOS               ****************/
/*************       Component: OS            ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef enum
{
	Ready,
	Suspended,
	Running,
	Deleted,
}State;


typedef struct
{
	void(*TaskHandler)(void);
	u8  Priority;     /*Priority is unique for every task and indicates the location of the task in TaskSystem array*/
	u16 Periodicity;  /* How Often the task repeat */
	u16 FirstDelay;   /* when the first time the task came */
	u16 TaskTiming;   
	State TaskState;
	u16 SuspendTime;  /* How long the Task suspend */
		
}Task;





#endif