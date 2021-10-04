# Driver functions

## 1) `LED_Setup()`

### Description

This function is used to setup controller to deal with led by setting led pin as output led

### Syntax

`LED_Setup(LED_t *MyLed);`

### Parameters

1. address of the led object from `LED_t` 

### Returns

1) `FunctionParameterError` -->  if the passed parameter is wrong
2) `NoError` --> if the function executed successfully

### Example Code

```c
LED_t led = {PORTA,PIN0,LED_FORWARD};
LED_Setup(&led);
```

## 2) `LED_TurnOn`

### Description

This function is used to turn on led by drive a high signal to led pin on case of `LED_FORWARD` and a low signal in case of `LED_REVERSE` 

### Syntax

`LED_TurnOn(LED_t *MyLed)`

### Parameters

1. Address of the led object from `LED_t` 

### Returns

1) `FunctionParameterError` -->  if the passed parameter is wrong
2) `NoError` --> if the function executed successfully

### Example Code

```c
LED_t led = {PORTA,PIN0,LED_FORWARD};
LED_Setup(&led);
LED_TurnOn(&led);
```

## 2) `LED_TurnOff`

### Description

This function is used to turn on led by drive a low signal to led pin on case of `LED_FORWARD` and a high signal in case of `LED_REVERSE` 

### Syntax

`LED_TurnOff(LED_t *MyLed)`

### Parameters

1. Address of the led object from `LED_t` 

### Returns

1) `FunctionParameterError` -->  if the passed parameter is wrong
2) `NoError` --> if the function executed successfully

### Example Code

```c
LED_t led = {PORTA,PIN0,LED_FORWARD};
LED_Setup(&led);
LED_TurnOff(&led);
```

## Driver data types

## `LED_t`

#### Brief

All LEDs must be an object from `LED_t` data types and **must be initialized**

#### Initialization  

```c
LED_t ledName = {PORT,PIN,ConnectionType}
```

1. **Port name** 🡆 `PORTA`, `PORTB`, `PORTC`, `PORTD`
2. **Pin number** 🡆 `PIN0`, `PIN1`, `PIN2`, `PIN3`, `PIN4`, ..., `PIN7`
3. **Connection type** 🡆 `LED_FORWARD` `LED_REVERSE`

#### Example

```c
/*
* Connect anode of the led to Vcc and cathode of the led for pin (Reverse bias)
*/
LED_t GreenLed = {PORTA,PIN0,LED_REVERSE}; 
```

#### Size

**2** bytes 
