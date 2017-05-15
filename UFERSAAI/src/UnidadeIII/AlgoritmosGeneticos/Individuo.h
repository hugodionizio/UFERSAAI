/*
 * Individuo.h
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEIII_INDIVIDUO_H_
#define UNIDADEIII_INDIVIDUO_H_

#include "Cromossomo.h"

typedef struct Individuo {
	int numCromossomos;
	Cromossomo *cromossomo;
} Individuo;

// a) Inicializar a população de cromossosmos
void inicializarIndividuo(Individuo *, DescritorPopulacao);
void imprimirIndividuo(Individuo);

// b) Avaliar cada cromossomo na população
float avaliar(Individuo *);

float aptidao(Individuo); // fitness function (gene = função: x2-12x+40
//typedef aptidao

// Seleção natural de Darwin (Heurística)
void selecionarIndividuoMaisAdaptado();

// c) Selecionar os pais para gerar novos cromosssomos
void selecionarPais();

/*
 * d) Aplicar os operadores de recombinação e mutação a estes pais
 *    de forma a gerar os indivíduos da nova geração
 * */
void convergirGenetica();

/*
 * e) Apagar membros mais velhos da população
 *
 * */

/*
 * f) Avaliar todos os novos cromossomos e inserir-los na população
 *
 * */

/*
 * g) Se o tempo acabou ou o melhor cromossomo satisfaz os requerimentos
 * 	  e desempenho, retorna-o. Caso contrário, volta para o passo c)
 * */

#endif /* UNIDADEIII_INDIVIDUO_H_ */
