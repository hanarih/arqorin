
#ifndef BUSCA_H
#define BUSCA_H

// tipo de dado armazenado no vetor
typedef int TipoDado;

// capacidade de armazenamento do vetor
#define TAM_MAX 100

// estrutura de dados para o vetor
typedef struct{
    TipoDado dados[TAM_MAX + 1];
    int tamanho; // qtde de elementos armazenados
} Vetor;


// inicializar o vetor (construtor)
void criaVetor(Vetor *v);

// insere um elemento ao final do vetor
int insereNoVetor(Vetor *v, TipoDado valor);

// imprime os elementos do vetor
void imprimeVetor(const Vetor *v, void(*imprimeElemento)(TipoDado));

// Busca sequencial basica
int buscaSequencial(const Vetor *v, TipoDado chave);

// Busca sequencial com parada antecipada
int buscaSequencialComParada(const Vetor *v, TipoDado chave);

// Busca sequencial com sentinela
int buscaSequencialComSentinela(const Vetor *v, TipoDado chave);

#endif // BUSCA_H

