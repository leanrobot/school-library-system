//-----------------------------------------------------------------------------
// HashTable class: is a class which is a hash table container class. It is
// responsible for holding different types of hashable data.
//
// Assumptions:
// - The keys may only be chars from A - Z, inclusive.
// - Values from be a derived class of Hashable.
//-----------------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "hashable.h"

/*
 ADT SPEC:
 
 isEmpty(): boolean
 getNumberOfItems(): integer
 add(itemKey: KeyType, newItem: ItemType): boolean
 remove(itemKey: KeyType): boolean
 clear(): void
 getItem(itemKey: KeyType): ItemType
 contains(itemKey: KeyType): boolean
 traverse(visit(item: ItemType): void): void
 
 Carrano, Frank M. (2012-11-05). Data Abstraction & Problem Solving with C++:
 Walls and Mirrors (2-download) (6th Edition) (Page 529). Prentice Hall. 
 Kindle Edition.
*/

class HashTable {
public:
    // constructor
    HashTable(int initialSize = 71); // prime #.
    // destructor
    virtual ~HashTable();
    
    // impl of add, adds an item.
    bool add(char key, Hashable* value);
    // impl of remove, removes an item.
    Hashable* remove(char key);
    // impl of clear, clears the table.
    void clear();
    
    // impl of getItem in ADT, retrieves a values associated with key.
    Hashable* get(char key) const;
    
    // impl of isEmpty, true if empty, false otherwise.
    bool isEmpty() const;
    // impl of contains, returns whether there is values associated with key.
    bool contains(char key) const;
    
    // impl of getNumberOfItem in ADT, returns amount of values in table.
    int size() const;

private:
    Hashable** table; //array used for underlying table in the hashtable.
    int tableSize; // size of the table.
    int elementCount; // number of values in the table.
    
    int indexOf(char key) const; // private helper for determining indexes
                        // all operations.
};

#endif /* HASHTABLE_H */

