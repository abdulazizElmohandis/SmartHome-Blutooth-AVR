#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/MCAL/DIO/DIO_Config.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/DIO/DIO_Private.h"


void MDIO_void_SetPinDirection(DIO_PORT_e portID, DIO_PIN_e pinID, DIO_Direction_e pinDIR){

    if ((portID <= PORTD) && (pinID <= PIN7) && (pinDIR <= OUTPUT) &&
        (portID >= PORTA) && (pinID >= PIN0) && (pinDIR >= INPUT))
    {
            
        switch (portID)
        {
        case PORTA:
            switch (pinDIR)
            {
            case INPUT:
                CLR_BIT(DDRA_REG, pinID);
                break;
            case OUTPUT:
                SET_BIT(DDRA_REG, pinID);
                break;
            }
            break;

        case PORTB:
            switch (pinDIR)
            {
            case INPUT:
                CLR_BIT(DDRB_REG, pinID);
                break;
            case OUTPUT:
                SET_BIT(DDRB_REG, pinID);
                break;
            }
            break;
        case PORTC:
            switch (pinDIR)
            {
            case INPUT:
                CLR_BIT(DDRC_REG, pinID);
                break;
            case OUTPUT:
                SET_BIT(DDRC_REG, pinID);
                break;
            }
            break;
        case PORTD:
            switch (pinDIR)
            {
            case INPUT:
                CLR_BIT(DDRD_REG, pinID);
                break;
            case OUTPUT:
                SET_BIT(DDRD_REG, pinID);
                break;
            }
            break;
        }


    }else{

        //later
    }
    


}

void  MDIO_void_SetPinValue(DIO_PORT_e portID, DIO_PIN_e pinID, DIO_Value_e pinValue){



    if ((portID <= PORTD) && (pinID <= PIN7) && (pinValue <= DIO_SET) &&
        (portID >= PORTA) && (pinID >= PIN0) && (pinValue >= DIO_RESET))
    {
            
        switch (portID)
        {
        case PORTA:
            switch (pinValue)
            {
            case DIO_RESET:
                CLR_BIT(PORTA_REG, pinID);
                break;
            case DIO_SET:
                SET_BIT(PORTA_REG, pinID);
                break;
            }
            break;

        case PORTB:
            switch (pinValue)
            {
            case DIO_RESET:
                CLR_BIT(PORTB_REG, pinID);
                break;
            case DIO_SET:
                SET_BIT(PORTB_REG, pinID);
                break;
            }
            break;
        case PORTC:
            switch (pinValue)
            {
            case DIO_RESET:
                CLR_BIT(PORTC_REG, pinID);
                break;
            case DIO_SET:
                SET_BIT(PORTC_REG, pinID);
                break;
            }
            break;
        case PORTD:
            switch (pinValue)
            {
            case DIO_RESET:
                CLR_BIT(PORTD_REG, pinID);
                break;
            case DIO_SET:
                SET_BIT(PORTD_REG, pinID);
                break;
            }
            break;
        }


    }else{

        //later
    }

}
    
DIO_Value_e MDIO_void_GetPinValue(DIO_PORT_e portID, DIO_PIN_e pinID){

    DIO_Value_e local_pinValue;

    if ((portID <= PORTD) && (pinID <= PIN7) &&  
        (portID >= PORTA) && (pinID >= PIN0) )
    {

        switch (portID)
        {
        case PORTA:
            local_pinValue = GET_BIT(PINA_REG, pinID);
            break;
        
        case PORTB:
            local_pinValue = GET_BIT(PINB_REG, pinID);
            break;

        case PORTC:
            local_pinValue = GET_BIT(PINC_REG, pinID);
            break;

        case PORTD:
            local_pinValue = GET_BIT(PIND_REG, pinID);
            break;

        }


    }else{

        //later
    }
    
    return local_pinValue;

  
}

void MDIO_TogglePinValue(DIO_PORT_e portID, DIO_PIN_e pinID){


    if ((portID <= PORTD) && (pinID <= PIN7) &&  
        (portID >= PORTA) && (pinID >= PIN0) )
    {

        switch (portID)
        {
        case PORTA:
            TOGGLE_BIT(PORTA_REG, pinID);
            break;
        case PORTB:
            TOGGLE_BIT(PORTB_REG, pinID);
            break;
        case PORTC:
            TOGGLE_BIT(PORTC_REG, pinID);
            break;
        case PORTD:
            TOGGLE_BIT(PORTD_REG, pinID);
            break;
        }


    }else{

        //later
    }


}
 
