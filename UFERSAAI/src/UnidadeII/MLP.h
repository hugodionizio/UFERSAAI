/*
 * MLP.h
 *
 *  Created on: Apr 19, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEII_MLP_H_
#define UNIDADEII_MLP_H_

#include "Perceptron.h"
#include "Camada.h"

typedef struct MLP {
	Camada camada;

	Perceptron *perceptron;
} MLP;

#endif /* UNIDADEII_MLP_H_ */
