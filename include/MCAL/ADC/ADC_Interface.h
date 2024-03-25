#ifndef ADC_Interface_H_
#define ADC_Interface_H_

/*ACD MUX BITS in ADMUX*/
typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	ADC_0_0_10,
	ADC_1_0_10,
	ADC_0_0_200,
	ADC_1_0_200,
	ADC_2_2_10,
	ADC_3_2_10,
	ADC_2_2_200,
	ADC_3_2_200
}ADC_CHANNELS;

u16 MADC_u16GetDigitalvalue (ADC_CHANNELS A_AdcChannel);

void MADC_voidInit (void);


#endif /* ADC_Interface_H_ */