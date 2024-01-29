/*
 * Task.c
 *
 * Created: 1/17/2024 10:44:09 PM
 * Author : Blu-Ray
 */ 

#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "FreeRTOS.h"
#include "task.h"
//#include "queue.h"
#include "semphr.h"

#include "BIT_Manipulation.h"
#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "PORT_INTERFACE.h"
#include "CLCD_interface.h"


SemaphoreHandle_t xCSemaphore_1 = NULL;

xTaskHandle Task1Handler  	        = NULL;
xTaskHandle Task2Handler         	= NULL;
xTaskHandle Task3Handler         	= NULL;


void LCD_1(void *PV);
void LCD_2(void *PV);
void LCD_3(void *PV);


int main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	CLCD_voidSetCursor(1,0);

	
	xCSemaphore_1 =xSemaphoreCreateCounting(2,0);
	
	
	xTaskCreate(LCD_1,"LCD_1",100,NULL,1,&Task1Handler);
	xTaskCreate(LCD_2,"LCD_2",100,NULL,1,&Task2Handler);
	xTaskCreate(LCD_3,"LCD_3",100,NULL,1,&Task3Handler);
	/*start OS*/
	vTaskStartScheduler();
    /* Replace with your application code */
    while (1) 
    {
    }
}

void LCD_1(void *PV)
{
    xSemaphoreGive(xCSemaphore_1);
	while(1)
	{
		if (xSemaphoreTake( xCSemaphore_1, 100 ) == pdTRUE)
		{
			CLCD_voidClearDisplay();
			CLCD_voidSendString("TASK 1 is On ");
			_delay_ms(2000);
			xSemaphoreGive(xCSemaphore_1); // release the semaphore
			vTaskDelay(500);
		}
	}
}


void LCD_2(void *PV)
{

	while(1)
	{
		if (xSemaphoreTake( xCSemaphore_1, 100 ) == pdTRUE)
		{
			CLCD_voidClearDisplay();
			CLCD_voidSendString("TASK 2 is On ");
			_delay_ms(2000);
			xSemaphoreGive(xCSemaphore_1); // release the semaphore
			vTaskDelay(500);
		}
	}
}

void LCD_3(void *PV)
{

	while(1)
	{
		if (xSemaphoreTake( xCSemaphore_1, 100 ) == pdTRUE)
		{
			CLCD_voidClearDisplay();
			CLCD_voidSendString("TASK 3 is On ");
			_delay_ms(2000);
			xSemaphoreGive(xCSemaphore_1); // release the semaphore
			vTaskDelay(500);
		}
	}
}