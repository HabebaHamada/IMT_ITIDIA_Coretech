
#ifndef WDT_CONFIG_H_
#define WDT_CONFIG_H_



/* WDT Pre_scaler select */
/*
		Choose Options :-
		1- WDT_PS_16_3_MS	   ( for 16.3 ms )
		2- WDT_PS_32_5_MS	   ( for 32.5 ms )
		3- WDT_PS_65_MS	       ( for 65   ms )
		4- WDT_PS_0_13_S	   ( for 0.13  s )
		5- WDT_PS_0_26_S	   ( for 0.26  s )
		6- WDT_PS_0_52_S	   ( for 0.52  s )
		7- WDT_PS_1_0_S	       ( for 1.0   s )
		8- WDT_PS_2_1_S	       ( for 2.1   s )

 */
#define WDT_PRESCALER      WDT_PS_2_1_S


#endif /* WDT_CONFIG_H_ */
