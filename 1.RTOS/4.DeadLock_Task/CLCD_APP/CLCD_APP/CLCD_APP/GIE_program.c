



#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "GIE_interface.h"
#include "GIE_register.h"

/*Enable GIE (Global interrupt Enable)*/
void GIE_voidEnable (void)
{
SET_BIT(SREG_REG,SREG_I);
}

/*Disable GIE (Global interrupt Enable)*/
void GIE_voidDisable (void)
{
CLEAR_BIT(SREG_REG,SREG_I);
}

