#include <stdio.h>
#include "busca.h"

void criaVetor(Vetor *v){
    v -> tamanho = 0;
}

int insereNoVetor(Vetor *v, tipoDado valor){

    if (v -> tamanho >= TAM_MAX){
        return 0;
    }

    v -> dados[v -> tamanho] = valor;
    v -> tamanho++;

    return 1;
}

void imprimeVetor(const Vetor *v, void(*imprimeElemento)(tipoDado)){

    int i;

    for (i = 0; i < v -> tamanho; i++){
        imprimeElemento(v -> dados[i]);
    }
    printf("\n");
    
}