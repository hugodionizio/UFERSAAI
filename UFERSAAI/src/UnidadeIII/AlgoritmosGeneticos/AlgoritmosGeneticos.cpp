/*
 * AlgoritmosGeneticos.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#include <cstdlib>
#include <ctime>

#include "AlgoritmosGeneticos.h"

void inicializarAlgoritmoGenetico(AlgoritmosGeneticos *algoritmosGeneticos, DescritorPopulacao descritor) {
	Populacao *diversidade;
	Populacao pop;

	srand(time(NULL));
	inicializarPopulacao(&algoritmosGeneticos->populacao, descritor);
}
