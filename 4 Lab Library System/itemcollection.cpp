//-----------------------------------------------------------------------------
// ITEMCOLLECTION.CPP
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

#include "itemcollection.h"

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: sets all elements of the array to the NULL
  ----------------------------------------------------------------------------*/
ItemCollection::ItemCollection() {
    for(int i=0; i < MAX_ITEM_TYPES; i++) {
        items[i] = NULL;
    }
}

/*---------------------------------------------------------------------------
 ===== Destructor
 Descripton: Destructor deallocated the memory by calling the destructor from
 ItemTree class.
 Pre:
 Post: deallocated
 ----------------------------------------------------------------------------*/
ItemCollection::~ItemCollection() {
    for (int i = 0; i < MAX_ITEM_TYPES; i++){
        if (items[i]!=NULL){
            delete items[i];
        }
    }
}

/*---------------------------------------------------------------------------
 ===== insert
 Descripton: Insert item to the right tree
----------------------------------------------------------------------------*/
void ItemCollection::insert(Item* toInsert) {
    char itemType = toInsert->hash();      // get the type of the item
    int index = hash(itemType);            // calculate the index of the array
                                           // with the right type tree
    if(items[index] == NULL) {             // check if the tree exist
        items[index] = new ItemTree;       // and if not, create new tree
    }
    
    // insert the item into the right type of tree
    items[index]->insert(toInsert);
}

/*---------------------------------------------------------------------------
 ===== retrive
 Descripton: Travers through the tree and if finds the item for which is 
 looking for, returns pointer to that item
----------------------------------------------------------------------------*/
Item* ItemCollection::retrieve(Item* toGet) {
    char itemType = toGet->hash();          // get the type ot the item
    ItemTree* tree = items[hash(itemType)]; // find the right tree
    Item* gotten = tree->retrieve(toGet);   // and find item in that tree
    return gotten;
}

/*---------------------------------------------------------------------------
 ===== retrive
 Descripton: Returns the array of itemTree with all of the items
----------------------------------------------------------------------------*/
ItemTree** ItemCollection::retrieveAll(int& arraySize) {
    arraySize = MAX_ITEM_TYPES;
    return items;
}

/*---------------------------------------------------------------------------
 ===== hash
 Descripton: Helper method which is used to calculate the index of the array
 with the right type tree
----------------------------------------------------------------------------*/
int ItemCollection::hash(char ch) {
    return ch - 'A'; // calculate the index where 
}
