/*
 * lcd.c
 *
 *  Created on: Feb 29, 2020
 *      Author: Mohamed
 */
#include "GPIO.h"
#include "types.h"
#include "LCD_Config.h"
#include "GPIO_Config.h"
#include"register.h"
#include"systick.h"
#include"macroes.h"





void LCD_vidWriteCommand(u8 command)
{
	GPIO_SetPinValue(LCD_Control_Port,RW,0);
	GPIO_SetPinValue(LCD_Control_Port,RS,0);
	GPIO_vidSetPortValue(LCD_Data_Port,command);
	GPIO_SetPinValue(LCD_Control_Port,E,1);
	systick_delay_ms(1);
	GPIO_SetPinValue(LCD_Control_Port,E,0);
	systick_delay_ms(1);
}
 
void LCD_vidInit(void)
{

	RCGCPIO=0x0A;
	GPIO_VidDigitalEnable(PortB,0xFF);
	GPIO_VidDigitalEnable(PortD,0x07);

	GPIO_vidSetPortDirection(LCD_Data_Port,OutputPort);
	GPIO_SetPinDirection(LCD_Control_Port,RS,OutputPin);
	GPIO_SetPinDirection(LCD_Control_Port,E,OutputPin);
	GPIO_SetPinDirection(LCD_Control_Port,RW,OutputPin);
	systick_delay_ms(50);

	LCD_vidWriteCommand(0b00111000);
	systick_delay_ms(1);

	LCD_vidWriteCommand(0b00001100);
	systick_delay_ms(1);

	LCD_vidWriteCommand(0b00000001);

}
 

void LCD_vidWriteCharcter(u8 data)
{
	GPIO_SetPinValue(LCD_Control_Port,RW,0);
	GPIO_SetPinValue(LCD_Control_Port,RS,1);
	GPIO_vidSetPortValue(LCD_Data_Port,data);
	GPIO_SetPinValue(LCD_Control_Port,E,1);
	systick_delay_ms(1);

	GPIO_SetPinValue(LCD_Control_Port,E,0);
	systick_delay_ms(1);
}

void LCD_vidWriteNumber(s32 Number)
{
	s32 reverse_Number=1;
	if(Number < 0)
	{
		Number *= -1;
		LCD_vidWriteCharcter('-');
	}
	if(Number==0)
	{
		LCD_vidWriteCharcter('0');
	}

	while(Number!=0)
	{
		reverse_Number=Number%10+reverse_Number*10;
		Number/=10;
	}
	while(reverse_Number!=1)
	{
		LCD_vidWriteCharcter(reverse_Number%10+48);//+'0'
		reverse_Number/=10;
	}

}

void LCD_vidWriteString(u8* ptr)
{
	u8 i=0;
	while(ptr[i]!=0)
	{
		LCD_vidWriteCharcter(ptr[i]);
		i++;

	}
}

void LCD_vidClearDispaly(void)
{

	LCD_vidWriteCommand(1);
}












