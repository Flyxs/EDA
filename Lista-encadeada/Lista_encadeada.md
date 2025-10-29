# Lista Encadeada

## 1. O Conceito Principal: O que é uma Lista Encadeada?

Imagine uma "caça ao tesouro".

1. Você começa com uma única pista (o "início" ou "**cabeça**" da lista).

2. Essa pista lhe diz o valor de algo (dado) e, o mais importante, **onde encontrar a próxima pista** (ponteiro).

3. Você segue para a próxima pista, que tem seu próprio dado e um ponteiro para a próxima.

4. Você continua fazendo isso até que uma pista lhe diga: "Acabou. Não há mais pistas." (um ponteiro NULL).

É exatamente assim que uma lista encadeada funciona. Ela não armazena dados em blocos de memória contínuos como um array. Em vez disso, ela armazena cada elemento em um local separado da memória, e cada elemento "aponta" para o próximo.

- **Array (Vetor)**: Como uma fileira de cadeiras numeradas no cinema. Você sabe exatamente onde está a cadeira 5.

- **Lista Encadeada:** Como um trem. Você só tem acesso ao primeiro vagão (a "cabeça"). Para chegar ao vagão 5, você precisa passar pelo 1, 2, 3 e 4.

## 2. O Bloco de Construção em C: O "Nó" (Node)

Em C, o "vagão" do nosso trem é uma struct. Chamamos esse bloco de **"Nó"** (Node).

Cada nó precisa de duas coisas:

1. Os dados que queremos armazenar (ex: um int).

2. Um ponteiro para o próximo nó da lista.

Esta é a parte crucial: **é uma estrutura autorreferencial**. Ela contém um ponteiro para si mesma.

``` c
// Vamos usar 'typedef' para facilitar a leitura.
// Em vez de escrever 'struct no' toda vez, podemos só escrever 'No'.

typedef struct no {
    int valor;             // O dado que este nó armazena
    struct no *proximo;    // O ponteiro para o próximo nó
} No;
```

**Análise da Estrutura:**

- int valor;: Pode ser qualquer tipo de dado (um float, um char, outra struct, etc.).

- struct no *proximo;: Este é o "link". É um ponteiro que armazena o endereço de memória do próximo No na sequência. Se este for o último nó da lista, seu ponteiro proximo será NULL.

## 3. A "Cabeça" (Head) e a Alocação Dinâmica

Uma lista encadeada é definida pelo seu ponto de entrada: um único ponteiro para o primeiro nó. Chamamos isso de "cabeça" (ou head, inicio, lista, etc.).

Quando a lista está vazia, esse ponteiro simplesmente aponta para NULL.

``` c
// No seu programa principal (main), você começa com uma lista vazia:
No *lista = NULL;
```

**Importante:** Nós não são criados "automaticamente". Como eles não estão em um bloco contínuo (como um array), precisamos alocar memória para cada novo nó que criamos. Para isso, usamos malloc (da biblioteca <stdlib.h>).

Aqui está uma função de "fábrica" que cria um novo nó:

``` c
#include <stdlib.h> // Para malloc e NULL

// Função para criar um novo nó
No* criarNo(int valor) {
    // 1. Aloca memória para um novo 'No'
    No *novoNo = (No*) malloc(sizeof(No));
    
    // 2. Verifica se a alocação funcionou
    if (novoNo == NULL) {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }
    
    // 3. Define os valores do novo nó
    novoNo->valor = valor;
    novoNo->proximo = NULL; // Por padrão, ele não aponta para nada
    
    // 4. Retorna o ponteiro para o nó recém-criado
    return novoNo;
}
```

## 4. As Operações Essenciais (com Exemplos)

Vamos ver como usar essa estrutura.

### A. Inserir no Início da Lista

Esta é a operação de inserção mais simples e rápida. É como adicionar um novo vagão na frente do trem, tornando-o a nova locomotiva.

1. Crie um novo nó.

2. Faça o ponteiro proximo do novo nó apontar para a "cabeça" atual da lista.

3. Atualize a "cabeça" da lista para que ela seja o seu novo nó.

``` c
/* IMPORTANTE: 
A função precisa alterar o ponteiro 'lista' original.
Em C, isso significa que devemos passar um ponteiro para o ponteiro (No **lista)
ou podemos fazer a função RETORNAR a nova cabeça da lista.

Vamos usar a abordagem de retorno, que é mais fácil de entender.
*/

No* inserirNoInicio(No *lista, int valor) {
    // 1. Cria o novo nó
    No *novoNo = criarNo(valor);
    if (novoNo == NULL) {
        return lista; // Se falhar, retorna a lista como estava
    }
    
    // 2. O 'proximo' do novo nó aponta para a antiga cabeça
    novoNo->proximo = lista;
    
    // 3. A cabeça da lista agora é o novo nó
    return novoNo;
}
```

