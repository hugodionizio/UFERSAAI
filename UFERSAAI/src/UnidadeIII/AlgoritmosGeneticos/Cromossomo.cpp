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

	cromossomo->limInferior = posCromossomo.limites[0];
	cromossomo->limSuperior = posCromossomo.limites[1];
	cromossomo->restricoes = new float;
	*cromossomo->restricoes = posCromossomo.restrtricao;

	for (int posGene = 0; posGene < numGenes; ++posGene) {
		inicializarGene(&cromossomo->genes[posGene], posCromossomo);
	}
}

void imprimirCromossomo(Cromossomo cromossomo) {
	int numGenes = cromossomo.numGenes;

	cout << "[" << cromossomo.limInferior << ", "
			<< cromossomo.limSuperior << "] " << "e = "
			<< cromossomo.restricoes[0] << endl;

	cout << "||Número de genes: " << numGenes << endl;

	for (int gene = 0; gene < numGenes; ++gene) {
		if (getNumCaracteristicas(cromossomo.genes[gene]) > 1) {
			cout << "||Gene " << (gene+1) << endl;
		}
		else if (gene == 0)
			cout << "|||";
		imprimirGene(cromossomo.genes[gene]);
	}
	cout << endl;
}
