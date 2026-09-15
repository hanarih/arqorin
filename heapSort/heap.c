#include <stdio.h>

// Função para manter a propriedade de max-heap: ordenar filhos em ordem crescente
void heapify(int vetor[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    // Se o filho da esquerda for maior que a raiz
    if (esquerda < n && vetor[esquerda] > vetor[maior]) {
        maior = esquerda;
    }

    // Se o filho da direita for maior que o maior até agora
    if (direita < n && vetor[direita] > vetor[maior]) {
        maior = direita;
    }

    // Se o maior não for a raiz, troca e continua o heapify recursivamente
    if (maior != i) {
        int aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;

        heapify(vetor, n, maior);
    }
}

// Função para construir o heap inicial
void construirHeap(int vetor[], int n) {
    // Começa do último nó não-folha até a raiz
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(vetor, n, i);
    }
}

// Função principal do HeapSort
void heapSort(int vetor[], int n) {
    construirHeap(vetor, n);

    // Extrai os elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual (maior elemento) para o final
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;

        // Chama o heapify na heap reduzida
        heapify(vetor, i, 0);
    }
}

// Função auxiliar para imprimir o vetor
void imprimirVetor(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função principal para teste
int main() {
    int vetor[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, n);

    heapSort(vetor, n);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, n);

    return 0;
}