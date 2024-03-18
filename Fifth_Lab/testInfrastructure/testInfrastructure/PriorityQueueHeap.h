#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <iostream>

using namespace std;

template <typename Type, typename Compare = std::greater<Type>>
class PriorityQueueHeap {
private:
    Compare compare;
    Type *arr;
    int capacity;
    int size;

    void heapify(int i);
    void bubbleUp(int i);
    int pq_parent(int i);

public:
    PriorityQueueHeap();

    PriorityQueueHeap(const PriorityQueueHeap& other);

    PriorityQueueHeap(const Compare& comp);

    PriorityQueueHeap& operator=(const PriorityQueueHeap& other);

    ~PriorityQueueHeap();

    int pq_size();

    bool is_pq_empty();
    
    Type pq_top();

    void pq_insert(Type x);

    Type pq_delete();
};

// Your implementation here

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::PriorityQueueHeap() : compare() {
    capacity = 1;
    size = 0;
    arr = new Type[1];
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::~PriorityQueueHeap(){
    delete [] arr;
    size = 0;
    capacity = 0;
    arr = nullptr;
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::PriorityQueueHeap(const Compare& _comp) {
    compare = _comp; 
    capacity = 1;
    size = 0;
    arr = new Type[1];
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::PriorityQueueHeap(const PriorityQueueHeap& other) {
    arr = new Type[other.capacity];
    capacity = other.capacity;
    size = other.size;
    compare = other.compare;
    for(int i = 0; i < other.size; i++){
        arr[i] = other.arr[i];
    }
   
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>& PriorityQueueHeap<Type, Compare>::operator=(const PriorityQueueHeap& other) {
    if(this == &other){
        return *this;
    }

    delete [] arr;

    arr = new Type[other.capacity];
    capacity = other.capacity;
    size = other.size;
    compare = other.compare;
    for(int i = 0; i < other.size; i++){
        arr[i] = other.arr[i];
    }

    return *this;
}

template <typename Type, typename Compare>
int PriorityQueueHeap<Type, Compare>::pq_size() {
    return size;
}

template <typename Type, typename Compare>
bool PriorityQueueHeap<Type, Compare>::is_pq_empty(){
    return size == 0;
}

template <typename Type, typename Compare>
int PriorityQueueHeap<Type, Compare>::pq_parent(int i){
    int x = (i-1)/2;
    return x;
}

template <typename Type, typename Compare>
Type PriorityQueueHeap<Type, Compare>::pq_top(){
   if(is_pq_empty() == false){
    return arr[0];
   }else{
    throw out_of_range("The pq is empty");
   }
}

template <typename Type, typename Compare>
void PriorityQueueHeap<Type, Compare>::pq_insert(Type x) {
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


template <typename Type, typename Compare>
void PriorityQueueHeap<Type, Compare>::bubbleUp(int i){
    if(compare(arr[i], arr[pq_parent(i)]) == 1){
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

template <typename Type, typename Compare>
Type PriorityQueueHeap<Type, Compare>::pq_delete(){
  if(is_pq_empty() == true){
    throw out_of_range("pq is empty");
   }
   Type element_to_return = arr[0];
   arr[0] = arr[size-1];
   size--;
   if(size > 0){
    heapify(0);
   }
   return element_to_return;
}

template <typename Type, typename Compare>
void PriorityQueueHeap<Type, Compare>::heapify(int i){
    int left_child = (2*i) + 1;
    int right_child = (2*i) + 2;
    int larger_val = i;
    if(left_child < size && (compare(arr[left_child], arr[larger_val]) == 0)){
        larger_val = left_child;
    }
    if(right_child < size && (compare(arr[right_child], arr[larger_val]) == 0)){
        larger_val = right_child;
    }
    if(larger_val != i){
        Type temp = arr[i];
        arr[i] = arr[larger_val];
        arr[larger_val] = temp;
        heapify(larger_val);
    }else{
        return;
    }
}

#endif