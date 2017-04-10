/*
 * Camada.h
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEII_CAMADA_H_
#define UNIDADEII_CAMADA_H_

#include "Neuronio.h"

enum TipoCamada {
	// Uma camada
	PERCEPTRON,
	ADALINE, // ADAptive LINear Element

	// Multicamadas
	MLP, // Multi Layer Perceptron
	RBF // Radial Basis Function
};

enum TipoConexaoCamada {
	COMPLETAMENTECONECTADA,
	LOCALMENTECONECTADA,
	PARCIALMENTECONECTADA
};

enum atributoCamada {
	CONTINUO,
	CATEGORICO
};

typedef struct Camada {
	int tipoCamada;

	int quantidadeNeuronios;
	Neuronio *neuronio;
	int *tipoAtributo;
} Camada;

void inicializarCamada(Camada *, int, float *);

//	Organização de Camadas
//		Camada de entrada
//			Conexões
//		Camadas intermediárias
//		Camada de saída

// 			Conexões
//				Tipos de conexões

#endif /* UNIDADEII_CAMADA_H_ */
