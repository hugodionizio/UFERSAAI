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

	float valor;
	float limInferior;
	float limSuperior;
	float *restricoes;
} Cromossomo;

void inicializarCromossomo(Cromossomo *, DescritorPopulacao);
Cromossomo convergirGeneticaCromossomo(Cromossomo, Cromossomo);
float getCromossomoValor(Cromossomo);
float getRestricaoCromossomo(Cromossomo, int);
void imprimirCromossomo(Cromossomo);

#endif /* UNIDADEIII_CROMOSSOMO_H_ */

