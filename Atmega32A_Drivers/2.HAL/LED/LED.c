/** @file LED.c
*
* @brief Source file for led's function implementation.
* @layer HAL
* @author Abdelrhman Badr
* @last update 27-sep-21
*/

#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "DIO.h"
#include "LED.h"

Error_t LED_Setup(LED_t *MyLed)
{
	Error_t ReturnedError = NoError;
	/*Set Led pin as output pin*/
	ReturnedError = DIO_SetPinDirection(MyLed->LedPort, MyLed->LedPin, DIO_OUTPUT_PIN);
	/*Turn off led as initial state*/
	switch(MyLed->LedConnectionType)
	{
	case LED_FORWARD : ReturnedError = DIO_WritePin(MyLed->LedPort, MyLed->LedPin, DIO_LOW_PIN); break;
	case LED_REVERSE : ReturnedError = DIO_WritePin(MyLed->LedPort, MyLed->LedPin, DIO_HIGH_PIN); break;
	default : ReturnedError = FunctionParameterError;
	}

	return ReturnedError;
}
Error_t LED_TurnOn(LED_t *MyLed)
{
	Error_t ReturnedError = NoError;
	/*turn on led depending on type of connection*/
	switch(MyLed->LedConnectionType)
	{
	case LED_FORWARD: ReturnedError = DIO_WritePin(MyLed->LedPort, MyLed->LedPin, DIO_HIGH_PIN); break;
	case LED_REVERSE: ReturnedError = DIO_WritePin(MyLed->LedPort, MyLed->LedPin, DIO_LOW_PIN); break;
	default: ReturnedError = FunctionParameterError;
	}
	return ReturnedError;
}
Error_t LED_TurnOff(LED_t *MyLed)
{
	Error_t ReturnedError = NoError;
	/*turn on led depending on type of connection*/
	switch(MyLed->LedConnectionType)
	{
	case LED_FORWARD: ReturnedError = DIO_WritePin(MyLed->LedPort, MyLed->LedPin, DIO_LOW_PIN); break;
	case LED_REVERSE: ReturnedError = DIO_WritePin(MyLed->LedPort, MyLed->LedPin, DIO_HIGH_PIN); break;
	default: ReturnedError = FunctionParameterError;
	}
	return ReturnedError;
}
