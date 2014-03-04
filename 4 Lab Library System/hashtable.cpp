//
//  hashtable.cpp
//  4 Lab Library System
//
//  Created by Tom Petit on 3/2/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#include "hashtable.h"

HashTable::HashTable(int initial) {
    table = new Hashable*[initial];
    tableSize = initial;
}
HashTable::~HashTable() {
    delete table;
}

bool HashTable::add(char key, Hashable& value) {
    int index = indexOf(key);
    
    table[index] = &value;
    return true;
}

Hashable* HashTable::get(char key) const {
    return table[indexOf(key)];
}

Hashable* HashTable::remove(char key) {
    int index = indexOf(key);
    Hashable* toRemove = table[index];
    
    table[index] = NULL;
    return toRemove;
}

int HashTable::indexOf(char key) const {
    int index = key - 'A';
    
    //Quadratic probing, closed hashing.
    for(int collisions = 1; table[index] != NULL && table[index]->hash() != key; collisions++) {
        index = index + (collisions*collisions) % tableSize;
    }
    return index;
}

/*
class HashTable {
public:
    HashTable(int initialSize = 71); // prime #.
    ~HashTable();
    
    bool add(char key, Hashable& value);
    Hashable* remove(char key);
    void clear();
    
    Hashable& get(char key) const;
    
    bool isEmpty() const;
    bool contains(char key) const;
    
    int size() const;
private:
    Hashable** table; //array used for table in the hashtable.
    int tableSize;
    int elementCount;
};
*/