/*
 * RedeNeural.cpp
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "RedeNeural.h"

void inicializarRede(RedeNeural *rede, int numNeuronios, float **redeNeuronios, int problema, char **atributos) {
	int numCamadas = CLASSIFICACAO; // Padrão

	if(problema == CLASSIFICACAO || problema == RECONHECIMENTO) {
		rede->quantidadeCamadas = numCamadas;
		rede->camada = new Camada[numCamadas];
	}

	for (int c = 0; c < rede->quantidadeCamadas; ++c) {
		inicializarCamada(&rede->camada[c], numNeuronios, (float *)redeNeuronios[c]);
	}
}

