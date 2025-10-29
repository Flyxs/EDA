# 🗺️ Busca Linear (Força Bruta)

É o método mais simples e intuitivo. Ele percorre o array, um elemento de cada vez, do início ao fim, e compara cada elemento com o valor que você está procurando.

- **Como Funciona:** [item 1?] → [item 2?] → [item 3?] ...

- **Requisito:** Nenhum. Funciona em qualquer array.

- **Velocidade:** Lenta (O(n)). Se o array tem 1 milhão de itens, no pior caso, ela fará 1 milhão de comparações.

## Quando Usar

- Quando o array é pequeno (tão pequeno que a velocidade não importa).

- Quando o array está desordenado (e você não pode ou não quer gastar tempo para ordená-lo primeiro).

- Quando você só precisa fazer uma única busca. (Geralmente, ordenar o array O(nlogn) para fazer uma busca binária O(logn) é mais lento do que apenas fazer uma busca linear O(n)).

---

[**Exemplo no arquivo de código**](/Algoritimos-de-busca/busca-linear/busca_linear.c)
