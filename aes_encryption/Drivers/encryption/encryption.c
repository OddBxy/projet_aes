/*
 * encryption.c
 *
 *  Created on: Mar 17, 2025
 *      Author: theo0
 */

#include "encryption.h"

//private variables
static uint8_t Gf4x4[] = {0x02, 0x01, 0x01, 0x03, 0x03, 0x02, 0x01, 0x01, 0x01, 0x03, 0x02, 0x01, 0x01, 0x01, 0x03, 0x02};


//functions definition

void subBytes(uint8_t *buffer){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			buffer[4*i+j] = s_box[buffer[4*i+j]];			//buffer[idx] = s_box[buffer[idx]]
		}
	}
}


void shiftRows(uint8_t *buffer){
    for(int i = 1; i < 4; i++) {   // commence a partir de la ligne 1 (ligne 0 epargne)
        // Copie de la nieme ligne
        uint8_t temp[4];
        for (int j = 0; j < 4; j++) {
            temp[j] = buffer[4*j + i];
        }

        // Shift les elements
        for (int j = 0; j < 4; j++) {
            buffer[4*j+i] = temp[(i+j) % 4];
        }
    }
}




void mixColumns(uint8_t *buffer){

	//multiplication matricielle
	uint8_t result[16] = {0}; // Temporary result matrix

	for (int col = 0; col < 4; col++) { // pour chaque colonne de buffer
		for (int row = 0; row < 4; row++) { // pour chaque colonne de GF4x4

			uint8_t sum_val = 0;
			for (int k = 0; k < 4; k++) {
				sum_val ^= gmult(Gf4x4[k * 4 + row], buffer[col * 4 + k]);
			}
			result[col * 4 + row] = sum_val;

		}
	}

	// copie le resultat dans buffer
	for (int i = 0; i < 16; i++) {
		buffer[i] = result[i];
	}

}


