# 🎯 Busca Binária (Dividir e Conquistar)

É um método muito mais inteligente e rápido, mas tem uma regra de ouro: o array DEVE estar ordenado.

Ela funciona descartando metade do espaço de busca a cada comparação.

Como Funciona: [meio?] → (joga metade fora) → [meio da metade?] → (joga metade fora) ...

**Requisito:** O ARRAY DEVE ESTAR ORDENADO.

**Velocidade:** Extremamente rápida ($O$(logn)). Se o array tem 1 milhão de itens, ela encontra o resultado em no máximo 20 comparações.

## Quando Usar

- Quando o array é grande (aqui o ganho de velocidade é imenso).

- Quando o array já está ordenado.

- Quando você precisa fazer muitas buscas no mesmo array. (Neste caso, vale a pena pagar o custo de ordenar O(nlogn) uma vez para ter buscas quase instantâneas O(logn) depois).

``` c
[1, 3, 4, 6, 8] // Vamos procurar o  numero 3
[1, 3]          // Como o numero que queremos é menor que o meio, descartamos oq vem dps
[3]             // Encontramos
```

[**Exemplo no arquivo de código**](/Algoritimos-de-busca/busca-binaria/busca_binaria.c)
