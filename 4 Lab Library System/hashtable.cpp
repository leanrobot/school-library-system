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
    elementCount = 0;
}
HashTable::~HashTable() {
    delete table;
}

bool HashTable::add(char key, Hashable* value) {
    int index = indexOf(key);
    if(index < 0) return false;
    
    table[index] = value;
    elementCount++;
    return true;
}

Hashable* HashTable::get(char key) const {
    int index = indexOf(key);
    if(index < 0) return NULL;
    return table[index];
}

Hashable* HashTable::remove(char key) {
    int index = indexOf(key);
    if(index < 0) return NULL;
    Hashable* toRemove = table[index];
    
    elementCount--;
    table[index] = NULL;
    return toRemove;
}

int HashTable::indexOf(char key) const {
    if(!('A' <= key && key <= 'Z')) return -1;
    int index = (key - 'A') % tableSize;
    
    //Quadratic probing, closed hashing.
    for(int collisions = 1; table[index] != NULL && table[index]->hash() != key; collisions++) {
        index = index + (collisions*collisions) % tableSize;
    }
    return index;
}

bool HashTable::isEmpty() const {
    return elementCount == 0;
}
bool HashTable::contains(char key) const {
    return get(key) != NULL;
}

int HashTable::size() const {
    return elementCount;
}

/*
class HashTable {
public:
    HashTable(int initialSize = 71); // prime #.
    ~HashTable();
    
    bool add(char key, Hashable& value);
    Hashable* remove(char key);
    void clear(); TODO
    
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