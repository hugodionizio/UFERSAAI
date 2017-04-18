/*
 * Gene.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Gene.h"

void inicializarGene(Gene *gene, DescritorPopulacao posGene) {
	int numCaracteristica = posGene.totalCaracterisitcas, *caracteristicas =
			posGene.caracteristicas;

	gene->numCaracteristicas = numCaracteristica;
	gene->caracteristicas = new int[numCaracteristica];

	for (int posCaracteristica = 0; posCaracteristica < numCaracteristica;
			++posCaracteristica) {
		gene->caracteristicas[posCaracteristica] =
				caracteristicas[posCaracteristica];
	}

}
