/*
 * AlgoritmosGeneticos.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "AlgoritmosGeneticos.h"

void inicializarAlgoritmoGenetico(AlgoritmosGeneticos *algoritmosGeneticos, DescritorPopulacao descritor) {
	Populacao pop;

	inicializarPopulacao(&algoritmosGeneticos->populacao, descritor);
}
