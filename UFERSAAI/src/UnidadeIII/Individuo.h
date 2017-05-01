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

// a
void inicializarIndividuo(Individuo *, DescritorPopulacao);
void imprimirIndividuo(Individuo);

// b
float avaliar(Individuo *);

// c
float aptidao(Individuo *); // fitness function (gene = função: x2-12x+40
//typedef aptidao

// Seleção natural de Darwin (Heurística)
void selecionarIndividuoMaisAdaptado();

// Seleção de pais
void selecionarPais();

void convergirGenetica();

#endif /* UNIDADEIII_INDIVIDUO_H_ */