### B. Percorrer e Imprimir a Lista

Para ver todos os valores, você começa na "cabeça" e segue os ponteiros proximo até encontrar NULL.

``` c
#include <stdio.h> // Para printf

void imprimirLista(No *lista) {
    // Cria um ponteiro temporário 'atual' para percorrer a lista
    // sem perder a referência da cabeça original.
    No *atual = lista;
    
    printf("Lista: ");
    
    // O loop continua enquanto 'atual' não for NULL
    while (atual != NULL) {
        // 1. Imprime o valor do nó atual
        printf("%d -> ", atual->valor);
        
        // 2. Pula para o próximo nó
        atual = atual->proximo;
    }
    
    printf("NULL\n");
}
```

### C. Liberar a Memória (Muito Importante!)

Como alocamos memória com malloc, precisamos liberá-la com free quando a lista não for mais necessária, para evitar vazamentos de memória (memory leaks).

Você precisa liberar cada nó, um por um.

``` c
void liberarLista(No *lista) {
    No *atual = lista;
    No *proximoNo;
    
    while (atual != NULL) {
        // 1. Guarda o endereço do próximo nó (antes de apagar o atual)
        proximoNo = atual->proximo;
        
        // 2. Libera a memória do nó atual
        free(atual);
        
        // 3. Pula para o próximo nó que guardamos
        atual = proximoNo;
    }
    // A lista agora está vazia (e a 'lista' original na main se torna um ponteiro inválido)
}
```

## 5. Exemplo Completo (Juntando Tudo)

Vamos criar um programa main que usa todas essas funções.

``` c
#include <stdio.h>
#include <stdlib.h>

// --- Definição da Estrutura ---
typedef struct no {
    int valor;
    struct no *proximo;
} No;


// --- Função de Criar Nó ---
No* criarNo(int valor) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

// --- Função de Inserir no Início ---
No* inserirNoInicio(No *lista, int valor) {
    No *novoNo = criarNo(valor);
    if (novoNo == NULL) {
        return lista;
    }
    novoNo->proximo = lista;
    return novoNo; // Retorna a nova cabeça
}

// --- Função de Imprimir ---
void imprimirLista(No *lista) {
    No *atual = lista;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// --- Função de Liberar Memória ---
void liberarLista(No *lista) {
    No *atual = lista;
    No *proximoNo;
    
    while (atual != NULL) {
        proximoNo = atual->proximo;
        free(atual);
        atual = proximoNo;
    }
}


// --- Programa Principal ---
int main() {
    // 1. Começa com uma lista vazia
    No *minhaLista = NULL;
    
    imprimirLista(minhaLista); // Deve mostrar "Lista: NULL"
    
    // 2. Insere elementos (lembre-se de atualizar 'minhaLista')
    minhaLista = inserirNoInicio(minhaLista, 30);
    minhaLista = inserirNoInicio(minhaLista, 20);
    minhaLista = inserirNoInicio(minhaLista, 10);
    
    // 3. Imprime a lista preenchida
    // Como inserimos no INÍCIO, a ordem será inversa da inserção
    imprimirLista(minhaLista); // Deve mostrar "Lista: 10 -> 20 -> 30 -> NULL"
    
    // 4. Libera a memória ao final
    liberarLista(minhaLista);
    minhaLista = NULL; // Boa prática: definir o ponteiro como NULL após liberar
    
    return 0;
}
```

## 6. Prós e Contras

Como você perguntou sobre ponteiros recentemente, este é o exemplo perfeito de por que eles são usados:

Os ponteiros são o "cimento" que liga os blocos de memória (os nós) que estão espalhados. Sem ponteiros, a ideia de uma lista encadeada não existiria.

### Vantagens (Prós)

- Tamanho Dinâmico: A lista cresce e diminui conforme você precisa. Você não precisa saber o tamanho dela de antemão, ao contrário de um array.

- Inserção/Remoção Rápida (no início): Adicionar ou remover o primeiro elemento é extremamente rápido (só precisamos mudar 1 ou 2 ponteiros).

### Desvantagens (Contras)

- Sem Acesso Aleatório: Você não pode pular direto para o elemento 5 (lista[5]). Você deve percorrer os elementos 0, 1, 2, 3 e 4 para chegar lá.

- Uso de Memória: Cada elemento gasta um pouco mais de memória, pois precisa armazenar o valor + o ponteiro para o próximo.
