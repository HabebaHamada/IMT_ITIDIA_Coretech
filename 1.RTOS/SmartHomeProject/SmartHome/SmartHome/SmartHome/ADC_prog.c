

#include "STD_TYPES.h"
#include "BIT_Manipulation.h"
#include "ADC_private.h"
#include "ADC_config.h"




void ADC_Vid_Init(){

	CLEAR_BIT(ADMUX, ADMUX_REFS0);
	CLEAR_BIT(ADMUX, ADMUX_REFS1);
	/* for right adj */
	CLEAR_BIT(ADMUX, ADMUX_ADLAR);

	ADCSRA &= 0b11111000;
	ADCSRA |= PRESCALER_VALUE;

	SET_BIT(ADCSRA, ADCSRA_ADEN);
	/*
	Set(ADCSRA, ADCSRA_ADPS0);
	Set(ADCSRA, ADCSRA_ADPS1);
	Set(ADCSRA, ADCSRA_ADPS2);
	*/

}


u16 ADC_vid_getADCValue_Sync(u8 Copy_u8Channel){

	ADMUX &= 0b11100000;
	ADMUX |= Copy_u8Channel;

	/*Start Conversion*/

	SET_BIT(ADCSRA, ADCSRA_ADSC);
	/*Check that the conversion completed*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);

	SET_BIT(ADCSRA,ADCSRA_ADIF);

	return ADCL;
}


signed int Temp_ADC_read(void)     //Read Analog Value of Temp Sensor
{
	ADMUX=0;                        //use ADC0
	SET_BIT(ADCSRA,4);               // clear flag
	SET_BIT(ADCSRA,6);               //start conversion bit register
	while(GET_BIT(ADCSRA,4)==0){ }; //wait for conversion till flag became one
    return ADCL;
}


