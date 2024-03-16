# Target - Estágio em Desenvolvimento

Meu usuário principal no GitHub é `rfsousa`, lá podem ser encontrados outros projetos, relacionados a segurança em sistemas e projeto de algoritmos.

## Pergunta 1

O pseudocódigo apresentado calcula com uma complexidade de tempo `O(n)` a soma dos primeiros números naturais até um determinado índice. No caso, o índice é 13, portanto a resposta deve ser `(13 * (13 + 1) / 2`, que é `91`.

Como a pergunta pediu por um repositório, realizei uma implementação em C++, no arquivo [Sum.cpp](./Sum.cpp).

## Pergunta 2

Para determinar se um número pertence à sequência de Fibonacci, a primeira intuição é calcular a sequência de Fibonacci em si.

Deixei as implementações em C++ em [Fibonacci.cpp](./Fibonacci.cpp), [Fibonacci.hpp](./Fibonacci.hpp), [FibonacciBenchmarkNaive.cpp](./FibonacciBenchmarkNaive.cpp), [FibonacciBenchmarkTopDown.cpp](./FibonacciBenchmarkTopDown.cpp), [FibonacciBenchmarkBottomUp.cpp](./FibonacciBenchmarkBottomUp.cpp).

O método mais simples para calcular seria o método recursivo, a função `fib(n)` retorna o n-ésimo número de Fibonacci. O caso base tem como resposta o próprio n, para `n < 2`, ex: `fib(0) = 0`, `fib(1) = 1`.

A recursão é `fib(n) = fib(n - 1) + fib(n - 2)`. Esta solução está correta, no entanto, ao analisar sua complexidade de tempo, encontramos `O(2^n)`, exponencial. Isso será um problema caso n seja, por exemplo, 10^5.

Para melhorar esta solução, podemos aplicar o conceito de memoização, que está relacionado com programação dinâmica. Isso consiste em observar que a árvore de recursão passa por estados repetidos e independentes que contribuem com a resposta e guardar a resposta para estes estados, de forma que não seja mais necessário recalcular.

Em resumo, basta adicionar um array para guardar a resposta ou consultá-la, caso já tenha sido calculada. Com isso, obtemos uma solução `O(n)` em tempo, mas `O(n)` em memória. Isso é conhecido como programação dinâmica _top-down_.

Ainda é possível melhorar ainda mais este algoritmo, basta reescrever a ideia de programação dinâmica, mas ao invés de quebrar um problema maior que será resolvido combinando a solução de problemas menores, cria-se inicialmente a solução de problemas menores e combinar-se-os até encontrar a solução do problema maior. A complexidade de tempo e memória ainda é a mesma, no entanto, a constante de tempo é reduzida, já que não existe mais a necessidade de trabalhar com recursão, que realiza operações relacionadas ao salvamento de contexto. Isso é conhecido como programação dinâmica _bottom-up_.

Existe uma solução em `O(log n)`, tempo logarítmico, mas torna-se necessário trabalhar com multiplicação rápida de matrizes, fugindo da pergunta.

Executando _stress tests_, em um AMD Ryzen 5 3500U, em um ambiente Linux, foram obtidos os seguintes resultados:

|                   | n = 45 | n = 1000 | n = 10000 |
|-------------------|--------|----------|-----------|
| O(2^n)            | 9.610s | -        | -         |
| O(n) _top-down_   | 0.003s | 0.003s   | 0.004s    |
| O(n)  _bottom-up_ | 0.002s | 0.002s   | 0.002s    | 

Ao final, optou-se por utilizar a ideia `bottom-up` em um programa que recebe várias perguntas do tipo "O número n faz parte da sequência de Fibonacci?". É realizado o cálculo da sequência até um número "grande o suficiente" e então guarda-se a sequência em uma tabela _hash_, para que a resposta possa ser dada em tempo médio `O(1)`.

## Pergunta 3

a) 1, 3, 5, 7, `9` - os primeiros ímpares

b) 2, 4, 8, 16, 32, 64, `128` - as primeiras potências de dois

c) 0, 1, 4, 9, 16, 25, 36, `49` - o quadrado dos primeiros naturais

d) 4, 16, 36, 64, `100` - o quadrado dos primeiros inteiros pares e positivos

e) 1, 1, 2, 3, 5, 8, `13` - a sequência Fibonacci

f) 2,10, 12, 16, 17, 18, 19, `200` - números que começam com a letra d, por extenso.

## Pergunta 4

Primeiro, é necessário ligar dois interruptores. Chame-os de A e B. Então, vá até a outra sala e veja quais lâmpadas acenderam. Então volte à sala dos interruptores, desligue A e ligue o terceiro interruptor. A corresponde à lâmpada que se apagou, B corresponde à lâmpada que se manteve acesa e o terceiro interruptor corresponde à lâmpada que acendeu.

## Pergunta 5

Este é um problema bastante intuitivo, [basta percorrer metade da _string_, trocando os caractere na posição `i` com o caractere `n - i - 1`](./ReverseString.cpp). Realizei a troca utilizando variável auxiliar, estou ciente da existência da função swap do C++, mas evitei usá-la e também conheço o algoritmo [XOR swap](https://pt.wikipedia.org/wiki/Algoritmo_XOR_Swap), mas não o implementei para permitir legibilidade do código.
