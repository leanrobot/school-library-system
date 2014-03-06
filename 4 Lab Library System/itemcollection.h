//
//  itemcollection.h
//  4 Lab Library System
//
//  Created by Tom Petit on 3/5/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#ifndef ____Lab_Library_System__itemcollection__
#define ____Lab_Library_System__itemcollection__

#include <iostream>
#include <vector>
#include "item.h"

class ItemCollection {
public:
    ItemCollection();
    ~ItemCollection();
    bool insert(Item* item);
    Item* retrieve(Item* item);
    Item* retrieve(int index);
    int size() const;
private:
    vector<Item*> items;
};

#endif /* defined(____Lab_Library_System__itemcollection__) */
