/*
 * RedeNeural.cpp
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "RedeNeural.h"

#include <iostream>

using namespace std;

void inicializarRede(RedeNeural *rede, int numNeuronios, float **redeNeuronios,
		int problema, char **atributos) {
	int numCamadas = CLASSIFICACAO; // Padrão

	cout << "Incializando Rede Neural Artificial..." << endl;

	imprimirPesosRede(redeNeuronios, numCamadas, numNeuronios, false);

	if (problema == CLASSIFICACAO || problema == RECONHECIMENTO) {
		rede->quantidadeCamadas = numCamadas;
		rede->camada = new Camada[numCamadas];
	}

	for (int c = 0; c < rede->quantidadeCamadas; ++c) {
		inicializarCamada(&rede->camada[c], (char *) atributos[c], numNeuronios,
				(float *) redeNeuronios[c]);
	}
}

void imprimirRedeNeural(RedeNeural rede) {
	cout << "Número de camadas: " << rede.quantidadeCamadas << endl;

	cout << "Camadas: " << endl;
	for (int c = 0; c < rede.quantidadeCamadas; ++c) {
		imprimirCamada(rede.camada[c]);
	}
}
