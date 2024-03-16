#include <iostream>

#include "Fibonacci.hpp"

int main() {

    unsigned int q;
    std::cout << "Quantas perguntas?" << std::endl;
    std::cin >> q;  // número de perguntas "o número n faz parte da sequência de Fibonacci?" a serem respondidas

    // hash set com os MAXN primeiros números de fibonacci
    std::unordered_set<int> fibonacciNumbers = fibonacciSequence(MAXN);

    // responde as perguntas em O(1), em média
    for(int i = 0; i < q; i++) {
        int n;
        std::cin >> n;

        if(fibonacciNumbers.count(n)) {
            std::cout << "O número " << n << " faz parte da sequência de Fibonacci." << std::endl;
        } else {
            std::cout << "O número " << n << " não faz parte da sequência de Fibonacci." << std::endl;
        }
    }

    return 0;
}