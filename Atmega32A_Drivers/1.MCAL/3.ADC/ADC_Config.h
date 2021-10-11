/*
 * ADC_Config.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Abdelrhman
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_CONVERSION_TIME	(50000)
/*
 * Select the Voltage refernce mode:
 * 1) ADC_AREF --> when the refernce voltage is connected to AREF pin
 * 2) ADC_AVCC --> when the refernce voltage is connected to AVCC pin
 * 3) ADC_INTERNAL_VOLT --> when the refence voltage is internal voltage 2.56 volt
 */
#define ADC_VOLTAGE_REFERENCE_MODE		(ADC_AVCC)

/*
 * Control the ADC interrupt flag
 * ADC_INTERRUPT_ENABLE  --> enable  ADC_interrupt
 * ADC_INTERRUPT_DISABLE --> disable ADC_interrupt
 */
#define ADC_INTERRUPT	(ADC_INTERRUPT_ENABLE)

/*
 * ADC Prescaler Selections
 * ADC_DIVISION_FACTOR_2 	ADC_DIVISION_FACTOR_4		ADC_DIVISION_FACTOR_8
 * ADC_DIVISION_FACTOR_16	ADC_DIVISION_FACTOR_32		ADC_DIVISION_FACTOR_64
 * ADC_DIVISION_FACTOR_128
 * These configuration determine the division factor between the XTAL frequency and the input
 * clock to the ADC.
 */
#define ADC_DIVISION_FACTOR		(ADC_DIVISION_FACTOR_128)

/*
 * ADC adjust mode
 * ===============
 * 8	--> ADCH ==> The digital will be at 8 bits
 * 10 --> ADCH ==> The digital result will be at 10 bits
 */
#define ADC_NUMBER_OF_BITS		(8)

/*
 * Auto triggering source
 * ======================
 * ADC_FREE_RUNNING_MODE
 * ADC_ANALOG_COMPARATOR
 * ADC_EXTERNAL_INT0
 * ADC_TIMER0_COMPARE_MATCH
 * ADC_TIMER0_OVERFLOW
 * ADC_TIMER1_COMPARE_MATCH_B
 * ADC_TIMER1_OVERFLOW
 * ADC_TIMER1_CAPTURE_EVENT
 * ADC_SINGLE_CONVERSION
 */
#define ADC_TRIGGER_SOURCE		(ADC_SINGLE_CONVERSION)

#endif /* ADC_CONFIG_H_ */
