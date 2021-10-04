/*
 * ExternalInterupt.h
 *
 *  Created on: Oct 3, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef EXTERNALINTERUPT_H_
#define EXTERNALINTERUPT_H_

/*Interrupt numbers*/
#define EXTERNAL_INTERRUPT_INT0	(0)
#define EXTERNAL_INTERRUPT_INT1	(1)
#define EXTERNAL_INTERRUPT_INT2	(2)

/*Define Interrupt modes*/
#define EXTERNAL_INTERRUPT_LOW		(0)
#define EXTERNAL_INTERRUPT_CHANGE	(1)
#define EXTERNAL_INTERRUPT_FALLING	(2)
#define EXTERNAL_INTERRUPT_RISING	(3)

/*
*@brief : This function is used to initiate external interrupts and set call back functions
*@para  : 1) InterruptNumber : EXTERNAL_INTERRUPT_INT0	EXTERNAL_INTERRUPT_INT1	EXTERNAL_INTERRUPT_INT2
		: 2) InterruptSource : EXTERNAL_INTERRUPT_LOW	EXTERNAL_INTERRUPT_CHANGE  EXTERNAL_INTERRUPT_FALLING	EXTERNAL_INTERRUPT_RISING
		  3) Function name
*@return : FunctionParameterError                       	
*/                             	
Error_t ExternalInterrupt_SetCallBack(uint8_t InterruptNumber, uint8_t InterruptSource , void (*P_ISRFunction)(void));

#endif /* EXTERNALINTERUPT_H_ */
