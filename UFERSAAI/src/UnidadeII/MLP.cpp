/*
 * MLP.cpp
 *
 *  Created on: Apr 21, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "MLP.h"

#include <iostream>

using namespace std;

//	1. Inicialização dos pesos sinápticos com valores aleatórios.
void incializacaoPesosSinapticos(MLP *camada, int numEntradas) {

	cout << "1/11: Inicializando pesos sinápticos com valores aleatórios..."
			<< endl;

	camada->camada.quantidadeNeuronios = numEntradas;
	camada->perceptron = new Perceptron[numEntradas];

	for (int var = 0; var < numEntradas; var++) {
		inicializarPesosPerceptron(&camada->perceptron[var], numEntradas);
	}
}

//	2. Aplica o vetor de entradas X1, X2, ... Xn.
void vetorEntradas(MLP *atual, MLP *proxima, float *entradas) {

	cout << "2/11: Aplicando o vetor de entradas X1, X2, ... Xn ..." << endl;
	int numNeuronios = atual->camada.quantidadeNeuronios;

	for (int var = 0; var < numNeuronios; var++) {
		atual->perceptron[var].neuronio.saida.propagacao = entradas[var];
		cout << "Perceptron" << var << ":" << endl;
		for (int j = 0; j < numNeuronios; ++j) {
			proxima->perceptron[var].neuronio.dentrite[j].entrada = entradas[var];
			cout << proxima->perceptron[var].neuronio.dentrite[j].entrada << " ";
		}
		cout << endl;
	}
}

//	3. Calculam-se os nets dos neurônios da camada oculta, para cada j ε(1,l)
void netsNeuroniosCamadaOculta(MLP *oculta, float *b) {
	cout
			<< "3/11: Calculando os nets dos neurônios da camada oculta, para cada j ε(1,l) ... "
			<< endl;
	int numNeuronios = oculta->camada.quantidadeNeuronios;

	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		ativacao(&oculta->perceptron[neuronio].neuronio, numNeuronios, b);
	}
}

//	4. Aplica a função de transferência para obter as saídas ij da camada oculta.
void transferenciaCamadaOculta(MLP *oculta) {
	cout
			<< "4/11: Aplicando a função de transferência para obter as saídas ij da camada oculta... "
			<< endl;
	int numNeuronios = oculta->camada.quantidadeNeuronios;
	float i;

	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		propagacao(&oculta->perceptron[neuronio].neuronio, SIGMOIDE);
		i = getPropagacao(oculta->perceptron[neuronio]);
		cout << i << " " << endl;
	}
}

//	5. Calcula os nets dos neurônios da camada de saída, para cada k ε(1,M)
void netsNeuroniosCamadaSaida(MLP *saida, MLP oculta) {
	cout
			<< "5/11: Calculando os nets dos neurônios da camada de saída, para cada k ε(1,M)... "
			<< endl;
	int numEntradas = oculta.camada.quantidadeNeuronios;

	for (int neuronio = 0; neuronio < numEntradas; ++neuronio) {
		saida->perceptron[neuronio].neuronio.saida.ativacao = oculta.perceptron[neuronio].neuronio.saida.propagacao;
		cout << getAtivacao(saida->perceptron[neuronio]) << " ";
	}
	cout << endl;
}

//	6. Calcula as saídas Ok dos neurônios da camada de saída.
void saidasONeuroniosCamadaSaida(MLP *saida) {
	 cout << "6/11: Calculano as saídas Ok dos neurônios da camada de saída... "
			<< endl;
	int numNeuronios = saida->camada.quantidadeNeuronios;
	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		saida->perceptron[neuronio].neuronio.saida.propagacao = saida->perceptron[neuronio].neuronio.saida.ativacao;
		cout << getPropagacao(saida->perceptron[neuronio]) << " ";
	}
	cout << endl;
}

/*
 * 7. Calcula os erros para os neurônios da camada de saída
 *	  No qual dk é o valor desejado na saida e fks’(netks) é a derivada da função de
 *	  transferência do neurônio k da camada de saída.
 */
void errosNeuroniosCamadaSaida(MLP *saida, float saidaDesejada) {
	cout
			<< "7/11: Calculando os erros para os neurônios da camada de saída... "
			<< endl;
	int numNeuronios = saida->camada.quantidadeNeuronios;

	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		setG(&saida->perceptron[neuronio], saidaDesejada, getPropagacao(saida->perceptron[neuronio]));
		 cout << getG(saida->perceptron[neuronio]) << " ";
	}
	 cout << endl;
}

//	8. Calcula-se os erros nos neurônios da camada oculta, para cada j ε(1,l)
void errosNeuroniosCamadaOculta(MLP *oculta, MLP saida) {
	cout
			<< "8/11: Calculando os erros para os neurônios da camada oculta... "
			<< endl;
	int numNeuronios = oculta->camada.quantidadeNeuronios;

	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		setGOculta(&oculta->perceptron[neuronio], saida.perceptron[neuronio]);
		 cout << getG(oculta->perceptron[neuronio]) << " ";
	}
	 cout << endl;
}

//	(9 a 10). Atualiza-se os pesos da camada.
void atualizacaoPesosCamada(MLP *camada) {
	cout << "(9 a 10)/11: Atualizando os pesos da camada... " << endl;
	int numNeuronios = camada->camada.quantidadeNeuronios;

	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		atualizarPesosPerceptron(&camada->perceptron[neuronio]);
	}
}
