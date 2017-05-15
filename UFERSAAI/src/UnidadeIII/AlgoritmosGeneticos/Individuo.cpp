/*
 * Individuo.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include <iostream>

#include "Individuo.h"

using namespace std;

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

void imprimirIndividuo(Individuo individuo) {
	int numCromossos = individuo.numCromossomos;

	cout << "|Número de cromossomos: " << numCromossos << endl;

	for (int cromossomo = 0; cromossomo < numCromossos; ++cromossomo) {
		cout << "|Cromossomo " << (cromossomo+1) << endl;
		imprimirCromossomo(individuo.cromossomo[cromossomo]);
	}
}

float aptidao(Individuo *) {
	// f(x,y) = abs(exp(-x), pow(-y, 2) + 1) + pow(10,-4)
	// 0.0005
	// [-1 a 1]

	return (0);
}
