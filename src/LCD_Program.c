#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../include/MCAL/DIO/DIO_Interface.h"

#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/LCD/LCD_Config.h"
#include "../include/HAL/LCD/LCD_Private.h"

void HLCD_voidSendCommand(u8 A_command){

    // RS = 0
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_RESET);
    // RW = 0
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_RESET);
    MDIO_SetPortValue(LCD_DATA_PORT, A_command);
    // Enable Pulse
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_SET);
    _delay_ms(1);
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_RESET);
    _delay_ms(1);
}

void HLCD_voidSendCommandReadMode(u8 A_command){

    // RS = 0
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_RESET);
    // RW = 1
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_SET);
    MDIO_SetPortValue(LCD_DATA_PORT, A_command);
    // Enable Pulse
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_SET);
    _delay_ms(1);
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_RESET);
    _delay_ms(1);
}


void HLCD_voidSendData(u8 A_data){
    // RS = 1
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_SET);
    // RW = 0
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_RESET);
    MDIO_SetPortValue(LCD_DATA_PORT, A_data);
    // Enable Pulse
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_SET);
    _delay_ms(1); 
    MDIO_void_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_RESET);
    _delay_ms(1);
}

void HLCD_voidInit(void){
   _delay_ms(50);

   HLCD_voidSendCommand(FUNCTION_SET);
   _delay_ms(1);
   HLCD_voidSendCommand(DISPLAY_ON);
    _delay_ms(1);
    HLCD_voidSendCommand(DISPLAY_CLEAR);//clear display
    _delay_ms(2);
    HLCD_voidSendCommand(ENTRY_MODE);
    
}

void HLCD_ClearDisplay(void){

    HLCD_voidSendCommand(DISPLAY_CLEAR);//clear display
    _delay_ms(2);
    
}


void HLCD_VoidSendString(u8 *str){

    u8 i = 0;
    while(str[i] != '\0'){
        HLCD_voidSendData(str[i]);
        i++;
    }

}


void HLCD_VoidSendNumber(u32 A_u32Number){
    
 u32 local_u32Num = 1;
	if (A_u32Number == 0)
	{
		HLCD_voidSendData('0');
	}

	while (A_u32Number != 0)
	{
		local_u32Num = (local_u32Num * 10) + (A_u32Number % 10);
		A_u32Number = A_u32Number / 10;
	}
	while (local_u32Num != 1)
	{
		HLCD_voidSendData ((local_u32Num % 10) + 48);
		local_u32Num = local_u32Num / 10;
	}
}
    
    

void HLCD_voidGotoPosition(LCD_ROW_e A_LCD_ROW, LCD_COL_e A_LCD_COL){
    u8 DDRAM_adressMod = 0;
    switch (A_LCD_ROW)
    {
    case LCD_ROW_1:
        DDRAM_adressMod = 128 + A_LCD_COL;
        HLCD_voidSendCommand(DDRAM_adressMod);
        break;
    case LCD_ROW_2:
        DDRAM_adressMod = 192 + A_LCD_COL;
        HLCD_voidSendCommand(DDRAM_adressMod);

        break;
    }

}

void HLCD_voidCreateCustomChar(u8 *A_u8Arraychar, customchar_e A_customcharNum ){

    u8 CGRAM_adressMod = 64 + (A_customcharNum * 8);
    HLCD_voidSendCommand(CGRAM_adressMod);
    
    for (u8 i = 0; i < 8; i++){
        HLCD_voidSendData(A_u8Arraychar[i]);
    }

}

void HLCD_voidSendCustomChar(customchar_e A_customcharNum, LCD_ROW_e A_LCD_ROW, LCD_COL_e A_LCD_COL){
    HLCD_voidGotoPosition(A_LCD_ROW, A_LCD_COL);
    HLCD_voidSendData(A_customcharNum);
}

// u8 LCD_read_busy_flag_and_address_counter() {
//     u8 status;
//     // Send command to read busy flag and address counter
//     HLCD_voidSendCommandReadMode(0x80); // Command to read busy flag and address counter
//     // Wait until busy flag (BF) is cleared
//     while (1) {
//         // Read the status from the LCD data bus
//         status = LCD_read_data();
//         // Check if busy flag (BF) is cleared (bit 7 is 0)
//         if ((status & 0x80) == 0) {
//             // BF is cleared, break the loop
//             break;
//         }
//     }
//     // Return the status (which includes the address counter value)
//     return status;
// }
