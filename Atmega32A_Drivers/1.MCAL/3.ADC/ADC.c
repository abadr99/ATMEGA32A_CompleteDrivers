/*
 * ADC.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Abdelrhman Badr
 */

#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC.h"

static uint8_t ADC_BusyFlag = ADC_IDLE;
static void (*GlopalPointer_ADCInterrupt)(void) = NULL;
uint16_t ADC_ReadingValue = 0;

void ADC_Initiate(void)

{
	/*Set reference voltage*/
	#if ADC_VOLTAGE_REFERENCE_MODE == ADC_AREF
		CLEAR_BIT(ADMUX_REG,ADMUX_REFS1_BIT);
		CLEAR_BIT(ADMUX_REG,ADMUX_REFS0_BIT);
	#elif ADC_VOLTAGE_REFERENCE_MODE == ADC_AVCC
		CLEAR_BIT(ADMUX_REG,ADMUX_REFS1_BIT);
		SET_BIT(ADMUX_REG,ADMUX_REFS0_BIT);
	#elif ADC_VOLTAGE_REFERENCE_MODE == ADC_INTERNAL_VOLT
		SET_BIT(ADMUX_REG,ADMUX_REFS1_BIT);
		SET_BIT(ADMUX_REG,ADMUX_REFS0_BIT);
	#else
		#error "Error ADC_VOLTAGE_REFERENCE_MODE configuration"
	#endif /*ADC_VOLTAGE_REFERENCE_MODE*/

	/*Set adjust mode depending on ADC_NUMBER_OF_BITS*/
	#if ADC_NUMBER_OF_BITS == 8
		SET_BIT(ADMUX_REG,ADMUX_ADLAR_BIT);
	#elif ADC_NUMBER_OF_BITS == 10
		CLEAR_BIT(ADMUX_REG,ADMUX_ADLAR_BIT);
	#else
		#error "Error ADC_NUMBER_OF_BITS configuration"
	#endif /*ADC_NUMBER_OF_BITS*/

	/*Set trigger source*/
	#if ADC_TRIGGER_SOURCE == ADC_FREE_RUNNING_MODE
		CLEAR_BIT(SFIOR_REG,SFIOR_ADTS2_BIT);
		CLEAR_BIT(SFIOR_REG,SFIOR_ADTS1_BIT);
		CLEAR_BIT(SFIOR_REG,SFIOR_ADTS0_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADATE_BIT); /*Enable auto trigger*/
	#elif ADC_TRIGGER_SOURCE == ADC_ANALOG_COMPARATOR
		CLEAR_BIT(SIFOR_REG,SIFOR_ADTS2_BIT);
		CLEAR_BIT(SIFOR_REG,SIFOR_ADTS1_BIT);
		SET_BIT(SIFOR_REG,SIFOR_ADTS0_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADATE_BIT); /*Enable auto trigger*/
	#elif ADC_TRIGGER_SOURCE == ADC_EXTERNAL_INT0
		CLEAR_BIT(SIFOR_REG,SIFOR_ADTS2_BIT);
		SET_BIT(SIFOR_REG,SIFOR_ADTS1_BIT);
		CLEAR_BIT(SIFOR_REG,SIFOR_ADTS0_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADATE_BIT); /*Enable auto trigger*/
	#elif ADC_TRIGGER_SOURCE == ADC_TIMER0_COMPARE_MATCH
		CLEAR_BIT(SIFOR_REG,SIFOR_ADTS2_BIT);
		SET_BIT(SIFOR_REG,SIFOR_ADTS1_BIT);
		SET_BIT(SIFOR_REG,SIFOR_ADTS0_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADATE_BIT); /*Enable auto trigger*/
	#elif ADC_TRIGGER_SOURCE == ADC_TIMER0_OVERFLOW
		SET_BIT(SIFOR_REG,SIFOR_ADTS2_BIT);
		CLEAR_BIT(SIFOR_REG,SIFOR_ADTS1_BIT);
		CLEAR_BIT(SIFOR_REG,SIFOR_ADTS0_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADATE_BIT); /*Enable auto trigger*/
	#elif ADC_TRIGGER_SOURCE == ADC_TIMER1_COMPARE_MATCH_B
		SET_BIT(SIFOR_REG,SIFOR_ADTS2_BIT);
		CLEAR_BIT(SIFOR_REG,SIFOR_ADTS1_BIT);
		SET_BIT(SIFOR_REG,SIFOR_ADTS0_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADATE_BIT); /*Enable auto trigger*/
	#elif ADC_TRIGGER_SOURCE == ADC_TIMER1_OVERFLOW
		CLEAR_BIT(SIFOR_REG,SIFOR_ADTS2_BIT);
		SET_BIT(SIFOR_REG,SIFOR_ADTS1_BIT);
		SET_BIT(SIFOR_REG,SIFOR_ADTS0_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADATE_BIT); /*Enable auto trigger*/
	#elif ADC_TRIGGER_SOURCE == ADC_TIMER1_CAPTURE_EVENT
		SET_BIT(SIFOR_REG,SIFOR_ADTS2_BIT);
		SET_BIT(SIFOR_REG,SIFOR_ADTS1_BIT);
		SET_BIT(SIFOR_REG,SIFOR_ADTS0_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADATE_BIT); /*Enable auto trigger*/
	#elif ADC_TRIGGER_SOURCE == ADC_SINGLE_CONVERSION
		CLEAR_BIT(SFIOR_REG,SFIOR_ADTS2_BIT);
		CLEAR_BIT(SFIOR_REG,SFIOR_ADTS1_BIT);
		CLEAR_BIT(SFIOR_REG,SFIOR_ADTS0_BIT);
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADATE_BIT); /*disable auto trigger*/
	#else
		#error "Error in ADC_TRIGGER_SOURCE configuration"
	#endif /*ADC_TRIGGER_SOURCE*/

	/*Interrupt mode*/
	#if ADC_INTERRUPT == ADC_INTERRUPT_ENABLE
		SET_BIT(ADCSRA_REG,ADCSRA_ADIE_BIT);
	#elif ADC_INTERRUPT == ADC_INTERRUPT_DISABLE
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADIE_BIT);
	#else
		#error "Error in ADC_INTERRUPT configuration"
	#endif


	/*Set ADC frequency*/
	#if ADC_DIVISION_FACTOR == ADC_DIVISION_FACTOR_2
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADPS2_BIT);
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADPS1_BIT);
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADPS0_BIT);
	#elif ADC_DIVISION_FACTOR == ADC_DIVISION_FACTOR_4
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADPS2_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS1_BIT);
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADPS0_BIT);
	#elif ADC_DIVISION_FACTOR == ADC_DIVISION_FACTOR_8
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADPS2_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS1_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS0_BIT);
	#elif ADC_DIVISION_FACTOR == ADC_DIVISION_FACTOR_16
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS2_BIT);
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADPS1_BIT);
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADPS0_BIT);
	#elif ADC_DIVISION_FACTOR == ADC_DIVISION_FACTOR_32
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS2_BIT);
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADPS1_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS0_BIT);
	#elif ADC_DIVISION_FACTOR == ADC_DIVISION_FACTOR_64
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS2_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS1_BIT);
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADPS0_BIT);
	#elif ADC_DIVISION_FACTOR == ADC_DIVISION_FACTOR_128
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS2_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS1_BIT);
		SET_BIT(ADCSRA_REG,ADCSRA_ADPS0_BIT);
	#else
		#error "Error in ADC_DIVISION_FACTOR configuration"
	#endif/*ADC_DIVISION_FACTOR*/

	/*Enable ADC*/
	SET_BIT(ADCSRA_REG,ADCSRA_ADEN_BIT);
}

