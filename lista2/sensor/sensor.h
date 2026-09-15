#ifndef VETOR_SENSORES_H
#define VETOR_SENSORES_H

#define TAMANHO 1000

typedef struct {
    int dados[TAMANHO];
    int n;
} VetorSensores;

void gerarVetor(VetorSensores *v);
void copiarVetor(VetorSensores origem, VetorSensores *destino);
void insertionSort(VetorSensores *v);
void shellSort(VetorSensores *v);

#endif