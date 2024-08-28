#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Node {
public:
    int key;
    std::vector<Node*> forward;

    Node(int key, int level) : key(key), forward(level + 1, nullptr) {}
};

class SkipList {
private: 
    double P;
    int MAXLVL;
    Node* header;
    int level;

public:
    SkipList(int max_lvl, double p);
    ~SkipList();
    int randomLevel();
    void insertElement(int key);
    void deleteElement(int search_key);
    bool searchElement(int key);
    void displayList();
};


SkipList::SkipList(int max_lvl, double p) : MAXLVL(max_lvl), P(p), level(0) {
    header = new Node(-1, MAXLVL);
}

SkipList::~SkipList() {
   Node* temp_node = header->forward[0];
   while(temp_node != nullptr){
        Node* curr_node = temp_node;
        temp_node = temp_node->forward[0];
        delete curr_node;
   }
} 

int SkipList::randomLevel() {
    float random_num = (float)rand()/RAND_MAX;
    for(int level = 0; level < MAXLVL; level++){
        if(random_num >= P){
            return level;
        }
        random_num = (float)rand()/RAND_MAX;
    } 
    return MAXLVL;
}

void SkipList::insertElement(int key) {
    Node* curr_node = header;
 
    vector<Node*> vect(MAXLVL + 1);
 
    for(int i = level; i >= 0; i--){
        while((curr_node->forward[i] != nullptr) && (curr_node->forward[i]->key < key)){
            curr_node = curr_node->forward[i];
        }
        vect[i] = curr_node;
    }
 
    curr_node = curr_node->forward[0];
 
    if((curr_node == nullptr) || (curr_node->key != key)){
        int random_level = randomLevel();
        if(random_level > level){
            for(int i = level + 1; i < random_level + 1;i++){
                vect[i] = header;
            }
            level = random_level;
        }
 
        Node* new_node = new Node(key, random_level);
 
        for(int i = 0; i <= random_level; i++){
            new_node->forward[i] = vect[i]->forward[i];
            vect[i]->forward[i] = new_node;
        }
    }
    
}

void SkipList::deleteElement(int search_key) {
    Node* curr_node = header;
 
    vector<Node*> vect(MAXLVL + 1);
 
    for(int i = level; i >= 0; i--){
        while((curr_node->forward[i] != nullptr) && (curr_node->forward[i]->key < search_key)){
            curr_node = curr_node->forward[i];
        }
        vect[i] = curr_node;
    }
 
    curr_node = curr_node->forward[0];
 
    if((curr_node != nullptr) && (curr_node->key == search_key)){
        for(int i = 0; i < level + 1;i++){
            if(vect[i]->forward[i] != curr_node){
                break;
            }
            vect[i]->forward[i] = curr_node->forward[i];
        }
 
        delete curr_node;
 
        while((level > 0) && (header->forward[level] == nullptr)){
            level--;
        }
    }
    
}

bool SkipList::searchElement(int key) {
    Node* curr_node = header;
    int level_number = level;
    while(level_number >= 0){
        Node* next = curr_node->forward[level_number];
        while(next != nullptr){
            if(next->key == key){
                return true;
            }else if(next->key > key){
                break;
            }
            next = next->forward[level_number];
        }
        level_number--;
    }
    return false;
}

void SkipList::displayList() {
    std::cout << "\n*****Skip List******" << std::endl;
    Node* head = header;
    for (int lvl = 0; lvl <= level; lvl++) {
        std::cout << "Level " << lvl << ": ";
        Node* node = head->forward[lvl];
        while (node != nullptr) {
            std::cout << node->key << " ";
            node = node->forward[lvl];
        }
        std::cout << std::endl;
    }
}

#endif