/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: DIO           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "DIO_register.h"
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"


		                                                       
u8  DIO_u8WritePinValue(u8 Copy_u8Pin, u8 Copy_u8Port, u8 Copy_u8Value)
{	
	u8 Local_u8ErrorState=FALSE;
	if ((Copy_u8Pin < DIO_u8NumOfPins)&&(Copy_u8Port < DIO_u8NumOfPorts))
	{
	   ASSIGN_BIT(*DIO_u8ArrPORT[Copy_u8Port],Copy_u8Pin, Copy_u8Value);
	   Local_u8ErrorState=TRUE;
	   
	}
		
	return Local_u8ErrorState;
}

u8  DIO_u8WritePortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=FALSE;
	
  if (Copy_u8Port <DIO_u8NumOfPorts)
  {
	  Assign_Reg(*DIO_u8ArrPORT[Copy_u8Port],Copy_u8Value);
	  Local_u8ErrorState=TRUE;
  } 
  			
	return Local_u8ErrorState;
}

u8  DIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8PTRvalue)
{
	u8 Local_u8ErrorState=FALSE;
	
	if ((Copy_u8PTRvalue!=NULL) && (Copy_u8Pin<DIO_u8NumOfPins))
	{
		
		*Copy_u8PTRvalue =GET_BIT(*DIO_u8ArrPIN[Copy_u8Port], Copy_u8Pin);
		Local_u8ErrorState=TRUE;
		
	} 

	return Local_u8ErrorState;
}
u8  DIO_u8ReadPortValue(u8 Copy_u8Port, u8* Copy_u8PTRvalue)
{
	
	u8 Local_u8ErrorState=FALSE;
	
	if ((Copy_u8PTRvalue!=NULL) && (Copy_u8Port< DIO_u8NumOfPorts))
	{
		
		*Copy_u8PTRvalue =*DIO_u8ArrPIN[Copy_u8Port];
		Local_u8ErrorState=TRUE;
		
	}
	return Local_u8ErrorState;
	
}
/*u8  DIO_u8WritePinDirection(u8 Copy_u8Pin, u8 Copy_u8Port, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState=FALSE;
	
	if ((Copy_u8Pin < DIO_u8NumOfPins)&&(Copy_u8Port < DIO_u8NumOfPorts))
	{
		ASSIGN_BIT(*DIO_u8ArrDDR[Copy_u8Port],Copy_u8Pin,Copy_u8Direction);
		Local_u8ErrorState=TRUE;
	} 
		
	return Local_u8ErrorState;
}

u8  DIO_u8WritePortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState=FALSE;
	if (Copy_u8Port < DIO_u8NumOfPorts)
	{
	    Assign_Reg(*DIO_u8ArrDDR[Copy_u8Port],Copy_u8Direction);
		
		Local_u8ErrorState=TRUE;
	}
		
	return Local_u8ErrorState;
}*/
