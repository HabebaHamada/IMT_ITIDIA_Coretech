/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: PORT          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include"PORT_register.h"
#include"PORT_config.h"
#include"PORT_private.h"
#include"PORT_interface.h"

void PORT_voidInit(void)
{
	DDRA=PORTA_DIR;
    DDRB=PORTB_DIR;
    DDRC=PORTC_DIR;
    DDRD=PORTD_DIR;
	
	PORTA=PORTA_INITVAL ;
    PORTB=PORTB_INITVAL	;
    PORTC=PORTC_INITVAL	;
    PORTD=PORTD_INITVAL	;
}