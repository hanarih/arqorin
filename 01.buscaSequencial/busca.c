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


int buscaSequencial(const Vetor *v, TipoDado chave){

    int i;

    for(i = 0; i < v-> tamanho; i++){
        if(v->dados[i] == chave){
            return i;
        }
    }

    return -1;
}

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

int buscaSequencialComSentinela(Vetor *v, TipoDado chave){
    
    int i;

    v->dados[v->tamanho] = chave; // insere a sentinela
   
    while(v->dados[i] != chave){
        i = i + 1;
    }

    if(i < v->tamanho){
        return i; // encontrou 
    } else {
        return -1; // enocntrou só na sentinela, nao existe
    }
}
