/*
 * RTOS_APP.c
 *
 * Created: 1/14/2024 9:30:22 PM
 * Author : Blu-Ray
 */ 


#include <avr/io.h>
#define  F_CPU 8000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>
#include "MDIO_Interface.h"
#include "MDIO_Private.h"
#include "MTimer0_Interface.h"
#include "MGIE_Interface.h"

#include "RTOS_interface.h"

void LED_TOG1(void);
void LED_TOG2(void);
void LED_TOG3(void);
void LED_TOG4(void);

u8 preload_value=123;

int main(void)
{
    /* Replace with your application code */
	
		RTOS_u8CreateTask(LED_TOG1,0,1,0);
	    RTOS_u8CreateTask(LED_TOG2,1, 2,0);
	    RTOS_u8CreateTask(LED_TOG3,2, 4,0);
	    RTOS_u8CreateTask(LED_TOG4,3,10,0);
		  
		  
	MDIO_VoidSetPortDirection(PORTA,0xff);
	
	
		MDIO_VoidSetPinValue(PORTA,0,1);
		MDIO_VoidSetPinValue(PORTA,1,1);
		MDIO_VoidSetPinValue(PORTA,2,1);
		MDIO_VoidSetPinValue(PORTA,3,1);
	
	MTimer0_VoidSetTCNT(123);
	MTimer0_VoidInitOV();
	MTimer0_ViodEnableTimer();
	
	MGIE_VoidEnable();
	


      RTOS_voidStartOS();
    while (1) 
    {
    }
}

void LED_TOG1(void){
	static u8 OV_counter=0;
	OV_counter++;
	if(OV_counter==31)
	{
		TCNT0=preload_value;
		OV_counter=0;
		MDIO_VoidTogglePin(PORTA,0);
	}
}

void LED_TOG2(void){
   static u8 OV_counter=0;
   OV_counter++;
   if(OV_counter==31)
   {
	TCNT0=preload_value;
	OV_counter=0;
	MDIO_VoidTogglePin(PORTA,1);
   }
}

void LED_TOG3(void){
	static u8 OV_counter=0;
	OV_counter++;
	if(OV_counter==31)
	{
		TCNT0=preload_value;
		OV_counter=0;
		MDIO_VoidTogglePin(PORTA,2);
	}
}

void LED_TOG4(void){
	static u8 OV_counter=0;
	OV_counter++;
	if(OV_counter==31)
	{
		TCNT0=preload_value;
		OV_counter=0;
		MDIO_VoidTogglePin(PORTA,3);
	}
}


