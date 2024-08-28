#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include "SortedPriorityQueue.h"

using namespace std;

void bucket_sort(int *arr, int n, int dig);
int get_max(int *arr, int n);
int get_dig(int num, int dig);

void radixSort(int *arr, int n) {
    int max = get_max(arr, n);

    int dig = 0;
    while(max != 0){
        bucket_sort(arr, n, dig);
        dig++;
        max = max/10;
    }
}

int get_dig(int num, int dig){
    int number = num/(pow(10, dig));
    number = number%10;
    return number;
}

void bucket_sort(int *arr, int n, int dig){
    vector<list<int>> table(10);
    for(int i = 0; i < n; i++){
        table[get_dig(arr[i], dig)].push_back(arr[i]);
    }

    int j = 0;
    for(int i = 0; i < 10; i++){
        while(table[i].empty() == false){
            arr[j] = table[i].front();
            table[i].pop_front();
            j++;
        }
    }
}

int get_max(int *arr, int n){
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void insertionSort(int *arr, int n) {
    SortedPriorityQueue<int>* pq = new SortedPriorityQueue<int>();
    for(int i = 0; i < n; i++){
        pq->pq_insert(arr[i]);
    }

    for(int i = 0; i < n; i++){
        arr[i] = pq->pq_delete();
    }
}
