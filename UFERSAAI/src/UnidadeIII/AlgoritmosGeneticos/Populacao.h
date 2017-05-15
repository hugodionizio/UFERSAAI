/*
 * Populacao.h
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEIII_POPULACAO_H_
#define UNIDADEIII_POPULACAO_H_

#include "Individuo.h"

typedef struct Populacao {
	int numIndividuos;
	Individuo *individuo;
} Populacao;

void inicializarPopulacao(Populacao *, DescritorPopulacao);
float calcularProbabilidade(Populacao, Individuo, int);
void imprimirPopulacao(Populacao);

#endif /* UNIDADEIII_POPULACAO_H_ */
