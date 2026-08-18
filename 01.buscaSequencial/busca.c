#include<stdio.h>
#include "busca.h"


void criaVetor(Vetor *v){
    v->tamanho = 0;
}

int insereNoVetor(Vetor *v, TipoDado valor){

    if (v->tamanho >= TAM_MAX){
        return 0;
    }

    v->dados[v->tamanho] = valor;
    v->tamanho++;
    
    return 1;
}


void imprimeVetor(const Vetor *v, void(*imprimeElemento)(TipoDado)){

    int i;
    for(i = 0; i <  v->tamanho; i++){
        imprimeElemento(v->dados[i]);
    }
    printf("\n");
}


// Busca sequencial basica
int buscaSequencial(const Vetor *v, TipoDado chave){

    int i;

    for(i = 0; i < v-> tamanho; i++){
        if(v->dados[i] == chave){
            return i;
        }
    }

    return -1;
}

// Busca sequencial com parada antecipada
int buscaSequencialComParada(const Vetor *v, TipoDado chave){

    int i;

    for(i = 0; i < v->tamanho; i++){
        if(v->dados[i] ==  chave){
            return i;
        } else if (v->dados[i] > chave){
            return -1; // elemento nao existe, pode parar
        } else {
            return -1;
        }
    }
}

// Busca sequencial com sentinela
int buscaSequencialComSentinela(const Vetor *v, TipoDado chave){
    
    // remove o const pra insetir a sentinela
    Vetor *vetor = (Vetor *)v;
    int n = v->tamanho;
    int i;

    v->dados[n] = chave; // insere a sentinela
    i = 0;

    while(vetor->dados[i] != chave){
        i = i + 1;
    }

    if(i < n){
        return i; // encontrou nos dados reais
    } else {
        return -1; // enocntrou só na sentinela, nao existe
    }
}
