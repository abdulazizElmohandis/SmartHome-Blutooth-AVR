#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/TIMERS/TIMERS_Private.h"
#include "../include/MCAL/TIMERS/TIMERS_Config.h"
#include "../include/MCAL/TIMERS/TIMERS_Interface.h"


void (*TIMER0_OVF_CALLBACK)(void) = NULL;
void (*TIMER0_CTC_CALLBACK)(void) = NULL;

void MTIMER0_voidInit (void)
{
	#if TIMER0_MODE == NORMAL_MODE
	// Set Wave Generation to Normal Mode
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	// Enable OVF Interrupt, and Disable CTC Interrupt
	SET_BIT(TIMSK,0);
	CLR_BIT(TIMSK,1);

	// Start Timer by setting its Clock
	TCCR0 &= TIMER0_CLK_MASK;
	TCCR0 |= TIMER0_CLK;

	#elif TIMER0_MODE == PHASE_CORRECT_MODE
	// Set Wave Generation to Phase Correct Mode
	#elif TIMER0_MODE == CTC_MODE
	// Set Wave Generation to CTC Mode
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	// Disable OVF Interrupt, and Enable CTC Interrupt
	SET_BIT(TIMSK,1);
	CLR_BIT(TIMSK,0);

	// Set Compare match value
	OCR0 = OCR0_VALUE;

	// Start Timer by setting its Clock and also set OC0 Pin Mode
	TCCR0 &= TIMER0_CLK_OCR_MASK;
	TCCR0 |= (TIMER0_CLK | (OC0_MODE << 4));

	#elif TIMER0_MODE == FAST_PWM_MODE

	//wave generation 
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

	// disable all interrupts
	CLR_BIT(TIMSK,0);
	CLR_BIT(TIMSK,1);


	//set OCR0 value
	OCR0 = OCR0_VALUE;

	// Set OC0 congifuration (Inverting or Non-Inverting)
	// Set Timer clock
	TCCR0 &= TIMER0_CLK_MASK;
	TCCR0 |= (TIMER0_CLK | (OC0_MODE << 4));

	#endif
}




void MTIMER0_voidSetPreloadValue (u8 A_u8NoOfTicks)
{
	TCNT0 = A_u8NoOfTicks;
}

void MTIMER0_voidStopTimer (void)
{
	TCCR0 &= TIMER0_CLK_MASK;
}

void MTIMER0_voidSetOCR0Value (u8 A_u8OCR0Value)
{
	OCR0 = A_u8OCR0Value;
}



void MTIMER1_voidInit(void)
{
	// Select Timer Mode --> 14
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);

	// Non-Inverting Mode for OC1A
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);

	// ICR1  <-- 19999
	ICR1= 19999;

	// OCR1A <-- 1000
	OCR1A= OCR1A_VALUE;

	// Start Timer by setting its clock
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}

//change compare match value for OCR1A
void MTIMER1_voidSetOCR1AValue(u16 A_u16value)
{
	OCR1A = A_u16value;
}











void MTIMER0_voidSetOVFCallback (void (*A_PtrToFunc)(void))
{
	if (A_PtrToFunc != NULL)
	{
		TIMER0_OVF_CALLBACK = A_PtrToFunc;
	}
}

void MTIMER0_voidSetCTCCallback (void (*A_PtrToFunc)(void))
{
	if (A_PtrToFunc != NULL)
	{
		TIMER0_CTC_CALLBACK = A_PtrToFunc;
	}
}

void __vector_10(void) __attribute__((signal,used));
void __vector_10(void)
{
	if (TIMER0_CTC_CALLBACK != NULL)
	{
		TIMER0_CTC_CALLBACK();
	}
}

void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	if (TIMER0_OVF_CALLBACK != NULL)
	{
		TIMER0_OVF_CALLBACK();
	}
}
