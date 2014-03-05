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

ItemFactory::ItemFactory() {
    Item* youth = new Youth;
    Item* fiction = new Fiction;
    Item* periodical = new Periodical;
    
    itemTable.add(youth->hash(), youth);
    itemTable.add(fiction->hash(), fiction);
    itemTable.add(periodical->hash(), periodical);
}
ItemFactory::~ItemFactory() {
    
}

Item* ItemFactory::createItem(istream& input) {
    return NULL; //TODO
}