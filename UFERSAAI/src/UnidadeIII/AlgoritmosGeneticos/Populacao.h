/*
 * Populacao.h
 *
 *  Created on: Apr 17, 2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef UNIDADEIII_POPULACAO_H_
#define UNIDADEIII_POPULACAO_H_

#include "Individuo.h"

typedef struct Populacao {
	int numIndividuos;
	Individuo *individuo;
	Individuo *listaOrdenada;

} Populacao;

void inicializarPopulacao(Populacao *, DescritorPopulacao);
float calcularProbabilidade(Populacao, Individuo, int);

// Seleção natural de Darwin (Heurística)
void selecionarIndividuoMaisAdaptado();

// c) Selecionar os pais para gerar novos cromosssomos
void selecionarPais(Populacao *);

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

void imprimirPopulacao(Populacao);
void imprimirMelhoresPais(Populacao);

#endif /* UNIDADEIII_POPULACAO_H_ */
