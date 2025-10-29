#include <stdio.h>
#include <stdlib.h> // Para qsort, malloc e free
#include <string.h> // Para memcpy


int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int busca_binaria(int arr[], int n, int chave) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2; 

        if (arr[meio] == chave) {
            return meio; 
        } else if (arr[meio] < chave) {
            inicio = meio + 1; 
        } else {
            fim = meio - 1; 
        }
    }
    return -1;
}

int main() {
    int N, C;

    scanf("%d %d", &N, &C);

    int *lista_original = (int*)malloc(N * sizeof(int));
    int *lista_ordenada = (int*)malloc(N * sizeof(int));

    if (lista_original == NULL || lista_ordenada == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &lista_original[i]);
    }

    memcpy(lista_ordenada, lista_original, N * sizeof(int));

    qsort(lista_ordenada, N, sizeof(int), comparar);

    int indice_secreto = busca_binaria(lista_ordenada, N, C);

    printf("%d\n", indice_secreto);

    for (int i = indice_secreto; i < N; i++) {
        printf("%d", lista_original[i]);
        if (i < N - 1 || indice_secreto > 0) {
            printf(" ");
        }
    }

    for (int i = 0; i < indice_secreto; i++) {
        printf("%d", lista_original[i]);
        if (i < indice_secreto - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(lista_original);
    free(lista_ordenada);

    return 0;
}