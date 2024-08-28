#ifndef UNSORTED_PRIORITY_QUEUE_H
#define UNSORTED_PRIORITY_QUEUE_H

#include "AbstractPriorityQueue.h"

template <typename Type>
class UnsortedPriorityQueue : public AbstractPriorityQueue<Type> {
    private:
        Type *arr;
        int capacity;
        int size;

    public:
        UnsortedPriorityQueue();

        ~UnsortedPriorityQueue();

        void pq_insert(Type value);

        Type pq_delete();

        Type pq_get_min();

        int pq_size();
};

template <typename Type>
UnsortedPriorityQueue<Type>::UnsortedPriorityQueue() {
    capacity = 1;
    size = 0;
    arr = new Type[1];
}

template <typename Type>
UnsortedPriorityQueue<Type>::~UnsortedPriorityQueue(){
    delete [] arr;
    size = 0;
    capacity = 0;
    arr = nullptr;
}

template <typename Type>
void UnsortedPriorityQueue<Type>::pq_insert(Type value) {
    if(capacity < (size + 1)){
        capacity = capacity * 2;
        Type* temp_data = new Type[capacity];
        for(int i = 0; i < size; i++){
            temp_data[i] = arr[i];
        }
        delete [] arr;
        arr = new Type[capacity];
        for(int i = 0; i < size; i++){
            arr[i] = temp_data[i];
        }
        delete [] temp_data;
        arr[size] = value;
        size++;
    }else{
        arr[size] = value;
        size++;
    }
}

template <typename Type>
Type UnsortedPriorityQueue<Type>::pq_delete(){
    Type min = pq_get_min();
    bool min_found = false;
    for(int i = 0; i < size; i++){
        if(arr[i] == min && (i != size-1) && min_found == false){
            min_found = true;
            arr[i] = arr[i+1];
        }else if(min_found == true && (i != size-1)){
            arr[i] = arr[i+1];
        }
    }
    size--;
    return min;
}

template <typename Type>
Type UnsortedPriorityQueue<Type>::pq_get_min(){
    if(size != 0){
        Type min = arr[0];
        for(int i = 0; i < size; i++){
            if(arr[i] < min){
                min = arr[i];
            }
        }
        return min;
    }else{
        throw out_of_range("empty list");
    }
}

template <typename Type>
int UnsortedPriorityQueue<Type>::pq_size(){
    return size;
}

#endif