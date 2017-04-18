/*
 * Perceptron.h
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEII_PERCEPTRON_H_
#define UNIDADEII_PERCEPTRON_H_

#include "Neuronio.h"

#endif /* UNIDADEII_PERCEPTRON_H_ */

//	Perceptron
typedef struct Perceptron {
	Neuronio neuronio;

	float *novoPeso;
	float *pesoAtual;
	float *correcaoEntrada;
	float taxaAprendizado;
	float g; // saída desejada - saída obtida
} Perceptron;

void setCorrecaoEntrada(Perceptron *, int);
void setG(Perceptron *, float, float);
void setNovoPeso(Perceptron *, int);

