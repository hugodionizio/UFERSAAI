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

void selecionarPais(Populacao *populacao) {
	float tmpMaior, tmpSegundoMaior, atual;

	populacao->listaOrdenada = new Individuo[2];

	populacao->listaOrdenada[0] = populacao->individuo[0];
	populacao->listaOrdenada[1] = populacao->individuo[1];
	for (int i = 0; i < populacao->numIndividuos; ++i) {
		tmpMaior = minimizarProbabilidade(*populacao, (Individuo)populacao->listaOrdenada[0]);
		tmpSegundoMaior = minimizarProbabilidade(*populacao, (Individuo)populacao->listaOrdenada[1]);
		atual = minimizarProbabilidade(*populacao, (Individuo)populacao->individuo[i]);
		if (tmpMaior < atual) {
			populacao->listaOrdenada[1] = populacao->listaOrdenada[0];
			populacao->listaOrdenada[0] = populacao->individuo[i];
		} else if (tmpSegundoMaior < atual && atual < tmpMaior) {
			populacao->listaOrdenada[1] = populacao->individuo[i];
		}
	}
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

void imprimirMelhoresPais(Populacao pop) {
	cout << "Melhores pais:" << endl;
	cout << 100*minimizarProbabilidade(pop, pop.listaOrdenada[0]) << "%" << endl;
	cout << 100*minimizarProbabilidade(pop, pop.listaOrdenada[1]) << "%" << endl;
}
