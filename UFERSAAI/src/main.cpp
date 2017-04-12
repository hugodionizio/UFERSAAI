/*
 * src/main.cpp
 *
 *  Created on: 20/03/2017
 *      Author: hugo
 */

#include "UnidadeI/UnidadeI.h"
#include "UnidadeII/UnidadeII.h"
#include "UnidadeIII/UnidadeIII.h"

using namespace std;

int main(int argc, char **argv) {

	exemploUnidadeII(argc, argv);
	backpropagation(1.0, 0.0);

	return (0);
}
