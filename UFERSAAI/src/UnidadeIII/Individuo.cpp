/*
 * Individuo.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Individuo.h"

void inicializarIndividuo(Individuo *individuo,
		DescritorPopulacao posIndividuo) {
	int numCromossomos = posIndividuo.totalCromossomos;

	individuo->numCromossomos = numCromossomos;
	individuo->cromossomo = new Cromossomo[numCromossomos];

	for (int posCromossomo = 0; posCromossomo < numCromossomos;
			++posCromossomo) {
		inicializarCromossomo(&individuo->cromossomo[posCromossomo],
				posIndividuo);
	}
}
