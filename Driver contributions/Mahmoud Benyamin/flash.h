/*
 * flash.h
 *
 *  Created on: Mar 2, 2020
 *      Author: mahmo
 */

#ifndef FLASH_H_
#define FLASH_H_
static int flash_key =0;
void flash_enable(void);
void flash_read(uint32_t * data,int length);
int flash_write(uint32_t* data,int length);
void flash_page_erase(int block);
void flash_mass_earase(void);
int Flash_Erase(int blockCount);



#endif /* FLASH_H_ */
