/*
 * Camada.cpp
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Camada.h"
#include <iostream>
#include <cstring>

using namespace std;

void inicializarCamada(Camada *camada, char *atributo, int numNeuronios, float *neuronios) {
	cout << "Inicializando camadas..." << endl;

	camada->atributo = new char[strlen(atributo)];
	strcpy(camada->atributo, atributo);
	camada->quantidadeNeuronios = numNeuronios;
	camada->neuronio = new Neuronio[numNeuronios];

	for (int n = 0; n < numNeuronios; ++n) {
		inicializarNeuronio(&camada->neuronio[n], neuronios[n]);
	}
}

void imprimirCamada(Camada camada) {
	cout << "\n" << camada.atributo;

	for (int n = 0; n < camada.quantidadeNeuronios; ++n) {
		cout << "N=" << (n+1) << ", ";
		imprimirNeuronio(camada.neuronio[n]);
	}
}
