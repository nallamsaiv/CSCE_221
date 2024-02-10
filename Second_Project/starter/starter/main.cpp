#include <iostream>
using namespace std;
#include "AbstractStack.h"
#include "StackArrayDouble.h"
#include "StackArrayLinear.h"
#include "StackLinkedList.h"

#include <chrono>

using namespace std::chrono;

int main() {
    // Write your own tests here
    std::chrono::time_point<std::chrono::system_clock> start, end;

    StackArrayLinear<int> linear_stack;
    StackArrayDouble<int> double_stack;
    StackLinkedList<int> linked_list_stack;

    start = std::chrono::system_clock::now();
    for(int i = 1; i <= 20000; i++){
        linear_stack.push(i);
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Linear Stack Run Time: " << elapsed.count() << endl;

    start = std::chrono::system_clock::now();
    for(int i = 1; i <= 20000; i++){
        linked_list_stack.push(i);
    }
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout << "Linked List Stack Run Time: " << elapsed.count() << endl;

    start = std::chrono::system_clock::now();
    for(int i = 1; i <= 20000; i++){
        double_stack.push(i);
    }
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout << "Double Stack Run Time: " << elapsed.count() << endl;


    return 0;
}