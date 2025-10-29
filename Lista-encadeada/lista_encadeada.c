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

// Removes todos os valores = x da lista
void remove_valores(celula *le, int x) {
    while (le -> prox != NULL) {
        if (le -> prox -> dado == x) {
            remove_inicio(le);
        }
        else le = le -> prox;
    }
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

void imprimir_lista(celula *le) {
    if (le == NULL) {
        printf("A lista ainda não foi criada\n");
        return;
    }
    printf("[");
    celula *atual = le -> prox;
    while (atual != NULL) {
        printf(" %d ->", atual -> dado);
        atual = atual -> prox;
    }
    printf(" NULL ]");
}

void limpar_terminal() {
    #ifdef _WIN32
        // Se for Windows
        system("cls");
    #else
        // Se for Linux, macOS ou outro
        system("clear");
    #endif
}

int main() {
    int true = 1;

    celula *minhalista = NULL;

    while (true == 1) {
        limpar_terminal();

        int escolha;
        imprimir_lista(minhalista);
        printf("Escolha uma opção:\n [1]Criar lista\n [2]Adicionar Valor\n [3]Remover Elemento\n [4]Apagar Lista\n [5]Sair\n");
        scanf("%d", &escolha);
        
        if (escolha == 1) {
            if (minhalista != NULL) {
                printf("A lista já existe!\n");
            }
            else minhalista = cria_lista();
        }

        else if (escolha == 2) {
            
        }

        else if (escolha == 3) {

        }

        else if (escolha == 4) {

        }
        
        else if (escolha == 5) {
            if (minhalista != NULL) {
                destroi_lista(minhalista);
                minhalista = NULL; 
            }
            printf("Saindo...\n");
            true = 0; 
        }

        else printf("Comando Invalido\n");
    }
}