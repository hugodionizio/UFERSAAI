/*
 * Perceptron.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "Perceptron.h"
#include "../Auxiliar.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void setCorrecaoEntrada(Perceptron *perceptron, int i) {
	float c = perceptron->taxaAprendizado;
	float g = perceptron->g;
	float xi = perceptron->neuronio.dentrite[i].entrada;

	perceptron->correcaoEntrada[i] = c * g * xi;
}

void setG(Perceptron *perceptron, float saidaDesejada, float saidaObtida) {
	perceptron->g = (saidaDesejada - saidaObtida)*dsigmoide(perceptron->neuronio.saida.propagacao);
}

void setGOculta(Perceptron *perceptron, Perceptron saida) {
	float somatorio = 0;

	for (int dentrites = 0; dentrites < perceptron->neuronio.numDentrites; ++dentrites) {
		somatorio+=saida.g*perceptron->neuronio.dentrite->peso;
	}
	perceptron->g = dsigmoide(perceptron->neuronio.saida.propagacao)*somatorio;
}

float getG(Perceptron perceptron) {
	return (perceptron.g);
}

void setNovoPeso(Perceptron *perceptron, int i) {
	float wi = perceptron->pesoAtual[i];
	float deltai = perceptron->correcaoEntrada[i];

	perceptron->novoPeso[i] = wi + deltai;
}

void inicializarPesosPerceptron(Perceptron *perceptron, int numEntradas) {
	float auxf = 0;

	perceptron->neuronio.numDentrites = numEntradas;
	perceptron->neuronio.dentrite = new Dentrite[numEntradas];

	cout << "1.1/11: Inicializando pesos sinápticos com valores aleatórios..."
				<< endl;
	for (int dentrite = 0; dentrite < numEntradas; ++dentrite) {
		perceptron->neuronio.dentrite[dentrite].peso = (float) (rand() % 10) / 10;
		auxf = perceptron->neuronio.dentrite[dentrite].peso;
		cout << auxf << " ";
	}
	cout << endl;
}

void atualizarPesosPerceptron(Perceptron *perceptron) {
	int numDentrites = perceptron->neuronio.numDentrites;

	float auxf;

	cout << "(9.1 ou 10.1)/11: Atualizando os pesos do perceptron... " << endl;

	for (int dentrite = 0; dentrite < numDentrites; ++dentrite) {
		perceptron->neuronio.dentrite[dentrite].peso += perceptron->g+perceptron->neuronio.dentrite[dentrite].entrada;
		auxf = perceptron->neuronio.dentrite[dentrite].peso;
		cout << auxf << " ";
	}
	cout << endl;
}

float getAtivacao(Perceptron perceptron){
	return (perceptron.neuronio.saida.ativacao);
}

float getPropagacao(Perceptron perceptron){
	return (perceptron.neuronio.saida.propagacao);
}
