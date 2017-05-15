/*
 * Populacao.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#include <iostream>
#include <cmath>

#include "Populacao.h"

using namespace std;


void inicializarPopulacao(Populacao *populacao, DescritorPopulacao descritor) {
	int numIndividuos = descritor.tamPopulacao;

	populacao->numIndividuos = numIndividuos;
	populacao->individuo = new Individuo[numIndividuos];

	for (int posIndividuo = 0; posIndividuo < numIndividuos; ++posIndividuo) {
		inicializarIndividuo(&populacao->individuo[posIndividuo], descritor);
	}
}

float minimizarProbabilidade(Populacao populacao, Individuo individuo) {
	return (calcularProbabilidade(populacao, individuo, -1));
}

float calcularProbabilidade(Populacao populacao, Individuo individuo, int potencia) {
	float soma = 0;

	for (int i = 0; i < populacao.numIndividuos; ++i) {
		soma += pow(aptidao(populacao.individuo[i]), potencia);
	}

	return (pow(aptidao(individuo), potencia)/soma);
}

void imprimirPopulacao(Populacao pop) {
	int numIndividuos = pop.numIndividuos;
	//cout << "Número de indivíduos: " << numIndividuos << endl;
	cout << "Indivíduo\tCromossomo\tBinário\tAptidão: f(x,y) = |abs(exp(-x) - y² + 1| + 10^(-4)\tProbabilidade" << endl;

	for (int posIndividuo = 0; posIndividuo < numIndividuos; ++posIndividuo) {
		//cout << "Indivíduo " << (posIndividuo+1) << endl;
		cout << "I" << (posIndividuo+1) << "\t";
		imprimirIndividuo(pop.individuo[posIndividuo]);
		cout << 100*minimizarProbabilidade(pop, pop.individuo[posIndividuo]) << "%";
		cout << endl;
	}
	cout << endl;
}
