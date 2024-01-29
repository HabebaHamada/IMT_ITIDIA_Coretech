#ifndef ADC_INT_H
#define ADC_INT_H

typedef enum{

	ADC0 ,
	ADC1 ,
	ADC2 ,
	ADC3 ,
	ADC4 ,
	ADC5 ,
	ADC6 ,
	ADC7

}et_pinADC;

u16 ADC_vid_getADCValue_Sync(u8 Copy_u8Channel);

void ADC_Vid_Init();

signed int Temp_ADC_read(void) ;

#endif
