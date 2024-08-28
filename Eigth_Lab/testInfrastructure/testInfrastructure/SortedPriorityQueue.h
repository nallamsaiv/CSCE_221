#ifndef SORTED_PRIORITY_QUEUE_H
#define SORTED_PRIORITY_QUEUE_H

template <typename Type>
class SortedPriorityQueue {
    private:
        Type *arr;
        int capacity;
        int startIndex;
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
    startIndex = 0;
    arr = new Type[1];
}

template <typename Type>
SortedPriorityQueue<Type>::~SortedPriorityQueue(){
    delete [] arr;
    size = 0;
    capacity = 0;
    startIndex = 0;
    arr = nullptr;
}

template <typename Type>
void SortedPriorityQueue<Type>::pq_insert(Type value) {
    if(capacity < (size + 1)){
        capacity = capacity * 2;
        Type* temp_data = new Type[capacity];
        for(int i = startIndex; i < (size + startIndex); i++){
            temp_data[i-startIndex] = arr[i];
        }
        delete [] arr;
        arr = new Type[capacity];
        for(int i = 0; i < size; i++){
            arr[i] = temp_data[i];
        }
        delete [] temp_data;
        startIndex = 0;
    }
    arr[size] = value;
    size++;

    bool sorted = false;
    int curr = size - 1;
    Type temp;
    while(sorted == false){
        if(curr == 0 || arr[curr] <= arr[curr - 1]){
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
    size--;
    return arr[size];
}

template <typename Type>
Type SortedPriorityQueue<Type>::pq_get_min(){
    if(size != 0){
        return arr[size-1];
    }
}

template <typename Type>
int SortedPriorityQueue<Type>::pq_size(){
    return size;
}

#endif