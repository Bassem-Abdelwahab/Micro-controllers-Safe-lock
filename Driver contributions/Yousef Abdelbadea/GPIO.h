/*
 * GPIO.h
 *
 *  Created on: Feb 23, 2020
 *      Author: yousef
 */
#include"types.h"
#ifndef GPIO_H_
#define GPIO_H_

#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3
#define PortE 4
#define PortF 5

#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7

#define OutputPort 0xFF
#define OutputPin 1
#define input 0


void GPIO_VidClockGattingMode(u8 PortNumber);
void GPIO_VidDigitalEnable(u8 PortNumber,u8 Value);

void GPIO_vidSetPortDirection(u8 PortNumber,u8 Value);
void GPIO_vidSetPortValue(u8 PortNumber,u8 Value);
u8 GPIO_u8ReadPort(u8 PortNumber);

void GPIO_SetPinValue(u8 PortNum,u8 PinNum,u8 Value);
void GPIO_SetPinDirection(u8 PortNum,u8 PinNum,u8 Direction);
u8 GPIO_u8ReadPin(u8 PortNum,u8 PinNum);


#endif /* GPIO_H_ */