void MDIO_Set_PortDirection(DIO_PORT_e portID, u8 portDir){

    if ((portID <= PORTD) && (portID >= PORTA)  )
    {
        switch (portID)
        {
        case PORTA:
           DDRA_REG = portDir;
            break;  
        case PORTB:
           DDRB_REG = portDir;
            break;
        case PORTC:
           DDRC_REG = portDir;
            break;
        case PORTD:
           DDRD_REG = portDir;
            break;        
        
        }


    }else{


        //later
    }
    

}

void MDIO_SetPortValue(DIO_PORT_e portID, u8 portValue){

    if ((portID <= PORTD) && (portID >= PORTA)  )
    {
        switch (portID)
        {
        case PORTA:
           PORTA_REG = portValue;
            break;  
        case PORTB:
           PORTB_REG = portValue;
            break;
        case PORTC:
           PORTC_REG = portValue;
            break;
        case PORTD:
           PORTD_REG = portValue;
            break;        
        }


    }else{


        //later
    }
    

}

void MDIO_voidInit(void){

    DDRA_REG =  CONC_BIT(PA7_INITIAL_DIR,PA6_INITIAL_DIR,
                        PA5_INITIAL_DIR, PA4_INITIAL_DIR,
                        PA3_INITIAL_DIR, PA2_INITIAL_DIR,
                        PA1_INITIAL_DIR, PA0_INITIAL_DIR);

    DDRB_REG =  CONC_BIT(PB7_INITIAL_DIR,PB6_INITIAL_DIR,
                        PB5_INITIAL_DIR, PB4_INITIAL_DIR,
                        PB3_INITIAL_DIR, PB2_INITIAL_DIR,
                        PB1_INITIAL_DIR, PB0_INITIAL_DIR);

    DDRC_REG =  CONC_BIT(PC7_INITIAL_DIR,PC6_INITIAL_DIR,
                        PC5_INITIAL_DIR, PC4_INITIAL_DIR,
                        PC3_INITIAL_DIR, PC2_INITIAL_DIR,
                        PC1_INITIAL_DIR, PC0_INITIAL_DIR);

    DDRD_REG =  CONC_BIT(PD7_INITIAL_DIR,PD6_INITIAL_DIR,
                        PD5_INITIAL_DIR, PD4_INITIAL_DIR,
                        PD3_INITIAL_DIR, PD2_INITIAL_DIR,
                        PD1_INITIAL_DIR, PD0_INITIAL_DIR);


    /*pins Initial Value*/                    
    
    PORTA_REG =  CONC_BIT(PA7_INITIAL_VALUE,PA6_INITIAL_VALUE,
                        PA5_INITIAL_VALUE, PA4_INITIAL_VALUE,
                        PA3_INITIAL_VALUE, PA2_INITIAL_VALUE,
                        PA1_INITIAL_VALUE, PA0_INITIAL_VALUE);

    PORTB_REG =  CONC_BIT(PB7_INITIAL_VALUE,PB6_INITIAL_VALUE,
                        PB5_INITIAL_VALUE, PB4_INITIAL_VALUE,
                        PB3_INITIAL_VALUE, PB2_INITIAL_VALUE,
                        PB1_INITIAL_VALUE, PB0_INITIAL_VALUE);

    DDRC_REG =  CONC_BIT(PC7_INITIAL_VALUE,PC6_INITIAL_VALUE,
                        PC5_INITIAL_VALUE, PC4_INITIAL_VALUE,
                        PC3_INITIAL_VALUE, PC2_INITIAL_VALUE,
                        PC1_INITIAL_VALUE, PC0_INITIAL_VALUE);

    PORTD_REG =  CONC_BIT(PD7_INITIAL_VALUE,PD6_INITIAL_VALUE,
                        PD5_INITIAL_VALUE, PD4_INITIAL_VALUE,
                        PD3_INITIAL_VALUE, PD2_INITIAL_VALUE,
                        PD1_INITIAL_VALUE, PD0_INITIAL_VALUE);


}


