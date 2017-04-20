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
void incializacaoPesosSinapticos(MLP *camada, int numEntradas) {
	float result = 0;

	// cout << "1/11: Inicializando pesos sinápticos com valores aleatórios..."
	//		<< endl;
	float auxf = 0;
	camada->camada.quantidadeNeuronios = numEntradas;
	camada->perceptron = new Perceptron[numEntradas];
	
	for (int var = 0; var < numEntradas; var++) {
		camada->perceptron[var].neuronio.dentrite = new Dentrite[numEntradas];
		for (int dentrite = 0; dentrite < numEntradas; ++dentrite) {
			camada->perceptron[var].neuronio.dentrite[dentrite].peso = (float) (rand() % 10) / 10;
			auxf = camada->perceptron[var].neuronio.dentrite[dentrite].peso;
			// cout << auxf << " ";
		}
		// cout << endl;
	}
}

//	2. Aplica o vetor de entradas X1, X2, ... Xn.
void vetorEntradas(MLP *atual, MLP *proxima, float *entradas) {

	// cout << "2/11: Aplicando o vetor de entradas X1, X2, ... Xn ..." << endl;
	int numNeuronios = atual->camada.quantidadeNeuronios;
	
	for (int var = 0; var < numNeuronios; var++) {
		atual->perceptron[var].neuronio.saida.propagacao = entradas[var];
		for (int j = 0; j < numNeuronios; ++j) {
			proxima->perceptron[var].neuronio.dentrite[j].entrada = entradas[var];
		}
	}
}

//	3. Calculam-se os nets dos neurônios da camada oculta, para cada j ε(1,l)
void netsNeuroniosCamadaOculta(MLP *oculta, float *b) {
//	cout
//			<< "3/11: Calculando os nets dos neurônios da camada oculta, para cada j ε(1,l) ... "
//			<< endl;
	int numNeuronios = oculta->camada.quantidadeNeuronios;

	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		ativacao(&oculta->perceptron[neuronio].neuronio, numNeuronios, b);
	}
}

//	4. Aplica a função de transferência para obter as saídas ij da camada oculta.
void transferenciaCamadaOculta(MLP *oculta) {
//	cout
//			<< "4/11: Aplicando a função de transferência para obter as saídas ij da camada oculta... "
//			<< endl;
	int numNeuronios = oculta->camada.quantidadeNeuronios;
	float i;

	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		propagacao(&oculta->perceptron[neuronio].neuronio, SIGMOIDE);
		i = oculta->perceptron[neuronio].neuronio.saida.propagacao;
		// cout << i << " ";
	}
	// cout << endl;
}

//	5. Calcula os nets dos neurônios da camada de saída, para cada k ε(1,M)
void netsNeuroniosCamadaSaida(MLP *saida, MLP oculta) {
//	cout
//			<< "5/11: Calculando os nets dos neurônios da camada de saída, para cada k ε(1,M)... "
//			<< endl;
	int numEntradas = oculta.camada.quantidadeNeuronios;

	for (int neuronio = 0; neuronio < numEntradas; ++neuronio) {
		saida->perceptron[neuronio].neuronio.saida.ativacao = oculta.perceptron[neuronio].neuronio.saida.propagacao;
	}
}

//	6. Calcula as saídas Ok dos neurônios da camada de saída.
void saidasONeuroniosCamadaSaida(MLP *saida) {
	// cout << "6/11: Calculano as saídas Ok dos neurônios da camada de saída... "
	//		<< endl;
	int numNeuronios = saida->camada.quantidadeNeuronios;
	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		saida->perceptron[neuronio].neuronio.saida.propagacao = saida->perceptron[neuronio].neuronio.saida.ativacao;
	}
}

//	7 a 8. Calcula os erros para os neurônios da camada \
No qual dk é o valor desejado na saida e fks’(netks) é a derivada da função de \
transferência do neurônio k da camada de saída.
void errosNeuroniosCamada(MLP *camada, float saidaDesejada) {
//	cout
//			<< "(7 a 8)/11: Calculando os erros para os neurônios da camada ... "
//			<< endl;
	int numNeuronios = camada->camada.quantidadeNeuronios;

	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		setG(&camada->perceptron[neuronio], saidaDesejada, camada->perceptron[neuronio].neuronio.saida.propagacao);
		// cout << getG(camada->perceptron[neuronio]) << " ";
		camada->perceptron[neuronio].taxaAprendizado++;
	}
	// cout << endl;
}

