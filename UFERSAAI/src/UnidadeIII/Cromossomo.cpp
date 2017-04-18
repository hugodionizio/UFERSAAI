/*
 * Cromossomo.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Cromossomo.h"

void inicializarCromossomo(Cromossomo *cromossomo,
		DescritorPopulacao posCromossomo) {
	int numGenes = posCromossomo.totalGenes;

	cromossomo->numGenes = numGenes;
	cromossomo->genes = new Gene[numGenes];

	for (int posGene = 0; posGene < numGenes; ++posGene) {
		inicializarGene(&cromossomo->genes[posGene], posCromossomo);
	}
}

