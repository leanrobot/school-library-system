//
//  itemcollection.h
//  4 Lab Library System
//
//  Created by Tom Petit on 3/6/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#ifndef ____Lab_Library_System__itemcollection__
#define ____Lab_Library_System__itemcollection__

#include <iostream>
#include "itemtree.h"

class ItemCollection {
private:
    
    static const int MAX_ITEM_TYPES = 26;
    ItemTree* items[MAX_ITEM_TYPES];
    int hash(char ch);


public:
    ItemCollection();
    ~ItemCollection();
    bool insert(Item*);
    Item* retrieve(Item*);
    ItemTree** retrieveAll(int& arraySize); //returns items array.

};

#endif /* defined(____Lab_Library_System__itemcollection__) */
