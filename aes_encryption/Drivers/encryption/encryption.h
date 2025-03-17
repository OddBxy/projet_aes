/*
 * encryption.h
 *
 *  Created on: Mar 17, 2025
 *      Author: theo0
 */

#ifndef ENCRYPTION_ENCRYPTION_H_
#define ENCRYPTION_ENCRYPTION_H_


void add_roundKey(uint8_t *buffer, uint8_t *roundKey);
void subBytes(uint8_t *buffer);

//source d'erreurs
void shiftRows(uint8_t *buffer);

#endif /* ENCRYPTION_ENCRYPTION_H_ */
