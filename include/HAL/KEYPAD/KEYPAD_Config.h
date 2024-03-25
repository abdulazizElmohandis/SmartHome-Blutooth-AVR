#ifndef KEYPAD_config_H_
#define KEYPAD_config_H_

#define KEYPAD_NO_ROWS 4
#define KEYPAD_NO_COLS 4


u8 global_ArrofKeys[KEYPAD_NO_ROWS][KEYPAD_NO_COLS] = {
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', '*'},
    {'C', '0', '=', '/'}
};

#define KEYPAD_PORT PORTD

#define KEYPAD_ROW0 PIN0
#define KEYPAD_ROW1 PIN1
#define KEYPAD_ROW2 PIN2
#define KEYPAD_ROW3 PIN3

#define KEYPAD_COL0 PIN4
#define KEYPAD_COL1 PIN5
#define KEYPAD_COL2 PIN6
#define KEYPAD_COL3 PIN7

//for array of rows and columns 
//if you want to adjust no of rows and columns asjust here also
#define KEYPAD_ROWS {KEYPAD_ROW0, KEYPAD_ROW1, KEYPAD_ROW2, KEYPAD_ROW3}
#define KEYPAD_COLS {KEYPAD_COL0, KEYPAD_COL1, KEYPAD_COL2, KEYPAD_COL3}



#endif /* KEYPAD_config_H_ */