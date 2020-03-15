/*
 * macroes.h
 *
 *  Created on: Feb 23, 2020
 *      Author: yousef
 */

#ifndef MACROES_H_
#define MACROES_H_

#define Set_Bit(data,bit) data|=(1<<bit)
#define Clr_Bit(data,bit) data&=~(1<<bit)
#define Toggle_Bit(data,bit) data^=(1<<bit)
#define Get_Bit(data,bit) ((data>>bit)&1)


#endif /* MACROES_H_ */
