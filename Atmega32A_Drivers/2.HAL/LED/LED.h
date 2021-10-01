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

typedef struct
{
	uint8_t LedPort;
	uint8_t LedPin;
	uint8_t LedConnectionType;

}LED_t;

Error_t LED_Setup(LED_t *MyLed);
Error_t LED_TurnOn(LED_t *MyLed);
Error_t LED_TurnOff(LED_t *MyLed);

#endif /*LED_H_*/
