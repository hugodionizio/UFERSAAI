/*
 * UnidadeII.cpp
 *
 *  Created on: 07/04/2017
 *      Author: hugo
 */

#include <iostream>;
#include <cmath>;

using namespace std;

float backpropagation(float a, float b) {
	float result = 0;

	float A = 0, B = 0, y, expB;
	float i, j;
	float wji, ypi, theta_j;
	bool propagation = true;


	cout << "Informe o valor de A: ";
	cin >> A;

	cout << "\nInforme o valor de B: ";
	cin >> B;

	wji = 1;
	ypi = A*B;

	// y(pi) = 1/(1+exp(-sum(iw(ji)*y(pi)+theta(j))))
	while (propagation) {
		expB+=  i*wji*ypi+theta_j;
		propagation = false;
	}

	y = 1/(1+exp((double)expB));

	cout << y << endl;

	return result;
}

