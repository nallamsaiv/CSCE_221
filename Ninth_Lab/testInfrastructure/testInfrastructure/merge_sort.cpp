#include <iostream>
#include <thread>
using namespace std;

void merge(int *arr, int start, int half, int end);

void mergeSort(int * arr, int start, int end, int level) {
    int half;
    if(((end - start) + 1) > 1){
        half = start + (end - start) / 2;
        if(level > 0){
            std::thread thread1(mergeSort, arr, start, half, level - 1);
            std::thread thread2(mergeSort, arr, half + 1, end, level - 1);

            thread1.join();
            thread2.join();
        }else{
            mergeSort(arr, start, half, level - 1);
            mergeSort(arr, half + 1, end, level - 1);
        }
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