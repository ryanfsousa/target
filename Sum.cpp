#include <iostream>

int main() {

    int index = 13, sum = 0, k = 0;

    while(k < index) {
        k++;
        sum += k;
    }

    std::cout << sum << std::endl;

    return 0;
}