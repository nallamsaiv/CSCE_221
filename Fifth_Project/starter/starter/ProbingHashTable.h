#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "AbstractHashTable.h"
#include <vector>

// Linear probing hash table class
class ProbingHashTable : public AbstractHashTable {
    private:
    std::vector<HashEntry> table;
    void resizeAndRehash();
    
    public: 
    ProbingHashTable();
    ~ProbingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key) const; 
    bool contains(std::string key) const;
};

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor 
ProbingHashTable::ProbingHashTable(): AbstractHashTable() {
    capacity = 11;
    num_elements = 0;
    table.resize(capacity);
    maxLoadFactor = 0.6;
}

// destructor
ProbingHashTable::~ProbingHashTable() {
   capacity = 0;
   num_elements = 0;
   table.clear();
}

// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {

    int i = 0;
    int hashed = hash(key);
    int index = 0;
    int delete_available = -1;
    int empty_available = -1;
    bool inserted = false;

    while(i < capacity){
        index = (hashed + i) % capacity;

        if(table[index].key == key && table[index].DELETED == false && table[index].isFilled == true){
            table[index].val = val;
            inserted = true;
            break;
        }else if(delete_available == -1 && table[index].DELETED == true && table[index].isFilled == false){
            delete_available = index;
        }else if(table[index].DELETED == false && table[index].isFilled == false){
            empty_available = index;
            break;
        }
        i++;
    }


    if(inserted == false && delete_available == -1){
        table[empty_available] = HashEntry(key, val);
        num_elements++;
    }else if(inserted == false && delete_available != -1){
        table[delete_available] = HashEntry(key, val);
        num_elements++;
    }

    if(load_factor() > maxLoadFactor){
        resizeAndRehash();
    }

}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(std::string key) {
    int index = 0;
    int hashed = hash(key);
    int i = 0;

    while(i < capacity){
        index = (hashed + i) % capacity;

        if(table[index].key == key && table[index].DELETED != true && table[index].isFilled != false){
            table[index].DELETED = true;
            table[index].isFilled = false;
            num_elements--;
            return table[index].val;
        }else if(table[index].DELETED == false && table[index].isFilled == false){
            throw std::out_of_range("key does not exist");
        }
        i++;
    }
    
	throw std::out_of_range("key does not exist");
}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(std::string key) const {
	int index = 0;
    int hashed = hash(key);
    int i = 0;

    while(i < capacity){
        index = (hashed + i) % capacity;

        if(table[index].key == key && table[index].DELETED != true && table[index].isFilled != false){
            return table[index].val;
        }else if(table[index].DELETED == false && table[index].isFilled == false){
            throw std::out_of_range("key does not exist");
        }
        i++;
    }

    throw std::out_of_range("key does not exist");
}

bool ProbingHashTable::contains(std::string key) const {
	int index = 0;
    int hashed = hash(key);
    int i = 0;

    while(i < capacity){
        index = (hashed + i) % capacity;

        if(table[index].key == key && table[index].DELETED != true && table[index].isFilled != false){
            return true;
        }else if(table[index].DELETED == false && table[index].isFilled == false){
            return false;
        }
        i++;
    }

    return false;
}

void ProbingHashTable::resizeAndRehash() {
    int new_capacity = findNextPrime(capacity*2);
    std::vector<HashEntry> new_table(capacity);
    new_table = table;
    table.clear();
    capacity = new_capacity;
    table.resize(capacity);
    num_elements = 0;

    for(int i = 0; i < new_table.size(); i++){
        if(new_table[i].isFilled == true){
            this->insert(new_table[i].key, new_table[i].val);
        }
    }
    
}

#endif