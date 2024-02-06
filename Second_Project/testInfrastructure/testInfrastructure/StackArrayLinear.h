#ifndef STACK_LINEAR_ARRAY_H
#define STACK_LINEAR_ARRAY_H
#include "AbstractStack.h"

template <typename T>
class StackArrayLinear : public AbstractStack<T> {
private:
    T* data;
    int length;
    int topIndex;

public:
    StackArrayLinear();

    ~StackArrayLinear();

    StackArrayLinear(const StackArrayLinear& other);

    StackArrayLinear& operator=(const StackArrayLinear& other);

    bool isEmpty();

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

// Your implementation here
template <typename T>
StackArrayLinear<T>::StackArrayLinear(){
    length = 1;
    data = new T[1];
    topIndex = -1;
}

template <typename T>
StackArrayLinear<T>::~StackArrayLinear(){
    if(data != nullptr){
        delete [] data;
    }
    data = nullptr;
    length = 0;
}

template <typename T>
StackArrayLinear<T>::StackArrayLinear(const StackArrayLinear& other) {
    length = other.length;
    topIndex = other.topIndex;
    data = new T[length];
    for(int i = 0; i <= topIndex; i++){
        data[i] = other.data[i];
    }
}

template <typename T>
StackArrayLinear<T>& StackArrayLinear<T>::operator=(const StackArrayLinear& other) {
   if(this == &other){
        return *this;
    }

    delete[] data;
    length = other.length;
    topIndex = other.topIndex;
    data = new T[length];

    for(unsigned int i = 0; i <= topIndex; i++){
        data[i] = other.data[i];
    }

    return *this;
}

template <typename T>
bool StackArrayLinear<T>::isEmpty(){
    if(topIndex == -1){
        return true; //set top index to a negative number when the list is empty
    }else{
        return false;
    }
}

template <typename T>
int StackArrayLinear<T>::size(){
    return topIndex + 1;
}

template <typename T>
T& StackArrayLinear<T>::top(){
    if(topIndex == -1){
        throw std::out_of_range("The list is empty");
    }else{
        return data[topIndex];
    }
}

template <typename T>
T StackArrayLinear<T>::pop(){
    if(topIndex == -1){
        throw std::out_of_range("The list is empty");
    }else{
        T popped = top();
        if(topIndex != 0){
            topIndex--;
        }else{
            delete [] data;
            data = new T[length];
            topIndex = -1;
        }
        return popped;
    }
}

template <typename T>
void StackArrayLinear<T>::push(const T& e){
    if(length < (topIndex + 2)){
        length += 10;
        T* temp_data = new T[length];
        for(int i = 0; i <= topIndex; i++){
            temp_data[i] = data[i];
        }
        delete [] data;
        data = new T[length];
        for(int i = 0; i <= topIndex; i++){
            data[i] = temp_data[i];
        }
        delete [] temp_data;
        topIndex++;
        data[topIndex] = e;
    } else{
        topIndex++;
        data[topIndex] = e;
    }
}

#endif