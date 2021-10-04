/** @file LED.h
*
* @brief .
* @layer HAL
* @author Abdelrhman Badr
* @last update 27-sep-21
*/

#ifndef LED_H_
#define LED_H_


/*Led connection's types*/
#define LED_FORWARD	(1)
#define LED_REVERSE	(2)

/*
* @Struct name : LED_t
* @brief : This struct is used to define led port, pin and connection type of led
* @note  : - All leds used must be an object from this struct
		   - All objects from this type must be initialized
*/
typedef struct
{
	uint8_t LedPort;
	uint8_t LedPin;
	uint8_t LedConnectionType;

}LED_t;

/*
*@brief : This function is used to setup controller to work with led
*@para  : Address of the led object
*@return: Error state : 1) FunctionParameterError -->  if the passed parameter is wrong
						2) NoError --> if the function executed successfully
*@note  : All leds used must be an object from LED_t and passed to this function
*/
Error_t LED_Setup(LED_t *MyLed);
/*
*@brief : This function is used to turn on led
*@para  : Address of the led object
*@return: Error state : 1) FunctionParameterError -->  if the passed parameter is wrong
						2) NoError --> if the function executed successfully
*/
Error_t LED_TurnOn(LED_t *MyLed);
/*
*@brief : This function is used to turn off led
*@para  : Address of the led object
*@return: Error state : 1) FunctionParameterError -->  if the passed parameter is wrong
						2) NoError --> if the function executed successfully
*/
Error_t LED_TurnOff(LED_t *MyLed);

#endif /*LED_H_*/
