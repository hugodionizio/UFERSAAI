/*
 * UnidadeII.h
 *
 *  Created on: 07/04/2017
 *      Author: hugo
 */

#ifndef UNIDADEII_H_
#define UNIDADEII_H_

#include "Neuronio.h"
#include "Camada.h"
#include "RedeNeural.h"

// saída desejada - saída obtida
//	Processos de Aprendizagem
//		Adaptação dos parâmetros livres através do ambiente
void estimularRede(RedeNeural *);
void respostaEstimuloRede(RedeNeural *);
void atualizarRedeNeural(RedeNeural *);

//		Regras de Aprendizagem
float custo(RedeNeural);
float minimizar(RedeNeural);
void correcaoErro(RedeNeural *);

void hebbiano(RedeNeural *); // fortalecimento ou enfraquecimento de sinapase entre neurônios

void competitivo(RedeNeural *);

void boltzmann(RedeNeural *);

//		Paradigmas de Aprendizagem
enum Paradigma {
	SUPERVISIONADO,
	NAOSUPERVISIONADO,
	REFORCO
};

//			Reforço
void reforcoPrimario(RedeNeural *);
void reforcoHeuristico(RedeNeural *);
void reforco(RedeNeural *);

//		Supervisionada
//			Percepetron de Múltiplas Camadas - Multi Layer Perceptron (MLP)
//			Funções de Base Radial (RBF)
//			Máquina de Vetor de Suporte (SVM)
//			Máquinas de Comitê
//			Redes Recorrentes

//		Não Supervisionada
//			Redes Competitivas
//			Redes de Kohonen - SOM
float backpropagation(float *, int);

// 		Redes Neurais Não Supervisionadas
//			Sistemas Tutores Inteligentes

//	Considerações de Projeto


/*
 * **************
 * * Aplicações *
 * **************
 */
//	Transmissão de dados
//	Armazenamento de dados
//	Processamento de voz
//	Processamento de imagens
//	Sonar
//	Radar
//	Sismologia (exploração de petróleo)
//	Robótica
//	Aplicações Biomédicas

int exemploUnidadeII(int, char **);

#endif /* UNIDADEII_H_ */
