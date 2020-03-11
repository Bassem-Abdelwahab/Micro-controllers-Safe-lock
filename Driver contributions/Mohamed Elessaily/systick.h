/*
 * timer.h
 *
 *  Created on: Mar 7, 2020
 *      Author: msm
 */
#include"types.h"
#include <std.h>
#ifndef SYSTICK_H_
#define SYSTICK_H_

#define COUNT 0x00010000
#define ENABLE 5
#define MS 16000000
void systick_init();
void systick_wait(u32 delay);
void systick_delay_ms(u32 delay);


#endif /* SYSTICK_H_ */
