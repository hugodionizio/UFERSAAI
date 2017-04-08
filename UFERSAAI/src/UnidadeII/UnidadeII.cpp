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

void ativacao(Neuronio *neuronio, int n) {
	float x, w;

	for (int j = 0; j < n; ++j) {
		x = neuronio->dentrite[j].entrada;
		w = neuronio->dentrite[j].peso;

		neuronio->saida.ativacao[j] = x*w;
	}
}

void propagacao(Neuronio *neuronio, int n) {
	neuronio->saida.propagacao = 0;

	for (int j = 0; j < n; ++j) {
		neuronio->saida.propagacao += neuronio->saida.ativacao[j];
	}
}

float processamento(Neuronio *neuronio, int n) {
	ativacao(neuronio, n);
	propagacao(neuronio, n);

	return neuronio->saida.propagacao;
}

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
	float i, j;
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

