# Functions

## 1) DIO_SetPinDirection()

### Description

This function is used to set the direction of data for specified digital pin either ``` DIO_OUTPUT_PIN ``` ```DIO_INPUT_PIN```  ```DIO_INPUT_PULLUP_PIN```.

### Syntax

 `DIO_SetPinDirection(Port , PinNumber , Direction);`

### Parameters

1) Port name : Pass the port name of the required pin `PORTA` ```PORTB``` ``PORTC`` `PORTD`
2) Pin number: Pass the required pin number `PIN0` `PIN1` `...` `PIN7`
3) Direction : Pass the data direction of the required pin ``` DIO_OUTPUT_PIN ``` ```DIO_INPUT_PIN```  ```DIO_INPUT_PULLUP_PIN```

### Return 

1. `NoError` : in case of the function is executed successfully
2. `FunctionParameterError` : in case of the passed parameter is not correct 

### Example code

```c
void main (void)
{
    uint8_t errorVar;
    /*Set BO pin as output pin*/
    errorVar = DIO_SetPinDirection(PORTB,PIN0,DIO_OUTPUT_PIN);
    /*Check if the function work successfully or not*/
    if(errorVar != NoError)
    {
        //Handle error as you want
	}
}
```

## 2) DIO_SetPortDirection()

### Description

This function is used to set the direction of data for specified digital port.

### Syntax

` DIO_SetPortDirection(uint8_t Port , uint8_t Direction);`

### Parameters

1) Port name : Pass the port name of the required port `PORTA` ```PORTB``` ``PORTC`` `PORTD`
2) Direction : Pass the data direction of the required port 

### Return 

1. `NoError` : in case of the function is executed successfully
2. `FunctionParameterError` : in case of the passed parameter is not correct 

### Example code   

 ```c
 /*Set B0 as output and B1:5 as input and B6:7 as output*/
 DIO_SetPortDirection(PORTB,0b11000001);
 ```

### Notes

1) For binary representation 1 is for output and 0 is for input.
2) For output port `DIO_OUTPUT_PORT` and for input port `DIO_INPUT_PORT`
3) 

## 3) DIO_WritePin();

### Description

This function is used with specific output pin to determine the output voltage from this pin

### Syntax

`DIO_WritePin(uint8_t Port , uint8_t PinNumber ,uint8_t VoltageLevel);`

### Parameters

1) Port name : Pass the port name of the required port `PORTA` ```PORTB``` ``PORTC`` `PORTD`
2) Pin number: Pass the required pin number `PIN0` `PIN1` `...` `PIN7`
3) Voltage level : pass the required output value for the required pin `DIO_HIGH_PIN` `DIO_LOW_PIN` 

### Return 

1. `NoError` : in case of the function is executed successfully
2. `FunctionParameterError` : in case of the passed parameter is not correct 

### Example code   

 ```c
/*Set output from B0 as high and output from B1 as low*/
uint8_t error1 = DIO_WritePin(PORTB , PIN0 , DIO_HIGH_PIN);
uint8_t error2 = DIO_WritePin(PORTB , PIN1 , DIO_LOW_PIN);
if(error1 != NoError)
{
    /*Function error*/
    /*Handle error as you wanr*/
}
if(error2 != NoError)
{
    /*Function error*/
    /*Handle error as you wanr*/
}
 ```

## 4) DIO_WritePort();

### Description

This function is used with specific output port to determine the output voltage from this pin

### Syntax

`DIO_WritePort(uint8_t Port , uint8_t PortVal);`

### Parameters

1) Port name : Pass the port name of the required port `PORTA` ```PORTB``` ``PORTC`` `PORTD`
2) Port value : pass the required output value for the required port (0 : 255) 

### Return 

1. `NoError` : in case of the function is executed successfully
2. `FunctionParameterError` : in case of the passed parameter is not correct
3. `OverFlowError`: in case of passed port value is larger than 255 

### Example code   

 ```c
/*Set output from PORTA as a high port*/
DIO_WritePort(PORTA,DIO_HIGH_PORT);
/*Set output from PORTB as a low port*/
DIO_WritePort(PORTB,DIO_LOW_PORT);
/*set output from C0:3 as low and output from C4:7 as high*/
DIO_WritePort(PORTC,0b11110000);
 ```

## 5) DIO_ReadPin();

### Description

This function is used with specific input pin to get the input value

### Syntax

`DIO_ReadPin(uint8_t Port , uint8_t PinNumber , uint8_t * PinVal);`

### Parameters

1) Port name : Pass the port name of the required port `PORTA` ```PORTB``` ``PORTC`` `PORTD`
2) Pin number: Pass the required pin number `PIN0` `PIN1` `...` `PIN7`
3) Pin value : Pass the **address** of the variable to assign input reading

### Return 

1. `NoError` : in case of the function is executed successfully
2. `FunctionParameterError` : in case of the passed parameter is not correct

### Example code   

 ```c
/*Get the value of B0*/
uint8_t error;
uint8_t B0_ReadingVal;
error = DIO_ReadPin(PORTB, PIN0, &B0_ReadingVal);
if(error != NoError)
{
    /*Handle error*/
}
 ```

## 6) DIO_ReadPort();

### Description

This function is used with specific input port to get the input value

### Syntax

`DIO_ReadPort(uint8_t Port  , uint8_t * PortVal);`

### Parameters

1) Port name : Pass the port name of the required port `PORTA` ```PORTB``` ``PORTC`` `PORTD`
2) Port value : Pass the **address** of the variable to assign input reading

### Return 

1. `NoError` : in case of the function is executed successfully
2. `FunctionParameterError` : in case of the passed parameter is not correct

### Example code   

 ```c
/*Get the value of port B*/
uint8_t B_ReadingVal;
DIO_ReadPort(PORTB, &B_ReadingVal);
 ```

