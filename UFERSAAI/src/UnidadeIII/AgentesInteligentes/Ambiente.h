/*
 * Ambiente.h
 *
 *  Created on: 04/05/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef SRC_UNIDADEIII_AGENTESINTELIGENTES_AMBIENTE_H_
#define SRC_UNIDADEIII_AGENTESINTELIGENTES_AMBIENTE_H_

typedef struct Ambiente {
	float desempenho;
	int *ambiente;
	int *sensores;
	int *atuadores;

} Ambiente;

void inicializarAmbiente(Ambiente *);
void coletarInformacoes(Ambiente *);

#endif /* SRC_UNIDADEIII_AGENTESINTELIGENTES_AMBIENTE_H_ */
