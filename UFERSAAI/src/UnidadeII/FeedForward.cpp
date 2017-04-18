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

//	1. Inicialização dos pesos sinápticos com valores aleatórios.
void incializacaoPesosSinapticos(float *wPesos, int numEntradas) {
	float result = 0;

	cout << "1/11: Inicializando pesos sinápticos com valores aleatórios..."
			<< endl;
	float auxf = 0;
	for (int var = 0; var < 2; var++) {
		wPesos[var] = (float) (rand() % 10) / 10;
		auxf = wPesos[var];
		cout << auxf << " ";
	}
	cout << endl;
}

//	2. Aplica o vetor de entradas X1, X2, ... Xn.
void vetorEntradas(float *xEntradas, float *entradas, int numEntradas) {

	cout << "2/11: Aplicando o vetor de entradas X1, X2, ... Xn ..." << endl;
	for (int var = 0; var < numEntradas; var++) {
		xEntradas[var] = entradas[var];
	}
}

//	3. Calculam-se os nets dos neurônios da camada oculta, para cada j ε(1,l)
void netsNeuroniosCamadaOculta(Camada *oculta, float *wPesos, float *xEntradas,
		float *b, int numEntradas) {
	cout
			<< "3/11: Calculando os nets dos neurônios da camada oculta, para cada j ε(1,l) ... "
			<< endl;
	oculta->quantidadeNeuronios = numEntradas;
	oculta->neuronio = new Neuronio[numEntradas];

	for (int neuronio = 0; neuronio < numEntradas; ++neuronio) {
		oculta->neuronio[neuronio].valor = wPesos[neuronio]
				* xEntradas[neuronio] + b[numEntradas];
	}
}

//	4. Aplica a função de transferência para obter as saídas ij da camada oculta.
void transferenciaCamadaOculta(Camada *oculta) {
	cout
			<< "4/11: Aplicando a função de transferência para obter as saídas ij da camada oculta... "
			<< endl;
	int numNeuronios = oculta->quantidadeNeuronios;
	float i;

	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		i = sigmoide(oculta->neuronio[neuronio].valor);
		oculta->neuronio[neuronio].saida.propagacao = i;
		cout << i << " ";
	}
	cout << endl;
}

//	5. Calcula os nets dos neurônios da camada de saída, para cada k ε(1,M)
void netsNeuroniosCamadaSaida(Camada *saida, Camada oculta) {
	cout
			<< "5/11: Calculando os nets dos neurônios da camada de saída, para cada k ε(1,M)... "
			<< endl;
	int numEntradas = oculta.quantidadeNeuronios;
	saida->quantidadeNeuronios = numEntradas;
	saida->neuronio = new Neuronio[numEntradas];

	for (int neuronio = 0; neuronio < numEntradas; ++neuronio) {
		saida->neuronio[neuronio].valor = oculta.neuronio[neuronio].saida.propagacao;
	}
}

//	6. Calcula as saídas Ok dos neurônios da camada de saída.
void saidasONeuroniosCamadaSaida(Camada *saida) {
	cout << "6/11: Calculano as saídas Ok dos neurônios da camada de saída... "
			<< endl;
}

//	7. Calcula os erros para os neurônios da camada de saída \
No qual dk é o valor desejado na saida e fks’(netks) é a derivada da função de \
transferência do neurônio k da camada de saída.
void errosNeuroniosCamadaSaida(Camada saida) {
	cout
			<< "7/11: Calculando os erros para os neurônios da camada de saída ... "
			<< endl;
}

//	8. Calcula-se os erros nos neurônios da camada oculta, para cada j ε(1,l)
void errosNeuroniosCamadaOculta(Camada oculta) {
	cout
			<< "8/11: Calculando os erros nos neurônios da camada oculta, para cada j ε(1,l) ... "
			<< endl;
}

//	9. Atualiza-se os pesos da camada de saída.
void atualizacaoPesosCamadaSaida(Camada saida) {
	cout << "9/11: Atualizando os pesos da camada de saída... " << endl;
}

//	10. Atualiza-se os pesos da camada oculta.
void atualizacaoPesosCamadaOculta(Camada oculta) {
	cout << "10/11: Atualizando os pesos da camada oculta... " << endl;
}

