/*
 * aes_utilities.h
 *
 *  Created on: Mar 17, 2025
 *      Author: theo0
 */

#ifndef AES_UTILITIES_AES_UTILITIES_H_
#define AES_UTILITIES_AES_UTILITIES_H_

#include "main.h"

extern uint8_t s_box[256];
uint8_t gmult(uint8_t a, uint8_t b);
void coef_add(uint8_t a[], uint8_t b[], uint8_t d[]);
void add_round_key(uint8_t *state, uint8_t *w, uint8_t r);

#endif /* AES_UTILITIES_AES_UTILITIES_H_ */
