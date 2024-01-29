/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: CLCD          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


void CLCD_voidInit(void);

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidSendString(const char* Copy_pcString);

void CLCD_voidSetCursor(u8 Copy_u8XPosition, u8 Copy_u8YPosition);

void CLCD2_voidInit(void);

void CLCD2_voidSendCommand(u8 Copy_u8Command);

void CLCD2_voidSendData(u8 Copy_u8Data);

void CLCD2_voidSendString(const char* Copy_pcString);

void CLCD2_voidSetCursor(u8 Copy_u8XPosition, u8 Copy_u8YPosition);

void CLCD_voidClearDisplay(void);

void CLCD2_voidClearDisplay(void);


#endif