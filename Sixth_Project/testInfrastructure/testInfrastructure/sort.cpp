#include <iostream>
#include <queue>
#include <random>
using namespace std;

void merge(int *arr, int start, int half, int end);
int partition(int *arr, int pivot, int start, int end);

void bubbleSort(int *arr, int size){
    int temp;
    int back = 0;
    for (int i = 0; i < (size - 1); i++){
        for (int j = 0; j < (size - 1 - back); j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        back++;
    }
}

void heapSort(int *arr, int size){
    priority_queue <int, vector<int>, greater<int> > pq; 
 
    for (int i = 0; i < size; i++) {
        pq.push(arr[i]);
    }
    
    int index = 0;
    while (pq.empty() == false) {
        arr[index] = pq.top();
        pq.pop();
        index++;
    }
}

void mergeSort(int *arr, int start, int end) {
    int half;

    if(((end - start) + 1) > 1){
        half = start + (end - start)/2;
        mergeSort(arr, start, half);
        mergeSort(arr, half + 1, end);
        merge(arr, start, half, end);
    }else{
        return;
    }
}

void merge(int *arr, int start, int half, int end){
    int size_1 = half - start + 1;
    int size_2 = end - half;
    int left[size_1];
    int right[size_2];

    for (int i = 0; i < size_1; i++){
        left[i] = arr[start + i];
    }
    for (int j = 0; j < size_2; j++){
        right[j] = arr[half + 1 + j];
    }
    
    int n = (end - start) + 1;
    int i = 0;
    int j = 0;
    int k = start;

    while(i + j < n){
        if (i < size_1 && (j >= size_2 || left[i] <= right[j])){
            arr[k] = left[i];
            i++;
        }else if(j < size_2) {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
}

void quickSort(int *arr, int start, int end) {
    if(((end - start) + 1) <= 1){
        return;
    }
    int pivot = end;
    int place_partitioned = partition(arr, pivot, start, end);
    quickSort(arr, start, place_partitioned - 1);
    quickSort(arr, place_partitioned + 1, end);
}

int partition(int *arr, int pivot, int start, int end){
    int pivot_val = arr[pivot];
    int begin_less = start;
    int temp;

    for(int i = start; i < (end + 1); i++){
        if(arr[i] < pivot_val){
            temp = arr[begin_less];
            arr[begin_less] = arr[i];
            arr[i] = temp;
            begin_less++;
        }
    }
    temp = arr[begin_less];
    arr[begin_less] = arr[pivot];
    arr[pivot] = temp;
    return begin_less;
}
