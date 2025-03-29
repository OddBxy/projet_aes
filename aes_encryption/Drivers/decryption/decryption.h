/*
 * decryption.h
 *
 *  Created on: Mar 17, 2025
 *      Author: theo0
 */

#ifndef DECRYPTION_DECRYPTION_H_
#define DECRYPTION_DECRYPTION_H_

//#include <stdint.h>
#include <stdlib.h>
#include "aes_utilities.h"

void inv_mix_columns(uint8_t *state);
void inv_shift_rows(uint8_t *state);
void inv_sub_bytes(uint8_t *state) ;
void aes_inv_cipher(uint8_t *out, uint8_t *dec, uint8_t *w);

#endif /* DECRYPTION_DECRYPTION_H_ */
