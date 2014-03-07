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
#include "hashtable.h"

const int MAX_FACTORY_SIZE = 26;

class ItemFactory {

public:
    ItemFactory( );                      // constructor
    ~ItemFactory( );                     // destructor
    Item* createItem(istream&);   // creates an item of the desired type
  
private:
    HashTable itemTable;
    
};

#endif
