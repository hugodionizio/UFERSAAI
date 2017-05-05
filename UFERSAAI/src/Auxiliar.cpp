/*
 * Auxiliar.cpp
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include <cmath>

float **converterEstaticaDinamica(float **estatica, float **dinamica, int lin,
		int col) {
	float **pAux;
	float *pM;

	dinamica = new float*[lin];
	for (int i = 0; i < lin; i++) {
		dinamica[i] = new float[col];
		for (int j = 0; j < col; j++) {
			pAux = (float **) &estatica[i * lin - 1];
			pM = (float *) &pAux[j];
			dinamica[i][j] = *(pM);
		}
	}

	return (dinamica);
}

float sigmoide(float z) {
	return (1/(1+exp(-z)));
}

float dsigmoide(float z) {
	return (exp(-z)/powf((1+exp(-z)),2.0));
}
