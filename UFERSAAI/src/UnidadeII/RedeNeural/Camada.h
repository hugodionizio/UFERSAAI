/*
 * Camada.h
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEII_REDENEURAL_CAMADA_H_
#define UNIDADEII_REDENEURAL_CAMADA_H_

#include "Neuronio.h"

typedef enum TipoCamada {
	// Uma camada
	PERCEPTRON,
	ADALINE, // ADAptive LINear Element

	// Multicamadas
	MLPERCEPTRON, // Multi Layer Perceptron
	RBF // Radial Basis Function
} TipoCamada;

typedef enum TipoConexaoCamada {
	COMPLETAMENTECONECTADA, LOCALMENTECONECTADA, PARCIALMENTECONECTADA
} TipoConexaoCamada;

typedef enum AtributoCamada {
	CONTINUO, CATEGORICO
} AtributoCamada;

typedef struct Camada {
	TipoCamada tipo;
	TipoConexaoCamada tipoConexao;

	int quantidadeNeuronios;
	Neuronio *neuronio;
	AtributoCamada *tipoAtributo;
	char *atributo;
} Camada;

void inicializarCamada(Camada *, char *, int, float *);
void imprimirCamada(Camada);

//	Organização de Camadas
//		Camada de entrada
//			Conexões
//		Camadas intermediárias
//		Camada de saída

// 			Conexões
//				Tipos de conexões

#endif /* UNIDADEII_REDENEURAL_CAMADA_H_ */
