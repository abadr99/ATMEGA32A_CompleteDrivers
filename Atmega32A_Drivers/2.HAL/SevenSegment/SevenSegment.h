/*
 * SevenSegment.h
 *
 *  Created on: Sep 29, 2021
 *      Author: Abdelrhman
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

/*Define seven segment types*/
#define SEVEN_SEGMENT_COMMON_CATHODE	(1)
#define SEVEN_SEGMENT_COMMON_ANODE		(2)

typedef struct
{
	uint8_t _7SegPort;
	uint8_t _7SegType;
}SevenSegment_t;

Error_t SevenSegment_Setup(SevenSegment_t *_7Seg);
Error_t SevenSegment_DisplayNumber(SevenSegment_t *_7Seg , uint8_t Number);
#endif /* SEVENSEGMENT_H_ */
