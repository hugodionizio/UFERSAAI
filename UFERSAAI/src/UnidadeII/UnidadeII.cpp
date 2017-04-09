/*
 * UnidadeII.cpp
 *
 *  Created on: 07/04/2017
 *      Author: hugo
 */

#include <iostream>
#include <cmath>
#include "UnidadeII.h"

using namespace std;

void setG(Perceptron *perceptron, float saidaDesejada, float saidaObtida) {
	perceptron->g = saidaDesejada - saidaObtida;
}

void setCorrecaoEntrada(Perceptron *perceptron, int i) {
	float c = perceptron->taxaAprendizado;
	float g = perceptron->g;
	float xi = perceptron->neuronio.dentrite[i].entrada;

	perceptron->correcaoEntrada[i] = c * g * xi;
}

void setNovoPeso(Perceptron *perceptron, int i) {
	float wi = perceptron->pesoAtual[i];
	float deltai = perceptron->correcaoEntrada[i];

	perceptron->novoPeso[i] = wi + deltai;
}

float backpropagation(float a, float b) {
	float result = 0;

	float A = 0, B = 0, y, expB;
	float i = 0, j = 0;
	float wji, ypi, theta_j;
	bool propagation = true;


	cout << "Informe o valor de A: ";
	cin >> A;

	cout << "\nInforme o valor de B: ";
	cin >> B;

	wji = 1;
	ypi = A*B;

	// y(pi) = 1/(1+exp(-sum(iw(ji)*y(pi)+theta(j))))
	while (propagation) {
		expB+=  i*wji*ypi+theta_j;
		propagation = false;
	}

	y = 1/(1+exp((double)expB));

	cout << y << endl;

	return result;
}

int exemploUnidadeII(int argc, char **argv) {
	char atributo[3][10] = {"sol", "nublado", "chuva"};
	RedeNeural tempo;
	Camada *camadas;

	int numNeuronios = 3;
	Neuronio *neuronio;

	inicializarRede(&tempo, CLASSIFICACAO);

	camadas = tempo.camada;
	for (int c = 0; c < tempo.quantidadeCamadas; ++c) {
		camadas[c].quantidadeNeuronios = numNeuronios;
		camadas[c].neuronio = new Neuronio[numNeuronios];
	}

	neuronio = camadas[0].neuronio;
	neuronio[0].valor = 1;
	neuronio[1].valor = 0;
	neuronio[2].valor = 0;

	neuronio = camadas[1].neuronio;
	neuronio[0].valor = 1;
	neuronio[1].valor = 0;
	neuronio[2].valor = 0;

	neuronio = camadas[2].neuronio;
	neuronio[0].valor = 1;
	neuronio[1].valor = 0;
	neuronio[2].valor = 0;

	return (0);
}
