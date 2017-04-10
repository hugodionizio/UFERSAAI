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
	float *ativacao;
	float propagacao;
} Axionio;

enum ModeloNeuronio {
	MCCULLOCHPITTS
};

typedef struct Neuronio {
	float valor;

	Dentrite *dentrite;
	Axionio saida;

	struct Neuronio *sinapse;
} Neuronio;

enum TipoConexaoNeuronio {
	EXCITATORIA,
	INIBITORIA
};

//	Conceitos
//		Aspectos do RNA
//			Arquitetura
//			Unidade de Processamento
void ativacao(Neuronio *, int); // E
void propagacao(Neuronio *, int); // T(E)
float processamento(Neuronio *, int); // y = T(E)

void inicializarNeuronio(Neuronio *, float);

#endif /* UNIDADEII_NEURONIO_H_ */
