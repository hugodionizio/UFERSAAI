/*
 * UnidadeII.cpp
 *
 *  Created on: 07/04/2017
 *      Author: hugo
 */

#include <iostream>
#include <cmath>
#include "UnidadeII.h"

#include <cstdlib>
#include <ctime>

using namespace std;

// Rede de pesos dos neurônios
float backpropagation(float *xEntradas, int numEntradas) {
//	time_t t;
//	srand(t*time(NULL));

	float result = 0;

	float A = 0, B = 0, x[2], y, expB;
	int i = 0, j = 0;
	float w[2], ypi, theta_j;
	bool propagation = true;

	A = 0;
	B = 0;

	//	1. Inicialização dos pesos sinápticos com valores aleatórios.
	float auxf = 0;
	for (int var = 0; var < 2; var++) {
		w[var] = (float) (rand() % 10) / 10;
		auxf = w[var];
		cout << auxf << " ";
	}

	//	2. Aplica o vetor de entradas X1, X2, ... Xn.
//	for (int var = 0; var < numEntradas; ++var) {
	x[0] = xEntradas[0];
	x[1] = xEntradas[1];
//	}

//	3. Calculam-se os nets dos neurônios da camada oculta, para cada j ε(1,l)
//	4. Aplica a função de transferência para obter as saídas ij da camada oculta.
//	5. Calcula os nets dos neurônios da camada de saída, para cada k ε(1,M)

//	cout << "Informe o valor de A: ";
//	cin >> A;

//	cout << "\nInforme o valor de B: ";
//	cin >> B;

	ypi = 1;

	// y(pi) = 1/(1+exp(-sum(iw(ji)*y(pi)+theta(j))))
	i = 0;
	j = 0;
	while (i < 3) {
		while (j < 3) {
			int aux = w[i];
			expB += i * aux * ypi + theta_j;
			j++;
		}
		i++;
	}

	y = 1 / (1 + exp(expB));

	cout << y << endl;

	return result;
}

void exemploBackpropagation() {
	time_t t;
	srand(t * time(NULL));

	//exemploUnidadeII(argc, argv);
	float *entradas = new float[2] { 0.0, 0.0 };
	backpropagation(entradas, 2);
	delete[] entradas;

	entradas = new float[2] { 0.0, 1.0 };
	backpropagation(entradas, 2);
	delete[] entradas;

	entradas = new float[2] { 1.0, 0.0 };
	backpropagation(entradas, 2);
	delete[] entradas;

	entradas = new float[2] { 1.0, 1.0 };
	backpropagation(entradas, 2);
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
