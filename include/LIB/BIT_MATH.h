#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(REG, BIT_NO)    (REG |= (1 << BIT_NO))
#define CLR_BIT(REG, BIT_NO)    (REG &= ~(1 << BIT_NO)) 
#define GET_BIT(REG, BIT_NO)    (1 & (REG >> BIT_NO))
#define TOGGLE_BIT(REG, BIT_NO) (REG ^= (1 << BIT_NO))

#define CONC_BIT(B7,B6,B5,B4,B3,B2,B1,B0)  CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0) 0b##B7##B6##B5##B4##B3##B2##B1##B0

#define NULL ((void *)0)

/* ## is used to concatenate values */
/* CONC_HELP is used to concatenate values not macro names*/
 

#endif