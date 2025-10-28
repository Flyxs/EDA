// Exemplo de Código (Busca Linear)
// Este código implementa a "analogia da pilha de provas". Ele retorna o índice onde o número foi encontrado, ou -1 se não foi.

#include <stdio.h>

/**
 * Busca linearmente por 'x' no array 'v'.
 * Retorna o ÍNDICE (posição) se encontrar.
 * Retorna -1 se não encontrar.
 */
int busca_linear(int v[], int qtd, int x) {
    for (int i = 0; i < qtd; i++) {
        // "É este o item?"
        if (v[i] == x) {
            return i; // Encontrou! Retorna a posição.
        }
    }
    // "Chequei a pilha inteira e não encontrei."
    return -1;
}

int main() {
    // Array DESORDENADO
    int meu_array[] = {15, 8, 92, 4, 33, 21};
    int n = 6;
    
    int para_buscar = 4;
    int indice = busca_linear(meu_array, n, para_buscar);
    
    if (indice != -1) {
        printf("Busca Linear: Encontrou '%d' no índice %d.\n", para_buscar, indice);
    } else {
        printf("Busca Linear: Não encontrou '%d'.\n", para_buscar);
    }

    para_buscar = 100;
    indice = busca_linear(meu_array, n, para_buscar);

    if (indice != -1) {
        printf("Busca Linear: Encontrou '%d' no índice %d.\n", para_buscar, indice);
    } else {
        printf("Busca Linear: Não encontrou '%d'.\n", para_buscar);
    }

    return 0;
}