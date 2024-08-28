#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

using namespace std;

template <typename Type>
class PriorityQueueHeap : public AbstractPriorityQueue<Type> {
private:
    Type *arr;
    int capacity;
    int size;
    
    void minHeapify(int i);
    void bubbleUp(int i);
    int pq_parent(int i);

public:
    PriorityQueueHeap();

    ~PriorityQueueHeap();

    int pq_size();
    
    Type pq_get_min();

    void pq_insert(Type value);

    Type pq_delete();
};

// Your implementation here

template <typename Type>
PriorityQueueHeap<Type>::PriorityQueueHeap(){
    capacity = 1;
    size = 0;
    arr = new Type[1];
}

template <typename Type>
PriorityQueueHeap<Type>::~PriorityQueueHeap(){
    delete [] arr;
    size = 0;
    capacity = 0;
    arr = nullptr;
}

template <typename Type>
int PriorityQueueHeap<Type>::pq_size() {
    return size;
}

template <typename Type>
int PriorityQueueHeap<Type>::pq_parent(int i){
    int x = (i-1)/2;
    return x;
}

template <typename Type>
Type PriorityQueueHeap<Type>::pq_get_min(){
    if(size != 0){
    return arr[0];
   }else{
    throw out_of_range("The pq is empty");
   }
}

template <typename Type>
void PriorityQueueHeap<Type>::pq_insert(Type x) {
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
        arr[size] = x;
        size++;
    }else{
        arr[size] = x;
        size++;
    }
    if(size != 1){
        bubbleUp(size - 1);
    }
}


template <typename Type>
void PriorityQueueHeap<Type>::bubbleUp(int i){
    if(arr[i] > arr[pq_parent(i)]){
        return;
    }else{
        Type temp = arr[i];
        arr[i] = arr[pq_parent(i)];
        arr[pq_parent(i)] = temp;
        if(pq_parent(i) != 0){
            bubbleUp(pq_parent(i));
        }else{
            return;
        }
    }
}

template <typename Type>
Type PriorityQueueHeap<Type>::pq_delete(){
    if(size == 0){
    throw out_of_range("pq is empty");
   }
   Type element_to_return = arr[0];
   arr[0] = arr[size-1];
   size--;
   if(size > 0){
    minHeapify(0);
   }
   return element_to_return;
}

template <typename Type>
void PriorityQueueHeap<Type>::minHeapify(int i){
    int left_child = (2*i) + 1;
    int right_child = (2*i) + 2;
    int larger_val = i;
    if(left_child < size && (arr[left_child] < arr[larger_val])){
        larger_val = left_child;
    }
    if(right_child < size && (arr[right_child] < arr[larger_val])){
        larger_val = right_child;
    }
    if(larger_val != i){
        Type temp = arr[i];
        arr[i] = arr[larger_val];
        arr[larger_val] = temp;
        minHeapify(larger_val);
    }else{
        return;
    }
    
}

#endif