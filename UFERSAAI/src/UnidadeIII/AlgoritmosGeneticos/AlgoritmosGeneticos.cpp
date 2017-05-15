/*
 * AlgoritmosGeneticos.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "AlgoritmosGeneticos.h"

using namespace std;

void inicializarAlgoritmoGenetico(AlgoritmosGeneticos *algoritmosGeneticos, DescritorPopulacao descritor) {
	Populacao *diversidade;
	Populacao pop;

	srand(time(NULL));
	cout << "Algoritmos Genéticos" << endl;
	cout << "Incializando população..." << endl;
	inicializarPopulacao(&algoritmosGeneticos->populacao, descritor);
}

int mainAlgoritmosGeneticos(int argc, char **argv) {
	AlgoritmosGeneticos ag;
	DescritorPopulacao dp{4, 2, 17, 1, nullptr, {-1, 1}, 0.0005};
	int tempo = 10;

	dp.caracteristicas = new int;
	*dp.caracteristicas = 1;

	cout << "\nUnidade III - ";
	inicializarAlgoritmoGenetico(&ag, dp);

	imprimirPopulacao(ag.populacao);

	do {
		selecionarPais(&ag.populacao);
		imprimirMelhoresPais(ag.populacao);

		convergirGenetica(&ag.populacao);

		liberarGeracao(&ag.populacao);
		imprimirPopulacao(ag.populacao);

		avaliarNovosIndividuos(&ag.populacao);
		imprimirPopulacao(ag.populacao);

		tempo--;
	} while(!tempoMelhorIndividuo(ag.populacao, tempo));



	return (0);
}
