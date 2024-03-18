#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current->next;
            current->next = nullptr;
            current->prev = nullptr;
            delete current;
            current = temp;
        }
        tail = nullptr;
        head = nullptr;
    }

    // inserts element to end of list
    void append(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    string display() {
        Node<T>* current = head;
        string displayStr = "";
        while (current) {
            displayStr += to_string(current->data);
            current = current->next;
            if (current != nullptr) {
                displayStr += " <-> ";
            }
        }
        return displayStr;
    }

    bool isPalindromic() {
       // Your implementation here
       if(size == 0 || size == 1){
        return true;
       }
       T data_1;
       T data_2;
       Node<T>* current_1 = head;
       Node<T>* current_2 = tail;
       while(current_1 != nullptr){ //comparing values by iterating from front to back and back to front
        data_1 = current_1->data;
        data_2 = current_2->data;

        if(data_1 != data_2){
            return false;
        } //comparison

        Node<T>* next_node = current_1->next;
        current_1 = next_node;
        Node<T>* prev_node = current_2->prev;
        current_2 = prev_node;
       }
       return true;
    }

    /*
    // Consider the first node in the list to be at position 1
    // Consider the second node in the list to be at position 2 and so on
    // Positions can range from 1 to x (where x = size)

    // You must swap the data of an even positioned node with its preceding odd positioned node
        // For example you must swap 
            // node 2's data with node 1's data
            // node 4's data with node 3's data
        // If the doubly linked list has odd number of nodes, then the last node will be left as is (as it does not have a succeeding even positioned node to swap with)
    */
    void swapAtEvenPosition() {
       // Your implementation here
        Node<T>* current = head;
        Node<T>* prev_node = nullptr;
        T temp_data1;
        int count = 1;
        while(current != nullptr){
            if(count % 2 == 0){
                prev_node = current->prev;
                temp_data1 = prev_node->data;
                prev_node->data = current->data;
                current->data = temp_data1;
            }
            count += 1;
            Node<T>* next_node = current->next;
            current = next_node;
        }
    }
};

#ifndef TEST_MODE
int main() {
    cout << "Testing isPalindromic" << endl;
    cout << endl;
    {
        {
            DoublyLinkedList<int> dll;
            dll.append(1);
            dll.append(2);
            dll.append(3);
            dll.append(2);
            dll.append(1);

            std::cout << "Doubly Linked List:" << std::endl;
            cout << dll.display() << endl;

            // should be palindromic
            std::cout << "Is Palindromic: " << (dll.isPalindromic() ? "true" : "false") << std::endl;
            cout << endl;
        }

        {
            DoublyLinkedList<int> dll2;
            dll2.append(1);
            dll2.append(2);
            dll2.append(3);
            dll2.append(2);
            dll2.append(2);

            std::cout << "Doubly Linked List:" << std::endl;
            cout << dll2.display() << endl;

            // should not be palindromic
            std::cout << "Is Palindromic: " << (dll2.isPalindromic() ? "true" : "false") << std::endl;
            cout << endl;
        }

        {
            DoublyLinkedList<int> dll3;
            dll3.append(1);
            dll3.append(2);
            dll3.append(2);
            dll3.append(1);

            std::cout << "Doubly Linked List:" << std::endl;
            cout << dll3.display() << endl;
            
            // should be palindromic
            std::cout << "Is Palindromic: " << (dll3.isPalindromic() ? "true" : "false") << std::endl;
            cout << endl;
        }
        {
            //additional test cases
            DoublyLinkedList<int> dll4;
            dll4.append(1);

            std::cout << "Doubly Linked List:" << std::endl;
            cout << dll4.display() << endl;
            
            // should be palindromic
            std::cout << "Is Palindromic: " << (dll4.isPalindromic() ? "true" : "false") << std::endl;
            cout << endl;
        }
        {
            //additional test cases
            DoublyLinkedList<int> dll5;

            std::cout << "Doubly Linked List:" << std::endl;
            cout << dll5.display() << endl;
            
            // should be palindromic
            std::cout << "Is Palindromic: " << (dll5.isPalindromic() ? "true" : "false") << std::endl;
            cout << endl;
        }
        {
            //additional test cases
            DoublyLinkedList<int> dll6;
            dll6.append(6);
            dll6.append(2);
            dll6.append(2);
            dll6.append(1);
            dll6.append(1);
            dll6.append(2);
            dll6.append(2);
            dll6.append(6);

            std::cout << "Doubly Linked List:" << std::endl;
            cout << dll6.display() << endl;
            
            // should be palindromic
            std::cout << "Is Palindromic: " << (dll6.isPalindromic() ? "true" : "false") << std::endl;
            cout << endl;
        }
    }

    cout << endl;
    cout << endl;

    cout << "Testing swapAtEvenPosition" << endl;
    cout << endl;

    {
        {
            DoublyLinkedList<int> dll;
            dll.append(15);
            dll.append(9);
            dll.append(5);
            dll.append(12);
            dll.append(7);

            std::cout << "Doubly Linked List Before Swapping:" << std::endl;
            cout << dll.display() << endl;

            dll.swapAtEvenPosition();
            
            // Expected: 9 15 12 5 7
            std::cout << "Doubly Linked List After Swapping:" << std::endl;
            cout << dll.display() << endl;
            cout << endl;
        }

        {
            DoublyLinkedList<int> dll2;
            dll2.append(21);
            dll2.append(8);
            dll2.append(52);
            dll2.append(6);

            std::cout << "Doubly Linked List Before Swapping:" << std::endl;
            cout << dll2.display() << endl;

            dll2.swapAtEvenPosition();
            
            // Expected: 8 21 6 52
            std::cout << "Doubly Linked List After Swapping:" << std::endl;
            cout << dll2.display() << endl;
            cout << endl;
        }

        {
            //additional test cases
            DoublyLinkedList<int> dll3;
            dll3.append(21);
            dll3.append(8);
            dll3.append(52);
            dll3.append(6);
            dll3.append(32);
            dll3.append(19);
            dll3.append(52);

            std::cout << "Doubly Linked List Before Swapping:" << std::endl;
            cout << dll3.display() << endl;

            dll3.swapAtEvenPosition();
            
            // Expected: 8 21 6 52 19 32 52
            std::cout << "Doubly Linked List After Swapping:" << std::endl;
            cout << dll3.display() << endl;
        }

    }


    return 0;
}
#endif
