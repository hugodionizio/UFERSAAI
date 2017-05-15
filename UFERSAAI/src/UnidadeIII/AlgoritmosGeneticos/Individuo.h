/*
 * Individuo.h
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEIII_INDIVIDUO_H_
#define UNIDADEIII_INDIVIDUO_H_

#include "Cromossomo.h"

typedef struct Individuo {
	int numCromossomos;
	Cromossomo *cromossomo;
} Individuo;

// a) Inicializar a população de cromossosmos
void inicializarIndividuo(Individuo *, DescritorPopulacao);
void imprimirIndividuo(Individuo);

// b) Avaliar cada cromossomo na população
float avaliar(Individuo *);

float aptidao(Individuo); // fitness function (gene = função: x2-12x+40
//typedef aptidao

#endif /* UNIDADEIII_INDIVIDUO_H_ */
