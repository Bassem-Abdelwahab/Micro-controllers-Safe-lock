/*
 * Switch.c
 *
 *  Created on: Feb 25, 2020
 *      Author: yousef
 */
#include"types.h"
#include"register.h"
#include"GPIO_Config.h"

void Init_Switch()
{
	GPIOF_LOCK=0x4C4F434B;
	GPIOF_CoMMIT=0x1F;
	GPIOF_PUR=0x11;
}

u8 Switch_Presed(u8 Switch)
{
	u8 value;
	switch(Switch)
	{
	case 0:
		value=GPIOF_DATA & 0x10;
		break;
	case 1:
		value=GPIOF_DATA & 0x01;
		break;
	case 2:
		value=GPIOF_DATA & 0x11;
		break;

	}
	return value;
}

