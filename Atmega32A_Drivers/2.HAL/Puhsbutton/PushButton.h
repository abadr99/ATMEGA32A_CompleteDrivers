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

/*
* @Struct name : PushButton_t
* @brief : This struct is used to define push button port, pin and connection type of push button
* @note  : - All push buttons used must be an object from this struct
		   - All objects from this type must be initialized
*/
typedef struct
{
	uint8_t PushButtonPort;
	uint8_t PushButtonPin;
	uint8_t PushButtonConncetionType;
}PushButton_t;

/*
*@brief : This function is used to setup controller to work with push button
*@para  : Address of the push button object
*@return: Error state : 1) FunctionParameterError -->  if the passed parameter is wrong
						2) NoError --> if the function executed successfully
*@note  : All push buttons used must be an object from PushButton_t and passed to this function
*/
Error_t PushButton_Setup(PushButton_t *Pb);
/*
*@brief : This function is used to get the value of push button reading
*@para  : Address of the push button object
*@para  : Address of the variable that will carry the push button reading value
*@return: Error state : 1)FunctionParameterError -->  if the passed parameter is wrong
						2)NoError --> if the function executed successfully
*/
Error_t PushButton_GetState(PushButton_t *Pb , uint8_t *PbState);
#endif /* PUSHBUTTON_H_ */
