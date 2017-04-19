/*
 * RedeNeural.h
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEII_REDENEURAL_H_
#define UNIDADEII_REDENEURAL_H_

#include "Camada.h"

// Redes Neurais Artificiais (RNA)
enum TipoTreinamento {
	TREINAMSUPERVISIONADO, TREINAMNAOSUPERVISIONADO
};

// Topologia
enum TipoArranjoConexao {
	FEEDFORWARD, ARRANJORECORRENTE
};

enum Arquitetura {
	UMACAMADA, COMPETITIVA, REDERECORRENTE, MULTIPLASCAMADAS, HOPFIELD
};

enum TipoProblema {
	CLASSIFICACAO = 3, RECONHECIMENTO = 3
};

typedef struct RedeNeural {
	int tipoConexao;
	int conexoesExcitatorias;	// W(ik, t) > 0
	int conexoesInibitorias;	// W(ik, t) < 0

	int quantidadeCamadas;
	Camada *camada;
} RedeNeural;

void inicializarRede(RedeNeural *, int, float **, int, char **);
void imprimirRedeNeural(RedeNeural);

//	Desempenho da Rede Neural
typedef struct Desempenho {
	char material[20];
	float velocidade;
	char tipoProcessamento[20];
	char armazenamento[20];
	int possibilidades;
	char controleProcessos[20];
} Desempenho;

//	Funcionalidades
//		Distinção de padrões visuais
//		Previsão de cotação de moedas

//	Características da Rede
//		Aprendizagem através de exemplos (adaptação)
//		Treinamento de modelo adaptativo
//		Generalização de informações incompletas
//		*Robustez
//		*Tolerância a falhas
//		*Paralelismo (Rapidez de processamento)
//		*Implantação rápida
//		Mapeamento de entrada-saída

//	Ciclo de Vida de uma Rede Neural
//		Definição da Rede Neural
//		Treinamento da Rede Neural
//		Utilização da Rede Neural
//		Manutenção da Rede Neural

#endif /* UNIDADEII_REDENEURAL_H_ */
