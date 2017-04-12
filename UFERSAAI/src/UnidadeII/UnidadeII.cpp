/*
 * UnidadeII.cpp
 *
 *  Created on: 07/04/2017
 *      Author: hugo
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "UnidadeII.h"

using namespace std;


// Rede de pesos dos neurônios
float **converterEstaticaDinamica(float **estatica, float **dinamica, int lin, int col) {
	float **pAux;
	float *pM;

	dinamica = new float*[lin];
	for(int i = 0; i < lin; i++) {
		dinamica[i] = new float[col];
		for(int j = 0; j < col; j++) {
			pAux = (float **)&estatica[i*lin-1];
			pM = (float *)&pAux[j];
			dinamica[i][j] = *(pM);
		}
	}

	return dinamica;
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

void setG(Perceptron *perceptron, float saidaDesejada, float saidaObtida) {
	perceptron->g = saidaDesejada - saidaObtida;
}

void setCorrecaoEntrada(Perceptron *perceptron, int i) {
	float c = perceptron->taxaAprendizado;
	float g = perceptron->g;
	float xi = perceptron->neuronio.dentrite[i].entrada;

	perceptron->correcaoEntrada[i] = c * g * xi;
}

void setNovoPeso(Perceptron *perceptron, int i) {
	float wi = perceptron->pesoAtual[i];
	float deltai = perceptron->correcaoEntrada[i];

	perceptron->novoPeso[i] = wi + deltai;
}

float backpropagation(float a, float b) {
//	time_t t;
	srand(time(NULL));

	float result = 0;

	float A = 0, B = 0, y, expB;
	int i = 0, j = 0;
	float w[3][3], ypi, theta_j;
	bool propagation = true;

	cout << "Informe o valor de A: ";
	cin >> A;

	cout << "\nInforme o valor de B: ";
	cin >> B;

	float auxf = 0;
	for (int var = 0; var < 3; ++var) {
		for (int n = 0; n < 3; ++n) {
			w[var][n] = (float)(rand() % 10)/10;
			auxf = w[var][n];
			cout << auxf << " ";
		}
	}


	ypi = 1;

	// y(pi) = 1/(1+exp(-sum(iw(ji)*y(pi)+theta(j))))
	i = 0;
	j = 0;
	while (i < 3) {
		while (j < 3) {
			int aux = w[i][j];
			expB += i * aux * ypi + theta_j;
			j++;
		}
		i++;
	}

	y = 1 / (1 + exp(expB));

	cout << y << endl;

	return result;
}

int exemploUnidadeII(int argc, char **argv) {
	cout << "Treinando rede..." << endl;

	int numNeuronios = 3;
	int numCamadas = CLASSIFICACAO;

	float redeNeuronios[3][3] = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
	float **pRedeNeuronios, **teste;
	char atributos[3][10] = { "sol", "nublado", "chuva" };

	RedeNeural tempo;

	cout << "rede de neurônios" << endl;

	inicializarRede(&tempo, numNeuronios, (float **)&pRedeNeuronios+1, numCamadas, (char **)atributos);
	imprimirRedeNeural(tempo);

	return (0);
}
