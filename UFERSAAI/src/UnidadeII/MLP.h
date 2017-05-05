/*
 * MLP.h
 *
 *  Created on: Apr 19, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEII_MLP_H_
#define UNIDADEII_MLP_H_

#include "Perceptron.h"
#include "RedeNeural/Camada.h"

typedef struct MLP {
	Camada camada;
	bool nivelada;

	Perceptron *perceptron;
} MLP;

//	1. Inicialização dos pesos sinápticos com valores aleatórios.
void incializacaoPesosSinapticos(MLP *, int);

//	2. Aplica o vetor de entradas X1, X2, ... Xn.
void vetorEntradas(MLP *, MLP *, float *);

//	3. Calculam-se os nets dos neurônios da camada oculta, para cada j ε(1,l)
void netsNeuroniosCamadaOculta(MLP *, float *);

//	4. Aplica a função de transferência para obter as saídas ij da camada oculta.
void transferenciaCamadaOculta(MLP *);

//	5. Calcula os nets dos neurônios da camada de saída, para cada k ε(1,M)
void netsNeuroniosCamadaSaida(MLP *, MLP);

//	6. Calcula as saídas Ok dos neurônios da camada de saída.
void saidasONeuroniosCamadaSaida(MLP *);

/*
 * 7. Calcula os erros para os neurônios da camada de saída
 *	  No qual dk é o valor desejado na saida e fks’(netks) é a derivada da função de
 *	  transferência do neurônio k da camada de saída.
 */
void errosNeuroniosCamadaSaida(MLP *, float);

//	8. Calcula-se os erros nos neurônios da camada oculta, para cada j ε(1,l)
void errosNeuroniosCamadaOculta(MLP *, MLP);

//	(9 a 10). Atualiza-se os pesos da camada de saída.
void atualizacaoPesosCamada(MLP *);

#endif /* UNIDADEII_MLP_H_ */

