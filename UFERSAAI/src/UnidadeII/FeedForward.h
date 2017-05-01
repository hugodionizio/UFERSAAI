/*
 * FeedForward.h
 *
 *  Created on: Apr 18, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEII_FEEDFORWARD_H_
#define UNIDADEII_FEEDFORWARD_H_

#include "MLP.h"
#include "../Auxiliar.h"
#include "RedeNeural/RedeNeural.h"

typedef struct FeedForward {
	RedeNeural descritor;
	MLP mlp;
	float erro;
} FeedForward;

//	11. Calcula-se o erro da rede
void erroRede(FeedForward *);

float backpropagation(float *, int, float);

#endif /* UNIDADEII_FEEDFORWARD_H_ */
