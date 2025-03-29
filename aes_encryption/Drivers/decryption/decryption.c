/*
 * decryption.c
 *
 *  Created on: Mar 17, 2025
 *      Author: alicia.battault
 */

#include "decryption.h"




//functions definition


void coef_mult(uint8_t *a, uint8_t *b, uint8_t *d) {

	d[0] = gmult(a[0],b[0])^gmult(a[3],b[1])^gmult(a[2],b[2])^gmult(a[1],b[3]);
	d[1] = gmult(a[1],b[0])^gmult(a[0],b[1])^gmult(a[3],b[2])^gmult(a[2],b[3]);
	d[2] = gmult(a[2],b[0])^gmult(a[1],b[1])^gmult(a[0],b[2])^gmult(a[3],b[3]);
	d[3] = gmult(a[3],b[0])^gmult(a[2],b[1])^gmult(a[1],b[2])^gmult(a[0],b[3]);
}


void inv_mix_columns(uint8_t *buffer) {

	const uint8_t InvGf4x4[16] = {
	    0x0E, 0x09, 0x0D, 0x0B,
	    0x0B, 0x0E, 0x09, 0x0D,
	    0x0D, 0x0B, 0x0E, 0x09,
	    0x09, 0x0D, 0x0B, 0x0E
	};

	uint8_t result[16] = {0}; // Matrice temporaire

	for (int col = 0; col < 4; col++) { // Pour chaque colonne du buffer
		for (int row = 0; row < 4; row++) { // Pour chaque ligne de la matrice inverse

			uint8_t sum_val = 0;
			for (int k = 0; k < 4; k++) {
				sum_val ^= gmult(InvGf4x4[k * 4 + row], buffer[col * 4 + k]);
			}
			result[col * 4 + row] = sum_val;
		}
	}

	// Copie du résultat dans buffer
	for (int i = 0; i < 16; i++) {
		buffer[i] = result[i];
	}
}



void inv_shift_rows(uint8_t *buffer) {
    for (int i = 1; i < 4; i++) {  // Commence à partir de la ligne 1 (ligne 0 inchangée)
        uint8_t temp[4];

        // Copie de la i-ème ligne
        for (int j = 0; j < 4; j++) {
            temp[j] = buffer[4*j + i];
        }

        // Décalage des éléments vers la droite
        for (int j = 0; j < 4; j++) {
            buffer[4*j + i] = temp[(4 + j - i) % 4];
        }
    }
}


void inv_sub_bytes(uint8_t *buffer2) {

	uint8_t i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			buffer2[4*i+j] = inv_s_box[buffer2[4*i+j]];
		}
	}
}




void aes_inv_cipher(uint8_t *out, uint8_t *dec, uint8_t *w) {

	uint8_t state[16];


	for (int i = 0; i < 16; i++) {

			state[i] = out[i];
		}


	add_round_key(state, w, 10);

	for (int r = 9; r > 0; r--) {
		inv_shift_rows(state);
		inv_sub_bytes(state);
		add_round_key(state, w, r);
		inv_mix_columns(state);
	}

	inv_shift_rows(state);
	inv_sub_bytes(state);
	add_round_key(state, w, 0);

	for (int i = 0; i < 16; i++) {
		dec[i] = state[i];

	}

}





