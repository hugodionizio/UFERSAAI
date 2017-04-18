/*
 * Cromossomo.h
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEIII_CROMOSSOMO_H_
#define UNIDADEIII_CROMOSSOMO_H_

#include "Gene.h"

typedef struct Cromossomo {
	int numGenes;
	Gene *genes;
} Cromossomo;

void inicializarCromossomo(Cromossomo *, DescritorPopulacao);

#endif /* UNIDADEIII_CROMOSSOMO_H_ */

