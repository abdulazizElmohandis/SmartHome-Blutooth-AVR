#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

void HMOTORS_voidServoInit(void){

    MTIMER1_voidInit();
    MTIMER1_voidSetOCR1AValue(1000); //angle 0
} 

void HMOTORS_voidServoSetAngle(u8 Angle){
    u16 Local_u16Value = 0;
    Local_u16Value = ((u64)Angle*1000/180) + 1000;
    MTIMER1_voidSetOCR1AValue(Local_u16Value);
}

void HMOTORS_voidStepperForward(void){
    for(u16 i = 0; i < 512;i++){
        // Step 1 
        MDIO_void_SetPinValue(PORTB, PIN0, DIO_RESET);
        MDIO_void_SetPinValue(PORTB, PIN1, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN2, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN3, DIO_SET);
        _delay_ms(10);

        // Step 2
        MDIO_void_SetPinValue(PORTB, PIN0, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN1, DIO_RESET);
        MDIO_void_SetPinValue(PORTB, PIN2, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN3, DIO_SET);
        _delay_ms(10);

        // Step 3
        MDIO_void_SetPinValue(PORTB, PIN0, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN1, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN2, DIO_RESET);
        MDIO_void_SetPinValue(PORTB, PIN3, DIO_SET);
        _delay_ms(10);

        // Step 4
        MDIO_void_SetPinValue(PORTB, PIN0, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN1, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN2, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN3, DIO_RESET);
        _delay_ms(10);

    }

}



void HMOTORS_voidStepperBackward(void){

    for(u16 i = 0; i < 512; i++) {
        // Step 4 (Reversed)
        MDIO_void_SetPinValue(PORTB, PIN0, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN1, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN2, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN3, DIO_RESET);
        _delay_ms(10);

        // Step 3 (Reversed)
        MDIO_void_SetPinValue(PORTB, PIN0, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN1, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN2, DIO_RESET);
        MDIO_void_SetPinValue(PORTB, PIN3, DIO_SET);
        _delay_ms(10);

        // Step 2 (Reversed)
        MDIO_void_SetPinValue(PORTB, PIN0, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN1, DIO_RESET);
        MDIO_void_SetPinValue(PORTB, PIN2, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN3, DIO_SET);
        _delay_ms(10);

        // Step 1 (Reversed)
        MDIO_void_SetPinValue(PORTB, PIN0, DIO_RESET);
        MDIO_void_SetPinValue(PORTB, PIN1, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN2, DIO_SET);
        MDIO_void_SetPinValue(PORTB, PIN3, DIO_SET);
        _delay_ms(10);
    }
}


