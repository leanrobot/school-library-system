//
//  itemcollection.cpp
//  4 Lab Library System
//
//  Created by Tom Petit on 3/6/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#include "itemcollection.h"

ItemCollection::ItemCollection() {
    for(int i=0; i < MAX_ITEM_TYPES; i++) {
        items[i] = NULL;
    }
}
ItemCollection::~ItemCollection() {
    for (int i = 0; i < MAX_ITEM_TYPES; i++){
        if (items[i]!=NULL){
            delete items[i];
        }
    }
}

bool ItemCollection::insert(Item* toInsert) {
    char itemType = toInsert->hash();
    int index = hash(itemType);
    if(items[index] == NULL) {
        items[index] = new ItemTree;
    }
    items[index]->insert(toInsert);
    return true;
}

Item* ItemCollection::retrieve(Item* toGet) {
    char itemType = toGet->hash();
    
    ItemTree* tree = items[hash(itemType)];
    Item* gotten = tree->retrieve(toGet);
    
    return gotten;
}

ItemTree** ItemCollection::retrieveAll(int& arraySize) {
    arraySize = MAX_ITEM_TYPES;
    return items;
}


int ItemCollection::hash(char ch) {
    return ch - 'A';
}
