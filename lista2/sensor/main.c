#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sensor.h"

int main() {

    VetorSensores original, v_insertion, v_shell;

    srand(time(NULL)); 
    gerarVetor(&original);

    // insertion
    copiarVetor(original, &v_insertion);
    
    clock_t inicio_ins = clock(); // comeca o tempo
    insertionSort(&v_insertion); // ordena os numeros
    clock_t fim_ins = clock(); // para o tempo
    
    double tempo_ins = ((double)(fim_ins - inicio_ins)) / CLOCKS_PER_SEC * 1000.0; // ms

    // shell
    copiarVetor(original, &v_shell);
    
    clock_t inicio_shell = clock();
    shellSort(&v_shell);
    clock_t fim_shell = clock();
    
    double tempo_shell = ((double)(fim_shell - inicio_shell)) / CLOCKS_PER_SEC * 1000.0; 

    // resul
    printf("Comparação\n");
    printf("Tempo Insertion Sort : %.4f ms\n", tempo_ins);
    printf("Tempo Shell Sort     : %.4f ms\n", tempo_shell);

    return 0;
}