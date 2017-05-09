/*
 * AgentesInteligentes.h
 *
 *  Created on: 04/05/2017
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef SRC_UNIDADEIII_AGENTESINTELIGENTES_AGENTESINTELIGENTES_H_
#define SRC_UNIDADEIII_AGENTESINTELIGENTES_AGENTESINTELIGENTES_H_

enum TipoAgente {
	DEFAULT_AGENTE,
	CONSTANTE
};

enum Classe {
	DEFAULT
};

typedef struct AgentesInteligentes {
	Classe classe;
	float medidaDesempenho;
	int dicernimento;

} AgentesInteligentes;

void inicializarAgentesInteligentes(AgentesInteligentes *);
void medirDesempenho(AgentesInteligentes *);
void discernir(AgentesInteligentes *);


#endif /* SRC_UNIDADEIII_AGENTESINTELIGENTES_AGENTESINTELIGENTES_H_ */
