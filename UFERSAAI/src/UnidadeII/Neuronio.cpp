/*
 * Neuronio.cpp
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Neuronio.h"

void ativacao(Neuronio *neuronio, int n) {
	float x, w;

	for (int j = 0; j < n; ++j) {
		x = neuronio->dentrite[j].entrada;
		w = neuronio->dentrite[j].peso;

		neuronio->saida.ativacao[j] = x*w;
	}
}

void propagacao(Neuronio *neuronio, int n) {
	neuronio->saida.propagacao = 0;

	for (int j = 0; j < n; ++j) {
		neuronio->saida.propagacao += neuronio->saida.ativacao[j];
	}
}

float processamento(Neuronio *neuronio, int n) {
	ativacao(neuronio, n);
	propagacao(neuronio, n);

	return neuronio->saida.propagacao;
}


void inicializarNeuronio(Neuronio *neuronio) {

}

