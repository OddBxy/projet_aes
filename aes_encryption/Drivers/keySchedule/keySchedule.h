/*
 * keySchedule.h
 *
 *  Created on: Mar 17, 2025
 *      Author: theo0
 */

#ifndef KEYSCHEDULE_KEYSCHEDULE_H_
#define KEYSCHEDULE_KEYSCHEDULE_H_

#include "encryption.h"


void rotWord(uint8_t *col);
void subWord(uint8_t *col);
void newKey(uint8_t *key, uint8_t *result);

#endif /* KEYSCHEDULE_KEYSCHEDULE_H_ */
