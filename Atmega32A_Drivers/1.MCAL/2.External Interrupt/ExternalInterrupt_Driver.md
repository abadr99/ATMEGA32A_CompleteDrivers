# Driver functions

## `ExternalInterrupt_SetCallBack()`

### Description

This function is used to set interrupt trigger source, enable interrupt peripheral and set call back function   

### Syntax

` ExternalInterrupt_SetCallBack(uint8_t InterruptNumber, uint8_t InterruptSource , void (*P_ISRFunction)(void))`

### Parameters

1) **Interrupt Number** : `EXTERNAL_INTERRUPT_INT0` `EXTERNAL_INTERRUPT_INT1` 											         	                                  `EXTERNAL_INTERRUPT_INT2`
2) **Interrupt source** : `EXTERNAL_INTERRUPT_LOW` `EXTERNAL_INTERRUPT_CHANGE`                                                                                                          `EXTERNAL_INTERRUPT_FALLING` `EXTERNAL_INTERRUPT_RISING` 
3) **Function name** : This function will be executed when the event occurs

### Returns

`FunctionParameterError` : in case of on of the passed parameters is wrong

`NoError` : if the function is executed successfully

### Example Code

```c
	/*
	* This code is used to contoll led (ll) when another led (l) is flashing
	*/
	LED_t l = {PORTA,PIN0,LED_FORWARD};
	LED_t ll = {PORTA,PIN1,LED_FORWARD};
	LED_Setup(&l);
	LED_Setup(&ll);
	PushButton_t pb = {PORTA,PIN2,PUSH_BUTTON_INPUT_PULL_UP};
	PushButton_Setup(&pb);
	while(1)
	{
		ExternalInterrupt_SetCallBack(EXTERNAL_INTERRUPT_INT0,EXTERNAL_INTERRUPT_FALLING,LED);
		LED_TurnOn(&l);
		_delay_ms(5000);
		LED_TurnOff(&l);
		_delay_ms(5000);

	}
}
void LED(void)
{
	TOGGLE_BIT(x,0);
	switch (x)
	{
	case 0 : LED_TurnOff(&ll);  break;
	case 1 : LED_TurnOn(&ll);  break;

	}
}
```

### 