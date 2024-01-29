/*
 * MACROS_FUN.h
 *
 *  Created on: Sep 12, 2021
 *      Author: Mohamed Eltaweel
 */

#ifndef BIT_MATH_H_ 
#define BIT_MATH_H_


/*********************************
 defining set bit functoin to set 1 to nbit of byte
 *************************************/
#define SET_BIT(byte,nbit)	byte|=(1<<nbit)

/****************************************
defining clear bit functoin to clear nbit of byte 
****************************************/
#define CLR_BIT(byte,nbit)	byte&=~(1<<nbit)

/****************************************
defining get bit functoin to get nbit of byte 
****************************************/
#define GET_BIT(byte,nbit)	((byte>>nbit)&1)

/****************************************
defining toggle bit to toggle nbit of byte 
****************************************/
#define TOGGLE_BIT(byte,nbit)	byte^=(1<<nbit)

#endif /* BIT_MATH_H_ */
