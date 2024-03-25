#ifndef DIO_Interface_H_
#define DIO_Interface_H_

typedef enum{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
}DIO_PORT_e;

typedef enum{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}DIO_PIN_e;

typedef enum{
    INPUT = 0,
    OUTPUT
}DIO_Direction_e;

typedef enum{
    DIO_RESET = 0,
    DIO_SET
}DIO_Value_e;



#define HIGH 1
#define LOW 0

#define OUTPUT_PORT 0xFF
#define INPUT_PORT 0

#define ALL_SET_PORT 0xFF
#define ALL_RESET_PORT 0

void MDIO_void_SetPinDirection(DIO_PORT_e portID, DIO_PIN_e pinID, DIO_Direction_e pinDIR);


void MDIO_void_SetPinValue(DIO_PORT_e portID, DIO_PIN_e pinID, DIO_Value_e pinValue);

DIO_Value_e MDIO_void_GetPinValue(DIO_PORT_e portID, DIO_PIN_e pinID);

void MDIO_TogglePinValue(DIO_PORT_e portID, DIO_PIN_e pinID);

/*portDir takes 8 bit value or OUTPUT_PORT / INPUT_PORT*/
void MDIO_SetPortDir(DIO_PORT_e portID, u8 portDir);
/*portValue takes 8 bit value or ALL_SET_PORT */
void MDIO_SetPortValue(DIO_PORT_e portID, u8 portValue);


void MDIO_voidInit(void);


#endif /* DIO_Interface_H_ */