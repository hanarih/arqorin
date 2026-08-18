#include <stdio.h>
#include "busca.h"


void imprimir(TipoDado valor){
    printf("%d", valor);
}

int main() {
    Vetor v;
    int resultado;

    criaVetor(&v);

    TipoDado valores[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(valores) / sizeof(valores[0]);

    int i;

    // inserir os valores no vetor

    for (i = 0; i < n; i++){
        insereNoVetor(&v, valores[i]);
    }

    //imprime o vetor

    printf("vetor: ");
    // imprimeVetor(&v, );

    //busca sequencial

    resultado = buscaSequencial(&v, 7);
    printf("busca sequencial, chave 7 posicao: %d\n", resultado);

    resultado = buscaSequencial(&v, 8);
    printf("busca sequencial, chave 8 posicao: %d\n", resultado);


    // busca sequencial com parada antecipada

    resultado = buscaSequencialComParada(&v, 9);
    printf("busca sequencial com parada antecipada, chave 9 posicao: %d\n", resultado);


    // busca sequencial com sentinela

    resultado = buscaSequencialComSentinela(&v, 17);
    printf("busca sequencial com parada antecipada, chave 17 posicao: %d\n", resultado);

    return 0;
}