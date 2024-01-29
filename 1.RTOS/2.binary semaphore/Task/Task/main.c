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
#include "semphr.h"
#include "queue.h"

#include "BIT_Manipulation.h"
#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "PORT_INTERFACE.h"
#include "CLCD_interface.h"


xSemaphoreHandle xBinarySemaphore_1 = NULL;

xTaskHandle Task1Handler  	        = NULL;
xTaskHandle Task2Handler         	= NULL;


void LCD_1(void *PV);
void LCD_2(void *PV);

int main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	CLCD_voidSetCursor(1,0);

	
	xBinarySemaphore_1 =xSemaphoreCreateBinary( );
	
	xSemaphoreGive( xBinarySemaphore_1 );

	

	xTaskCreate(LCD_1,"LCD_1",100,NULL,1,&Task1Handler);
	xTaskCreate(LCD_2,"LCD_2",100,NULL,0,&Task2Handler);
	/*start OS*/
	vTaskStartScheduler();
    /* Replace with your application code */
    while (1) 
    {
    }
}

void LCD_1(void *PV)
{

	while(1)
	{
		if (xSemaphoreTake( xBinarySemaphore_1, 100 ) == pdTRUE)
		{
			CLCD_voidClearDisplay();
			CLCD_voidSendString("TASK 1 is On ");
			_delay_ms(2000);
			xSemaphoreGive(xBinarySemaphore_1); // release the semphare
			vTaskDelay(1000);
		}
	}
}


void LCD_2(void *PV)
{

	while(1)
	{
		if (xSemaphoreTake( xBinarySemaphore_1, 100 ) == pdTRUE)
		{
			CLCD_voidClearDisplay();
			CLCD_voidSendString("TASK 2 is On ");
			_delay_ms(2000);
			xSemaphoreGive(xBinarySemaphore_1); // release the semaphore
			vTaskDelay(500);
		}
	}
}