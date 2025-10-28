#include <stdio.h>
#include <stdlib.h>

// Função para intercalar (merge) dois sub-arrays ordenados
void merge(int v[], int e, int m, int d) {
    int i, j, k;
    int n1 = m - e + 1;
    int n2 = d - m;

    // Cria arrays temporários
    int *E = (int*) malloc(n1 * sizeof(int));
    int *D = (int*) malloc(n2 * sizeof(int));

    // Copia dados para os arrays temporários E[] e D[]
    for (i = 0; i < n1; i++) E[i] = v[e + i];
    for (j = 0; j < n2; j++) D[j] = v[m + 1 + j];

    // Intercala os arrays temporários de volta em v[e..d]
    i = 0; // Índice inicial do primeiro sub-array
    j = 0; // Índice inicial do segundo sub-array
    k = e; // Índice inicial do array intercalado
    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) {
            v[k] = E[i];
            i++;
        } else {
            v[k] = D[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de E[], se houver
    while (i < n1) {
        v[k] = E[i];
        i++;
        k++;
    }
    // Copia os elementos restantes de D[], se houver
    while (j < n2) {
        v[k] = D[j];
        j++;
        k++;
    }
    
    free(E);
    free(D);
}

// Função principal do merge_sort
void merge_sort(int v[], int e, int d) {
    if (e < d) {
        // Encontra o meio
        int m = e + (d - e) / 2;

        // Ordena a primeira e a segunda metade
        merge_sort(v, e, m);
        merge_sort(v, m + 1, d);

        // Intercala as metades ordenadas
        merge(v, e, m, d);
    }
}

void imprimir_array(int v[], int qtd) {
    for(int i = 0; i < qtd; i++) printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int meu_array[] = {12, 11, 13, 5, 6, 7};
    int n = 6;
    
    printf("Original: ");
    imprimir_array(meu_array, n);
    
    merge_sort(meu_array, 0, n - 1);
    
    printf("Ordenado: ");
    imprimir_array(meu_array, n); // Saída: Ordenado: 5 6 7 11 12 13
    
    return 0;
}