//	11. Calcula-se o erro da rede
void erroRede(FeedForward ff) {
	cout << "11/11: Calculando o erro da rede... " << endl;
}

float backpropagation(float *entradas, int numEntradas, float saidaDesejada) {
//	time_t t;
//	srand(t*time(NULL));

	float result = 0;

	float A = 0, B = 0, *x = new float[numEntradas], y, expB;
	int i = 0, j = 0;
	float *w = new float[numEntradas], *b = new float[numEntradas], ypi,
			theta_j;
	bool propagation = true;
	FeedForward ff;
	Camada oculta, saida;

	A = 0;
	B = 0;

	// Inicializando b
	for (int iB = 0; iB < numEntradas; ++iB) {
		b[iB] = 0;
	}

	//	1. Inicialização dos pesos sinápticos com valores aleatórios.
	cout << "1/11: Inicialização dos pesos sinápticos com valores aleatórios..."
			<< endl;
	incializacaoPesosSinapticos(w, numEntradas);

	//	2. Aplica o vetor de entradas X1, X2, ... Xn.
	cout << "2/11: Aplicação do vetor de entradas X1, X2, ... Xn ..." << endl;
	vetorEntradas(x, entradas, numEntradas);

//	3. Calculam-se os nets dos neurônios da camada oculta, para cada j ε(1,l)
	cout
			<< "3/11: Cálculo dos nets dos neurônios da camada oculta, para cada j ε(1,l) ... "
			<< endl;
	netsNeuroniosCamadaOculta(&oculta, w, x, b, numEntradas);

//	4. Aplica a função de transferência para obter as saídas ij da camada oculta.
	cout
			<< "4/11: Aplicação da função de transferência para obter as saídas ij da camada oculta... "
			<< endl;
	transferenciaCamadaOculta(&oculta);

//	5. Calcula os nets dos neurônios da camada de saída, para cada k ε(1,M)
	cout
			<< "5/11: Cálculo dos nets dos neurônios da camada de saída, para cada k ε(1,M)... "
			<< endl;
	netsNeuroniosCamadaSaida(&saida, oculta);

//	6. Calcula as saídas Ok dos neurônios da camada de saída.
	cout << "6/11: Cálculo das saídas Ok dos neurônios da camada de saída... "
			<< endl;
	saidasONeuroniosCamadaSaida(&saida);

//	7. Calcula os erros para os neurônios da camada de saída \
	No qual dk é o valor desejado na saida e fks’(netks) é a derivada da função de \
	transferência do neurônio k da camada de saída.
	cout << "7/11: Cálculo dos erros para os neurônios da camada de saída ... "
			<< endl;
	errosNeuroniosCamadaSaida(saida);

//	8. Calcula-se os erros nos neurônios da camada oculta, para cada j ε(1,l)
	cout
			<< "8/11: Cálculo dos erros nos neurônios da camada oculta, para cada j ε(1,l) ... "
			<< endl;
	errosNeuroniosCamadaOculta(oculta);

//	9. Atualiza-se os pesos da camada de saída.
	cout << "9/11: Atualização dos pesos da camada de saída... " << endl;
	atualizacaoPesosCamadaSaida(saida);

//	10. Atualiza-se os pesos da camada oculta.
	cout << "10/11: Atualização dos pesos da camada oculta... " << endl;
	atualizacaoPesosCamadaOculta(oculta);

//	11. Calcula-se o erro da rede
	cout << "11/11: Cálculo do erro da rede... " << endl;
	erroRede(ff);

//	cout << "Informe o valor de A: ";
//	cin >> A;

//	cout << "\nInforme o valor de B: ";
//	cin >> B;

	ypi = 1;

	// y(pi) = 1/(1+exp(-sum(iw(ji)*y(pi)+theta(j))))
	i = 0;
	j = 0;
	while (i < 3) {
		while (j < 3) {
			int aux = w[i];
			expB += i * aux * ypi + theta_j;
			j++;
		}
		i++;
	}

	y = 1 / (1 + exp(expB));

	cout << y << endl;

	return result;
}

