/*
 * FeedForward.cpp
 *
 *  Created on: Apr 18, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "FeedForward.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//	11. Calcula-se o erro da rede
void erroRede(FeedForward *ff) {
	cout << "11/11: Calculando o erro da rede... " << endl;
	int numNeuronios = ff->mlp.camada.quantidadeNeuronios;

	ff->erro = powf(ff->mlp.perceptron[0].neuronio.saida.propagacao, 2.0);
	for (int neuronio = 1; neuronio < numNeuronios; ++neuronio) {
		ff->erro += powf(ff->mlp.perceptron[neuronio].neuronio.saida.propagacao, 2.0);
	}
	ff->erro = ff->erro/2.0;
	// cout << ff->erro << endl;
}

float backpropagation(float *entradas, int numEntradas, float saidaDesejada) {
//	time_t t;
//	srand(t*time(NULL));

	float result = 0;
	int limite = 0;

	float *b = new float[numEntradas];
	FeedForward ff;
	int numOcultas = 1;
	MLP entrada, *oculta, saida;

	cout << "Entradas:" << endl;
	for (int entrada = 0; entrada < numEntradas; ++entrada) {
		//entradas[entrada]+=0.5;
	}
	cout << endl;

	// Inicializando b
	cout << "Inicializando b..." << endl;
	for (int iB = 0; iB < numEntradas; ++iB) {
		b[iB] = 0;
		cout << "b" << iB << " " << b[iB] << "\t";
	}
	cout << endl;

	//	1. Inicialização dos pesos sinápticos com valores aleatórios.
	oculta = new MLP[numOcultas];
	cout << "Camada de entrada:" << endl;
	incializacaoPesosSinapticos(&entrada, numEntradas);

	cout << "Camada(s) oculta(s):" << endl;
	for (int camada = 0; camada < numOcultas; ++camada) {
		incializacaoPesosSinapticos(&oculta[camada], numEntradas);
	}

	cout << "Camada de saída:" << endl;
	incializacaoPesosSinapticos(&saida, numEntradas);

	do {
	//	2. Aplica o vetor de entradas X1, X2, ... Xn.
		vetorEntradas(&entrada, &oculta[0], entradas);

	//	3. Calculam-se os nets dos neurônios da camada oculta, para cada j ε(1,l)
		netsNeuroniosCamadaOculta(&oculta[0], b);

	//	4. Aplica a função de transferência para obter as saídas ij da camada oculta[0].
		transferenciaCamadaOculta(&oculta[0]);

	//	5. Calcula os nets dos neurônios da camada de saída, para cada k ε(1,M)
		netsNeuroniosCamadaSaida(&saida, oculta[0]);

	//	6. Calcula as saídas Ok dos neurônios da camada de saída.
		saidasONeuroniosCamadaSaida(&saida);

	//	7. Calcula os erros para os neurônios da camada de saída \
		No qual dk é o valor desejado na saida e fks’(netks) é a derivada da função de \
		transferência do neurônio k da camada de saída.
		errosNeuroniosCamadaSaida(&saida, saidaDesejada);

	//	8. Calcula-se os erros nos neurônios da camada oculta, para cada j ε(1,l)
		errosNeuroniosCamadaOculta(&oculta[0], saida);

	//	9. Atualiza-se os pesos da camada de saída.
		atualizacaoPesosCamada(&saida);

	//	10. Atualiza-se os pesos da camada oculta[0].
		for (int camada = 0; camada < numOcultas; ++camada) {
			atualizacaoPesosCamada(&oculta[0]);
		}

	//	11. Calcula-se o erro da rede
		ff.mlp = saida;
		erroRede(&ff);

		result = getPropagacao(saida.perceptron[0]);
		limite++;
	} while (abs(result - saidaDesejada) > 100);
	result = getPropagacao(saida.perceptron[1]);

	cout << result << "\t";

	cout << ff.erro << "(" << limite << ")" << endl;

	return result;
}

