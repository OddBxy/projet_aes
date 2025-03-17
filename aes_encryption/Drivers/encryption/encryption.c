/*
 * encryption.c
 *
 *  Created on: Mar 17, 2025
 *      Author: theo0
 */

#include "encryption.h"


void add_roundKey(uint8_t *buffer, uint8_t *roundKey){

	for(int i=0; i<4; i++){
		buffer[4*0 + i] = buffer[i]^roundKey[i];				//colonne i ligne 0
		buffer[4*1 + i] = buffer[1 + i]^roundKey[1 + i];		//colonne i ligne 1
		buffer[4*2 + i] = buffer[2 + i]^roundKey[2 + i];		//colonne i ligne 2
		buffer[4*3 + i] = buffer[3 + i]^roundKey[3 + i];		//colonne i ligne 3
	}

	//buffers sont 1d mais on les traites 2d en colonnes de 4
}
