// Exemplo de Código (Insertion Sort)

#include <stdio.h>

void insertion_sort(int v[], int qtd) {
    for (int i = 1; i < qtd; i++) {
        int chave = v[i]; // A "carta" que pegamos
        int j = i - 1;

        // Move os elementos maiores que a 'chave' para a direita
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        // Insere a 'chave' na posição correta
        v[j + 1] = chave;
    }
}

void imprimir_array(int v[], int qtd) {
    for(int i = 0; i < qtd; i++) printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int meu_array[] = {12, 11, 13, 5, 6};
    int n = 5;
    
    printf("Original: ");
    imprimir_array(meu_array, n);
    
    insertion_sort(meu_array, n);
    
    printf("Ordenado: ");
    imprimir_array(meu_array, n); // Saída: Ordenado: 5 6 11 12 13
    
    return 0;
}