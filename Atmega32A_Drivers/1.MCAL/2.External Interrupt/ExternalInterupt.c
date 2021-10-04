/*
 * ExternalInterupt.c
 *
 *  Created on: Oct 3, 2021
 *      Author: Abdelrhman Badr
 */

#include "stdint.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "ExternalInterrupt.h"

/*Global pointer to INT0*/
static void (*GlopalPointer_INT0) (void) = NULL;
/*Global pointer to INT1*/
static void (*GlopalPointer_INT1) (void) = NULL;
/*Global pointer to INT2*/
static void (*GlopalPointer_INT2) (void) = NULL;


Error_t ExternalInterrupt_SetCallBack(uint8_t InterruptNumber, uint8_t InterruptSource , void (*P_ISRFunction)(void))
{
	Error_t ReturnedError = NoError;
	switch(InterruptNumber)
	{
	case EXTERNAL_INTERRUPT_INT0:
								switch(InterruptSource)
								{
								case EXTERNAL_INTERRUPT_LOW: 	 CLEAR_BIT(MCUCR_REG,MCUCR_ISC01_BIT); 	CLEAR_BIT(MCUCR_REG,MCUCR_ISC01_BIT);	break;
								case EXTERNAL_INTERRUPT_CHANGE:  CLEAR_BIT(MCUCR_REG,MCUCR_ISC01_BIT); 	SET_BIT(MCUCR_REG,MCUCR_ISC01_BIT);		break;
								case EXTERNAL_INTERRUPT_FALLING: SET_BIT(MCUCR_REG,MCUCR_ISC01_BIT); 	CLEAR_BIT(MCUCR_REG,MCUCR_ISC01_BIT);	break;
								case EXTERNAL_INTERRUPT_RISING:  SET_BIT(MCUCR_REG,MCUCR_ISC01_BIT); 	SET_BIT(MCUCR_REG,MCUCR_ISC01_BIT);		break;
								default : ReturnedError = FunctionParameterError; break;
								}
								/*Set glopal pointer to ISR function*/
								GlopalPointer_INT0 = P_ISRFunction;
							    /*Enable external interrupt0*/
							    SET_BIT(GICR_REG,GICR_INT0_BIT);
								break;

	case EXTERNAL_INTERRUPT_INT1:
								switch(InterruptSource)
								{
								case EXTERNAL_INTERRUPT_LOW: 	 CLEAR_BIT(MCUCR_REG,MCUCR_ISC11_BIT); 	CLEAR_BIT(MCUCR_REG,MCUCR_ISC10_BIT);	break;
								case EXTERNAL_INTERRUPT_CHANGE:  CLEAR_BIT(MCUCR_REG,MCUCR_ISC11_BIT); 	SET_BIT(MCUCR_REG,MCUCR_ISC10_BIT);		break;
								case EXTERNAL_INTERRUPT_FALLING: SET_BIT(MCUCR_REG,MCUCR_ISC11_BIT); 	CLEAR_BIT(MCUCR_REG,MCUCR_ISC10_BIT);	break;
								case EXTERNAL_INTERRUPT_RISING:  SET_BIT(MCUCR_REG,MCUCR_ISC11_BIT); 	SET_BIT(MCUCR_REG,MCUCR_ISC10_BIT);		break;
								default : ReturnedError = FunctionParameterError; break;
								}
								/*Set glopal pointer to ISR function*/
								GlopalPointer_INT1 = P_ISRFunction;
								/*Enable external interrupt1*/
								SET_BIT(GICR_REG,GICR_INT1_BIT);
								break;
	case EXTERNAL_INTERRUPT_INT2:
								switch(InterruptSource)
								{
								case EXTERNAL_INTERRUPT_FALLING: CLEAR_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT); break;
								case EXTERNAL_INTERRUPT_RISING:  SET_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT); 	break;
								default : ReturnedError = FunctionParameterError; break;
								}
								/*Set glopal pointer to ISR function*/
								GlopalPointer_INT2 = P_ISRFunction;
								/*Enable external interrupt2*/
								SET_BIT(GICR_REG,GICR_INT2_BIT);
								break;

	default : ReturnedError = FunctionParameterError; break;
	}
	return ReturnedError;
}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	if(GlopalPointer_INT0 != NULL)
	{
		GlopalPointer_INT0();
	}

}
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	if(GlopalPointer_INT1 != NULL)
	{
		GlopalPointer_INT1();
	}
}
void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	if(GlopalPointer_INT2 != NULL)
	{
		GlopalPointer_INT2();
	}
}
