#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include <util/delay.h>
  
#include "../include/MCAL/DIO/DIO_Interface.h"

#include "../include/MCAL/EXTI/EXTI_Private.h"
#include "../include/MCAL/EXTI/EXTI_Config.h"
#include "../include/MCAL/EXTI/EXTI_Interface.h"

void (*ISR0_ptrToFun)(void) = NULL;
void (*ISR1_ptrToFun)(void) = NULL;
void (*ISR2_ptrToFun)(void) = NULL;


void MEXTI_voidConfig (EXTI_ID A_EXTI_ID, EXTI_SENSE_MODE A_EXTISenseMode){

    //input validation
    if((A_EXTI_ID <= EXTI2) && (A_EXTISenseMode <= RISING_EDGE)){
        switch (A_EXTI_ID)
        {
        case EXTI0:
            MCUCR &= ~((SENSE_MODE_MASK << EXTI0_SENSE_MODE_BITS));
            MCUCR |= ((A_EXTISenseMode << EXTI0_SENSE_MODE_BITS));
        break;
        
        case EXTI1:
            MCUCR &= ~((SENSE_MODE_MASK << EXTI1_SENSE_MODE_BITS));
            MCUCR |= ((A_EXTISenseMode << EXTI1_SENSE_MODE_BITS));
            break;

        case EXTI2:
            if((A_EXTISenseMode == FALLING_EDGE) || (A_EXTISenseMode == RISING_EDGE)){
            
                switch (A_EXTISenseMode)
                {
                case FALLING_EDGE:
                    CLR_BIT(MCUCSR, EXTI2_SENSE_MODE_BITS);
                    break;
                case RISING_EDGE:
                    SET_BIT(MCUCSR, EXTI2_SENSE_MODE_BITS);
                    break;            

                }
            }

            break;                    
        }

    }
}

void MEXTI_voidEnable (EXTI_ID A_EXTI_ID){


    if (A_EXTI_ID <= EXTI2){
            switch (A_EXTI_ID)
            {
            case EXTI0:
                SET_BIT(GICR, EXTI0_ENABLE_BIT);
            break;
            
            case EXTI1:
                SET_BIT(GICR, EXTI1_ENABLE_BIT);
                break;

            case EXTI2:
                SET_BIT(GICR, EXTI2_ENABLE_BIT);
                break;                    
            }
    }


}

void MEXTI_voidDisable (EXTI_ID A_EXTI_ID){

        if (A_EXTI_ID <= EXTI2){
            switch (A_EXTI_ID)
            {
                case EXTI0:
                    CLR_BIT(GICR, EXTI0_ENABLE_BIT);
                break;
                
                case EXTI1:
                    CLR_BIT(GICR, EXTI1_ENABLE_BIT);
                    break;

                case EXTI2:
                    CLR_BIT(GICR, EXTI2_ENABLE_BIT);
                    break;                    
            }
    }


}

void MEXTI_voidClearFlag (EXTI_ID A_EXTI_ID){

        if (A_EXTI_ID <= EXTI2){
            switch (A_EXTI_ID)
            {
            case EXTI0:
                SET_BIT(GIFR, EXTI0_ENABLE_BIT);
            break;
            
            case EXTI1:
                SET_BIT(GIFR, EXTI1_ENABLE_BIT);
                break;

            case EXTI2:
                SET_BIT(GIFR, EXTI2_ENABLE_BIT);
                break;                    
            }
    }

    


}



void MEXTI_voidSetCallBack (EXTI_ID A_EXTI_ID, void(*A_ptrToFunc)(void)){

        if ((A_EXTI_ID <= EXTI2) && (A_ptrToFunc != NULL)){

            switch (A_EXTI_ID)
            {
            case EXTI0:
                ISR0_ptrToFun = A_ptrToFunc;
            break;
            
            case EXTI1:
                ISR1_ptrToFun = A_ptrToFunc;
                break;

            case EXTI2:
                ISR2_ptrToFun = A_ptrToFunc;
                break;                    
            }
    }

}



void __vector_1(void) __attribute__((signal,used));
void __vector_1(void){

    if(ISR0_ptrToFun != NULL){

        ISR0_ptrToFun();
    }

}

void __vector_2(void) __attribute__((signal,used));
void __vector_2(void){

    if(ISR1_ptrToFun  != NULL){
        
        ISR1_ptrToFun();
    }
}

void __vector_3(void) __attribute__((signal,used));
void __vector_3(void){

    if(ISR2_ptrToFun != NULL){
        
        ISR2_ptrToFun();
    }
    
}