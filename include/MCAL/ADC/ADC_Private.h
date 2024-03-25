#ifndef ADC_Private_H_
#define ADC_Private_H_

#define ADMUX  (*(volatile u8 *)0x27)
#define ADCSRA (*(volatile u8 *)0x26)
#define ADCH   (*(volatile u8 *)0x25)
#define ADCL   (*(volatile u8 *)0x24)


/*To read the value of 0x24 and 0x25
  So it's u16
  Have to be Right Adjust to read ADCLH*/
#define ADCLH  (*(volatile u16 *)0x24) 

/*ADC MUX bits first 5 bits
    0 -------> 32 in decimal*/
#define ADC_CHANNEL_MASK 0b11100000

#endif /* ADC_Private_H_ */