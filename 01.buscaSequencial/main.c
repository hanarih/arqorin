#include <stdio.h>
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
    for(i = 0; i < v->tamanho; i++){
        imprimeElemento(v->dados[i]);
    }
    printf("\n"); 
}

int buscaSequencial(const Vetor *v, TipoDado chave){
    int i;
    for(i = 0; i < v->tamanho; i++){
        if(v->dados[i] == chave){
            return i;
        }
    }
    return -1;
}

int buscaSequencialComParada(const Vetor *v, TipoDado chave){
    int i;
    for(i = 0; i < v->tamanho; i++){
        if(v->dados[i] == chave){
            return i;
        } else if (v->dados[i] > chave){
            return -1; // ja passou o valor, elemento nao existe no vetor
        }
    }
    return -1;
}

int buscaSequencialComSentinela(const Vetor *v, TipoDado chave){
    Vetor *vetor = (Vetor *)v;
    int n = v->tamanho;
    int i;

    vetor->dados[n] = chave; // coloca o sentinela na posicao extra
    i = 0;

    while(vetor->dados[i] != chave){
        i = i + 1;
    }

    if(i < n){
        return i; 
    } else {
        return -1;
    }
}

void imprimeInt(TipoDado valor) {
    printf("%d ", valor);
}

int main() {
    Vetor v;
    criaVetor(&v);

    // Insere elemt ordenados 
    insereNoVetor(&v, 10);
    insereNoVetor(&v, 20);
    insereNoVetor(&v, 30);
    insereNoVetor(&v, 40);
    insereNoVetor(&v, 50);

    printf("Vetor atual: ");
    imprimeVetor(&v, imprimeInt);

    int chave1 = 30;
    int chave2 = 25;

    printf("\n--- Busca Sequencial Basica ---\n");
    printf("Chave %d encontrada na posicao: %d\n", chave1, buscaSequencial(&v, chave1));
    printf("Chave %d encontrada na posicao: %d\n", chave2, buscaSequencial(&v, chave2));

    printf("\n--- Busca Sequencial com Parada ---\n");
    printf("Chave %d encontrada na posicao: %d\n", chave1, buscaSequencialComParada(&v, chave1));
    printf("Chave %d encontrada na posicao: %d\n", chave2, buscaSequencialComParada(&v, chave2));

    printf("\n--- Busca Sequencial com Sentinela ---\n");
    printf("Chave %d encontrada na posicao: %d\n", chave1, buscaSequencialComSentinela(&v, chave1));
    printf("Chave %d encontrada na posicao: %d\n", chave2, buscaSequencialComSentinela(&v, chave2));

    return 0;
}