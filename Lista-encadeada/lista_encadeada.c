#include <stdio.h>
#include <stdlib.h>

// Cria a estrutura de cada célula da lista 
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Cria a lista
celula *cria_lista() {
    celula *le = malloc(sizeof(celula));
    le -> prox = NULL;
    printf("Lista Criada\n");
    return le;
}

// Insere uma célula a frente do le
void insere_inicio(celula *le, int x) {
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = le -> prox;
    le -> prox = novo;
    printf("Valor %d inserido!\n", x);
}

// Insere no final da lista
void insere_final(celula *le, int x) {
    while (le -> prox != NULL) {
        le = le -> prox;
    }

    if (le -> prox == NULL) {
        insere_inicio(le, x);
        printf("Adicionado no final da lista\n");
    }
}

// Remove o inicio da lista
void remove_inicio(celula *le) {
    if (le -> prox == NULL) {
        printf ("Não é possivel remover\n");
        return;
    }
    celula *lixo = le -> prox;
    le -> prox = lixo -> prox;
    int dado = lixo -> dado;
    printf("Inicio Removido. Dado: %d", dado);
    free(lixo);
}

// Remove o final da lista
void remove_final(celula *le) {
    if (le -> prox == NULL) {
        printf ("Não é possivel remover\n");
        return;
    }
    while (le -> prox -> prox != NULL) {
        le = le -> prox;
    }

    if (le -> prox -> prox == NULL) {
        remove_inicio(le);
    }
}

// Destroi a lista
void destroi_lista(celula *le) {
    while (le -> prox != NULL) {
        remove_inicio(le);
    }
    free(le);
}