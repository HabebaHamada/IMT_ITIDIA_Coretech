#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDIO_Interface.h"
#include "MDIO_Private.h"


void MDIO_VoidSetPinDirection (u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Direction)
{
	if (DIRECTION_OUT==Copy_U8Direction)
	{
		switch(Copy_U8Port)
		{
			case PORTA:
			{
				SET_BIT(DDRA_REG,Copy_U8Pin);
				break;
			}
			case PORTB:
			{
				SET_BIT(DDRB_REG,Copy_U8Pin);
				break;
			}
			case PORTC:
			{
				SET_BIT(DDRC_REG,Copy_U8Pin);
				break;
			}
			case PORTD:
			{
				SET_BIT(DDRD_REG,Copy_U8Pin);
				break;
			}
		}
		
	
		
	}
	else if (DIRECTION_IN==Copy_U8Direction)
	{
		switch(Copy_U8Port)
		{
			case PORTA:
			{
				CLR_BIT(DDRA_REG,Copy_U8Pin);
				break;
			}
			case PORTB:
			{
				CLR_BIT(DDRB_REG,Copy_U8Pin);
				break;
			}
			case PORTC:
			{
				CLR_BIT(DDRC_REG,Copy_U8Pin);
				break;
			}
			case PORTD:
			{
				CLR_BIT(DDRD_REG,Copy_U8Pin);
				break;
			}
		}
	}
}
u8 MDIO_U8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin)
{
	u8 LOC_U8RetData;
	switch (Copy_U8Port)
	{
		case PORTA: LOC_U8RetData=GET_BIT(PINA_REG,Copy_U8Pin); break;
		case PORTB: LOC_U8RetData=GET_BIT(PINB_REG,Copy_U8Pin); break;
		case PORTC: LOC_U8RetData=GET_BIT(PINC_REG,Copy_U8Pin); break;
		case PORTD: LOC_U8RetData=GET_BIT(PIND_REG,Copy_U8Pin); break;
	}
	return LOC_U8RetData;
}
void MDIO_VoidSetPinValue (u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Value)
{
	if (VAL_HIGH==Copy_U8Value)
	{
		switch(Copy_U8Port)
		{
			case PORTA: SET_BIT(PORTA_REG,Copy_U8Pin); break;
			case PORTB: SET_BIT(PORTB_REG,Copy_U8Pin); break;
			case PORTC: SET_BIT(PORTC_REG,Copy_U8Pin); break;
			case PORTD: SET_BIT(PORTD_REG,Copy_U8Pin); break;
		}
	}
	else if (VAL_LOW==Copy_U8Value)
	{
		switch(Copy_U8Port)
		{
			case PORTA: CLR_BIT(PORTA_REG,Copy_U8Pin); break;
			case PORTB: CLR_BIT(PORTB_REG,Copy_U8Pin); break;
			case PORTC: CLR_BIT(PORTC_REG,Copy_U8Pin); break;
			case PORTD: CLR_BIT(PORTD_REG,Copy_U8Pin); break;
		}
	}
}
void MDIO_VoidSetPortDirection (u8 Copy_U8Port,u8 Copy_U8Direction)
{
	switch(Copy_U8Port)
	{
		case PORTA: DDRA_REG=Copy_U8Direction; break;
		case PORTB: DDRB_REG=Copy_U8Direction; break;
		case PORTC: DDRC_REG=Copy_U8Direction; break;
		case PORTD: DDRD_REG=Copy_U8Direction; break;
	}
}
void MDIO_VoidSetPortValue (u8 Copy_U8Port,u8 Copy_U8Value)
{
	switch(Copy_U8Port)
	{
		case PORTA: PORTA_REG=Copy_U8Value; break;
		case PORTB: PORTB_REG=Copy_U8Value; break;
		case PORTC: PORTC_REG=Copy_U8Value; break;
		case PORTD: PORTD_REG=Copy_U8Value; break;
	}
}
void MDIO_VoidTogglePin(u8 Copy_U8Port,u8 Copy_U8Pin)
{
	switch(Copy_U8Port)
	{
		case PORTA: TOGGLE_BIT(PORTA_REG,Copy_U8Pin); break;
		case PORTB: TOGGLE_BIT(PORTB_REG,Copy_U8Pin); break;
		case PORTC: TOGGLE_BIT(PORTC_REG,Copy_U8Pin); break;
		case PORTD: TOGGLE_BIT(PORTD_REG,Copy_U8Pin); break;
	}
}