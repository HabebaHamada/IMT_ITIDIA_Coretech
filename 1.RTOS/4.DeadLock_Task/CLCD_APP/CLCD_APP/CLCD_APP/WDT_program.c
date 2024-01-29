
#include "BIT_Manipulation.h"
#include "STD_TYPES.h"

#include "WDT_private.h"
#include "WDT_config.h"
#include "WDT_register.h"
#include "WDT_interface.h"

/*For Critical Section*/
#include "GIE_interface.h"


void WDT_voidEnable (void)
{
	SET_BIT(WDTCR_REG , WDTCR_WDE);
}

void WDT_voidSleep(void)
{
	/* CLear The Pre_scaler bits */
	WDTCR_REG &= WDT_PRESCALE_MASKING;

	/* Set The required pre_scaller */
	WDTCR_REG |= WDT_PRESCALER;
}


void WDT_voidDisable(void)
{
	/*Hint : Must the Critical Section because maybe interrupt event happened when the Four Cycle Work
	 *Within the next four clock cycles, write a logic 0 to WDE. This disables the Watch_dog
	 ******** (Critical Section )**********
	 * Disable -->> Interrupt -->> Enable
	 * */


	/*Disable All interrupts*/
	GIE_voidDisable();

	/*Write a logic one to WDTOE and WDE*/
	WDTCR_REG = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);
	WDTCR_REG = 0x00;

	/*Enable all Interrupt*/
	GIE_voidEnable();
}

