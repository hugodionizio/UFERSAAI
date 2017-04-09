/*
 * RedeNeural.cpp
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "RedeNeural.h"

void inicializarRede(RedeNeural *rede, int problema) {
	int numCamadas = 3;

	if(problema == CLASSIFICACAO || problema == RECONHECIMENTO) {
		rede->quantidadeCamadas = numCamadas;
		rede->camada = new Camada[numCamadas];
	}
}

