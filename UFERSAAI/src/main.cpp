/*
 * src/main.cpp
 *
 *  Created on: 20/03/2017
 *      Author: hugo
 */

#include "UnidadeI/UnidadeI.h"
#include "UnidadeII/UnidadeII.h"
#include "UnidadeIII/UnidadeIII.h"

#include <cstdlib>
#include <ctime>


using namespace std;

int main(int argc, char **argv) {
	time_t t;
	srand(t*time(NULL));

	//exemploUnidadeII(argc, argv);
	float *entradas = new float[2]{0.0, 0.0};
	backpropagation(entradas, 2);
	delete [] entradas;

	entradas = new float[2]{0.0, 1.0};
	backpropagation(entradas, 2);
	delete [] entradas;

	entradas = new float[2]{1.0, 0.0};
	backpropagation(entradas, 2);
	delete [] entradas;

	entradas = new float[2]{1.0, 1.0};
	backpropagation(entradas, 2);
	delete [] entradas;

	return (0);
}
