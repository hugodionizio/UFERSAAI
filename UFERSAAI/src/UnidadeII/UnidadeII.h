/*
 * UnidadeII.h
 *
 *  Created on: 07/04/2017
 *      Author: hugo
 */

#ifndef UNIDADEII_H_
#define UNIDADEII_H_

// Redes Neurais Artificiais (RNA)

typedef struct Dentrite {
	float entrada;
	float peso;
} Dentrite;

typedef struct Axionio {
	float *ativacao;
	float propagacao;
} Axionio;

enum ModeloNeuronio {
	MCCULLOCHPITTS
};

enum TipoTreinamento {
	SUPERVISIONADO,
	NAOSUPERVISIONADO
};

typedef struct Neuronio {
	float valor;

	Dentrite *dentrite;
	Axionio saida;

	struct Neuronio *sinapse;
} Neuronio;

enum TipoConexaoNeuronio {
	EXCITATORIA,
	INIBITORIA
};

// Topologia
enum TipoCamada {
	// Uma camada
	PERCEPTRON,
	ADALINE, // ADAptive LINear Element

	// Multicamadas
	MLP, // Multi Layer Perceptron
	RBF // Radial Basis Function
};

enum TipoConexaoCamada {
	COMPLETAMENTECONECTADA,
	LOCALMENTECONECTADA,
	PARCIALMENTECONECTADA
};

enum TipoArranjoConexao {
	FEEDFORWARD,
	ARRANJORECORRENTE
};

enum Arquitetura {
	UMACAMADA,
	COMPETITIVA,
	REDERECORRENTE,
	MULTIPLASCAMADAS,
	HOPFIELD
};

enum FuncaoAtivacao {
	LINEAR,
	SIGMOIDE,

	// Em modelo Perceptron
	DEGRAULIMIAR,
	DEGRAUUNITARIO,

	TANGENTEHIPERBOLICA // Aprendizado Backpropagation
};

typedef struct Camada {
	int quantidade;
	int tipo;

	Neuronio *neuronio;
};

typedef struct RedeNeural {
	int tipoConexao;
	int conexoesExcitatorias;	// W(ik, t) > 0
	int conexoesInibitorias;	// W(ik, t) < 0
} RedeNeural;

//	Desempenho da Rede Neural
typedef struct Desempenho {
	char material[20];
	float velocidade;
	char tipoProcessamento[20];
	char armazenamento[20];
	int possibilidades;
	char controleProcessos[20];
} Desempenho;

//	Funcionalidades
//		Distinção de padrões visuais
//		Previsão de cotação de moedas

//	Características da Rede
//		Aprendizagem através de exemplos (adaptação)
//		Treinamento de modelo adaptativo
//		Generalização de informações incompletas
//		*Robustez
//		*Tolerância a falhas
//		*Paralelismo (Rapidez de processamento)
//		*Implantação rápida
//		Mapeamento de entrada-saída

//	Ciclo de Vida de uma Rede Neural
//		Definição da Rede Neural
//		Treinamento da Rede Neural
//		Utilização da Rede Neural
//		Manutenção da Rede Neural

//	Organização de Camadas
//		Camada de entrada
//			Conexões
//		Camadas intermediárias
//		Camada de saída

//	Conceitos
//		Aspectos do RNA
//			Arquitetura
//			Unidade de Processamento
void ativacao(Neuronio *, int); // E
void propagacao(Neuronio *, int); // T(E)
float processamento(Neuronio *, int); // y = T(E)

// 			Conexões
//				Tipos de conexões


//	Perceptron
typedef struct Perceptron {
	Neuronio neuronio;

	float *novoPeso;
	float *pesoAtual;
	float *correcaoEntrada;
	float taxaAprendizado;
	float g; // saída desejada - saída obtida
};

void setG(Perceptron *, float, float); // saída desejada - saída obtida
void setCorrecaoEntrada(Perceptron *, int);
void setNovoPeso(Perceptron *, int);

//	Processos de Aprendizagem
//		Adaptação dos parâmetros livres através do ambiente
void estimularRede(RedeNeural *);
void respostaEstimuloRede(RedeNeural *);
void atualizarRedeNeural(RedeNeural *);

//		Regras de Aprendizagem
float custo(RedeNeural);
float minimizar(RedeNeural);
void correcaoErro(RedeNeural *);

void hebbiano(RedeNeural *); // fortalecimento ou enfraquecimento de sinapase entre neurônios

void competitivo(RedeNeural *);

void boltzmann(RedeNeural *);

//		Paradigmas de Aprendizagem
enum Paradigma {
	SUPERVISIONADO,
	NAOSUPERVISIONADO,
	REFORCO
};

void reforcoPrimario(RedeNeural *);
void reforcoHeuristico(RedeNeural *);
void reforco(RedeNeural *);

//		Multi Layer Perceptron (MLP)
float backpropagation(float, float);

// 		Redes Neurais Não Supervisionadas
//			Sistemas Tutores Inteligentes

/*
 * **************
 * * Aplicações *
 * **************
 */
//	Transmissão de dados
//	Armazenamento de dados
//	Processamento de voz
//	Processamento de imagens
//	Sonar
//	Radar
//	Sismologia (exploração de petróleo)
//	Robótica
//	Aplicações Biomédicas

#endif /* UNIDADEII_H_ */
