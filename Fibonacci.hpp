#include <unordered_set>

#define MAXN 100000 // o tamanho do vetor para guardar a resposta de estados já calculados
                    // um computador moderno deve levar ~1 segundo para calcular até 10^8.

unsigned int answer[MAXN];

unsigned int fib(unsigned int n) {
    if(n < 2) return n;                 // caso base
    return fib(n - 1) + fib(n - 2);     // recursão
}

unsigned int fibTopDown(unsigned int n) {
    if(n < 2) return n;

    if(answer[n]) return answer[n];    // verifica se já foi calculado

    answer[n] = fibTopDown(n - 1) + fibTopDown(n - 2); // guarda a resposta

    return answer[n];
}

// É possível fazer isso em O(1) de memória utilizando apenas duas variáveis
unsigned int fibBottomUp(unsigned int n) {
    if(answer[n]) return answer[n];

    answer[0] = 0;
    answer[1] = 1;

    for(int i = 2; i <= n; i++) {
        answer[i] = answer[i - 1] + answer[i - 2];
    }

    return answer[n];
}

std::unordered_set<int> fibonacciSequence(int n) {
    std::unordered_set<int> hashSet;

    int first = 0, second = 1;

    hashSet.insert(0);
    hashSet.insert(1);

    while(hashSet.size() < n) {
        int next = first + second;
        hashSet.insert(next);
        first = second;
        second = next;
    }

    return hashSet;
}