/*
 * Populacao.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Populacao.h"

void inicializarPopulacao(Populacao *populacao, DescritorPopulacao descritor) {
	int numIndividuos = descritor.tamPopulacao;

	populacao->numIndividuos = numIndividuos;
	populacao->individuo = new Individuo[numIndividuos];

	for (int posIndividuo = 0; posIndividuo < numIndividuos; ++posIndividuo) {
		inicializarIndividuo(&populacao->individuo[posIndividuo], descritor);
	}
}
