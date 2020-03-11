/*
 * timer.c
 *
 *  Created on: Mar 7, 2020
 *      Author: msm
 */
#include"types.h"
#include<std.h>
#include"systick.h"
#include"register.h"
void systick_init(){
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = 0x00FFFFFF;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R = ENABLE;
}
void systick_wait(u32 delay){
    NVIC_ST_RELOAD_R = delay-1;
    while((NVIC_ST_CURRENT_R & COUNT) == 0);

}
void systick_delay_ms(u32 delay){

    u32 i;
    for(i=0;i<delay;i++){
        systick_wait(MS);
    }
}


