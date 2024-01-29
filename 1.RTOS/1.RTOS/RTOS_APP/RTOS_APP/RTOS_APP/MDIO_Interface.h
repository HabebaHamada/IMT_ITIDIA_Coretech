#ifndef MDIO_Interface_H_
#define MDIO_Interface_H_
#include"STD_TYPES.h"
/******************************************
defining set pin direction to set direction of pin. 
this function takes the port name, pin number and the direction assigned
*******************************************/
void MDIO_VoidSetPinDirection (u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Direction);
/*********************************************
defining get pin fuction to get the value of pin.
this  function takes port name and pin number
**********************************************/
u8 MDIO_U8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin);
/***********************************************
defining set pin value to set value of specific pin
this function takes the port name, pin number and value assigned to this pin
**************************************************/
void MDIO_VoidSetPinValue (u8 Copy_U8Port,u8 Copy_U8pin,u8 Copy_U8Value);
/**************************************************
defining set port direction to set the direction of specific port
this function takes the port name and its direction 
****************************************************/
void MDIO_VoidSetPortDirection (u8 Copy_U8Port,u8 Copy_U8Direction);
/**************************************************
defining set port value to set the value of specific port
this function takes the port name and the value assigned to it
**************************************************/
void MDIO_VoidSetPortValue (u8 Copy_U8Port,u8 Copy_U8Value);
/**************************************************
defining toggle pin fuction to toggle value in specific pin of any port
this function takes the port name and pin number
****************************************************/
void MDIO_VoidTogglePin(u8 Copy_U8Port,u8 Copy_U8Pin);
#endif