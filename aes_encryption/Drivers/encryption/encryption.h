/*
 * encryption.h
 *
 *  Created on: Mar 17, 2025
 *      Author: theo0
 */

#ifndef ENCRYPTION_ENCRYPTION_H_
#define ENCRYPTION_ENCRYPTION_H_

#include "aes_utilities.h"

//void add_roundKey(uint8_t *buffer, uint8_t *roundKey);
void subBytes(uint8_t *buffer);
void shiftRows(uint8_t *buffer);
void mixColumns(uint8_t *buffer);
void aes_cipher(uint8_t *in, uint8_t *out, uint8_t *w);


#endif /* ENCRYPTION_ENCRYPTION_H_ */
