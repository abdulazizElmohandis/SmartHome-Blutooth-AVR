#ifndef LCD_Interface_H_
#define LCD_Interface_H_

typedef enum {
    LCD_ROW_1 = 0,
    LCD_ROW_2
}LCD_ROW_e;

typedef enum {
    LCD_COL_1 = 0,
    LCD_COL_2,
    LCD_COL_3,
    LCD_COL_4,
    LCD_COL_5,
    LCD_COL_6,
    LCD_COL_7,
    LCD_COL_8,
    LCD_COL_9,
    LCD_COL_10,
    LCD_COL_11,
    LCD_COL_12,
    LCD_COL_13,
    LCD_COL_14,
    LCD_COL_15,
    LCD_COL_16S
}LCD_COL_e;

typedef enum{
    customchar1 = 0,
    customchar2,
    customchar3,
    customchar4,
    customchar5,
    customchar6,
    customchar7,
    customchar8
}customchar_e;

void HLCD_voidSendCommand(u8 A_command);
void HLCD_voidSendData(u8 A_command);
void HLCD_voidInit(void);
void HLCD_voidInit(void);
void HLCD_VoidSendString(u8 *str);
void HLCD_VoidSendNumber(u32 A_u32Number);
void HLCD_voidGotoPosition(LCD_ROW_e A_LCD_ROW, LCD_COL_e A_LCD_COL);
void HLCD_voidSendCustomChar(customchar_e A_charNum, LCD_ROW_e A_LCD_ROW, LCD_COL_e A_LCD_COL);
void HLCD_voidCreateCustomChar(u8 *A_u8Arraychar, customchar_e A_charNum);
void HLCD_ClearDisplay(void);



#endif /* LCD_Interface_H_ */