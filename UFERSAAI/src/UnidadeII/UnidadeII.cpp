/*
 * UnidadeII.cpp
 *
 *  Created on: 07/04/2017
 *      Author: hugo
 */

#include "UnidadeII.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void exemploBackpropagation() {
	//time_t t;
	srand(time(NULL));

	int numEntradas = 2;
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

void backpropagationXOR() {
	cout << "Backpropagation para XOR" << endl;
	float matrizConfusao[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
	float saidaDesejada[4] = {0, 1, 1, 0};
	float entrada[2];

	srand(time(NULL));

	for (int i = 0; i < 4; ++i) {
//		for (int j = 0; j < 2; ++j) {
//			cout << matrizConfusao[i][j] << "\t";
//		}
		entrada[0] = matrizConfusao[i][0]; entrada[1] = matrizConfusao[i][1];
		backpropagation(entrada, 2, saidaDesejada[i]);
	}
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
