/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: RTOS               ****************/
/*************       Component: OS            ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MTimer0_Interface.h"

#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"

Task SystemTasks[MaxNumberOfTasks]={0};

Task Empty={0};

u8 RTOS_u8CreateTask(void(*Copy_TaskHandler)(void),u8 Copy_u8Priority, u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay )
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8Priority<=MaxNumberOfTasks)
	{
	   if(SystemTasks[Copy_u8Priority].TaskHandler==0)
	    {
		SystemTasks[Copy_u8Priority].TaskHandler=Copy_TaskHandler;
		SystemTasks[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
		SystemTasks[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
		SystemTasks[Copy_u8Priority].TaskTiming=Copy_u16FirstDelay;
		SystemTasks[Copy_u8Priority].TaskState=Ready;

		}

       else
        {
		  /* The required priority is already reserved */
			Local_u8ErrorState=1;
			
        }	
	}
	else
	{
		/*Priority is bigger than the Max Number of tasks*/
		Local_u8ErrorState=2;
	}
    	
	
	
	return Local_u8ErrorState;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority]=Empty;
	SystemTasks[Copy_u8Priority].TaskState=Deleted;
	
}

u8 RTOS_u8SuspendTask(u8 Copy_u8Priority, u8 Copy_u8SuspendTime)
{
	u8 Local_ErrorState = 0;
	if (SystemTasks[Copy_u8Priority].TaskHandler != 0)
	{
		
		SystemTasks[Copy_u8Priority].TaskState = Suspended;
		SystemTasks[Copy_u8Priority].SuspendTime = Copy_u8SuspendTime;
	}
	
	else
	{
		/* Task not exist */
		Local_ErrorState = 1;
	}
	
	return Local_ErrorState;
	
}
	
	
u8 RTOS_u8ResumeTask(u8 Copy_u8Priority)
{
	u8 Local_ErrorState = 0;
	if (SystemTasks[Copy_u8Priority].TaskHandler != 0)
	{
		
		SystemTasks[Copy_u8Priority].TaskState = Ready;
	}
	
	else
	{
		/* Task not exist */
		Local_ErrorState = 1;
	}
	
	return Local_ErrorState;
	
	
}

u8 RTOS_u8GetTaskState(u8 Copy_u8Priority)
{
	u8 Local_ErrorState = 0;
	if (SystemTasks[Copy_u8Priority].TaskHandler != 0)
	{
		
		return SystemTasks[Copy_u8Priority].TaskState;
	}
	
	else
	{
		/* Task not exist */
		Local_ErrorState = 100;
		return Local_ErrorState;

	}	
	
}

void Scheduler(void)
{
	u8 Local_u8Counter=0;
	
	/* Loop on all Taks */
	for (Local_u8Counter =0; Local_u8Counter < MaxNumberOfTasks; Local_u8Counter++)
	{
		/* Is there a registered task ... ? */
		if (SystemTasks[Local_u8Counter].TaskHandler != 0)
		{	
			if (SystemTasks[Local_u8Counter].TaskState == Ready )
			{
				if (SystemTasks[Local_u8Counter].TaskTiming == 0)
				{
					/* Run the task */
					SystemTasks[Local_u8Counter].TaskHandler();
					
					/*Task state is Running*/
				    SystemTasks[Local_u8Counter].TaskState = Running;
					
					/* Reload the periodicity */
					SystemTasks[Local_u8Counter].TaskTiming =SystemTasks[Local_u8Counter].Periodicity;
				}
			
				else 
				{
					SystemTasks[Local_u8Counter].TaskTiming--;
				}
			}
			else if(SystemTasks[Local_u8Counter].TaskState == Running )
			{
				if (SystemTasks[Local_u8Counter].TaskTiming == 0)
				{
				  SystemTasks[Local_u8Counter].TaskState = Ready;

				}
				else 
				{
					SystemTasks[Local_u8Counter].TaskTiming--;
				}
				
			}
			else if(SystemTasks[Local_u8Counter].TaskState == Suspended )
			{
				if (SystemTasks[Local_u8Counter].SuspendTime == 0)
				{
				  SystemTasks[Local_u8Counter].TaskState = Ready;

				}
				else 
				{
					SystemTasks[Local_u8Counter].SuspendTime--;
				}
				
			}
		}
	}
	
}

void RTOS_voidStartOS(void)
{
	MTimer0_VoidSetCallBack(Scheduler);
}
