#include "BIT_MATH.h"
#include "MTimer0_Private.h"
#include "MTimer0_CNFG.h"
#include "MTimer0_Interface.h"

u8 TCNT_Value;
void (*PGlb_Func)(void);

void MTimer0_VoidInitOV(void)
{
	/* SET THE NORMAL MODE*/ 
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	/* clear the prescaler */
	CLR_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
	/* ENABLE PIE*/
	SET_BIT(TIMSK,0);

}
void MTimer0_VoidSetTCNT(u8 Copy_U8TCNTVal){
	TCNT0=Copy_U8TCNTVal;
	TCNT_Value=Copy_U8TCNTVal;
}


void MTimer0_ViodEnableTimer(void)
{
	TCCR0 &=0b11111000;
	TCCR0 |=PRESCALER;
}

void MTimer0_voidDisableTimer(void)
{
	CLR_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
}

void MTimer0_VoidSetCallBack(void (*P_func)(void))
{
	PGlb_Func = P_func;
}
void __vector_11(void)
{
	PGlb_Func();
}
