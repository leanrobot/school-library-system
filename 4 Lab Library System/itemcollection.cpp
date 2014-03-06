//
//  itemcollection.cpp
//  4 Lab Library System
//
//  Created by Tom Petit on 3/5/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#include "itemcollection.h"

ItemCollection::ItemCollection() {
    //vector is instantiated automatically.
}

ItemCollection::~ItemCollection() {
    items.clear();
    //vector is destroyed automatically
}

bool ItemCollection::insert(Item* item) {
    
    std::vector<Item*>::iterator iter = items.begin();
    if(items.size() > 0) {
        for(; iter != items.end() && *(*iter) < *item ; iter++) {
        }
        items.insert(iter, item);
    }
    else {
        items.push_back(item);
    }
    
    return true;
}

Item* ItemCollection::retrieve(Item* item) {
    
    std::vector<Item*>::iterator iter;
    for(iter=items.begin(); iter != items.end(); iter++) {
        if(*item == **iter) return *iter;
    }
    return NULL;
}

Item* ItemCollection::retrieve(int i) {
    return items[i];
}

int ItemCollection::size() const {
    return items.size();
}