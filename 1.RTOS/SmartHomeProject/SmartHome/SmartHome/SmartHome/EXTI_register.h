/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: EXTI          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define General_Interrupt_Control_Register   GICR
#define General_Interrupt_Flag_Register      GIFR
#define MCU_Control_Register                 MCUCR
#define MCU_Control_Status_Register          MCUCSR

#define GICR         *((volatile u8*)0x5B)
#define GIFR         *((volatile u8*)0x5A)
#define MCUCR        *((volatile u8*)0x55)
#define MCUCSR       *((volatile u8*)0x54)

#define GICR_INT1    7
#define GICR_INT0    6
#define GICR_INT2    5
 
#define GIFR_INTF1   7
#define GIFR_INTF0   6
#define GIFR_INTF2   5

//MCUCR INT0 Sense Control bits.
#define MCUCR_ISC00  0
#define MCUCR_ISC01  1

//MCUCR INT1 Sense Control bits.
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3

//MCUCSR INT2 Sense Control bits.

#define MCUCSR_ISC2  6

//Global Interrupt Enable
#define  I       7

#endif