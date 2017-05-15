/*
 * Populacao.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#include <iostream>
#include <cmath>

#include "Populacao.h"

using namespace std;

const char Cabecalho[] = "Indivíduo\tCromossomo\tBinário\tAptidão: f(x,y) = |abs(exp(-x) - y² + 1| + 10^(-4)\tProbabilidade";

void inicializarPopulacao(Populacao *populacao, DescritorPopulacao descritor) {
	int numIndividuos = descritor.tamPopulacao;

	populacao->numIndividuos = numIndividuos;
	populacao->individuo = new Individuo[numIndividuos];
	populacao->ultimoIndividuo = 0;

	cout << "Inicializando indivíduos..." << endl;
	for (int posIndividuo = 0; posIndividuo < numIndividuos; ++posIndividuo) {
		inicializarIndividuo(&populacao->individuo[posIndividuo], descritor, posIndividuo);
		populacao->ultimoIndividuo++;
	}
}

float minimizarProbabilidade(Populacao populacao, Individuo individuo) {
	return (calcularProbabilidade(populacao, individuo, -1));
}

float calcularProbabilidade(Populacao populacao, Individuo individuo, int potencia) {
	float soma = 0;

	for (int i = 0; i < populacao.numIndividuos; ++i) {
		soma += pow(aptidao(populacao.individuo[i]), potencia);
	}

	return (pow(aptidao(individuo), potencia)/soma);
}

void selecionarPais(Populacao *populacao) {
	float tmpMaior, tmpSegundoMaior, atual;

	cout << "Selecionando pais..." << endl;
	populacao->listaOrdenada = new Individuo[2];

	populacao->listaOrdenada[0] = populacao->individuo[0];
	populacao->listaOrdenada[1] = populacao->individuo[1];
	for (int i = 0; i < populacao->numIndividuos; ++i) {
		tmpMaior = minimizarProbabilidade(*populacao, (Individuo)populacao->listaOrdenada[0]);
		tmpSegundoMaior = minimizarProbabilidade(*populacao, (Individuo)populacao->listaOrdenada[1]);
		atual = minimizarProbabilidade(*populacao, (Individuo)populacao->individuo[i]);
		if (tmpMaior < atual) {
			populacao->listaOrdenada[1] = populacao->listaOrdenada[0];
			populacao->listaOrdenada[0] = populacao->individuo[i];
		} else if (tmpSegundoMaior < atual && atual < tmpMaior) {
			populacao->listaOrdenada[1] = populacao->individuo[i];
		}
//		if(i%(int)(populacao->numIndividuos/10) == 0)
//			cout << 100*((float)i/populacao->numIndividuos) << "% " << endl;
	}
}

void convergirGenetica(Populacao *populacao) {

	Individuo filho = convergirGeneticaIndividuo(populacao->listaOrdenada[0], populacao->listaOrdenada[1], populacao->ultimoIndividuo);

	cout << "Convergindo genética..." << endl;
	populacao->ultimoIndividuo++;

	cout << Cabecalho << endl;
	cout << "I";
	imprimirIndividuo(filho);
}

void liberarGeracao(Populacao *populacao) {
	int numIndividuos = populacao->numIndividuos;
	int menorIndice = getIndiceIndividuo(populacao->individuo[0]);
	int indice, i;

	cout << "Removendo membros mais velhos da população..." << endl;
	for (i = 0; i < numIndividuos; ++i) {
		indice = getIndiceIndividuo(populacao->individuo[i]);
		if(menorIndice > indice ) {
			menorIndice = indice;
		}
	}
	liberarIndividuo(&populacao->individuo[i]);
}

void avaliarNovosIndividuos(Populacao *populacao) {
	int numIndividuos = populacao->numIndividuos;

	cout << "Avaliando novos indivíduos..." << endl;
	for (int i = 0; i < numIndividuos; ++i) {
		if(getIndiceIndividuo(populacao->individuo[i]) < 0) {
			populacao->individuo[i] = populacao->novoIndividuo;
			i = numIndividuos;
		}
	}
}

bool tempoMelhorIndividuo(Populacao populacao, int tempo) {
	bool sucesso = false;

	int numIndividuos = populacao.numIndividuos;
	cout << "Verificando tempo e melhor indivíduo" << endl;
	for (int i = 0; i < numIndividuos; ++i) {
		if (aptidao(populacao.individuo[i]) <= getCriterio(populacao.individuo[i])) {
			sucesso = true;
			i = numIndividuos;
		}
	}

	if(tempo < 1)
		sucesso = true;

	return (sucesso);
}

void imprimirPopulacao(Populacao pop) {
	int numIndividuos = pop.numIndividuos;
	//cout << "Número de indivíduos: " << numIndividuos << endl;
	cout << Cabecalho << endl;

	for (int posIndividuo = 0; posIndividuo < numIndividuos; ++posIndividuo) {
		//cout << "Indivíduo " << (posIndividuo+1) << endl;
		if(getIndiceIndividuo(pop.individuo[posIndividuo]) >= 0) {
			cout << "I";
			imprimirIndividuo(pop.individuo[posIndividuo]);
			cout << 100*minimizarProbabilidade(pop, pop.individuo[posIndividuo]) << "%";
			cout << endl;
		}
	}
	cout << endl;
}

void imprimirMelhoresPais(Populacao pop) {
	cout << "Melhores pais: ";
	cout << "[I" << (getIndiceIndividuo(pop.listaOrdenada[0])+1) << "] ";
	cout << 100*minimizarProbabilidade(pop, pop.listaOrdenada[0]) << "%\t";
	cout << "[I" << (getIndiceIndividuo(pop.listaOrdenada[1])+1) << "] ";
	cout << 100*minimizarProbabilidade(pop, pop.listaOrdenada[1]) << "%" << endl;
	cout << endl;
}
