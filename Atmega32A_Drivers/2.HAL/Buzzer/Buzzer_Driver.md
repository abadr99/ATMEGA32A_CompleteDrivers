# Driver functions

## 1) `Buzzer_Setup()`

### Description

This function is used to setup the controller to deal with microcontroller by setting the buzzer pin as output pin

### Syntax

`Buzzer_Setup(Buzzer_t   *MyBuzzer)`

### Parameters

1) Address of the buzzer object from (`Buzzer_t` data type)

### Returns

1) `FunctionParameterError` -->  if the passed parameter is wrong
2) `NoError` --> if the function executed successfully

### Example Code

```c
/*Define an object*/
Buzzer_t myBuz = {PORTA,PIN0}; //where buzzer is connected to A0
Buzzer_Setup(&myBuz); //setup myBuz buzzer
```

### Notes and Warnings

All buzzers used must be setup using this function

## 2) `Buzzer_TurnOn()`

### Description

This function is used to turn on the buzzer by drive a high signal to buzzer pin

### Syntax

`Buzzer_TurnOn(Buzzer_t  *MyBuzzer)`

### Parameters

1) Address of the buzzer object from (`Buzzer_t` data type)

### Returns

1) `FunctionParameterError` -->  if the passed parameter is wrong
2) `NoError` --> if the function executed successfully

### Example Code

```c
/*Define an object*/
Buzzer_t myBuz = {PORTA,PIN0}; //where buzzer is connected to A0
Buzzer_Setup(&myBuz); //setup myBuz buzzer
Buzzer_TurnOn(&myBuz); //turn on the buzzer
```

## 2) `Buzzer_TurnOff()`

### Description

This function is used to turn off the buzzer by drive a low signal to buzzer pin

### Syntax

`Buzzer_TurnOff(Buzzer_t  *MyBuzzer)`

### Parameters

1) Address of the buzzer object from (`Buzzer_t` data type)

### Returns

1) `FunctionParameterError` -->  if the passed parameter is wrong
2) `NoError` --> if the function executed successfully

### Example Code

```c
/*Define an object*/
Buzzer_t myBuz = {PORTA,PIN0}; //where buzzer is connected to A0
Buzzer_Setup(&myBuz); //setup myBuz buzzer
Buzzer_TurnOff(&myBuz); //turn off the buzzer
```

# Driver data type

## `Buzzer_t` 

#### Brief

All buzzers must be an object from `Buzzer_t` data types and **must be initialized**

#### Initialization  

```c
Buzzer_t BuzzerName = {PORT,PIN};
```

1. **Port name** 🡆 `PORTA`, `PORTB`, `PORTC`, `PORTD`
2. **Pin number** 🡆 `PIN0`, `PIN1`, `PIN2`, `PIN3`, `PIN4`, ..., `PIN7`

#### Example

```c
/*
* Connect buzzer at B0
*/
LED_t GreenLed = {PORTB,PIN0}; 
```

#### Size

**2** bytes

