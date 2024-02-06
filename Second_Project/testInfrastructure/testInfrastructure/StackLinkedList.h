#ifndef STACK_LinkedList_H
#define STACK_LinkedList_H
#include "AbstractStack.h"

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data_node){
        data = data_node;
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
    head = nullptr;
    length = 0;
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
    length = 0;
}

template <typename T>
StackLinkedList<T>::StackLinkedList(const StackLinkedList& other) {
    Node<T>* current = other.head;
    length = other.length;
    Node<T>* prev_node;
    int count = 1;
    while (current != nullptr){
        if(count == 1){
            Node<T>* curr_node = new Node<T>(current->data);
            head = curr_node;
            prev_node = curr_node;
            curr_node->next = nullptr;
        }else{
            Node<T>* curr_node = new Node<T>(current->data);
            prev_node->next = curr_node;
            prev_node = curr_node;
            curr_node->next = nullptr;
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
        Node<T>* next = current->next;
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
            curr_node->next = nullptr;
        }else{
            Node<T>* curr_node = new Node<T>(current->data);
            prev_node->next = curr_node;
            prev_node = curr_node;
            curr_node->next = nullptr;
        }
        Node<T>* next = current->next;
        current = next;
        count++;
    }
    length = other.length;

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
    return length;
}

template <typename T>
T& StackLinkedList<T>::top(){
    if(!isEmpty()){
        return head->data;
    }else{
        throw std::out_of_range("The list is empty");
    }
}

template <typename T>
T StackLinkedList<T>::pop(){
    if(!isEmpty()){
        Node<T>* temp = head;
        T data_node = head->data;
        head = temp->next;
        delete temp;
        length--;
        return data_node;
    }else{
        throw std::out_of_range("The list is empty");
    }
}

template <typename T>
void StackLinkedList<T>::push(const T& e){
    if(isEmpty() == false){
        Node<T>* current = head;
        Node<T>* add_node = new Node<T>(e);
        add_node->next = current;
        head = add_node;
    }else{
        Node<T>* new_node = new Node<T>(e);
        new_node->next = nullptr;
        head = new_node;
    }
    length++;
}


#endif