/*
 * Individuo.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Individuo.h"

void inicializarIndividuo(Individuo *Individuo, DescritorPopulacao posIndividuo) {
	int numCromossomos = posIndividuo.totalCromossomos;

	Cromossomo *cromossomo = new Cromossomo[numCromossomos];

	for (int posCromossomo = 0; posCromossomo < numCromossomos; ++posCromossomo) {
		inicializarCromossomo(&cromossomo[posCromossomo], posIndividuo);
	}
}
