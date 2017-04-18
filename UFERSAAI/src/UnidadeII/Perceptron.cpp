/*
 * Perceptron.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Perceptron.h"

void setCorrecaoEntrada(Perceptron *perceptron, int i) {
	float c = perceptron->taxaAprendizado;
	float g = perceptron->g;
	float xi = perceptron->neuronio.dentrite[i].entrada;

	perceptron->correcaoEntrada[i] = c * g * xi;
}

void setG(Perceptron *perceptron, float saidaDesejada, float saidaObtida) {
	perceptron->g = saidaDesejada - saidaObtida;
}

void setNovoPeso(Perceptron *perceptron, int i) {
	float wi = perceptron->pesoAtual[i];
	float deltai = perceptron->correcaoEntrada[i];

	perceptron->novoPeso[i] = wi + deltai;
}

