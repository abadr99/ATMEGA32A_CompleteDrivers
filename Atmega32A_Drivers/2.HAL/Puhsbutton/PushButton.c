/*
 * PushButton.c
 *
 *  Created on: Sep 29, 2021
 *      Author: Abdelrhman
 */

#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "DIO.h"
#include "PushButton.h"

Error_t PushButton_Setup(PushButton_t *Pb)
{
	Error_t ReturnedError = NoError;
	/*Set push button pin direction*/
	switch(Pb->PushButtonConncetionType)
	{
	case PUSH_BUTTON_PULL_DOWN:
	case PUSH_BUTTON_PULL_UP:
								ReturnedError =DIO_SetPinDirection(Pb->PushButtonPort, Pb->PushButtonPin, DIO_INPUT_PIN);
								break;
	case PUSH_BUTTON_INPUT_PULL_UP:
								ReturnedError = DIO_SetPinDirection(Pb->PushButtonPort, Pb->PushButtonPin, DIO_INPUT_PULLUP_PIN);
								break;
	default: ReturnedError = FunctionParameterError;
	}
	return ReturnedError;
}

Error_t PushButton_GetState(PushButton_t *Pb , uint8_t *PbState)
{
	Error_t ReturnedError = NoError;
	uint8_t DIO_Val = 0;
	/*Get the pin val*/
	ReturnedError = DIO_ReadPin(Pb->PushButtonPort, Pb->PushButtonPin, &DIO_Val);

	if((ReturnedError == NoError) && (DIO_Val == DIO_HIGH_PIN))
	{
		switch(Pb->PushButtonConncetionType)
		{
		case PUSH_BUTTON_PULL_DOWN:
									*PbState = PUSH_BUTTON_PRESSED;
									break;
		case PUSH_BUTTON_PULL_UP:
		case PUSH_BUTTON_INPUT_PULL_UP:
									*PbState = PUSH_BUTTON_NOT_PRESSED;
									break;
		default: ReturnedError = FunctionParameterError;
		}
	}
	else if((ReturnedError == NoError) && (DIO_Val == DIO_LOW_PIN))
	{
		switch(Pb->PushButtonConncetionType)
		{
		case PUSH_BUTTON_PULL_DOWN:
									*PbState = PUSH_BUTTON_NOT_PRESSED;
									break;
		case PUSH_BUTTON_PULL_UP:
		case PUSH_BUTTON_INPUT_PULL_UP:
									*PbState = PUSH_BUTTON_PRESSED;
									break;
		default: ReturnedError = FunctionParameterError;
		}
	}
	return ReturnedError;
}
