/*
 * keySchedule.c
 *
 *  Created on: Mar 17, 2025
 *      Author: theo0
 */


#include "keySchedule.h"


void rotWord(uint8_t *col){

    uint8_t temp[4];
    for (int j = 0; j < 4; j++) {
        temp[j] = col[j];
    }

    // Shift les elements
    for (int i = 0; i < 4; i++) {
        col[j] = temp[(1+j) % 4];
    }

}
