/*
 * Buzzer.h
 *
 *  Created on: Sep 29, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef BUZZER_H_
#define BUZZER_H_

/*
* @Struct name : Buzzer_t
* @brief : This struct is used to define buzzer port and pin
* @note  : - All buzzer used must be an object from this struct
		   - All objects from this type must be initialized
*/
typedef struct
{
	uint8_t BuzzerPort;
	uint8_t BuzzerPin;
}Buzzer_t;

/*
*@breif: This function is used to setup microcontroller to deal with buzzer
*@para: address of the buzzer object
*@return: Error state : 1) FunctionParameterError -->  if the passed parameter is wrong
						2) NoError --> if the function executed successfully
*/
Error_t Buzzer_Setup(Buzzer_t   *MyBuzzer);
/*
*@breif: This function is used to turn on the buzzer (drive voltage to the buzzer)
*@para: address of the buzzer object
*@return: Error state : 1) FunctionParameterError -->  if the passed parameter is wrong
						2) NoError --> if the function executed successfully
*/
Error_t Buzzer_TurnOn(Buzzer_t  *MyBuzzer);
/*
*@breif: This function is used to turn off the buzzer (drive ground to the buzzer)
*@para: address of the buzzer object
*@return: Error state : 1) FunctionParameterError -->  if the passed parameter is wrong
						2) NoError --> if the function executed successfully
*/
Error_t Buzzer_TurnOff(Buzzer_t *MyBuzzer);

#endif /* BUZZER_H_ */
