#ifndef TIMERS_Interface_H_
#define TIMERS_Interface_H_

#define NORMAL_MODE			0
#define PHASE_CORRECT_MODE  1
#define CTC_MODE			2
#define FAST_PWM_MODE		3



void MTIMER0_voidInit (void);
void MTIMER0_voidSetPreloadValue (u8 A_u8NoOfTicks);
void MTIMER0_voidSetOVFCallback (void (*A_PtrToFunc)(void));
void MTIMER0_voidSetCTCCallback (void (*A_PtrToFunc)(void));
void MTIMER0_voidSetOCR0Value (u8 A_u8OCR0Value);
void MTIMER0_voidStopTimer (void);
void MTIMER1_voidInit(void);
void MTIMER1_voidSetOCR1AValue(u16 A_u16value);



#endif /* TIMERS_Interface_H_ */