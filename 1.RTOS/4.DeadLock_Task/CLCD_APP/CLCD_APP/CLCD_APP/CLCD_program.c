/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: CLCD          ****************/
/*************       Version: 1.00            ****************/
/*************       Date: 27/6/2022          ****************/
/*************************************************************/
#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_Manipulation.h"



#include "DIO_INTERFACE.h"
#include "CLCD_config.h"
#include "CLCD_private.h"
#include "CLCD_interface.h"

void CLCD_voidInit(void)
{
	/* Wait for more than 30ms */
	_delay_ms(40);
	
	/* Function Set Command : 2 Lines and 5*8 Font size */
	CLCD_voidSendCommand(0x38);
	
	/* Display ON/OFF Control : Display Enable, Cursor Disable and No Blinking Cursor*/
	CLCD_voidSendCommand(0x0C);
		
	/* Display Clear Command */
	CLCD_voidSendCommand(0x01);
	
	
}

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS to low for Command*/
   DIO_u8WritePinValue(CLCD_RS_PIN,CLCD_CONTROL_PORT ,DIO_u8PIN_LOW);
   
   /*Set RW to low for write*/
   DIO_u8WritePinValue(CLCD_RW_PIN,CLCD_CONTROL_PORT ,DIO_u8PIN_LOW);
   
   /*Send Command to data pins*/
   DIO_u8WritePortValue(CLCD_DATA_PORT,Copy_u8Command);
   
   /* Send Enable pulse */
   DIO_u8WritePinValue(CLCD_E_PIN,CLCD_CONTROL_PORT ,DIO_u8PIN_HIGH);
   _delay_ms(2);
   DIO_u8WritePinValue(CLCD_E_PIN,CLCD_CONTROL_PORT ,DIO_u8PIN_LOW);

   
	
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS to high for Data*/
	DIO_u8WritePinValue(CLCD_RS_PIN,CLCD_CONTROL_PORT ,DIO_u8PIN_HIGH);
	
	/*Set RW to low for write*/
	DIO_u8WritePinValue(CLCD_RW_PIN,CLCD_CONTROL_PORT ,DIO_u8PIN_LOW);
	
	/*Send Command to data pins*/
	DIO_u8WritePortValue(CLCD_DATA_PORT,Copy_u8Data);
	
	/* Send Enable pulse */
	DIO_u8WritePinValue(CLCD_E_PIN,CLCD_CONTROL_PORT ,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8WritePinValue(CLCD_E_PIN,CLCD_CONTROL_PORT ,DIO_u8PIN_LOW);

	
	
}

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter = 0;
	
	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidSetCursor(u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
	/* For the second line display add 0x40 to the Address */
	u8 Local_u8Address = (Copy_u8XPosition * 0x40) + (Copy_u8YPosition);
	
	/* Set bit 7 for DDRAM Address Command then send the Command */
	CLCD_voidSendCommand(Local_u8Address + 128);
	
	
}


/************************************************/

void CLCD2_voidInit(void)
{
	/* Wait for more than 30ms */
	_delay_ms(40);
	
	/* Function Set Command : 2 Lines and 5*8 Font size */
	CLCD2_voidSendCommand(0x38);
	
	/* Display ON/OFF Control : Display Enable, Cursor Disable and No Blinking Cursor*/
	CLCD2_voidSendCommand(0x0C);
	
	/* Display Clear Command */
	CLCD2_voidSendCommand(0x01);
	
	
}

void CLCD2_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS to low for Command*/
	DIO_u8WritePinValue(CLCD2_RS_PIN,CLCD2_CONTROL_PORT ,DIO_u8PIN_LOW);
	
	/*Set RW to low for write*/
	DIO_u8WritePinValue(CLCD2_RW_PIN,CLCD2_CONTROL_PORT ,DIO_u8PIN_LOW);
	
	/*Send Command to data pins*/
	DIO_u8WritePortValue(CLCD2_DATA_PORT,Copy_u8Command);
	
	/* Send Enable pulse */
	DIO_u8WritePinValue(CLCD2_E_PIN,CLCD2_CONTROL_PORT ,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8WritePinValue(CLCD2_E_PIN,CLCD2_CONTROL_PORT ,DIO_u8PIN_LOW);

}

void CLCD2_voidSendData(u8 Copy_u8Data)
{
	/*Set RS to high for Data*/
	DIO_u8WritePinValue(CLCD2_RS_PIN,CLCD2_CONTROL_PORT ,DIO_u8PIN_HIGH);
	
	/*Set RW to low for write*/
	DIO_u8WritePinValue(CLCD2_RW_PIN,CLCD2_CONTROL_PORT ,DIO_u8PIN_LOW);
	
	/*Send Command to data pins*/
	DIO_u8WritePortValue(CLCD2_DATA_PORT,Copy_u8Data);
	
	/* Send Enable pulse */
	DIO_u8WritePinValue(CLCD2_E_PIN,CLCD2_CONTROL_PORT ,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8WritePinValue(CLCD2_E_PIN,CLCD2_CONTROL_PORT ,DIO_u8PIN_LOW);

	
	
}

void CLCD2_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter = 0;
	
	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		CLCD2_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD2_voidSetCursor(u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
	/* For the second line display add 0x40 to the Address */
	u8 Local_u8Address = (Copy_u8XPosition * 0x40) + (Copy_u8YPosition);
	
	/* Set bit 7 for DDRAM Address Command then send the Command */
	CLCD2_voidSendCommand(Local_u8Address + 128);
	
}

void CLCD_voidClearDisplay()
{
	CLCD_voidSendCommand(0b00000001);	//sending Instruction to clear the whole display
}

void CLCD2_voidClearDisplay()
{
	CLCD2_voidSendCommand(0b00000001);	//sending Instruction to clear the whole display
}