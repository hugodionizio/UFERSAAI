/*
 * UnidadeII.cpp
 *
 *  Created on: 07/04/2017
 *      Author: hugo
 */

#include <iostream>
#include "UnidadeII.h"

#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void exemploBackpropagation() {
	time_t t;
	srand(t * time(NULL));

	int numEntradas = 2;
	//exemploUnidadeII(argc, argv);
	float saidaDesejada = 0;
	float *entradas = new float[numEntradas] { 0.0, 0.0 };
	backpropagation(entradas, numEntradas, saidaDesejada);
	delete[] entradas;

	saidaDesejada = 1.0;
	entradas = new float[numEntradas] { 0.0, 1.0 };
	backpropagation(entradas, numEntradas, saidaDesejada);
	delete[] entradas;

	saidaDesejada = 1.0;
	entradas = new float[numEntradas] { 1.0, 0.0 };
	backpropagation(entradas, numEntradas, saidaDesejada);
	delete[] entradas;

	saidaDesejada = 0.0;
	entradas = new float[numEntradas] { 1.0, 1.0 };
	backpropagation(entradas, numEntradas, saidaDesejada);
	delete[] entradas;
}

int exemploUnidadeII(int argc, char **argv) {
	cout << "Treinando rede..." << endl;

	int numNeuronios = 3;
	int numCamadas = CLASSIFICACAO;

	float redeNeuronios[3][3] = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
	float **pRedeNeuronios, **teste;
	char atributos[3][10] = { "sol", "nublado", "chuva" };

	RedeNeural tempo;

	cout << "rede de neurônios" << endl;

	inicializarRede(&tempo, numNeuronios, (float **) &pRedeNeuronios + 1,
			numCamadas, (char **) atributos);
	imprimirRedeNeural(tempo);

	return (0);
}