Error_t ADC_StartConversionSynch(uint8_t Channel,uint16_t *ReadingValue)
{
	Error_t ReturnedError = NoError;
	uint32_t ConversionTime = 0;
	*ReadingValue = 0;

	/*Check if the ADC is working now*/
	if(ADC_BusyFlag == ADC_IDLE)
	{

		/*Set busy flag*/
		ADC_BusyFlag = ADC_BUSY;

		/*Disable ADC*/
		CLEAR_BIT(ADCSRA_REG,ADCSRA_ADEN_BIT);

		/*Select channel before starting conversion*/
		ADMUX_REG &= 0b11100000;
		ADMUX_REG |= Channel;

		/*Enable ADC*/
		SET_BIT(ADCSRA_REG,ADCSRA_ADEN_BIT);

		/*Start conversion*/
		SET_BIT(ADCSRA_REG,ADCSRA_ADSC_BIT);

		/*Wait until conversion complete*/
		while((GET_BIT(ADCSRA_REG,ADCSRA_ADIF_BIT) == 0) && (ConversionTime < ADC_CONVERSION_TIMEOUT))
		{
			ConversionTime ++;
		}
		if(ConversionTime < ADC_CONVERSION_TIMEOUT)
		{
			/*Get the value*/
			#if ADC_NUMBER_OF_BITS == 8
				*ReadingValue = ADCH_REG;
			#elif ADC_NUMBER_OF_BITS == 10
				*ReadingValue = ADCL_REG | (ADCH_REG << 8);
			#endif /*ADC_NUMBER_OF_BITS*/
			/*ADC avaliable now*/
			ADC_BusyFlag = ADC_IDLE;
			/*Clear the flag*/
			SET_BIT(ADCSRA_REG,ADCSRA_ADIF_BIT);
		}
		else if (ConversionTime >= ADC_CONVERSION_TIMEOUT)
		{
			ReturnedError = -1;
		}

	}
	else if (ADC_BusyFlag == ADC_BUSY)
	{
		ReturnedError = BusyFunction;
	}
	return ReturnedError;
}

