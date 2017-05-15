/*
 * UnidadeII.cpp
 *
 *  Created on: 07/04/2017
 *      Author: hugo
 */

#include <cstdlib>
#include <ctime>

#include <iostream>

using namespace std;

#include "UnidadeIII.h"

int mainUnidadeIII(int argc, char **argv) {
	AlgoritmosGeneticos ag;
	DescritorPopulacao dp{2, 2, 17, 1, nullptr, {-1, 1}, 0.0005};

	dp.caracteristicas = new int;
	*dp.caracteristicas = 1;

	inicializarAlgoritmoGenetico(&ag, dp);

	imprimirPopulacao(ag.populacao);

	return (0);
}
