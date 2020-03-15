/*
 * GPIO.c
 *
 *  Created on: Feb 23, 2020
 *      Author: yousef
 */
#include "types.h"
#include"register.h"
#include"macroes.h"
#include"GPIO_Config.h"

void GPIO_VidDigitalEnable(u8 PortNumber,u8 Value)
{
	switch(PortNumber)
	{
	case 0:
		GPIOA_DEN =Value;
		break;
	case 1:
		GPIOB_DEN =Value;
		break;
	case 2:
		GPIOC_DEN =Value;
		break;
	case 3:
		GPIOD_DEN =Value;
		break;
	case 4:
		GPIOE_DEN =Value;
		break;
	case 5:
		GPIOF_DEN =Value;
		break;

	}
}
void GPIO_VidClockGattingMode(u8 PortNumber)
{
	switch(PortNumber)
	{
	case 0:
		RCGCPIO=1;//port A
		break;
	case 1:
		RCGCPIO=2;//port B
		break;
	case 2:
		RCGCPIO=4;//port C
		break;
	case 3:
		RCGCPIO=8;//port D
		break;
	case 4:
		RCGCPIO=16;//port E
		break;
	case 5:
		RCGCPIO=32;//port F
		break;

	}
}

void GPIO_vidSetPortDirection(u8 PortNumber,u8 Value)
{
	switch(PortNumber)
	{
	case 0:
		GPIOA_DIR=Value;
		break;
	case 1:
		GPIOB_DIR=Value;
		break;
	case 2:
		GPIOC_DIR=Value;
		break;
	case 3:
		GPIOD_DIR=Value;
		break;
	case 4:
		GPIOE_DIR=Value;
		break;
	case 5:
		GPIOF_DIR=Value;
		break;

	}
}


void GPIO_vidSetPortValue(u8 PortNumber,u8 Value)
{
	switch(PortNumber)
	{
	case 0:
		GPIOA_DATA=Value;
		break;
	case 1:
		GPIOB_DATA=Value;
		break;
	case 2:
		GPIOC_DATA=Value;
		break;
	case 3:
		GPIOD_DATA=Value;
		break;
	case 4:
		GPIOE_DATA=Value;
		break;
	case 5:
		GPIOF_DATA=Value;
		break;

	}
}

u8 GPIO_u8ReadPort(u8 PortNumber)
{
	u8 value;
	switch(PortNumber)
	{
	case 0:
		value=GPIOA_DATA;
		break;
	case 1:
		value=GPIOB_DATA;
		break;
	case 2:
		value=GPIOC_DATA;
		break;
	case 3:
		value=GPIOD_DATA;
		break;
	case 4:
		value=GPIOE_DATA;
		break;
	case 5:
		value=GPIOF_DATA;
		break;

	}
	return value;
}

void GPIO_SetPinValue(u8 PortNum,u8 PinNum,u8 Value)
{
	switch(PortNum)
	{
	case 0:
		if(Value==1)
		{
			Set_Bit(GPIOA_DATA ,PinNum);
		}
		else
		{
			Clr_Bit(GPIOA_DATA ,PinNum);
		}
		break;

	case 1:
		if(Value==1)
		{
			Set_Bit(GPIOB_DATA ,PinNum);
		}
		else
		{
			Clr_Bit(GPIOB_DATA ,PinNum);
		}
		break;

	case 2:
		if(Value==1)
		{
			Set_Bit(GPIOC_DATA ,PinNum);
		}
		else
		{
			Clr_Bit(GPIOC_DATA ,PinNum);
		}
		break;
	case 3:
		if(Value==1)
		{
			Set_Bit(GPIOD_DATA ,PinNum);
		}
		else
		{
			Clr_Bit(GPIOD_DATA ,PinNum);
		}
		break;
	case 4:
		if(Value==1)
		{
			Set_Bit(GPIOE_DATA ,PinNum);
		}
		else
		{
			Clr_Bit(GPIOE_DATA ,PinNum);
		}
		break;
	case 5:
		if(Value==1)
		{
			Set_Bit(GPIOF_DATA ,PinNum);
		}
		else
		{
			Clr_Bit(GPIOF_DATA ,PinNum);
		}
		break;
	}
}

void GPIO_SetPinDirection(u8 PortNum,u8 PinNum,u8 Direction)
{

	switch(PortNum)
	{
	case 0:
		if(Direction==1)
		{
			Set_Bit(GPIOA_DIR,PinNum);
		}
		else
		{
			Clr_Bit(GPIOA_DIR,PinNum);
		}
		break;

	case 1:
		if(Direction==1)
		{
			Set_Bit(GPIOB_DIR,PinNum);
		}
		else
		{
			Clr_Bit(GPIOB_DIR,PinNum);
		}
		break;

	case 2:
		if(Direction==1)
		{
			Set_Bit(GPIOC_DIR,PinNum);
		}
		else
		{
			Clr_Bit(GPIOC_DIR,PinNum);
		}
		break;
	case 3:
		if(Direction==1)
		{
			Set_Bit(GPIOD_DIR,PinNum);
		}
		else
		{
			Clr_Bit(GPIOD_DIR,PinNum);
		}
		break;
	case 4:
		if(Direction==1)
		{
			Set_Bit(GPIOE_DIR,PinNum);
		}
		else
		{
			Clr_Bit(GPIOE_DIR,PinNum);
		}
		break;
	case 5:
		if(Direction==1)
		{
			Set_Bit(GPIOF_DIR,PinNum);
		}
		else
		{
			Clr_Bit(GPIOF_DIR,PinNum);
		}
		break;
	}
}

u8 GPIO_u8ReadPin(u8 PortNum,u8 PinNum)
{
	u8 ReadValue=0;
	switch(PortNum)
	{
	case 0:
		ReadValue=Get_Bit(GPIOA_DATA,PinNum);
		break;
	case 1:
		ReadValue=Get_Bit(GPIOB_DATA,PinNum);
		break;
	case 2:
		ReadValue=Get_Bit(GPIOC_DATA,PinNum);
		break;
	case 3:
		ReadValue=Get_Bit(GPIOD_DATA,PinNum);
		break;
	case 4:
		ReadValue=Get_Bit(GPIOE_DATA,PinNum);
		break;
	case 5:
		ReadValue=Get_Bit(GPIOF_DATA,PinNum);
		break;
	}
	return ReadValue;
}





