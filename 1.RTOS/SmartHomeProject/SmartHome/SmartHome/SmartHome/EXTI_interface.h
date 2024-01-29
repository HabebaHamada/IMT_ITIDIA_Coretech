/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: EXTI          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL		0b00  //00
#define LOGICAL_CHANGE	0b01  //01
#define FALLING_EDGE	0b10  //10
#define RISING_EDGE		0b11  //11


 
void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);

void EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);
void EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);
void EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);
void EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));

#endif 