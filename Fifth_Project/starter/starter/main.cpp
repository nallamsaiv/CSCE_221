#include "AbstractHashTable.h"
#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;



int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::string filename = "dictionary.txt";
    std::ifstream file(filename);
    std::ofstream file2("data.csv");
    std::srand(time(NULL));
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 0;
    }

    vector<string> words;
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }

    file.close();

    int interval = 50000;

    char delem = ',';

    file2 << "Entries,Chaining,Probing,Double" << endl;

    for(int num_keys = 0; num_keys <= 20; num_keys++){
        int entries = 10 + (num_keys * interval);

        file2 << entries << delem;

        cout << "Chaining Hash Table" << endl;
        AbstractHashTable* cht = new ChainingHashTable();
        int count = 0;
        start = std::chrono::system_clock::now();
        for (int i = 0; i < entries; i++) {
            std::string word = words[i];
            cht->insert(word, 1);
            count++;
        }
        cout << "Entries: " << count << endl;
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Run Time: " << elapsed.count() << endl << endl;
        file2 << elapsed.count() << delem;
        delete cht;  

        
        cout << "Probing Hash Table" << endl;
        AbstractHashTable* pht = new ProbingHashTable();
        count = 0;
        start = std::chrono::system_clock::now();
        for (int i = 0; i < entries; i++) {
            std::string word = words[i];
            pht->insert(word, 1);
            count++;
        }
        cout << "Entries: " << count << endl;
        end = std::chrono::system_clock::now();
        elapsed = end - start;
        std::cout << "Run Time: " << elapsed.count() << endl << endl;
        file2 << elapsed.count() << delem;
        delete pht; 


        cout << "Double Hash Table" << endl;
        AbstractHashTable* dht = new DoubleHashTable();
        count = 0;
        start = std::chrono::system_clock::now();
        for (int i = 0; i < entries; i++) {
            std::string word = words[i];
            dht->insert(word, 1);
            count++;
        }
        cout << "Entries: " << count << endl;
        end = std::chrono::system_clock::now();
        elapsed = end - start;
        std::cout << "Run Time: " << elapsed.count() << endl << endl;
        file2 << elapsed.count() << endl;
        delete dht;
    }

    return 0;
}