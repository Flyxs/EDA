# A melhor forma de entender a diferença é com uma analogia clara

- Busca Linear: Imagine uma pilha de provas de alunos, todas desordenadas. Você está procurando a prova do "João". Você não tem escolha a não ser pegar a primeira prova, ver o nome, largar, pegar a segunda, ver o nome, e assim por diante, até encontrar o "João" ou checar a pilha inteira.

- Busca Binária: Imagine uma lista telefônica ou um dicionário. Você está procurando por "Silva". Você não começa na letra 'A'. Você abre o livro no meio (letra 'M'). Você vê que "Silva" ('S') vem depois de 'M'. Você agora ignora (joga fora) toda a primeira metade do livro. Você pega a segunda metade (de 'M' a 'Z') e repete o processo: abre no meio dela (letra 'T'), e assim por diante.

## Resumo da Comparação

| Característica | Busca Linear | Busca Binária |
| :--- | :--- | :--- |
| **Como funciona** | Um por um (força bruta) | Dividir e Conquistar |
| **Requisito** | NENHUM | Array deve estar ORDENADO |
| **Velocidade (Pior Caso)**| $O(n)$ (Lenta) | $O(\log n)$ (Rápida) |
| **Melhor para...** | Listas pequenas ou desordenadas | Listas grandes e ordenadas |
