// Exemplo de Código (Busca Binária)
// Este código implementa a "analogia do dicionário" (a versão iterativa, que usa while e é a mais recomendada).

#include <stdio.h>

/**
 * Busca binariamente por 'x' no array 'v'.
 * Retorna o ÍNDICE (posição) se encontrar.
 * Retorna -1 se não encontrar.     
 */

int busca_binaria(int v[], int qtd, int x) {
    int esquerda = 0;
    int direita = qtd - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // 1. "Abriu no meio e achou!"
        if (v[meio] == x) {
            return meio; // Encontrou!
        }
        
        // 2. "O item é MAIOR, vá para a metade direita"
        if (v[meio] < x) {
            esquerda = meio + 1;
        } 
        // 3. "O item é MENOR, vá para a metade esquerda"
        else {
            direita = meio - 1;
        }
    }

    // "Acabou o espaço de busca (esquerda > direita)"
    return -1; // Não encontrou
}

int main() {
    // Array ORDENADO!
    int meu_array[] = {4, 8, 15, 21, 33, 92};
    int n = 6;
    
    int para_buscar = 33;
    int indice = busca_binaria(meu_array, n, para_buscar);
    
    if (indice != -1) {
        printf("Busca Binária: Encontrou '%d' no índice %d.\n", para_buscar, indice);
    } else {
        printf("Busca Binária: Não encontrou '%d'.\n", para_buscar);
    }

    para_buscar = 100;
    indice = busca_binaria(meu_array, n, para_buscar);

    if (indice != -1) {
        printf("Busca Binária: Encontrou '%d' no índice %d.\n", para_buscar, indice);
    } else {
        printf("Busca Binária: Não encontrou '%d'.\n", para_buscar);
    }

    return 0;
}