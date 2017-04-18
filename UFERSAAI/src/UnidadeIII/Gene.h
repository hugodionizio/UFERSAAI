/*
 * Gene.h
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEIII_GENE_H_
#define UNIDADEIII_GENE_H_

typedef struct DescritorPopulacao {
	int tamPopulacao; // número total de indivíduos
	int totalCromossomos;
	int totalGenes;
	int totalCaracterisitcas;
	int *caracteristicas;
} DescritorPopulacao;

typedef struct Gene {
	int numCaracteristicas;
	int *caracteristicas;
} Gene;

void inicializarGene(Gene *, DescritorPopulacao);
void imprimirGene(Gene);

#endif /* UNIDADEIII_GENE_H_ */
