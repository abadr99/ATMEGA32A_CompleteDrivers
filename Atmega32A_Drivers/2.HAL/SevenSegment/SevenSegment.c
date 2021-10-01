/*
 * SevenSegment.c
 *
 *  Created on: Sep 29, 2021
 *      Author: Abdelrhman
 */

#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "DIO.h"
#include "SevenSegment_Private.h"
#include "SevenSegment.h"

Error_t SevenSegment_Setup(SevenSegment_t *_7Seg)
{
	Error_t ReturnedError = NoError;
	/*Set seven segment as output port*/
	ReturnedError = DIO_SetPortDirection(_7Seg->_7SegPort,DIO_OUTPUT_PORT);

	/*Turn off seven segment as initial value*/
	switch(_7Seg->_7SegType)
	{
	case SEVEN_SEGMENT_COMMON_CATHODE : ReturnedError = DIO_WritePort(_7Seg->_7SegPort, DIO_LOW_PORT); break;
	case SEVEN_SEGMENT_COMMON_ANODE   : ReturnedError = DIO_WritePort(_7Seg->_7SegPort, ~DIO_LOW_PORT); break;
	default : ReturnedError = FunctionParameterError;
	}
	return ReturnedError;
}
Error_t SevenSegment_DisplayNumber(SevenSegment_t *_7Seg , uint8_t Number)
{
	Error_t ReturnedError = NoError;
	switch(Number)
	{
	case 0: ReturnedError = DIO_WritePort(_7Seg->_7SegPort,SEVEN_SEGMENT_ZERO); break;
	case 1: ReturnedError = DIO_WritePort(_7Seg->_7SegPort,SEVEN_SEGMENT_ONE); break;
	case 2: ReturnedError = DIO_WritePort(_7Seg->_7SegPort,SEVEN_SEGMENT_TWO); break;
	case 3: ReturnedError = DIO_WritePort(_7Seg->_7SegPort,SEVEN_SEGMENT_THREE); break;
	case 4: ReturnedError = DIO_WritePort(_7Seg->_7SegPort,SEVEN_SEGMENT_FOUR); break;
	case 5: ReturnedError = DIO_WritePort(_7Seg->_7SegPort,SEVEN_SEGMENT_FIVE); break;
	case 6: ReturnedError = DIO_WritePort(_7Seg->_7SegPort,SEVEN_SEGMENT_SIX); break;
	case 7: ReturnedError = DIO_WritePort(_7Seg->_7SegPort,SEVEN_SEGMENT_SEVEN); break;
	case 8: ReturnedError = DIO_WritePort(_7Seg->_7SegPort,SEVEN_SEGMENT_EIGHT); break;
	case 9: ReturnedError = DIO_WritePort(_7Seg->_7SegPort,SEVEN_SEGMENT_NINE); break;
	default: ReturnedError = FunctionParameterError; break;
	}
	return ReturnedError;
}
