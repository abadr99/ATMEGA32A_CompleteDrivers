# Keypad driver

## Driver function

## `KeyPad_Setup()`

### Description

This function is used to set the microcontroller to deal with keypad device by the following steps

1) set the rows pins as input pull up pins (to get rid of external resistors cost and complexity)
2) set the cols pins as output pin
3) set the initial state of output pin as initial state of the input pin (HIGH)

### Syntax

`KeyPad_Setup()`

### Parameters

No parameters

### Return

No Return

### Example Code

```c
KeyPad_Setup(); //to setup keyPad
```

### Notes and Warnings

All keypad used must be setup.

## `KeyPad_GetValue()`

### Description

This function is used to get the pressed key value by the following

1) Drive a low signal for each col pin
2) Check which row will receive the low signal
3) if the row is founded then the value will be `KeyPad_Arr[Row][Col]` 

### Syntax

`KeyPad_GetValue(uint8_t *ReturnedValue)`

### Parameters

Address of variable that will carry the keypad pressed key value

### Return

void

### Example Code

```c
KeyPad_Setup(); //to setup keyPad
uint8_t kpdVal = KEYPAD_NOT_PRESSED;
KeyPad_GetValue(&kpdVal);
```

### Notes and Warnings

1. Variable that will be passed to `KeyPad_GetValue()` must be initialized with `KEYPAD_NOT_PRESSED` value.
2. All configurations of keypad are set on `KeyPad_Config.h` file



