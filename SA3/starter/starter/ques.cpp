#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "PriorityQueueHeap.h"

using namespace std;

#ifndef INTERSECTION_ARRAY
 
vector<int> intersectionOfTwoArrays(vector<int> nums, vector<int> otherNums) {
    vector<int> intersection;
    unordered_map<int, int> map_of_nums;
    int occurence = 1;
    int num;
    int other_num;

    //loop that goes over the otherNums vector and adds it to map_of_nums(unordered map)
    for(int i = 0; i < otherNums.size(); i++){
        //extracts value at position i
        other_num = otherNums[i];
        //check if the key already exists in the map, if it exists it adds one to the value of the key, else it creates a new key and sets its value to 1
        if(map_of_nums.find(other_num) == map_of_nums.end()){
            map_of_nums[other_num] = occurence;
        }else if(map_of_nums.find(other_num) != map_of_nums.end()){
            map_of_nums[other_num] = map_of_nums[other_num] + occurence;
        }   
    }

    //loop that goes over the nums vector to see the common elements present in both vectors
    for(int j = 0; j < nums.size(); j++){
        //extracts value at position j
        num = nums[j];
        //if the key is present in the map, it the adds the value to the intersection vector if the value that is associated with the key is greater than 0
        if(map_of_nums.find(num) != map_of_nums.end()){
            occurence = map_of_nums[num];
            if(occurence != 0){
                intersection.push_back(num);
                occurence = occurence - 1;
                map_of_nums[num] = occurence;
            }
        }  
    }

    //returns intersection vector
    return intersection;
}

#endif

#ifndef ROPE_GAME

int ropesGameCost(vector<int> ropes) {
    PriorityQueueHeap pq_ropes;
    int rope_size;
    int rope_size_1;
    int rope_size_2;
    int sum_curr_ropes;
    int sum_ropes = 0;

    //loop to add each element in the ropes vector to a priority queue
    for(int i = 0; i < ropes.size(); i++){
        //take element at position i and adds it to the priority queue
        rope_size = ropes[i];
        pq_ropes.pq_insert(rope_size);
    }

    //loop to extract the first 2 minimum values and add them, stops when less than 2 elements are present in the priorirty queue
    while(pq_ropes.pq_size() >= 2){
        //getting 2 minimum values
        rope_size_1 = pq_ropes.pq_delete();
        rope_size_2 = pq_ropes.pq_delete();

        //adding the 2 minimum values and adding to the overall sum
        sum_curr_ropes = rope_size_1 + rope_size_2;
        sum_ropes = sum_ropes + sum_curr_ropes;

        //inserting back into priority queue after getting the sum of the 2 minimum values
        pq_ropes.pq_insert(sum_curr_ropes);
    }

    //returns total cost
    return sum_ropes;
}

#endif

#ifndef TEST_MODE

int main() {
    // Test cases for intersectionOfTwoArrays:
    cout << "TEST CASES FOR intersectionOfTwoArrays" << endl;
    {
        cout << "Test Case 1:" << endl;
        vector<int> nums = {9, 8, 8, 7};
        vector<int> otherNums = {8, 8, 8, 9};

        vector<int> result = intersectionOfTwoArrays(nums, otherNums);
        cout << "Returned intersection: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        cout << "The above intersection should contain two 8's and one 9" << endl;
        cout << endl;
    }

    {
        cout << "Test Case 2:" << endl;
        vector<int> nums = {1, 8, 1, 8, 1, 7, 46, 1};
        vector<int> otherNums = {8, 1, 8, 1, 1, 203};

        vector<int> result = intersectionOfTwoArrays(nums, otherNums);
        cout << "Returned intersection: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        cout << "The above intersection should contain two 8's and three 1's" << endl;
        cout << endl;
    }

    {
        cout << "Test Case 3:" << endl;
        vector<int> nums = {1, 8, 7, 5, 53};
        vector<int> otherNums = {102, 203, 201, 103, 106, 107};

        vector<int> result = intersectionOfTwoArrays(nums, otherNums);
        cout << "Returned intersection: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        cout << "The above intersection should be empty (should not see any numbers)" << endl;
        cout << endl;
    }

    {
        cout << "Test Case 4:" << endl;
        vector<int> nums = {0, 9};
        vector<int> otherNums = {};

        vector<int> result = intersectionOfTwoArrays(nums, otherNums);
        cout << "Returned intersection: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        cout << "The above intersection should be empty (should not see any numbers)" << endl;
        cout << endl;
    }

    {
        cout << "Test Case 5:" << endl;
        vector<int> nums = {9};
        vector<int> otherNums = {9, 9};

        vector<int> result = intersectionOfTwoArrays(nums, otherNums);
        cout << "Returned intersection: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        cout << "The above intersection should contain one 9" << endl;
        cout << endl;
    }

    cout << "TEST CASES FOR ropesGameCost" << endl;

    {
        cout << "Test Case 1: " << endl;
        vector<int> ropes = {3, 8, 4, 6, 7};
        int actualCost = ropesGameCost(ropes);
        int expectedCost = 63;
        cout << "Returned Total Cost: " << actualCost << endl;
        cout << "Expected Total Cost: " << expectedCost << endl;
        cout << endl;
    }

     {
        cout << "Test Case 2: " << endl;
        vector<int> ropes = {3, 7, 9, 4};
        int actualCost = ropesGameCost(ropes);
        int expectedCost = 44;
        cout << "Returned Total Cost: " << actualCost << endl;
        cout << "Expected Total Cost: " << expectedCost << endl;
        cout << endl;
    }

    {
        cout << "Test Case 3: " << endl;
        vector<int> ropes = {3};
        int actualCost = ropesGameCost(ropes);
        int expectedCost = 0;
        cout << "Returned Total Cost: " << actualCost << endl;
        cout << "Expected Total Cost: " << expectedCost << endl;
        cout << endl;
    }

    {
        cout << "Test Case 4: " << endl;
        vector<int> ropes = {11, 12};
        int actualCost = ropesGameCost(ropes);
        int expectedCost = 23;
        cout << "Returned Total Cost: " << actualCost << endl;
        cout << "Expected Total Cost: " << expectedCost << endl;
        cout << endl;
    }

    return 0;
}
#endif