//
//  displaytransaction.cpp
//  4 Lab Library System
//
//  Created by Tom Petit on 3/6/14.
//  Copyright (c) 2014 University of Washington, Bothell. All rights reserved.
//

#include "displaytransaction.h"


DisplayTransaction::DisplayTransaction() {
   transactionType = 'D';
}
DisplayTransaction::~DisplayTransaction() {
    //TODO
}

Transaction* DisplayTransaction::create(istream& infile) {
    return new DisplayTransaction;
}

// execute
// This method executes display operation on an ItemCollection object
void DisplayTransaction::execute(ItemCollection& items, map<int, User*> & userCollection) {
    int numCategories;
    ItemTree** categories = items.retrieveAll(numCategories);
    for(int i=0; i<numCategories; i++) {
        ItemTree* category = categories[i];
        if(category != NULL) {
            category->print();
        }
    }
}

void DisplayTransaction::print() const {
    //TODO
}
 




