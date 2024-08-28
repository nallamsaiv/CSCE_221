#include "sort.cpp"
#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::ofstream file("data.csv");
    std::srand(time(NULL));
    if (!file.is_open()) {
        std::cerr << "Error opening file: data.csv" << std::endl;
        return 0;
    }

    file << "Input Size,Bubble Sort,Heap Sort,Merge Sort,Quick Sort" << endl;

    char delem = ',';

    for(int i = 10; i <= 1000000; i = i * 10){
        int *arr = new int[i];
        vector<int> arrCopy;

        for(int j = 0; j < i; j++){
            arr[j] = rand() % 1000000 + 1;
            arrCopy.push_back(arr[j]);
        }

        std::chrono::duration<double> elapsed;
        
        file << i << delem;
        if(i <= 100000){
            cout << "Bubble Sort" << endl;
            start = std::chrono::system_clock::now();
            bubbleSort(arr, i);
            end = std::chrono::system_clock::now();
            cout << "Input Size: " << i << endl;
            elapsed = end - start;
            std::cout << "Run Time: " << elapsed.count() << endl << endl;
            file << elapsed.count() << delem;
        }else{
            file << delem;
        }
        
        for(int j = 0; j < i; j++){
            arr[j] = arrCopy[j];
        }
        
        cout << "Heap Sort" << endl;
        start = std::chrono::system_clock::now();
        heapSort(arr, i);
        end = std::chrono::system_clock::now();
        cout << "Input Size: " << i << endl;
        elapsed = end - start;
        std::cout << "Run Time: " << elapsed.count() << endl << endl;
        file << elapsed.count() << delem;

        for(int j = 0; j < i; j++){
            arr[j] = arrCopy[j];
        }

        cout << "Merge Sort" << endl;
        start = std::chrono::system_clock::now();
        mergeSort(arr, 0, (i - 1));
        end = std::chrono::system_clock::now();
        cout << "Input Size: " << i << endl;
        elapsed = end - start;
        std::cout << "Run Time: " << elapsed.count() << endl << endl;
        file << elapsed.count() << delem;
        
        for(int j = 0; j < i; j++){
            arr[j] = arrCopy[j];
        }

        cout << "Quick Sort" << endl;
        start = std::chrono::system_clock::now();
        quickSort(arr, 0, (i - 1));
        end = std::chrono::system_clock::now();
        cout << "Input Size: " << i << endl;
        elapsed = end - start;
        std::cout << "Run Time: " << elapsed.count() << endl << endl;
        file << elapsed.count() << endl;

        delete [] arr;
        arrCopy.clear();
    }
}