#include "sensor.h"
#include <stdlib.h>

void gerarVetor(VetorSensores *v) {
    v->n = TAMANHO;
    for (int i = 0; i < TAMANHO; i++) {
        v->dados[i] = rand() % 1000; // cria os num aleatorios
    }
}

void copiarVetor(VetorSensores origem, VetorSensores *destino) { // duplica a mesma lista pra fazer os dois testes
    destino->n = origem.n;
    for (int i = 0; i < origem.n; i++) {
        destino->dados[i] = origem.dados[i];
    }
}

void insertionSort(VetorSensores *v) {

    for (int i = 1; i < v->n; i++) {
        int chave = v->dados[i]; // elemento a ser inserido
        int j = i - 1;

        
        while (j >= 0 && v->dados[j] > chave) {
            v->dados[j + 1] = v->dados[j]; // menores que a chave
            j = j - 1;
        }
        v->dados[j + 1] = chave; // chave vai pra posicao certa
    }
}

void shellSort(VetorSensores *v) {
    int n = v->n;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = v->dados[i];
            int j;

            for (j = i; j >= gap && v->dados[j - gap] > temp; j -= gap) {
                v->dados[j] = v->dados[j - gap];
            }
            v->dados[j] = temp;
        }
    }
}