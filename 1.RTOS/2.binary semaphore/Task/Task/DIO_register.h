/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: DIO           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

 /*************************************************************************************************/
/*PORT,PIN and DDR address  */

#define PORTA_Address	0x3B
#define PINA_Address	0x39

#define PORTB_Address	0x38
#define PINB_Address	0x36

#define PORTC_Address	0x35
#define PINC_Address	0x33

#define PORTD_Address	0x32
#define PIND_Address	0x30

/******************************************************************************************************/
#define PORTA          *((volatile u8*)PORTA_Address) 
#define PINA           *((volatile u8*)PINA_Address)

#define PORTB          *((volatile u8*)PORTB_Address)
#define PINB           *((volatile u8*)PINB_Address)

#define PORTC          *((volatile u8*)PORTC_Address)
#define PINC           *((volatile u8*)PINC_Address)

#define PORTD          *((volatile u8*)PORTD_Address)
#define PIND           *((volatile u8*)PIND_Address)

#endif