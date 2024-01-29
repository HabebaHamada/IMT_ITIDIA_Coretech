/*
 * SmartHome.c
 *
 * Created: 1/18/2024 7:13:10 PM
 * Author : HABEBA HAMADA
 */ 
#define  F_CPU 8000000UL
#include <util/delay.h>

/************************************************************************/
/* LIB Includes                                                         */
/************************************************************************/
#include "BIT_Manipulation.h"
#include "STD_TYPES.h"

/************************************************************************/
/* MCAL Includes                                                        */
/************************************************************************/
#include "DIO_INTERFACE.h"
#include "PORT_INTERFACE.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "UART_Int.h"
#include "ADC_int.h"

/************************************************************************/
/* HAL Includes                                                         */
/************************************************************************/
#include "CLCD_interface.h"

/************************************************************************/
/* RTOS Service Includes                                                */
/************************************************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"

/*Semaphore to protect LED_State Shared Resource*/
xSemaphoreHandle xBinarySemaphore_LED = NULL;

/************************************************************************/
/*  Tasks Handlers                                                      */
/************************************************************************/
//xTaskHandle LEDHandler  	      = NULL;
xTaskHandle Push_ButtonHandler    = NULL;
//xTaskHandle LCDHandler            = NULL;
//xTaskHandle UARTHandler           = NULL;
//xTaskHandle DoorHandler           = NULL;
//xTaskHandle TempHandler           = NULL;

   /*Prototypes of Tasks Function*/
void LED(void *PV);
void Push_Button(void *PV);
void LCD(void *PV);
void Door(void *PV);
void UART_Comm(void *PV);
void temp_Control(void *PV);


void INT0ISR(void);

/*Global Variables for LED state , Switch state , ADC result*/
static u8 LEDState=0;
static u8 Switch_State=0;
f32  ADC_result=0;

int main(void)
{	
	
	/*System Initialization*/	
	PORT_voidInit();
	GIE_voidEnable();
	EXTI_voidInt0Init();
	ADC_Vid_Init();
	UART_VidInt();
	
	CLCD_voidInit();
	CLCD2_voidInit();
	
	/*set EXTII call Back Function*/
	EXTI_u8Int0SetCallBack(INT0ISR);
	

	/*create semaphore*/
	xBinarySemaphore_LED =xSemaphoreCreateBinary( );
	
	/*Give semaphore as xSemaphoreCreateBinary initialize Semaphore */
	xSemaphoreGive( xBinarySemaphore_LED);


     /*System Tasks Creation*/
	 xTaskCreate(UART_Comm,"UART",200,NULL,3,NULL);
	 xTaskCreate(LCD,"LCD",150,NULL,1,NULL);
     xTaskCreate(LED,"LED",75,NULL,2,NULL);
     xTaskCreate(Door,"Door",75,NULL,2,NULL);
	 xTaskCreate(temp_Control,"Temp",75,NULL,2,NULL);
     xTaskCreate(Push_Button,"Push_Button",75,NULL,2,&Push_ButtonHandler);

	 
	 vTaskSuspend(Push_ButtonHandler);
	 
	/*start OS*/
	vTaskStartScheduler();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

void Door(void *PV)
{

	while(1)
	{
		DIO_u8ReadPinValue(DIO_u8PORTD,DIO_u8PIN3,&Switch_State);
		//_delay_ms(20);  // for deBouncing
		if (Switch_State==1)
		{
			DIO_u8WritePinValue(DIO_u8PIN6,DIO_u8PORTD,1);
		} 
		else if (Switch_State==0)
		{
			DIO_u8WritePinValue(DIO_u8PIN6,DIO_u8PORTD,0);
		}
		vTaskDelay(1500);
		
	}
}
void LCD(void *PV)
{
	while(1)
	{
		if (Switch_State==1)
		{
			CLCD_voidSetCursor(2,1);
			CLCD_voidSendString("Door is Closed ");
			_delay_ms(400);
		}
		else if (Switch_State==0)
		{
			CLCD_voidSetCursor(2,1);
			CLCD_voidSendString("Door is Open .");
			_delay_ms(400);
		}
		if (LEDState==1)
		{
			CLCD_voidSetCursor(1,1);
			CLCD_voidSendString("lED is On ");
			_delay_ms(400);
		}
		else if (LEDState==0)
		{
			CLCD_voidSetCursor(1,1);
			CLCD_voidSendString("lED is Off ");
			_delay_ms(400);
		}
		CLCD2_voidClearDisplay();
		CLCD2_voidSendString("T = ");
		CLCD2_WriteNumber(ADC_result);
		_delay_ms(400);
		
	}
}
void LED(void *PV)
{
	
	while(1)
	{
		
		if(xSemaphoreTake( xBinarySemaphore_LED, 100 ) == pdTRUE )
		{
			TOGGLE_BIT(LEDState,0);
			xSemaphoreGive( xBinarySemaphore_LED );
		    DIO_u8WritePinValue(DIO_u8PIN7,DIO_u8PORTD,LEDState);
		   vTaskDelay(6000);
		}
	}
}

void Push_Button(void *PV)
{
	while(1)
	{
		if(xSemaphoreTake( xBinarySemaphore_LED, 100 ) == pdTRUE )
		{
			TOGGLE_BIT(LEDState,0);
		    DIO_u8WritePinValue(DIO_u8PIN7,DIO_u8PORTD,LEDState);
			 _delay_ms(500);
			xSemaphoreGive( xBinarySemaphore_LED );
		}
	
        vTaskSuspend(Push_ButtonHandler);       	
	}
}

void INT0ISR(void)
{
    vTaskResume(Push_ButtonHandler);
}

void UART_Comm(void *PV)
{
	while(1)
   {
	   UART_Vid_SendString("\f lED is = ");
	   UART_Vid_SendInt(LEDState);
	   UART_Vid_SendString(", Door is = ");
	   UART_Vid_SendInt(Switch_State);
	   UART_Vid_SendString(",T = ");
	   UART_Vid_SendInt(ADC_result);
	   UART_Vid_SendString("\n\r");

	vTaskDelay(2500);
   }
}

void temp_Control(void *PV)
{
	vTaskDelay(1000);
	while(1)
	{
	 signed int volt;

	volt=Temp_ADC_read();
	ADC_result=(float)(5*volt)/1023;   //Equation conversation for LM35 Sensor
	ADC_result*=100;

	vTaskDelay(4000);
	}
	
}