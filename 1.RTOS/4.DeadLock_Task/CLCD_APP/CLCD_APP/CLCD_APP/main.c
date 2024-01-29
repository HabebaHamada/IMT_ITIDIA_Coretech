/*
 * CLCD_APP.c
 *
 * Created: 8/12/2022 3:32:11 AM
 * Author : Blu-Ray
 */ 

#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"

#include "BIT_Manipulation.h"
#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "PORT_INTERFACE.h"
#include "WDT_interface.h"
#include "CLCD_interface.h"


xSemaphoreHandle xBinarySemaphore_1 = NULL;
xSemaphoreHandle xBinarySemaphore_2 = NULL;

xTaskHandle Task1Handler  	= NULL;
xTaskHandle Task2Handler         	= NULL;


void LCD_1(void *PV);
void LCD_2(void *PV);
void WatchdogTask(void *PV);
void WatchdogTask2(void *PV);
void watchdogTask3(void* pvParameters) ;

int main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	CLCD_voidSetCursor(1,0);
	
	CLCD2_voidInit();
	CLCD2_voidSetCursor(1,0);

	
	xBinarySemaphore_1 =xSemaphoreCreateBinary( ); 
	xBinarySemaphore_2 =xSemaphoreCreateBinary( ); 
	
	xSemaphoreGive( xBinarySemaphore_1 );
	xSemaphoreGive( xBinarySemaphore_2 );
	

	xTaskCreate(LCD_1,"LCD_1",100,NULL,1,&Task1Handler);
	xTaskCreate(LCD_2,"LCD_2",100,NULL,0,&Task2Handler);
	/*start OS*/
	vTaskStartScheduler();
    while (1) 
    {
		
    }
}

void LCD_1(void *PV)
{
	vTaskDelay(500);
	
	while(1)
	{	  
		  if(xSemaphoreTake( xBinarySemaphore_2, 100 ) == pdTRUE )
		  {
			  CLCD2_voidClearDisplay();
			  CLCD2_voidSendString("TASK 1 is On ");
			  _delay_ms(1000);
			  //xSemaphoreGive( xBinarySemaphore_2 );
			 // vTaskDelay(2000);
		  }
		  
		  if(xSemaphoreTake( xBinarySemaphore_1, 100 ) == pdTRUE )
		   {
			   CLCD_voidClearDisplay();
			   CLCD_voidSendString("TASK 1 is On WOOOOW ");
			  	 _delay_ms(2000);
                  
			  	 xSemaphoreGive( xBinarySemaphore_1 );
				 xSemaphoreGive( xBinarySemaphore_2 );

				 WDT_voidSleep();
		  	}
		  
		  
	}
}

void LCD_2(void *PV)
{
	WDT_voidEnable();
	WDT_voidSleep();
	while(1)
	{
		 if(xSemaphoreTake( xBinarySemaphore_1, 100 ) == pdTRUE )
		 	{
			 	CLCD_voidClearDisplay();
			 	CLCD_voidSendString("TASK 2 is On ");
			 	_delay_ms(1000);
				 //xSemaphoreGive( xBinarySemaphore_1 );
			 	//vTaskDelay(2000);
		 	}
			 
		 if(xSemaphoreTake( xBinarySemaphore_2, 100 ) == pdTRUE )
		 {
			 CLCD2_voidClearDisplay();
			 CLCD2_voidSendString("TASK 2 is On WOOOOW ");
			 _delay_ms(2000);
			  //xSemaphoreGive( xBinarySemaphore_2 );
			 //vTaskDelay(2000);
		 }
		
	}
}

void WatchdogTask(void *PV)
{
	
TickType_t lastSemaphore1Time=0, lastSemaphore2Time=0;
     while (1)
	 {
		
	// Check if Task 1 is making progress
	if (xTaskGetTickCount() - lastSemaphore1Time > 2000) {
		// Task 1 has not reset semaphore1 within 2000 milliseconds
		// Take corrective action or reset the system)

		// Reset the semaphore1 timeout 
		lastSemaphore1Time = xTaskGetTickCount();
	}

	// Check if Task 2 is making progress
	if (xTaskGetTickCount() - lastSemaphore2Time > 2000) {
		// Task 2 has not reset semaphore2 within 2000 milliseconds
	    // Take corrective action or reset the system)
	
	
		// Reset the semaphore2 timeout 
		lastSemaphore2Time = xTaskGetTickCount();
	}

	// Delay allow other tasks to run
	vTaskDelay(1000);
     }

}


/*void WatchdogTask2(void *PV)
{
	WDT_voidSleep();
	
	while(1)
	{
			
			vTaskDelay(2000);
	}	

}*/
