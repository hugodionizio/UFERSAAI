/*
 * Individuo.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include <iostream>
#include <cmath>

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

	//cout << "|Número de cromossomos: " << numCromossos << endl;

	for (int cromossomo = 0; cromossomo < numCromossos; ++cromossomo) {
		cout << "C" << (cromossomo+1) << " = ";
		imprimirCromossomo(individuo.cromossomo[cromossomo]);
	}
	cout << aptidao(individuo) << "\t";
}

float aptidao(Individuo individuo) {
	float x, y;
	x = getCromossomoValor(individuo.cromossomo[0]);
	y = getCromossomoValor(individuo.cromossomo[1]);

	// [-1 a 1] // 0.0005
	// f(x,y) = abs(exp(-x) - pow(y, 2) + 1) + pow(10,-4)

	return (abs(exp(-x) - pow(y, 2) + 1) + pow(10,-4));
}
