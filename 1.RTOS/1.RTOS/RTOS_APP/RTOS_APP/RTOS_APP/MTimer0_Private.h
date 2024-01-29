#ifndef Timer0_Private
#define Timer0_Private

#include "STD_TYPES.h"


#define TCCR0 *((u8*)0x53)
#define TCNT0 *((u8*)0x52)
#define TIMSK *((u8*)0x59)
#define TIFR *((u8*)0x58)
#define OCR0 *((u8*)0x5C)
void __vector_11(void) __attribute__((signal));


#endif
