/*
 * Neuronio.h
 *
 *  Created on: 09/04/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEII_NEURONIO_H_
#define UNIDADEII_NEURONIO_H_

typedef struct Dentrite {
	float entrada;
	float peso;
} Dentrite;

typedef struct Axionio {
	float ativacao;
	float propagacao;
} Axionio;

enum ModeloNeuronio {
	MCCULLOCHPITTS
};

enum FuncaoAtivacao {
	LINEAR, SIGMOIDE,

	// Em modelo Perceptron
	DEGRAULIMIAR,
	DEGRAUUNITARIO,

	TANGENTEHIPERBOLICA, // Aprendizado Backpropagation
	OVERFLOWATIVACAO
};

typedef struct Neuronio {
	float valor;

	Dentrite *dentrite;
	Axionio saida;

	struct Neuronio *sinapse;
} Neuronio;

enum TipoConexaoNeuronio {
	EXCITATORIA, INIBITORIA
};

// Conversão de matrizes
float **converterEstaticaDinamica(float **, float **, int, int);
void imprimirPesosRede(float **, int, int, bool);

//	Conceitos
//		Aspectos do RNA
//			Arquitetura
//			Unidade de Processamento
void ativacao(Neuronio *, int, float *); // E
void propagacao(Neuronio *, FuncaoAtivacao); // T(E)
float processamento(Neuronio *, int, float *); // y = T(E)

void inicializarNeuronio(Neuronio *, float);
void imprimirNeuronio(Neuronio);

#endif /* UNIDADEII_NEURONIO_H_ */
