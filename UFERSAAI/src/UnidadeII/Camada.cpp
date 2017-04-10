/*
 * Camada.cpp
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Camada.h"

void inicializarCamada(Camada *camada, int numNeuronios, float *neuronios) {
	camada->quantidadeNeuronios = numNeuronios;
	camada->neuronio = new Neuronio[numNeuronios];

	for (int n = 0; n < numNeuronios; ++n) {
		inicializarNeuronio(&camada->neuronio[n], neuronios[n]);
	}
}
