/*
 * Cromossomo.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Cromossomo.h"

using namespace std;

void inicializarCromossomo(Cromossomo *cromossomo,
		DescritorPopulacao posCromossomo) {
	int numGenes = posCromossomo.totalGenes;
	float base, minimo;
	int potencia = 1;

	// Descritor do cromossomo
	cromossomo->numGenes = numGenes;
	cromossomo->limInferior = posCromossomo.limites[0];
	cromossomo->limSuperior = posCromossomo.limites[1];
	cromossomo->restricoes = new float;
	*cromossomo->restricoes = posCromossomo.restrtricao;

	// Atribuição de valor aleatório
	base = cromossomo->limSuperior*10/(2*cromossomo->restricoes[0]);
	potencia = (int)log10(base);
	cromossomo->valor = cromossomo->limInferior+(rand()%(int)(2*base))/pow(10,potencia);

	// Converter flutuante para binário (menor que 1) e guardar nos genes
	// 1 - Cálculo da mantissa
	cromossomo->genes = new Gene[numGenes];
	minimo = cromossomo->valor;
	for (int posGene = 0; posGene < numGenes; ++posGene) {
		if (posGene == 0) {
			if (minimo >= 0)
				inicializarGene(&cromossomo->genes[posGene], posCromossomo, 0);
			else
				inicializarGene(&cromossomo->genes[posGene], posCromossomo, 1);
		}
		else {
			inicializarGene(&cromossomo->genes[posGene], posCromossomo, (int)abs(minimo));
		}
		if (abs(minimo) > 1)
			minimo = (abs(minimo) - 1)*2;
		else
			minimo = abs(minimo)*2;
	}
}

float getCromossomoValor(Cromossomo cromossomo) {

	return (cromossomo.valor);
}

void imprimirCromossomo(Cromossomo cromossomo) {
	int numGenes = cromossomo.numGenes;

	cout << cromossomo.valor << "\t";

	/*
	cout << "[" << cromossomo.limInferior << ", "
			<< cromossomo.limSuperior << "] " << "e = "
			<< cromossomo.restricoes[0] << endl;

	cout << "||Número de genes: " << numGenes << endl;
	 * */

	for (int gene = 0; gene < numGenes; ++gene) {
		/*
		if (getNumCaracteristicas(cromossomo.genes[gene]) > 1) {
			cout << "||Gene " << (gene+1) << endl;
		}
		else if (gene == 0)
			cout << "|||";
		 * */
		imprimirGene(cromossomo.genes[gene]);
	}
	cout << "\t";
}
