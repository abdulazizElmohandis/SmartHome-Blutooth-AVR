#ifndef LCD_config_H_
#define LCD_config_H_


//Choose port for CTRL pins and DATA pins 
//Coice is between PORTA, PORTB, PORTC, PORTD
#define LCD_CTRL_PORT PORTC
#define LCD_DATA_PORT PORTA

#define LCD_RS_PIN PIN5
#define LCD_RW_PIN PIN6
#define LCD_EN_PIN PIN7

#define LCD_DATA_PIN0 PIN7
#define LCD_DATA_PIN1 PIN6
#define LCD_DATA_PIN2 PIN5
#define LCD_DATA_PIN3 PIN4
#define LCD_DATA_PIN4 PIN3
#define LCD_DATA_PIN5 PIN2
#define LCD_DATA_PIN6 PIN1
#define LCD_DATA_PIN7 PIN0

#define DONT_CARE 0 //dont care
#define NO_OF_LINES 1 //number of lines
#define FONT_SIZE 0 //font size
#define CURSOR_BLINK 1 //blink

#define DISPLAY_DIRECTION  1//increment(1)/decrement(0)
#define SHIFT             0//
#endif /* LCD_config_H_ */
