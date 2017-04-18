/*
 * FeedForward.h
 *
 *  Created on: Apr 18, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEII_FEEDFORWARD_H_
#define UNIDADEII_FEEDFORWARD_H_

#include "RedeNeural.h"
#include "../Auxiliar.h"

typedef struct FeedForward {
	RedeNeural ff;
} FeedForward;

//	1. Inicialização dos pesos sinápticos com valores aleatórios.
void incializacaoPesosSinapticos(float *, int);

//	2. Aplica o vetor de entradas X1, X2, ... Xn.
void vetorEntradas(float *, float *, int);

//	3. Calculam-se os nets dos neurônios da camada oculta, para cada j ε(1,l)
void netsNeuroniosCamadaOculta(Camada *, float *, float *, float *, int);

//	4. Aplica a função de transferência para obter as saídas ij da camada oculta.
void transferenciaCamadaOculta(Camada *);

//	5. Calcula os nets dos neurônios da camada de saída, para cada k ε(1,M)
void netsNeuroniosCamadaSaida(Camada *, Camada);

//	6. Calcula as saídas Ok dos neurônios da camada de saída.
void saidasONeuroniosCamadaSaida(Camada *);

//	7. Calcula os erros para os neurônios da camada de saída \
No qual dk é o valor desejado na saida e fks’(netks) é a derivada da função de \
transferência do neurônio k da camada de saída.
void errosNeuroniosCamadaSaida(Camada);

//	8. Calcula-se os erros nos neurônios da camada oculta, para cada j ε(1,l)
void errosNeuroniosCamadaOculta(Camada);

//	9. Atualiza-se os pesos da camada de saída.
void atualizacaoPesosCamadaSaida(Camada);

//	10. Atualiza-se os pesos da camada oculta.
void atualizacaoPesosCamadaOculta(Camada);

//	11. Calcula-se o erro da rede
void erroRede(FeedForward);

float backpropagation(float *, int, float);

#endif /* UNIDADEII_FEEDFORWARD_H_ */
