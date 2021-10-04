# Driver functions

## 1) `PushButton_Setup()`

### Description

This function is used to setup controller to deal with push button by set the pin as **input pin** in case of type of connection is `PUSH_BUTTON_PULL_DOWN` `PUSH_BUTTON_PULL_UP` and **input pull up pin** in case of `PUSH_BUTTON_INPUT_PULL_UP`

### Syntax

`PushButton_Setup(PushButton_t *Pb)`

### Parameters

1) Address of the push button object

### Returns

1) `FunctionParameterError` -->  if the passed parameter is wrong
2) `NoError` --> if the function executed successfully

### Example Code

```c
PushButton_t pb;
PushButton_Setup(&pb);
```

###  Notes and Warnings

All push buttons objects must be passed to this function.

## 2) `PushButton_GetState()`

### Description

This function is used to get the push button state `PUSH_BUTTON_PRESSED` `PUSH_BUTTON_NOT_PRESSED`

### Syntax

`PushButton_GetState(PushButton_t *Pb)`

### Parameters

1) Address of the push button object

### Returns

1) `FunctionParameterError` -->  if the passed parameter is wrong
2) `NoError` --> if the function executed successfully

### Example Code

```c
PushButton_t pb;
PushButton_Setup(&pb);
uint8_t PB_ReadingVal = PUSH_BUTTON_NOT_PRESSED;
PushButton_GetState(&pb,&PB_ReadingVal);
```

###  Notes and Warnings

All push buttons objects must be passed to this function.

# Driver datatypes

## `PushButton_t`

#### Brief

All pushbuttons must be an object from ``PushButton_t`` data type and **must be initialized**

#### Initialization  

```c
PushButton_t PushButtonName = {PORT,PIN,ConnectionType}
```

1. **Port name** 🡆 `PORTA`, `PORTB`, `PORTC`, `PORTD`
2. **Pin number** 🡆 `PIN0`, `PIN1`, `PIN2`, `PIN3`, `PIN4`, ..., `PIN7`
3. **Connection type** 🡆 `PUSH_BUTTON_PULL_DOWN` `PUSH_BUTTON_PULL_UP` `PUSH_BUTTON_INPUT_PULL_UP`

#### Example

```c
/*
* Connect push button as input pull down at B0
*/
PushButton_t pb = {PORTB,PIN0,PUSH_BUTTON_PULL_DOWN}; 
```

#### Size

**2** bytes 

