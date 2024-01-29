#ifndef Timer0_Interface
#define Timer0_Interface
#include "STD_TYPES.h"

#define PRE_1			1
#define PRE_8			2
#define PRE_64 		    3
#define PRE_256 		4
#define PRE_1024		5



void MTimer0_VoidInitOV(void);
void MTimer0_ViodEnableTimer(void);
void MTimer0_voidDisableTimer(void);
void MTimer0_VoidSetCallBack(void (*P_func)(void));
void MTimer0_VoidSetTCNT(u8 Copy_U8TCNTVal);


#endif
