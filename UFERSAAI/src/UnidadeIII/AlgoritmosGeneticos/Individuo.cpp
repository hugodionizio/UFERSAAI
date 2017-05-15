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
		DescritorPopulacao posIndividuo, int pos) {
	int numCromossomos = posIndividuo.totalCromossomos;

	individuo->numCromossomos = numCromossomos;
	individuo->cromossomo = new Cromossomo[numCromossomos];
	individuo->indice = pos;

	cout << "Inicializando cromossomos..." << endl;
	for (int posCromossomo = 0; posCromossomo < numCromossomos;
			++posCromossomo) {
		inicializarCromossomo(&individuo->cromossomo[posCromossomo],
				posIndividuo);
	}
}

float aptidao(Individuo individuo) {
	float x, y;
	x = getCromossomoValor(individuo.cromossomo[0]);
	y = getCromossomoValor(individuo.cromossomo[1]);

	// [-1 a 1] // 0.0005
	// f(x,y) = abs(exp(-x) - pow(y, 2) + 1) + pow(10,-4)

	return (abs(exp(-x) - pow(y, 2) + 1) + pow(10,-4));
}

Individuo convergirGeneticaIndividuo(Individuo individuoA, Individuo individuoB, int indice) {
	Individuo filho;
	int numCromossomos = individuoA.numCromossomos;

	filho.indice = indice;
	filho.numCromossomos = numCromossomos;
	filho.cromossomo = new Cromossomo[numCromossomos];

	for (int i = 0; i < numCromossomos; ++i) {
		filho.cromossomo[i] = convergirGeneticaCromossomo(individuoA.cromossomo[i], individuoB.cromossomo[i]);
	}

	return (filho);
}

void liberarIndividuo(Individuo *individuo) {
	individuo->indice = -1;
	individuo->numCromossomos = -1;
}

int getIndiceIndividuo(Individuo individuo) {
	return (individuo.indice);
}

float getCriterio(Individuo individuo) {
	return (getRestricaoCromossomo(individuo.cromossomo[0], 0));
}

void imprimirIndividuo(Individuo individuo) {
	int numCromossos = individuo.numCromossomos;

	cout << (individuo.indice+1) << "\t";

	//cout << "|Número de cromossomos: " << numCromossos << endl;

	for (int cromossomo = 0; cromossomo < numCromossos; ++cromossomo) {
		cout << "C" << (cromossomo+1) << " = ";
		imprimirCromossomo(individuo.cromossomo[cromossomo]);
	}
	cout << aptidao(individuo) << "\t";
}
