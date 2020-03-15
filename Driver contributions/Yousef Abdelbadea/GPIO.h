/*
 * GPIO.h
 *
 *  Created on: Feb 23, 2020
 *      Author: yousef
 */
#include"types.h"
#ifndef GPIO_H_
#define GPIO_H_
void GPIO_VidClockGattingMode(u8 PortNumber);
void GPIO_VidDigitalEnable(u8 PortNumber,u8 Value);

void GPIO_vidSetPortDirection(u8 PortNumber,u8 Value);
void GPIO_vidSetPortValue(u8 PortNumber,u8 Value);
u8 GPIO_u8ReadPort(u8 PortNumber);

void GPIO_SetPinValue(u8 PortNum,u8 PinNum,u8 Value);
void GPIO_SetPinDirection(u8 PortNum,u8 PinNum,u8 Direction);
u8 GPIO_u8ReadPin(u8 PortNum,u8 PinNum);


#endif /* GPIO_H_ */
