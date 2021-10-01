/*
 * PushButton.h
 *
 *  Created on: Sep 29, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

/*Define push button states*/
#define PUSH_BUTTON_PRESSED			(1)
#define PUSH_BUTTON_NOT_PRESSED		(2)

/*Define push button connection types*/
#define PUSH_BUTTON_PULL_DOWN		(1)
#define PUSH_BUTTON_PULL_UP			(2)
#define PUSH_BUTTON_INPUT_PULL_UP	(3)

typedef struct
{
	uint8_t PushButtonPort;
	uint8_t PushButtonPin;
	uint8_t PushButtonConncetionType;
}PushButton_t;

Error_t PushButton_Setup(PushButton_t *Pb);
Error_t PushButton_GetState(PushButton_t *Pb , uint8_t *PbState);
#endif /* PUSHBUTTON_H_ */
