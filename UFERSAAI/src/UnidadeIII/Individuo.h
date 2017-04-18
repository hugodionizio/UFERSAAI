/*
 * Individuo.h
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEIII_INDIVIDUO_H_
#define UNIDADEIII_INDIVIDUO_H_

#include "Cromossomo.h"

typedef struct Individuo {
	int numCromossomos;
	Cromossomo *cromossomo;
} Individuo;

void inicializarIndividuo(Individuo *, DescritorPopulacao);
void imprimirIndividuo(Individuo);

// Seleção natural de Darwin (Heurística)
void selecionarIndividuoMaisAdaptado();

#endif /* UNIDADEIII_INDIVIDUO_H_ */
