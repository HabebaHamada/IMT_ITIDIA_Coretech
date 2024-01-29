#include "BIT_MATH.h"
#include "MGIE_Private.h"

void MGIE_VoidEnable(void)
{
	SET_BIT(SREG,7);
}


void MGIE_VoidDisable(void)
{
	CLR_BIT(SREG,7);
}