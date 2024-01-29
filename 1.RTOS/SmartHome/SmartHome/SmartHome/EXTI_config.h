/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: EXTI          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/* Options:   1-LOW_LEVEL		
			  2-LOGICAL_CHANGE	
			  3-FALLING_EDGE	
			  4-RISING_EDGE		
*/

#define INT0_Sense   RISING_EDGE
#define INT1_Sense   LOW_LEVEL
#define INT2_Sense   FALLING_EDGE  /* NOTE: INT2 HAS ONLY FALLING AND RISING EDGE OPTIONS!!!*/

/* Options:   1-ENABLE		
			  2-DISABLE			
*/
#define INT0_Enable   ENABLE
#define INT1_Enable   ENABLE
#define INT2_Enable   DISABLE


#endif