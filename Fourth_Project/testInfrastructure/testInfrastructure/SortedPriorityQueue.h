#ifndef SORTED_PRIORITY_QUEUE_H
#define SORTED_PRIORITY_QUEUE_H

#include "AbstractPriorityQueue.h"

template <typename Type>
class SortedPriorityQueue : public AbstractPriorityQueue<Type> {
    private:
        Type *arr;
        int capacity;
        int size;

    public:
        SortedPriorityQueue();

        ~SortedPriorityQueue();

        void pq_insert(Type value);

        Type pq_delete();

        Type pq_get_min();

        int pq_size();
};

template <typename Type>
SortedPriorityQueue<Type>::SortedPriorityQueue() {
    capacity = 1;
    size = 0;
    arr = new Type[1];
}

template <typename Type>
SortedPriorityQueue<Type>::~SortedPriorityQueue(){
    delete [] arr;
    size = 0;
    capacity = 0;
    arr = nullptr;
}

template <typename Type>
void SortedPriorityQueue<Type>::pq_insert(Type value) {
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
    }
    arr[size] = value;
    size++;

    bool sorted = false;
    int curr = size - 1;
    Type temp;
    while(sorted == false){
        if(curr == 0 || arr[curr] >= arr[curr - 1]){
            sorted = true;
        }else{
            temp = arr[curr];
            arr[curr] = arr[curr-1];
            arr[curr-1] = temp;
            curr--;
        }
    }
    
}

template <typename Type>
Type SortedPriorityQueue<Type>::pq_delete(){
    if(size != 0){
        Type min = arr[0];

        for(int i = 0; i < size; i++){
            if(i != size-1){
                arr[i] = arr[i+1];
            }
        }
        size--;
        return min;
    }else{
        throw out_of_range("empty");
    }

}

template <typename Type>
Type SortedPriorityQueue<Type>::pq_get_min(){
    if(size != 0){
        return arr[0];
    }else{
        throw out_of_range("Empty");
    }
}

template <typename Type>
int SortedPriorityQueue<Type>::pq_size(){
    return size;
}

#endif