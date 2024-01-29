

#ifndef WDT_REGISTER_H_
#define WDT_REGISTER_H_


#define WDTCR_REG				*((volatile u8 *) 0x41)			/*Watch_dog Timer Control Register – WDTC*/

#define WDTCR_WDTOE			4								/*Watch_dog Turn-off Enable*/
#define	WDTCR_WDE			3								/*Watch_dog Enable*/
#define WDTCR_WDP2			2								/*Watch_dog Timer Pre_scaler 2, 1, and 0*/
#define WDTCR_WDP1			1
#define WDTCR_WDP0			0

#endif /* WDT_REGISTER_H_ */
