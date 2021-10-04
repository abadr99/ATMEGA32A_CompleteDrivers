/*
 * GlobalInterrupt.c
 *
 *  Created on: Oct 3, 2021
 *      Author: Abdelrhman Badr
 */

#include "stdint.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "GlobalInterrupt.h"

void GlobalInterrupt_Enable(void)
{
	SET_BIT(SREG_REG,SREG_I_BIT);
}

void GlobalInterrupt_Disable(void)
{
	CLEAR_BIT(SREG_REG,SREG_I_BIT);
}
