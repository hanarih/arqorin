#ifndef BUSCA_H
#define BUSCA_H

typedef int tipoDado;

#define TAM_MAX 100

typedef struct{
    tipoDado dados[TAM_MAX +1];
    int tamanho; // qnt de elementos armazenados
} Vetor;

// inicializar o vetor (construtor)
void criarVetor(Vetor *v);

int insereNoVetor(Vetor *v, tipoDado valor);

void imprimeVetor(const Vetor *v, void(*imprimeElemento)(tipoDado));

int buscaSequencial(const Vetor *v, tipoDado chave);

int buscaSequencialComParada(const Vetor *v, tipoDado chave);

int buscaSequencialComSentinela(const Vetor *v, tipoDado chave);

#endif

