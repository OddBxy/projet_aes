/*
 * keySchedule.c
 *
 *  Created on: Mar 17, 2025
 *      Author: theo0
 */


#include "keySchedule.h"


static uint8_t rcon[] = {
		0x01,0x00,0x00,0x00, 0x02,0x00,0x00,0x00, 0x04,0x00,0x00,0x00, 0x8,0x00,0x00,0x00, 0x10,0x00,0x00,0x00, 0x20,0x00,0x00,0x00, 0x40,0x00,0x00,0x00, 0x80,0x00,0x00,0x00, 0x1b,0x00,0x00,0x00, 0x36,0x00,0x00,0x00
};





void rotWord(uint8_t *col){

    uint8_t temp[4];
    for (int j = 0; j < 4; j++) {
        temp[j] = col[j];
    }

    // Shift les elements
    for (int i = 0; i < 4; i++) {
        col[i] = temp[(1+i) % 4];
    }

}

void subWord(uint8_t *col){
	for(int i=0; i<4; i++){
		col[i] = s_box[col[i]];
	}
}



void newKey(uint8_t *key, uint8_t *result){

	uint8_t tmp[4];
	uint8_t i;
	uint8_t len = 4*(10+1);
	uint8_t Nk = 4;

	for (i = 0; i < 16; i++) {
		result[i] = key[i];
	}

	for (i = Nk; i < len; i++) {
		tmp[0] = result[4*(i-1)+0];
		tmp[1] = result[4*(i-1)+1];
		tmp[2] = result[4*(i-1)+2];
		tmp[3] = result[4*(i-1)+3];

		if (i%Nk == 0) {

			rotWord(tmp);
			subWord(tmp);

			tmp[0] ^= rcon[4 * (i/Nk - 1)];

		} else if (Nk > 6 && i%Nk == 4) {

			subWord(tmp);

		}

		result[4*i+0] = result[4*(i-Nk)+0]^tmp[0];
		result[4*i+1] = result[4*(i-Nk)+1]^tmp[1];
		result[4*i+2] = result[4*(i-Nk)+2]^tmp[2];
		result[4*i+3] = result[4*(i-Nk)+3]^tmp[3];

	}

}


