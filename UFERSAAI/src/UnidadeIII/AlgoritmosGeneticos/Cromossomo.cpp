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
	float base, parteReal;
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

	cout << "Inicializando genes..." << endl;
	// Converter flutuante para binário (menor que 1) e guardar nos genes
	// 1 - Cálculo da mantissa
	cromossomo->genes = new Gene[numGenes];
	parteReal = cromossomo->valor;
	for (int posGene = 0; posGene < numGenes; ++posGene) {
		if (posGene == 0) {
			if (parteReal >= 0)
				inicializarGene(&cromossomo->genes[posGene], posCromossomo, 0);
			else
				inicializarGene(&cromossomo->genes[posGene], posCromossomo, 1);
		}
		else {
			inicializarGene(&cromossomo->genes[posGene], posCromossomo, (int)abs(parteReal));
		}
		if (abs(parteReal) > 1)
			parteReal = (abs(parteReal) - 1)*2;
		else
			parteReal = abs(parteReal)*2;
	}
}

Cromossomo convergirGeneticaCromossomo(Cromossomo cromossomoA, Cromossomo cromossomoB) {
	Cromossomo combinado;
	int numGenes = cromossomoA.numGenes;
	int caracteristica, mutacoes, positivo = 1;
	DescritorPopulacao dp;

	combinado.numGenes = numGenes;
	combinado.genes = new Gene[numGenes];
	combinado.limInferior = cromossomoA.limInferior;
	combinado.limSuperior = cromossomoA.limSuperior;
	combinado.restricoes = cromossomoA.restricoes;
	combinado.valor = 0.0f;

	dp.totalCaracterisitcas = getNumCaracteristicas(cromossomoA.genes[0]);
	mutacoes = (int)((float)numGenes*0.9);

	for (int i = 0; i < numGenes; ++i) {
		caracteristica = getCaracteristica(cromossomoA.genes[i], 0) | getCaracteristica(cromossomoB.genes[i], 0);
		inicializarGene(&combinado.genes[i], dp, caracteristica);
		if (mutacoes > 0) {
			mutacoes -= mutacao(&combinado.genes[i]);
		}
		//filho.cromossomo->valor += filho.cromossomo[i].valor*pow(2, numCromossomos - i);
		if(i > 0) {
			combinado.valor += caracteristica*pow(2, numGenes - i);
		}
		else {
			positivo -= caracteristica;
		}
	}
	combinado.valor*=positivo;

	return (combinado);
}

float getCromossomoValor(Cromossomo cromossomo) {

	return (cromossomo.valor);
}

float getRestricaoCromossomo(Cromossomo cromossomo, int pos) {
	return (cromossomo.restricoes[pos]);
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
