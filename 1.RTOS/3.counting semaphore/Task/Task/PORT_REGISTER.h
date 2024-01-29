/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: PORT          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

#define DDRA_Address	0x3A
#define PORTA_Address	0x3B

#define DDRB_Address	0x37
#define PORTB_Address	0x38

#define DDRC_Address	0x34
#define PORTC_Address	0x35

#define DDRD_Address	0x31
#define PORTD_Address	0x32



#define DDRA           *((volatile u8*)DDRA_Address)
#define PORTA          *((volatile u8*)PORTA_Address) 

#define DDRB           *((volatile u8*)DDRB_Address)
#define PORTB          *((volatile u8*)PORTB_Address)

#define DDRC           *((volatile u8*)DDRC_Address)
#define PORTC          *((volatile u8*)PORTC_Address)

#define DDRD           *((volatile u8*)DDRD_Address)
#define PORTD          *((volatile u8*)PORTD_Address)


#endif