Error_t ADC_StartConversionAsynch(uint8_t Channel , void (*ADCInterruptFunction)(void))
{
	Error_t ReturnedError = NoError;
	if(ADCInterruptFunction != NULL)
	{
		/*Set glopal ADC pointer to isr*/
		GlopalPointer_ADCInterrupt = ADCInterruptFunction;

		/*Enable ADC interrupt*/
		SET_BIT(ADCSRA_REG,ADCSRA_ADIE_BIT);

		/*check if the ADC is on progress or not*/
		if(ADC_BusyFlag == ADC_IDLE)
		{
			/*Set ADC flag as busy*/
			ADC_BusyFlag = ADC_BUSY;

			/*Start conversion algrothim*/

			/* 1) Disable ADC*/
			CLEAR_BIT(ADCSRA_REG,ADCSRA_ADEN_BIT);

			/* 2) Select channel before starting conversion*/
			ADMUX_REG &= 0b11100000;
			ADMUX_REG |= Channel;

			/* 3) Enable ADC*/
			SET_BIT(ADCSRA_REG,ADCSRA_ADEN_BIT);

			/* 4) Start conversion*/
			SET_BIT(ADCSRA_REG,ADCSRA_ADSC_BIT);
		}
		else if(ADC_BusyFlag == ADC_BUSY)
		{
			ReturnedError = BusyFunction;
		}
	}
	else
	{
		ReturnedError = NullPointer;
	}
	return ReturnedError;
}

void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
	if(GlopalPointer_ADCInterrupt != NULL)
	{
		/*Get the reading value*/
		#if ADC_NUMBER_OF_BITS == 8
			ADC_ReadingValue = ADCH_REG;
		#elif ADC_NUMBER_OF_BITS == 10
			ADC_ReadingValue = ADCL_REG | (ADCH_REG << 8);
		#endif /*ADC_NUMBER_OF_BITS*/

		/*Set ADC as idle*/
		ADC_BusyFlag = ADC_IDLE;

		/*Execute ISR*/
		GlopalPointer_ADCInterrupt();
	}
}
