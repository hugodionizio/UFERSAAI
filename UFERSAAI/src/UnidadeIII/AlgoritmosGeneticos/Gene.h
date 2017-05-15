/*
 * Gene.h
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEIII_GENE_H_
#define UNIDADEIII_GENE_H_

enum Caracteristicas {
	CARACTERISTICAUNICA,
	VARIASCARACTERISTICAS
};

typedef struct DescritorPopulacao {
	int tamPopulacao; // número total de indivíduos
	int totalCromossomos;
	int totalGenes;
	int totalCaracterisitcas;
	int *caracteristicas;

	int limites[2];
	float restrtricao;
} DescritorPopulacao;

typedef struct Gene {
	int numCaracteristicas;
	int *caracteristicas;

	bool bit;
} Gene;

void inicializarGene(Gene *, DescritorPopulacao, int);
int getNumCaracteristicas(Gene);
int getCaracteristica(Gene, int);
void imprimirGene(Gene);

int mutacao(Gene *);

#endif /* UNIDADEIII_GENE_H_ */
