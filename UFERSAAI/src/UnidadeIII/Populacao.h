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
	Individuo *individuo;
};

void inicializarPopulacao(Populacao *, DescritorPopulacao);

#endif /* UNIDADEIII_POPULACAO_H_ */
