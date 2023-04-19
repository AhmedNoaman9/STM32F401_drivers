/*
 * Bit_math.h
 *
 *  Created on: Dec 8, 2022
 *      Author: NO3M4N
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_






#define WORD_SIZE		8

#define ONE_BIT_CLR			0b1
#define TWO_BIT_CLR			0b11
#define THREE_BIT_CLR		0b111
#define FOUR_BIT_CLR			0b1111
#define FIVE_BIT_CLR			0b11111
#define SIX_BIT_CLR			0b111111


#define NINE_BIT_CLR			0b111111111

#define SET_BIT(REG,Bit_NO)     (REG) |= (1U<<(Bit_NO)) // For example !

#define CLR_BIT(REG,Bit_NO)		(REG) &= ~(1U<<(Bit_NO))

// Get The Bit number Bit_NO
#define GET_BIT(REG,Bit_NO)		((REG)>>(Bit_NO)&1)// (REG) &= (1<<(Bit_NO)) ////*****************//////////

// Right Shift by No
#define RSHFT_REG(REG,NO)		(REG) = (REG) >> (NO)

// Left Shift by NO
#define LSHFT_REG(REG,NO)		(REG) = (REG) << (NO)

#define CRSHFT_REG(REG,NO)      REG = (REG >> NO) | (REG << ((sizeof(REG)*8) - NO))

// Circular Left Shift
#define CLSHFT_REG(REG,NO)		REG = (REG << NO) | (REG >> ((sizeof(REG)*8) - NO))



#define SET_FIELD(REG,Bit_NO,CONF)     (REG) |= (CONF<<(Bit_NO)) // For example !
/* Conf has to be ones  = number of bits  ex if i clear 3 bits then conf is 0b111 */
#define CLR_FIELD(REG,Bit_NO,CONF)		(REG) &= ~(CONF<< (Bit_NO) )

// Get The Bit number Bit_NO
#define GET_FIELD(REG,Bit_NO,CONF)		((REG)>>(Bit_NO)&CONF )// (REG) &= (1<<(Bit_NO)) ////*****************//////////



/*
// Circular Right Shift
#define CRSHFT_REG(REG,NO)      (REG << NO) | (REG >> (ًWORD_SIZE - NO))

// Circular Left Shift
#define CLSHFT_REG(REG,NO)		(REG >> NO) | (REG << (WORD_SIZE - NO))
*/
// Assign a Value to a Register
#define ASSIGN_REG(REG,VALUE)		(REG) |= VALUE

// Set The Register [1s]
#define SET_REG(REG)			(REG) |= -1

// Clear the Register [0s]
#define CLR_REG(REG)			(REG) &= 0

// Toggle a Bit in Register
#define TGL_BIT(REG,Bit_NO)		REG ^= 1 << Bit_NO

// Toggle a Register Value
#define TGL_REG(REG)			REG ~= REG

// Set The High Nibble in a Register
#define SET_H_NIB(REG)			REG |= 0xF0 // assuming 8 bit word

// Set The Low Nibble in a Register
#define SET_L_NIB(REG)			REG |= 0x0F // assuming 8 bit word

// Clear The High Nibble in a Register
#define CLR_H_NIB(REG)			REG &= ~ (0xF0) // assuming 8 bit word

// Clear The Low Nibble in a Register
#define CLR_L_NIB(REG)			REG &= ~ (0x0F) // assuming 8 bit word



#endif /* BIT_MATH_H_ */
