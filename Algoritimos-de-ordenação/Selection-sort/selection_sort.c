// Exemplo de Código (Selection Sort)

#include <stdio.h>

void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int v[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        // Encontra o índice do menor elemento
        int indice_menor = i;
        for (int j = i + 1; j < qtd; j++) {
            if (v[j] < v[indice_menor]) {
                indice_menor = j;
            }
        }
        
        // Troca o menor encontrado com a posição 'i'
        if (i != indice_menor) {
            troca(&v[i], &v[indice_menor]);
        }
    }
}

void imprimir_array(int v[], int qtd) {
    for(int i = 0; i < qtd; i++) printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int meu_array[] = {64, 25, 12, 22, 11};
    int n = 5;
    
    printf("Original: ");
    imprimir_array(meu_array, n);
    
    selection_sort(meu_array, n);
    
    printf("Ordenado: ");
    imprimir_array(meu_array, n); // Saída: Ordenado: 11 12 22 25 64
    
    return 0;
}