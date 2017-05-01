/*
 * Neuronio.cpp
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Neuronio.h"

#include "../../Auxiliar.h"

#include <iostream>

using namespace std;

void ativacao(Neuronio *neuronio, int n, float *b) {
	float x, w;

	cout << "3.1 Ativando valores da soma..." << endl;
	for (int j = 0; j < n; ++j) {
		x = neuronio->dentrite[j].entrada;
		w = neuronio->dentrite[j].peso;

		neuronio->saida.ativacao += x * w + b[j];
		cout << neuronio->saida.ativacao << " ";
	}
	cout << endl;
}

void propagacao(Neuronio *neuronio, FuncaoAtivacao funcao) {

	cout << "Propagando sinal da soma por ";
	switch (funcao) {
		case SIGMOIDE:
			cout << "Sigmoide" << endl;
			neuronio->saida.propagacao = sigmoide(neuronio->saida.ativacao);
			break;
	}
}

float processamento(Neuronio *neuronio, int n, float *b) {
	ativacao(neuronio, n, b);
	propagacao(neuronio, SIGMOIDE);

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

	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			if (pointer) {
				cout << tabela[i][j] << " ";
			} else {
				pAux = (float **) &tabela[i * lin];
				pM = (float *) &pAux[j];
				cout << *(pM) << " ";
			}
		}
		cout << endl;
	}
}

