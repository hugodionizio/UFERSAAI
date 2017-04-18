/*
 * Cromossomo.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include <iostream>

#include "Cromossomo.h"

using namespace std;

void inicializarCromossomo(Cromossomo *cromossomo,
		DescritorPopulacao posCromossomo) {
	int numGenes = posCromossomo.totalGenes;

	cromossomo->numGenes = numGenes;
	cromossomo->genes = new Gene[numGenes];

	for (int posGene = 0; posGene < numGenes; ++posGene) {
		inicializarGene(&cromossomo->genes[posGene], posCromossomo);
	}
}

void imprimirCromossomo(Cromossomo cromossomo) {
	int numGenes = cromossomo.numGenes;

	cout << "Número de genes: " << numGenes << endl;
	for (int gene = 0; gene < numGenes; ++gene) {
		imprimirGene(cromossomo.genes[gene]);
	}
}
