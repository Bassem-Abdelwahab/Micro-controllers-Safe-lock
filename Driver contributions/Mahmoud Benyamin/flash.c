/*
 * flash.c
 *
 *  Created on: Mar 2, 2020
 *      Author: mahmo
 */
#define uint32_t  unsigned int
#include"tm4c123gh6pm.h"
#include"flash.h"
#define FLASH_BASE_ADDR         ((volatile uint32_t*)0x00020000)
void flash_enable(void){
if(FLASH_BOOTCFG_R &FLASH_BOOTCFG_KEY)// if bit = 1 there is key else there is another key
{ flash_key = 0xA442;}
else
{  flash_key = 0x71D5;}
}
void flash_page_erase(int block){
    // Clear then set the OFFSET (17:0) with the write address.
       FLASH_FMA_R &= 0xFFFC0000;
       // write address in the offset
       FLASH_FMA_R = (int) FLASH_BASE_ADDR + block*1024;
       //put 1 to erase bit in FMC REG and the flash key
       FLASH_FMC_R =(flash_key << 16)|FLASH_FMC_ERASE;
       while(FLASH_FMC_R & FLASH_FMC_ERASE);
}

void flash_mass_earase(void){
    FLASH_FMC_R = (flash_key << 16) |  FLASH_FMC_MERASE;
    while( FLASH_FMC_R & FLASH_FMC_MERASE);
}
int Flash_Erase(int blockCount)
{

    // Make sure Enable was called.
    if ( flash_key == 0) {
        return -1;
    }
        int i;
    for ( i = 0; i < blockCount; i++) {

        // Clear then set the OFFSET (17:0) with the write address.
        FLASH_FMA_R &= 0xFFFC0000;

        // Blocks are erased on 1KiB boundaries, so multiply the index by 1024
        //  and add this to the base address.
        FLASH_FMA_R |=(int) FLASH_BASE_ADDR + (i*1024);

        // Set the ERASE command bit.
        FLASH_FMC_R = ( flash_key << 16) | 0x2;

        // Poll the ERASE bit until it is cleared.
        while (FLASH_FMC_R & 0x2) {}

    }

    return 0;
}

int flash_write(uint32_t* data,int length){
    // Make sure Enable was called.
        if ( flash_key == 0) {
            return -1;
        }

        // Must erase the data first.  A write may only change a bit from 1 to 0, so if the
        //  bit is already zero, the write fails.  Erasing will set all bits to 1's.
        //  Calculate the number of 1KiB blocks that the data will span and erase that many.
        int blockCount = ((length * sizeof(uint32_t)) / 1024) + 1;
        Flash_Erase(blockCount);
        int i;
        for( i =0; i<length;i++){
            // but the content of the array[i] into the FMD register
            FLASH_FMD_R = data[i];
            // Clear then set the OFFSET address field (17:0) with the write address.
            FLASH_FMA_R &= 0xFFFC0000;
            FLASH_FMA_R |= (uint32_t)FLASH_BASE_ADDR + (i * sizeof(uint32_t));
            // start the write operation
            FLASH_FMC_R =(flash_key << 16)|FLASH_FMC_WRITE;
            while(FLASH_FMC_R & FLASH_FMC_WRITE);

        }

    return 0;
}
void flash_read(uint32_t * data,int length){

    // Copy the count of bytes into the target data buffer...
    int i;
    for (i = 0; i < length; i++) {
        data[i] = FLASH_BASE_ADDR[i];
    }
}


