//
//  itemfactory.cpp
//  4 Lab Library System
//
//  Created by Tom Petit on 3/5/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#include "itemfactory.h"
#include "youth.h"
#include "fiction.h"
#include "periodical.h"

bool ItemFactory::instanceFlag = false;
ItemFactory* ItemFactory::_instance = NULL;

ItemFactory* ItemFactory::instance() {
    if(!instanceFlag) {
        _instance = new ItemFactory;
        instanceFlag = true;
    }
    return _instance;
}
ItemFactory::ItemFactory() {
    Hashable* youth = new Youth;
    Hashable* fiction = new Fiction;
    Hashable* periodical = new Periodical;
    
    itemTable.add(youth->hash(), youth);
    itemTable.add(fiction->hash(), fiction);
    itemTable.add(periodical->hash(), periodical);
}

ItemFactory::~ItemFactory() {
    if(instanceFlag) {
        instanceFlag = false;
        _instance = NULL;
    }
}


Item* ItemFactory::createItem(istream& input) {
    
    char itemType = input.get(); //get the item type.
    input.get(); //throwaway the space.
    
    //cout << "looking for " << itemType << endl;
    
    //read the first character
    if(itemTable.contains(itemType)) {
        //cout << "found!\n";
        Hashable* hashed = itemTable.get(itemType);
        //downcast to item class
        Item* item = static_cast<Item*>(hashed);
        return item->create();
    }
    else {
        // read the rest of the line
        string throwAway;
        getline(input, throwAway);
    }
    return NULL;
}