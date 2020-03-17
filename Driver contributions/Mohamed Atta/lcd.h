/*
 * lcd.h
 *
 *  Created on: Feb 29, 2020
 *      Author: Mohamed
 */

#include"types.h"

#ifndef LCD_H_
#define LCD_H_
void LCD_vidWriteCommand(u8 command);

void LCD_vidInit(void);

void LCD_vidWriteCharcter(u8 data);

void LCD_vidWriteNumber(s32 Number);

void LCD_vidWriteString(u8* ptr);

void LCD_vidClearDispaly(void);
#endif /* LCD_H_ */
