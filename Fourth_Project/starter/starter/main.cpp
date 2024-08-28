#include "AbstractPriorityQueue.h"
#include "PriorityQueueHeap.h"
#include "UnsortedPriorityQueue.h"
#include "SortedPriorityQueue.h"
#include <chrono>
using namespace std;

#ifndef TEST
int main() {
    // You can write your own test cases here
    std::chrono::time_point<std::chrono::system_clock> start, end;

    for(int i = 1; i <= 10; i++){
        int counter = 10000*i;

        SortedPriorityQueue<int> sorted_pq;
        UnsortedPriorityQueue<int> unsorted_pq;
        PriorityQueueHeap<int> heap_pq;

        cout << counter << " inserts:" << endl;

        start = std::chrono::system_clock::now();
        for(int i = 1; i <= counter; i++){
            sorted_pq.pq_insert(i);
        }
        for(int i = 1; i <= counter; i++){
            int min = sorted_pq.pq_delete();
        }
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Sorted Priority Queue Run Time: " << elapsed.count() << endl;

        start = std::chrono::system_clock::now();
        for(int i = 1; i <= counter; i++){
            unsorted_pq.pq_insert(i);
        }
        for(int i = 1; i <= counter; i++){
            int min = unsorted_pq.pq_delete();
        }
        end = std::chrono::system_clock::now();
        elapsed = end - start;
        std::cout << "Unsorted Priority Queue Run Time: " << elapsed.count() << endl;

        start = std::chrono::system_clock::now();
        for(int i = 1; i <= counter; i++){
            heap_pq.pq_insert(i);
        }
        for(int i = 1; i <= counter; i++){
            int min = heap_pq.pq_delete();
        }
        end = std::chrono::system_clock::now();
        elapsed = end - start;
        std::cout << "Heap Priority Queue Run Time: " << elapsed.count() << endl;
        cout << endl;
    }
    return 0;
}
#endif