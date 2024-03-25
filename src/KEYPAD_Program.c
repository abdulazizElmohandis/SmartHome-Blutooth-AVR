#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../include/MCAL/DIO/DIO_Interface.h"

#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Config.h"
#include "../include/HAL/KEYPAD/KEYPAD_Private.h"

u8 static const global_u8ArrOfRows[KEYPAD_NO_ROWS] = KEYPAD_ROWS;
u8 static const global_u8ArrOfCols[KEYPAD_NO_COLS] = KEYPAD_COLS;


u8 HKEYPAD_u8GetPressedKey(void){

    u8 Local_u8PressedKey = NO_KEY_PRESSED;

    u8 Local_u8RowCounter = 0, Local_u8ColCounter = 0;
    u8 local_pinValue;
    u8 local_RowsBreakFlag = 0;

    for ( Local_u8RowCounter = 0; Local_u8RowCounter < KEYPAD_NO_ROWS; Local_u8RowCounter++)
    {
        MDIO_void_SetPinValue(KEYPAD_PORT, global_u8ArrOfRows[Local_u8RowCounter], DIO_RESET);

        for (Local_u8ColCounter = 0; Local_u8ColCounter < KEYPAD_NO_COLS; Local_u8ColCounter++){

            local_pinValue = MDIO_void_GetPinValue(KEYPAD_PORT, global_u8ArrOfCols[Local_u8ColCounter]);
            if(local_pinValue == KEY_IS_PRESSED){

                _delay_ms(20);
                local_pinValue = MDIO_void_GetPinValue(KEYPAD_PORT, global_u8ArrOfCols[Local_u8ColCounter]);
                if (local_pinValue == KEY_IS_PRESSED)
                {
                    while (local_pinValue == KEY_IS_PRESSED)//polling while key is pressed
                    {
                        local_pinValue = MDIO_void_GetPinValue(KEYPAD_PORT, global_u8ArrOfCols[Local_u8ColCounter]);
                    }
                    Local_u8PressedKey = global_ArrofKeys[Local_u8RowCounter][Local_u8ColCounter];
                    local_RowsBreakFlag = 1;
                    break;
                }
                
            }

        }
        MDIO_void_SetPinValue(KEYPAD_PORT, global_u8ArrOfRows[Local_u8RowCounter], DIO_SET);
        if (local_RowsBreakFlag == 1)
        {
            break;
        }
        
    }
    
    return Local_u8PressedKey;
}


void HKEYPAD_voidInit(){
    MDIO_void_SetPinDirection(KEYPAD_PORT,KEYPAD_ROW0,OUTPUT);
    MDIO_void_SetPinDirection(KEYPAD_PORT,KEYPAD_ROW1,OUTPUT);
    MDIO_void_SetPinDirection(KEYPAD_PORT,KEYPAD_ROW2,OUTPUT);
    MDIO_void_SetPinDirection(KEYPAD_PORT,KEYPAD_ROW3,OUTPUT);
    MDIO_void_SetPinDirection(KEYPAD_PORT,KEYPAD_COL0,INPUT);
    MDIO_void_SetPinDirection(KEYPAD_PORT,KEYPAD_COL1,INPUT);
    MDIO_void_SetPinDirection(KEYPAD_PORT,KEYPAD_COL2,INPUT);
    MDIO_void_SetPinDirection(KEYPAD_PORT,KEYPAD_COL3,INPUT);    
}
