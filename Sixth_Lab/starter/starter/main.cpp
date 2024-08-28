#include <iostream>

int main() {
    int *pointer = new int(10);
    std::cout << pointer << std::endl << *pointer;
    return 0;
}