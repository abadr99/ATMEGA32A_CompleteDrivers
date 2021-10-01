/*
 * Buzzer.c
 *
 *  Created on: Sep 29, 2021
 *      Author: Abdelrhman Badr
 */
#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "DIO.h"
#include "Buzzer.h"

Error_t Buzzer_Setup(Buzzer_t *MyBuzzer)
{
	Error_t ReturnedError = NoError;
	/*Set buzzer pin as output pin*/
	ReturnedError =  DIO_SetPinDirection(MyBuzzer->BuzzerPort , MyBuzzer->BuzzerPin ,DIO_OUTPUT_PORT);
	return ReturnedError;
}
Error_t Buzzer_TurnOn(Buzzer_t *MyBuzzer)
{
	Error_t ReturnedError = NoError;
	/*Drive buzzer pin with high signal*/
	ReturnedError = DIO_WritePin(MyBuzzer->BuzzerPort, MyBuzzer->BuzzerPin, DIO_HIGH_PIN);
	return ReturnedError;
}
Error_t Buzzer_TurnOff(Buzzer_t *MyBuzzer)
{
	Error_t ReturnedError = NoError;
	/*Drive buzzer pin with low signal*/
	ReturnedError = DIO_WritePin(MyBuzzer->BuzzerPort, MyBuzzer->BuzzerPin, DIO_LOW_PIN);
	return ReturnedError;
}

