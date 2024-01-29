#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


#define UDR *((volatile u8*)0x2C)

#define UCSRA *((volatile u8*)0x2B)
#define UDRE  5
#define TXC   6
#define RXC   7

#define UCSRB *((volatile u8*)0x2A)
#define UCSZ2 2
#define TXEN  3
#define RXEN  4

#define UCSRC *((volatile u8*)0x40)
#define UCSZ0 1
#define UCSZ1 2
#define USBS  3
#define UPM0  4
#define UPM1  5
#define URSEL 7


#define UBRRL *((volatile u8*)0x29)


#endif
