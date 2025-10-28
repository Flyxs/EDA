# Selection Sort (Ordenação por Seleção)

É um dos algoritmos mais simples. Funciona encontrando repetidamente o menor item e movendo-o para a posição correta.

- **Analogia:** Organizar uma estante de livros por altura. Você olha a estante inteira, pega o **livro mais baixo** e o coloca na primeira posição. Depois, você olha o resto da estante, pega o segundo mais baixo e o coloca na segunda posição, e assim por diante.

---

- ## Como Funciona

1. Assume que o primeiro elemento (i=0) é o menor.

2. Percorre o resto do array (j = i+1 até o fim) procurando por um elemento que seja realmente o menor.

3. Se encontrar, troca o menor encontrado com o elemento da posição i.

4. Repete o processo para i=1, i=2, etc.

- Velocidade: O(n2) (Lento, tanto no pior quanto no melhor caso).

- Espaço: O(1) (In-place).

- Estável: Não.

[**Exemplo no arquivo de código**](/Algoritimos-de-ordenação/selection-sort/selection_sort.c)

**[VOLTAR](/Algoritimos-de-ordenação/Algoritimos_de_ordenacao.md)**
