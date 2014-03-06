//
//  hashtable.h
//  4 Lab Library System
//
//  Created by Tom Petit on 3/2/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include <iostream>
#include "hashable.h"

/*
 ADT SPEC:
 
 isEmpty(): boolean
 getNumberOfItems(): integer
 add(itemKey: KeyType, newItem: ItemType): boolean
 remove(itemKey: KeyType): boolean
 clear(): void
 geItem(itemKey: KeyType): ItemType
 contains(itemKey: KeyType): boolean
 traverse(visit(item: ItemType): void): void
 
 Carrano, Frank M. (2012-11-05). Data Abstraction & Problem Solving with C++:
 Walls and Mirrors (2-download) (6th Edition) (Page 529). Prentice Hall. 
 Kindle Edition.
*/

class HashTable {
public:
    HashTable(int initialSize = 71); // prime #.
    virtual ~HashTable();
    
    bool add(char key, Hashable* value);
    Hashable* remove(char key);
    void clear();
    
    Hashable* get(char key) const;
    
    bool isEmpty() const;
    bool contains(char key) const;
    
    int size() const;

private:
    Hashable** table; //array used for table in the hashtable.
    int tableSize;
    int elementCount;
    
    int indexOf(char key) const;
};

#endif /* __HASHTABLE_H */

