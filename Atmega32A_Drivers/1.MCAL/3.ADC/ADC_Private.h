/*
 * ADC_Private.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Abdelrhman
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*Define conversion timeout*/
#define ADC_CONVERSION_TIMEOUT	(50000)

/*Define refernce voltage modes*/
#define ADC_AREF			(1)
#define ADC_AVCC			(2)
#define ADC_INTERNAL_VOLT	(3)

/*Interrupt modes*/
#define ADC_INTERRUPT_ENABLE	(1)
#define ADC_INTERRUPT_DISABLE	(0)

/*Prescaler selection modes*/
#define ADC_DIVISION_FACTOR_2	(0X01)
#define ADC_DIVISION_FACTOR_4	(0X02)
#define ADC_DIVISION_FACTOR_8	(0X03)
#define ADC_DIVISION_FACTOR_16	(0X04)
#define ADC_DIVISION_FACTOR_32	(0X05)
#define ADC_DIVISION_FACTOR_64	(0X06)
#define ADC_DIVISION_FACTOR_128	(0X07)

/*Adjust mode*/
#define ADC_LEFT_ADJUST		(1)
#define ADC_RIGHT_ADJUST	(0)

/*Auto trigger sources*/
 #define ADC_FREE_RUNNING_MODE		(0)
 #define ADC_ANALOG_COMPARATOR		(1)
 #define ADC_EXTERNAL_INT0			(2)
 #define ADC_TIMER0_COMPARE_MATCH	(3)
 #define ADC_TIMER0_OVERFLOW		(4)
 #define ADC_TIMER1_COMPARE_MATCH_B (5)
 #define ADC_TIMER1_OVERFLOW		(6)
 #define ADC_TIMER1_CAPTURE_EVENT	(7)
 #define ADC_SINGLE_CONVERSION	    (8)

/*Define busy states*/
#define ADC_BUSY	(1)
#define ADC_IDLE	(2)

/*Define ADC Errors*/
#define ADC_ERROR	(2000)
#endif /* ADC_PRIVATE_H_ */
