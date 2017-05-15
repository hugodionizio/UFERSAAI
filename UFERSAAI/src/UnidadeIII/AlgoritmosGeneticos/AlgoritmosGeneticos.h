/*
 * AlgoritmosGeneticos.h
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEIII_ALGORITMOSGENETICOS_H_
#define UNIDADEIII_ALGORITMOSGENETICOS_H_

#include "Populacao.h"

typedef struct AlgoritmosGeneticos {
	Populacao populacao;
	int descontinuidade;
} AlgoritmosGeneticos;

void inicializarAlgoritmoGenetico(AlgoritmosGeneticos *, DescritorPopulacao);
int mainAlgoritmosGeneticos(int, char **);

void menorCaminho(int *tabela, int lin, int col);
void descontinuidadeDura(AlgoritmosGeneticos *);

#endif /* UNIDADEIII_ALGORITMOSGENETICOS_H_ */
