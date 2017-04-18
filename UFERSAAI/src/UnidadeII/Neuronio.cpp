/*
 * Neuronio.cpp
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Neuronio.h"
#include <iostream>

using namespace std;

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


void inicializarNeuronio(Neuronio *neuronio, float valor) {
	cout << "Inicializando neurônios..." << endl;

	neuronio->valor = valor;
}

void imprimirNeuronio(Neuronio neuronio) {
	cout << neuronio.valor;
}
void imprimirPesosRede(float **tabela, int lin, int col, bool pointer) {
	float **pAux;
	float *pM;

	for(int i = 0; i < lin; i++) {
		for(int j = 0; j < col; j++) {
			if(pointer) {
				cout << tabela[i][j] << " " ;
			}
			else {
				pAux = (float **)&tabela[i*lin];
				pM = (float *)&pAux[j];
				cout << *(pM) << " ";
			}
		}
		cout << endl;
	}
}

