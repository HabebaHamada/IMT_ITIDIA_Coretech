
#include "STD_TYPES.h"
#include "BIT_Manipulation.h"
#include "UART_Private.h"

void UART_VidInt(void){
	UCSRC = (1<<7) | (3<<1);
	UBRRL = 51;
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRB, RXEN);
}

void UART_VidSendData(u8 Copy_u8Data){
	while(GET_BIT(UCSRA, UDRE)!=1);
	UDR = Copy_u8Data;
}

u8 UART_u8RecieveData(void){
	while(GET_BIT(UCSRA, RXC)!=1);
	return UDR;
}


void UART_Vid_SendString(u8 *user)
{
	u8 i = 0;
	UART_VidSendData(user[i]);
	while(user[i] != '\0')
	{
		i++;
		UART_VidSendData(user[i]);
	}
}

void UART_Vid_SendInt(u32 Copy_U32Number){


    if(Copy_U32Number == 0)
	{
		UART_VidSendData('0');
		return ;
	}
	else if(Copy_U32Number != 0){
		UART_Vid_SendInt(Copy_U32Number/10);
		UART_VidSendData((Copy_U32Number%10)+'0');
		return ;
	}

}
