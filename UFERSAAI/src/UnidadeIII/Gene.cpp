/*
 * Gene.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include <iostream>

#include "Gene.h"

using namespace std;

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

void imprimirGene(Gene gene) {
	int numCaracteristicas = gene.numCaracteristicas;
	cout << "Número de características: " << numCaracteristicas << endl;

	cout << "Características: " << endl;
	for (int caracteristica = 0; caracteristica < numCaracteristicas; ++caracteristica) {
		cout << gene.caracteristicas[caracteristica] << " ";
	}

}
