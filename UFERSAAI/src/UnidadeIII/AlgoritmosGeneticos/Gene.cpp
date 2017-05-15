/*
 * Gene.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Gene.h"

using namespace std;

void inicializarGene(Gene *gene, DescritorPopulacao posGene, int bit) {
	int numCaracteristica = posGene.totalCaracterisitcas, *caracteristicas =
			posGene.caracteristicas;

	gene->numCaracteristicas = numCaracteristica;
	gene->caracteristicas = new int[numCaracteristica];

	for (int posCaracteristica = 0; posCaracteristica < numCaracteristica;
			++posCaracteristica) {
		gene->caracteristicas[posCaracteristica] = bit;
				//rand()%2;
				//caracteristicas[posCaracteristica];
	}

}

void setGene(Gene *gene, bool bit) {
	gene->bit = bit;
}

bool getGene(Gene gene) {
	return (gene.bit);
}

void imprimirBitGene(Gene gene) {
	cout << gene.bit << " ";
}

int getNumCaracteristicas(Gene gene) {
	return (gene.numCaracteristicas);
}

int getCaracteristica(Gene gene, int posCaracteristica) {
	return (gene.caracteristicas[posCaracteristica]);
}

void imprimirGene(Gene gene) {
	int numCaracteristicas = gene.numCaracteristicas;

	if (numCaracteristicas > 1) {
		cout << "|||Número de características: " << numCaracteristicas << endl;

		cout << "|||Características: " << endl << "|||";
	}
	for (int caracteristica = 0; caracteristica < numCaracteristicas; ++caracteristica) {
		cout << gene.caracteristicas[caracteristica] << " ";
	}
	if (numCaracteristicas > 1) {
		cout << endl;
	}
}

void mutacao(Gene *gene) {

}
