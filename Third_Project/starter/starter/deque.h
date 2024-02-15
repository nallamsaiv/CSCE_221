#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"
using namespace std;

template <class Type>
class Deque {
private:
	int s;
	Node<Type>* firstNode;
	Node<Type>* lastNode;

public:
	Deque();
	Deque(const Deque& other); 
	Deque& operator=(const Deque& other); 
	~Deque();
	bool isEmpty();
	int size();
	Type first();
	Type last();
	void insertFirst(Type o);
	void insertLast(Type o);
	Type removeFirst();
	Type removeLast();
};

// Your implementation here 

template <class Type>
Deque<Type>::Deque() {
	s = 0;
	firstNode = nullptr;
	lastNode = nullptr;
}

template <class Type>
Deque<Type>::~Deque() {
	Node<Type>* current = firstNode;

    while (current != nullptr){
        Node<Type>* next = current->getNext();
        delete current;
        current = next;
    }
    if(firstNode != nullptr){
        firstNode = nullptr;
		lastNode = nullptr;
    }
    s = 0;
}

template <class Type>
Deque<Type>::Deque(const Deque& other) {
	Node<Type>* current = other.firstNode;
    s = other.s;
    Node<Type>* prev_node = nullptr;
    int count = 1;
    while (current != nullptr){
		Node<Type>* curr_node = new Node<Type>(current->getData());
        if(count == 1){
            firstNode = curr_node;
            prev_node = curr_node;
        }else{
			curr_node->setPrev(prev_node);
            prev_node->setNext(curr_node);
            prev_node = curr_node;
        }
		if(count == s){
			lastNode = curr_node;
		}
        Node<Type>* next = current->getNext();
        current = next;
        count++;
    }
}

template <class Type>
Deque<Type>& Deque<Type>::operator=(const Deque& other) {
	if(this == &other){
        return *this;
    }
	Node<Type>* current = firstNode;

    while (current != nullptr){
        Node<Type>* next = current->getNext();
        delete current;
        current = next;
    }

	current = other.firstNode;
    Node<Type>* prev_node = nullptr;
    int count = 1;
    s = other.s;
    while (current != nullptr){
		Node<Type>* curr_node = new Node<Type>(current->getData());
        if(count == 1){
            firstNode = curr_node;
            prev_node = curr_node;
        }else{
			curr_node->setPrev(prev_node);
            prev_node->setNext(curr_node);
            prev_node = curr_node;
        }
		if(count == s){
			lastNode = curr_node;
		}
        Node<Type>* next = current->getNext();
        current = next;
        count++;
    }

	return *this;
}

template <class Type>
bool Deque<Type>::isEmpty() {
	if(firstNode == nullptr){
		return true;
	}else{
		return false;
	}
}

template <class Type>
int Deque<Type>::size() {
	return s;
}

template <class Type>
Type Deque<Type>::first() {
	if(isEmpty()){
		return Type();
	}else{
		return firstNode->getData();
	}
}

template <class Type>
Type Deque<Type>::last() {
	if(isEmpty()){
		return Type();
	}else{
		return lastNode->getData();
	}
}

template <class Type>
void Deque<Type>::insertFirst(Type o) {
	Node<Type>* new_node = new Node<Type>(o);
    if(isEmpty()) {
        firstNode = new_node;
		lastNode = new_node;
    } else {
        new_node->setNext(firstNode);
        firstNode->setPrev(new_node);
        firstNode = new_node;
    }
    s++;
}

template <class Type>
void Deque<Type>::insertLast(Type o) {
	Node<Type>* new_node = new Node<Type>(o);
    if(isEmpty()) {
        firstNode = new_node;
		lastNode = new_node;
    } else {
        new_node->setPrev(lastNode);
        lastNode->setNext(new_node);
        lastNode = new_node;
    }
    s++;
}

template <class Type>
Type Deque<Type>::removeFirst() {
	if(isEmpty()){
		throw std::out_of_range("Queue is empty");
	}
	if(s==1){
		Node<Type>* temp = firstNode;
    	Type data_node = firstNode->getData();
    	firstNode = temp->getNext();
    	delete temp;
		lastNode = nullptr;
		firstNode = nullptr;
    	s--;
    	return data_node;
	}else{
		Node<Type>* temp = firstNode;
    	Type data_node = firstNode->getData();
    	firstNode = temp->getNext();
    	delete temp;
		firstNode->setPrev(nullptr);
    	s--;
    	return data_node;
	}
}

template <class Type>
Type Deque<Type>::removeLast() {
	if(isEmpty()){
		throw std::out_of_range("Queue is empty");
	}
	if(s==1){
		Node<Type>* temp = lastNode;
    	Type data_node = lastNode->getData();
    	lastNode = temp->getPrev();
    	delete temp;
		firstNode = nullptr;
		lastNode = nullptr;
    	s--;
    	return data_node;
	}else{
		Node<Type>* temp = lastNode;
    	Type data_node = lastNode->getData();
    	lastNode = temp->getPrev();
    	delete temp;
		lastNode->setNext(nullptr);
    	s--;
    	return data_node;
	}
}

#endif