//	(9 a 10). Atualiza-se os pesos da camada.
void atualizacaoPesosCamada(MLP *camada) {
	// cout << "(9 a 10)/11: Atualizando os pesos da camada... " << endl;
	int numNeuronios = camada->camada.quantidadeNeuronios;

	float auxf = 0;
	for (int neuronio = 0; neuronio < numNeuronios; ++neuronio) {
		for (int dentrite = 0; dentrite < numNeuronios; ++dentrite) {
			camada->perceptron[neuronio].neuronio.dentrite[dentrite].peso = getG(camada->perceptron[neuronio])*(float) (rand() % 10) / 10;
			auxf = camada->perceptron[neuronio].neuronio.dentrite[dentrite].peso;
			// cout << auxf << " ";
		}
		// cout << endl;
	}
}

//	11. Calcula-se o erro da rede
void erroRede(FeedForward *ff) {
	// cout << "11/11: Calculando o erro da rede... " << endl;
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

	float A = 0, B = 0, *x = new float[numEntradas], y, expB;
	int i = 0, j = 0, iteracoes = 0;
	float *w = new float[numEntradas], *b = new float[numEntradas], ypi,
			theta_j;
	bool propagation = true;
	FeedForward ff;
	MLP entrada, oculta, saida;

	A = 0;
	B = 0;

	for (int entrada = 0; entrada < numEntradas; ++entrada) {
		cout << entradas[entrada] << "\t";
	}

	// Inicializando b
	for (int iB = 0; iB < numEntradas; ++iB) {
		b[iB] = 0;
	}

	//	1. Inicialização dos pesos sinápticos com valores aleatórios.
	// cout << "1/11: Inicialização dos pesos sinápticos com valores aleatórios..."
	//		<< endl;
	incializacaoPesosSinapticos(&entrada, numEntradas);
	incializacaoPesosSinapticos(&oculta, numEntradas);
	incializacaoPesosSinapticos(&saida, numEntradas);

	do {
		result = oculta.perceptron->neuronio.saida.propagacao;

		//	2. Aplica o vetor de entradas X1, X2, ... Xn.
		// cout << "2/11: Aplicação do vetor de entradas X1, X2, ... Xn ..." << endl;
		vetorEntradas(&entrada, &oculta, entradas);

	//	3. Calculam-se os nets dos neurônios da camada oculta, para cada j ε(1,l)
	//	cout
	//			<< "3/11: Cálculo dos nets dos neurônios da camada oculta, para cada j ε(1,l) ... "
	//		<< endl;
		netsNeuroniosCamadaOculta(&oculta, b);

	//	4. Aplica a função de transferência para obter as saídas ij da camada oculta.
	//	cout
	//				<< "4/11: Aplicação da função de transferência para obter as saídas ij da camada oculta... "
	//				<< endl;
		transferenciaCamadaOculta(&oculta);

	//	5. Calcula os nets dos neurônios da camada de saída, para cada k ε(1,M)
	//	cout
	//			<< "5/11: Cálculo dos nets dos neurônios da camada de saída, para cada k ε(1,M)... "
	//			<< endl;
		netsNeuroniosCamadaSaida(&saida, oculta);

	//	6. Calcula as saídas Ok dos neurônios da camada de saída.
		// cout << "6/11: Cálculo das saídas Ok dos neurônios da camada de saída... "
		//		<< endl;
		saidasONeuroniosCamadaSaida(&saida);

	//	7. Calcula os erros para os neurônios da camada de saída \
		No qual dk é o valor desejado na saida e fks’(netks) é a derivada da função de \
		transferência do neurônio k da camada de saída.
		// cout << "7/11: Cálculo dos erros para os neurônios da camada de saída ... "
		//		<< endl;
		errosNeuroniosCamada(&saida, saidaDesejada);

	//	8. Calcula-se os erros nos neurônios da camada oculta, para cada j ε(1,l)
		//	cout
		//		<< "8/11: Cálculo dos erros nos neurônios da camada oculta, para cada j ε(1,l) ... "
		//		<< endl;
		errosNeuroniosCamada(&oculta, saidaDesejada);

	//	9. Atualiza-se os pesos da camada de saída.
		// cout << "9/11: Atualização dos pesos da camada de saída... " << endl;
		atualizacaoPesosCamada(&saida);

	//	10. Atualiza-se os pesos da camada oculta.
		// cout << "10/11: Atualização dos pesos da camada oculta... " << endl;
		atualizacaoPesosCamada(&oculta);

	//	11. Calcula-se o erro da rede
		// cout << "11/11: Cálculo do erro da rede... " << endl;
		ff.mlp = saida;
		erroRede(&ff);

		if(getPropagacao(oculta.perceptron[0])==getPropagacao(oculta.perceptron[1])) {
			oculta.nivelada = true;
		}
		//iteracoes++;
	} while (ff.erro != saidaDesejada && result != getPropagacao(oculta.perceptron[0]) && oculta.nivelada);
	result = oculta.perceptron[1].neuronio.saida.propagacao;

	cout << round(result) << "\t";

	cout << oculta.perceptron[1].taxaAprendizado << endl;

	return result;
}

