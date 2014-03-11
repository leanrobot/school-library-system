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
#include "youth.h"
#include "fiction.h"
#include "periodical.h"

#include "hashtable.h"

const int MAX_FACTORY_SIZE = 26;

class ItemFactory {

public:
    static ItemFactory* instance(); //Singleton controlled creation function.
    ~ItemFactory( );                // destructor
    Item* createItem(istream&);     // creates an item of the desired type
  
private:
    HashTable itemTable;
    static bool instanceFlag;
    static ItemFactory* _instance;
    
    ItemFactory();   // constructor
    //These are declared, but not implemented to prevent copies of
    //  the singleton from being made.
    ItemFactory(ItemFactory& copy);
    void operator=(ItemFactory& copy);
    
};

#endif /* ITEM_FACTORY_H */
