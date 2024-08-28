#ifndef CHAINING_H
#define CHAINING_H

#include "AbstractHashTable.h"
#include <vector>
#include <list>


// Chaining hash table class
class ChainingHashTable: public AbstractHashTable {
    private:
    std::vector<std::list<HashEntry>> table;
    void resizeAndRehash();

    public: 
    ChainingHashTable();
    ~ChainingHashTable(); 
    void insert(std::string key, const int val); 
    int remove(std::string key); 
    int get(std::string key) const;
    bool contains(std::string key) const;
};


///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor
ChainingHashTable::ChainingHashTable(): AbstractHashTable() {
    capacity = 11;
    num_elements = 0;
    table.resize(capacity);
    maxLoadFactor = 1.1;
}

// destructor
ChainingHashTable::~ChainingHashTable() {
   capacity = 0;
   num_elements = 0;
   table.resize(capacity);
}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
    int index = hash(key);
    for(std::list<HashEntry>::iterator it = table[index].begin(); it != table[index].end(); ++it){
        if(it->key == key){
            it->val = val;
            return;
        }
    }

    num_elements++;
    if(load_factor() > maxLoadFactor){
        resizeAndRehash();
    }
    index = hash(key);
    table[index].push_back(HashEntry(key, val));
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
    int index = hash(key);
    for(std::list<HashEntry>::iterator it = table[index].begin(); it != table[index].end(); ++it){
        if(it->key == key){
            int val_to_return = it->val;
            table[index].erase(it);
            num_elements--;
            return val_to_return;
        }
    }

    throw std::out_of_range("key does not exist");
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) const {
    int index = hash(key);
    for(std::list<HashEntry>::const_iterator it = table[index].cbegin(); it != table[index].cend(); ++it){
        if(it->key == key){
            return it->val;
        }
    }

    throw std::out_of_range("key does not exist");
}

bool ChainingHashTable::contains(const std::string key) const {
    int index = hash(key);
    for(std::list<HashEntry>::const_iterator it = table[index].cbegin(); it != table[index].cend(); ++it){
        if(it->key == key){
            return true;
        }
    }
	return false;
}

void ChainingHashTable::resizeAndRehash() {
    int new_capacity = findNextPrime(capacity*2);
    std::vector<std::list<HashEntry>> new_table(new_capacity);
    int new_index = 0;
    capacity = new_capacity;

    for(int i = 0; i < table.size(); i++){
        for(std::list<HashEntry>::iterator it = table[i].begin(); it != table[i].end(); ++it){
            new_index = hash(it->key);
            new_table[new_index].push_back(HashEntry(it->key, it->val));
        }
    }

    table = new_table;
}

#endif