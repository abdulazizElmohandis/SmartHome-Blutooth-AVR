#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include <util/delay.h>
  
#include "../include/MCAL/GIE/GIE_Interface.h"
#include "../include/MCAL/GIE/GIE_Private.h"
#include "../include/MCAL/GIE/GIE_Config.h"


void MGIE_voidEnableGIE(void){

    SET_BIT(SREG, I);
}


void MGIE_voidDisableGIE(void){

    CLR_BIT(SREG, I);
}