#include <stdio.h>
#include <stdlib.h> 
#include <limits.h> 

int main() {
    int* listas[8];    
    int tamanhos[8];    
    int indices[8] = {0}; 
    int total_elementos = 0;

    for (int i = 0; i < 8; i++) {
        scanf("%d", &tamanhos[i]);
        total_elementos += tamanhos[i];

        if (tamanhos[i] > 0) {
            listas[i] = (int*)malloc(tamanhos[i] * sizeof(int));
            if (listas[i] == NULL) {
                fprintf(stderr, "Erro ao alocar memória.\n");
                return 1;
            }
            
            for (int j = 0; j < tamanhos[i]; j++) {
                scanf("%d", &listas[i][j]);
            }
        } else {
            listas[i] = NULL;
        }
    }

    int primeiro_print = 1; 

    for (int count = 0; count < total_elementos; count++) {
        
        int menor_valor = INT_MAX; 
        int indice_do_menor = -1;  

        for (int i = 0; i < 8; i++) {
            if (indices[i] < tamanhos[i]) {
                
                int valor_atual = listas[i][indices[i]];

                if (valor_atual < menor_valor) {
                    menor_valor = valor_atual;
                    indice_do_menor = i;
                }
            }
        }

        if (indice_do_menor != -1) {
            
            if (!primeiro_print) {
                printf(" ");
            }
            
            printf("%d", menor_valor);
            primeiro_print = 0;

            indices[indice_do_menor]++;
        }
    }
    
    printf("\n"); 

    for (int i = 0; i < 8; i++) {
        if (listas[i] != NULL) {
            free(listas[i]);
        }
    }

    return 0;
}