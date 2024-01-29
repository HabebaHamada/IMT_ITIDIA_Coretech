/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: EXTI          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

/*Global Pointer to function to hold INT0 ISR ADDRESS*/

void (*EXTI_pvInt0Func)(void)=NULL;

void EXTI_voidInt0Init(void)
{
	/*1- Check Sense Control */
#if INT0_Sense ==LOW_LEVEL
    CLEAR_BIT(MCU_Control_Register,MCUCR_ISC00);
    CLEAR_BIT(MCU_Control_Register,MCUCR_ISC01);

#elif INT0_Sense == LOGICAL_CHANGE
    SET_BIT(MCU_Control_Register,MCUCR_ISC00);
    CLEAR_BIT(MCU_Control_Register,MCUCR_ISC01);
	
#elif INT0_Sense == FALLING_EDGE
    CLEAR_BIT(MCU_Control_Register,MCUCR_ISC00);
    SET_BIT(MCU_Control_Register,MCUCR_ISC01);
	
#elif INT0_Sense == RISING_EDGE
    SET_BIT(MCU_Control_Register,MCUCR_ISC00);
    SET_BIT(MCU_Control_Register,MCUCR_ISC01);

#endif	
/* Check Interrupt Enable*/

#if INT0_Enable==ENABLE
   SET_BIT(General_Interrupt_Control_Register,GICR_INT0);
   
#elif INT0_Enable==DISABLE
   CLEAR_BIT(General_Interrupt_Control_Register,GICR_INT0);
	/*ASSIGN_BIT(MCU_Control_Register,MCUCR_ISC00,GET_BIT(INT0_Sense,0));
	ASSIGN_BIT(MCU_Control_Register,MCUCR_ISC01,GET_BIT(INT0_Sense,1));
	ASSIGN_BIT(General_Interrupt_Control_Register,GICR_INT0,GET_BIT(INT0_Enable,0));*/
#endif
}

	
void EXTI_voidInt1Init(void)
{
	/*1- Check Sense Control */
#if INT1_Sense ==LOW_LEVEL
    CLEAR_BIT(MCU_Control_Register,MCUCR_ISC10);
    CLEAR_BIT(MCU_Control_Register,MCUCR_ISC11);

#elif INT1_Sense == LOGICAL_CHANGE
    SET_BIT(MCU_Control_Register,MCUCR_ISC10);
    CLEAR_BIT(MCU_Control_Register,MCUCR_ISC11);
	
#elif INT1_Sense == FALLING_EDGE
    CLEAR_BIT(MCU_Control_Register,MCUCR_ISC10);
    SET_BIT(MCU_Control_Register,MCUCR_ISC11);
	
#elif INT1_Sense == RISING_EDGE
    SET_BIT(MCU_Control_Register,MCUCR_ISC10);
    SET_BIT(MCU_Control_Register,MCUCR_ISC11);
	
#endif	
	/* Check Interrupt Enable*/

#if INT1_Enable==ENABLE
	SET_BIT(General_Interrupt_Control_Register,GICR_INT1);
	
#elif INT1_Enable==DISABLE
	CLEAR_BIT(General_Interrupt_Control_Register,GICR_INT1);
	/*ASSIGN_BIT(MCU_Control_Register,MCUCR_ISC10,GET_BIT(INT1_Sense,0));
	ASSIGN_BIT(MCU_Control_Register,MCUCR_ISC11,GET_BIT(INT1_Sense,1));
	ASSIGN_BIT(General_Interrupt_Control_Register,GICR_INT1,GET_BIT(INT1_Enable,0));*/
#endif
}

void EXTI_voidInt2Init(void)
{
	/*1- Check Sense Control */
	
#if INT2_Sense == FALLING_EDGE
    CLEAR_BIT(MCU_Control_Status_Register,MCUCSR_ISC2);
	
#elif INT2_Sense == RISING_EDGE
    SET_BIT(MCU_Control_Status_Register,MCUCSR_ISC2);

#endif	
	/* Check Interrupt Enable*/

#if INT2_Enable==ENABLE
	SET_BIT(General_Interrupt_Control_Register,GICR_INT2);
	
#elif INT2_Enable==DISABLE
	CLEAR_BIT(General_Interrupt_Control_Register,GICR_INT2);
	/*ASSIGN_BIT(MCU_Control_Status_Register,MCUCSR_ISC2,GET_BIT(INT2_Sense,0));
	ASSIGN_BIT(General_Interrupt_Control_Register,GICR_INT2,GET_BIT(INT1_Enable,0));*/
#endif
}

void EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	switch(Copy_u8Sense)
	{
		case LOW_LEVEL :
		 CLEAR_BIT(MCU_Control_Register,MCUCR_ISC00);
		 CLEAR_BIT(MCU_Control_Register,MCUCR_ISC01);break;
		case LOGICAL_CHANGE:
		 SET_BIT(MCU_Control_Register,MCUCR_ISC00);
		 CLEAR_BIT(MCU_Control_Register,MCUCR_ISC01);break;
		case FALLING_EDGE:
		 CLEAR_BIT(MCU_Control_Register,MCUCR_ISC00);
		 SET_BIT(MCU_Control_Register,MCUCR_ISC01);break;
		 
		case RISING_EDGE:
		SET_BIT(MCU_Control_Register,MCUCR_ISC00);
		SET_BIT(MCU_Control_Register,MCUCR_ISC01);break;
	}
}


void EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense)
{
	switch(Copy_u8Sense)
	{
		case LOW_LEVEL :
		CLEAR_BIT(MCU_Control_Register,MCUCR_ISC10);
		CLEAR_BIT(MCU_Control_Register,MCUCR_ISC11);break;
		case LOGICAL_CHANGE:
		SET_BIT(MCU_Control_Register,MCUCR_ISC01);
		CLEAR_BIT(MCU_Control_Register,MCUCR_ISC11);break;
		case FALLING_EDGE:
		CLEAR_BIT(MCU_Control_Register,MCUCR_ISC10);
		SET_BIT(MCU_Control_Register,MCUCR_ISC11);break;
		
		case RISING_EDGE:
		SET_BIT(MCU_Control_Register,MCUCR_ISC10);
		SET_BIT(MCU_Control_Register,MCUCR_ISC11);break;
	}
}

void EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense)
{
	switch(Copy_u8Sense)
	{
		case FALLING_EDGE:
		    CLEAR_BIT(MCU_Control_Status_Register,MCUCSR_ISC2);break;
				
		case RISING_EDGE:
		    SET_BIT(MCU_Control_Status_Register,MCUCSR_ISC2);break;
	}
}

void EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
	if (Copy_pvInt0Func!=NULL)
	{
		EXTI_pvInt0Func=Copy_pvInt0Func;
	} 
}

/* ISR OF INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	EXTI_pvInt0Func();
}