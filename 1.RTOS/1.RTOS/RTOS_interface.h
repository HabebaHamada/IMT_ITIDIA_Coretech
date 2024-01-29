/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: RTOS               ****************/
/*************       Component: OS            ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

/************************************************
 * Name        : RTOS_u8CreateTask              *
 * Return type : u8                             *
 * Arguments   : Copy_TaskHandler -->PTR TO FUNC*
 *               Copy_u8Priority --> u8         *
 *               Copy_u16Periodicity --> u8     *
 *               Copy_u16FirstDelay --> u16     *
 * Description : Creating a new Task            *
 ************************************************/
u8 RTOS_u8CreateTask(void(*Copy_TaskHandler)(void),u8 Copy_u8Priority, u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay);

/************************************************
 * Name        : RTOS_voidDeleteTask            *
 * Return type : void                           *
 * Arguments   : Copy_u8Priority --> u8         *
 * Description : Deleting a Task                *
 ************************************************/
void RTOS_voidDeleteTask(u8 Copy_u8Priority);

/************************************************
 * Name        : RTOS_u8SuspendTask             *
 * Return type : u8                             *
 * Arguments   : Copy_u8Priority --> u8         *
 *               Copy_u8SuspendTime --> u8      *
 * Description : Suspending a Task              *
 ************************************************/
u8 RTOS_u8SuspendTask(u8 Copy_u8Priority, u8 Copy_u8SuspendTime);

/************************************************
 * Name        : RTOS_u8ResumeTask              *
 * Return type : u8                             *
 * Arguments   : Copy_u8Priority --> u8         *
 * Description : Resuming a Task                *
 ************************************************/
u8 RTOS_u8ResumeTask(u8 Copy_u8Priority);

/************************************************
 * Name        : RTOS_u8GetTaskState            *
 * Return type : u8                             *
 * Arguments   : Copy_u8Priority --> u8         *
 * Description : Getting a Task state           *
 ************************************************/
u8 RTOS_u8GetTaskState(u8 Copy_u8Priority);

/************************************************
 * Name        : Scheduler                      *
 * Return type : void                           *
 * Arguments   : void                           *
 * Description : OS Scheduler                   *
 ************************************************/
void Scheduler(void);

/************************************************
 * Name        : RTOS_voidStartOS               *
 * Return type : void                           *
 * Arguments   : void                           *
 * Description : Starting OS                    *
 ************************************************/
void RTOS_voidStartOS(void);



#endif
