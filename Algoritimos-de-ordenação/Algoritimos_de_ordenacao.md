# Comparativo de Algoritmos de Ordenação

Algoritmos de ordenação são usados para reorganizar os elementos de uma coleção (como um array) em uma ordem específica (geralmente numérica ou alfabética). Eles são classificados por sua eficiência (velocidade) e uso de memória.

## Conceitos-Chave

1. **Complexidade de Tempo:** Mede quão rápido o algoritmo é.

    - *O*(*n*2) (**Quadrático**): Lento para grandes listas. Dobrar o tamanho da lista quadruplica o tempo.

    - *O*(nlogn) (**Log-Linear**): Muito rápido e eficiente para grandes listas.

2. **Complexidade de Espaço:** Mede quanta memória extra o algoritmo precisa.

    - *O*(1) (**In-place**): Excelente. Não precisa de memória extra (ou muito pouca).

    - *O*(n) (**Out-of-place**): Requer um array auxiliar do mesmo tamanho da lista original.

3. **Estabilidade (Stable)**: Um algoritmo é "estável" se elementos com chaves iguais mantêm sua ordem relativa original.

| Algoritmo | Velocidade (Média) | Velocidade (Pior Caso) | Espaço Extra | Estável? | Melhor para... |
| :--- | :--- | :--- | :--- | :--- | :--- |
| [**Seletion sort**](/Algoritimos-de-ordenação/Selection-sort/selection_sort.md) | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Não | Listas pequenas ou se "trocas" forem caras. |
| [**Insertion sort**](/Algoritimos-de-ordenação/Insertion-sort/insertion_sort.md) | $O(n^2)$ | $O(n^2)$ | $O(1)$ | **Sim** | Listas pequenas ou **quase ordenadas** (muito rápido). |
| [**Merge sort**](/Algoritimos-de-ordenação/Merge-sort/merge_sort.md) | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | **Sim** | Quando a **estabilidade** ou a garantia de $O(n \log n)$ é crítica. |
| [**Quick sort**](/Algoritimos-de-ordenação/Quick-sort/quick_sort.md) | $O(n \log n)$ | $O(n^2)$ (Raro) | $O(\log n)$ | Não | O mais rápido na **maioria dos casos** para listas grandes. |
