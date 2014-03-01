//-----------------------------------------------------------------------------
// ItemFactory class: a factory that produces instances of items. Includes the
// following features:
//  -- Creates items of a specified type
// Assumptions:
//  -- Assumes unique char can be derived from the string passed
//  -- Assumes no more than 26 item types are present
//-----------------------------------------------------------------------------

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include <string>
#include "item.h"

const int MAX_FACTORY_SIZE = 26;

class ItemFactory {

public:
    ItemFactory( );                      // constructor
    ~ItemFactory( );                     // destructor
    Item* createIt(string);              // creates an item of the desired type
  
private:
    Item* itemFactory[MAX_FACTORY_SIZE]; // Storage for item creation objects
    int hash(char);                      //use hash function to get hash index
};

#endif
