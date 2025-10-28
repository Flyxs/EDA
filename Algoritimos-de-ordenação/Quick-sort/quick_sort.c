#include <stdio.h>

void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Particionamento Lomuto (usa o último elemento como pivô)
 */
int particiona(int *v, int e, int d) {
    int pivo = v[d]; // Pivô é o último elemento
    int j = e;       // 'j' é a parede dos menores

    for (int k = e; k < d; k++) {
        if (v[k] <= pivo) {
            troca(&v[k], &v[j]);
            j++;
        }
    }
    // Coloca o pivô em sua posição final correta
    troca(&v[j], &v[d]); 
    return j; // Retorna o índice do pivô
}

void quick_sort(int *v, int e, int d) {
    if (e < d) {
        int j = particiona(v, e, d);
        
        quick_sort(v, e, j - 1); // Ordena a esquerda
        quick_sort(v, j + 1, d); // Ordena a direita
    }
}

void imprimir_array(int v[], int qtd) {
    for(int i = 0; i < qtd; i++) printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int meu_array[] = {10, 80, 30, 90, 40, 50, 70};
    int n = 7;
    
    printf("Original: ");
    imprimir_array(meu_array, n);
    
    quick_sort(meu_array, 0, n - 1);
    
    printf("Ordenado: ");
    imprimir_array(meu_array, n); // Saída: Ordenado: 10 30 40 50 70 80 90
    
    return 0;
}