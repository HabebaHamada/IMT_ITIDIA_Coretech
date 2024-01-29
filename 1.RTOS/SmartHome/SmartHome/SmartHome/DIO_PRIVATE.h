/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: DIO           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

u8 volatile* const DIO_u8ArrPORT[4]={&PORTA,&PORTB,&PORTC,&PORTD};
u8 volatile* const DIO_u8ArrPIN[4]= {&PINA,&PINB,&PINC,&PIND};
//u8* const DIO_u8ArrDDR[4]= {&DDRA,&DDRB,&DDRC,&DDRD};

	
#define DIO_u8NumOfPins   8
#define DIO_u8NumOfPorts  4


	
#endif