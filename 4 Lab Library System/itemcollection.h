//-----------------------------------------------------------------------------
// ITEMCOLLECTION.H
// ItemCollection class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// ItemCollection: is a collection of of the items contained in the library.
// Includes:
// -- All of the items are stored in a ballanced BST 
// -- Contains methods for inserting and retrieving item
// -- Contain retrive method which return the array with the trees
// Assumptions:
// --itemCollection assumes access to itemTree class
//-----------------------------------------------------------------------------

#ifndef ITEMCOLLECTION_H
#define ITEMCOLLECTION_H

#include <iostream>
#include "itemtree.h"

class ItemCollection {

public:
    // Constructor
    ItemCollection();
    
    // Destructor
    ~ItemCollection();
    
    // insert
    // Insert item to the right tree
    void insert(Item* item);
    
    // retrive
    // Travers through the tree and if finds the item for which is looking for,
    // returns pointer to that item
    Item* retrieve(Item* item);
    
    // retriveAll
    // Returns the array of itemTree with all of the items
    ItemTree** retrieveAll(int& arraySize);
    
private:
    // the size of the array
    static const int MAX_ITEM_TYPES = 26;
    
    // array which keeps pointers to the tree with items
    ItemTree* items[MAX_ITEM_TYPES];
    
   // hash
   // Helper method which is used to calculate the index of the array
   // with the right type tree
   int hash(char ch);

};

#endif /* ITEMCOLLECTION_H*/
