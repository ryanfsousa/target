#include <iostream>
#include <string>

void reverseString(std::string &str) {
    int n = str.size();

    // passe pela primeira metade da string, trocando com seu equivalente na outra metade
    for(int i = 0; i < n / 2; i++) {
        char aux = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = aux;
    }
}

int main() {

    std::string s;
    std::cin >> s;

    reverseString(s);

    std::cout << s << std::endl;

    return 0;
}