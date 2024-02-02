#ifndef STACK_LinkedList_H
#define STACK_LinkedList_H
#include "AbstractStack.h"

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data_1){
        data = data_1;
    }
};

template <typename T>
class StackLinkedList : public AbstractStack<T>{
private:
    Node<T>* head;
    int length;
public:
    StackLinkedList();

    ~StackLinkedList();

    StackLinkedList(const StackLinkedList& other);

    StackLinkedList& operator=(const StackLinkedList& other);

    bool isEmpty();

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

// Your implementation here
template <typename T>
StackLinkedList<T>::StackLinkedList(){
    Node<T>* node_1 = new Node<T>();
    node_1 = head;
    node_1->next = nullptr;
    length = 1;
}

template <typename T>
StackLinkedList<T>::~StackLinkedList(){
    Node<T>* current = head;

    while (current != nullptr){
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    if(head != nullptr){
        head = nullptr;
    }
}

template <typename T>
StackLinkedList<T>::StackLinkedList(const StackLinkedList& other) {
    Node<T>* current = other.head;
    Node<T>* prev_node;
    int count = 1;
    while (current != nullptr){
        if(count == 1){
            Node<T>* curr_node = new Node<T>(current->data);
            head = curr_node;
            prev_node = curr_node;
        }else{
            Node<T>* curr_node = new Node<T>(current->data);
            prev_node->next = curr_node;
            prev_node = curr_node;
        }
        Node<T>* next = current->next;
        current = next;
        count++;
    }
}

template <typename T>
StackLinkedList<T>& StackLinkedList<T>::operator=(const StackLinkedList& other) {
    if(this == &other){
        return *this;
    }
    Node<T>* current = head;

    while (current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }

    current = other.head;
    Node<T>* prev_node;
    int count = 1;
    while (current != nullptr){
        if(count == 1){
            Node<T>* curr_node = new Node<T>(current->data);
            head = curr_node;
            prev_node = curr_node;
        }else{
            Node<T>* curr_node = new Node<T>(current->data);
            prev_node->next = curr_node;
            prev_node = curr_node;
        }
        Node<T>* next = current->next;
        current = next;
        count++;
    }

    return *this;

}

template <typename T>
bool StackLinkedList<T>::isEmpty(){
    if(head == nullptr){
        return true;
    }else{
        return false;
    }
}

template <typename T>
int StackLinkedList<T>::size(){
    Node<T>* current = head;
    int count = 0;
    while (current != nullptr){
        Node<T>* next = current->next;
        current = next;
        count++;
    }
    return count;
}

template <typename T>
T& StackLinkedList<T>::top(){
    if(!isEmpty()){
        Node<T>* current = head;
        Node<T>* prev_node;
        int count = 0;
        while (current != nullptr){
            Node<T>* next = current->next;
            prev_node = current;
            current = next;
            count++;
        }
        return prev_node->data;
    }else{
        throw std::out_of_range("The list is empty");
    }
}

template <typename T>
T StackLinkedList<T>::pop(){
    if(!isEmpty()){
        Node<T>* current = head;
        Node<T>* prev_node_2 = nullptr;
        Node<T>* prev_node = nullptr;
        int count = 0;
        while (current != nullptr){
            Node<T>* next = current->next;
            prev_node_2 = prev_node;
            prev_node = current;
            current = next;
            count++;
        }
        T data_node = prev_node->data;
        if(prev_node_2 != nullptr){
            prev_node_2->next = nullptr;
        }
        delete prev_node;

        return data_node;
    }else{
        throw std::out_of_range("The list is empty");
    }
}

template <typename T>
void StackLinkedList<T>::push(const T& e){
    if(!isEmpty()){
        Node<T>* current = head;
        Node<T>* prev_node = nullptr;
        int count = 0;
        while (current != nullptr){
            Node<T>* next = current->next;
            prev_node = current;
            current = next;
            count++;
        }
        Node<T>* new_node = new Node<T>(e);
        prev_node->next = new_node;
        new_node->next = nullptr;
    }else{
        Node<T>* new_node = new Node<T>(e);
        new_node->next = nullptr;
        head = new_node;
    }
}


#endif