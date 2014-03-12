//-----------------------------------------------------------------------------
// ItemFactory class: a factory that produces instances of items. Includes the
// following features:
//  -- Creates items of a specified type
// Assumptions:
//  -- Assumes unique char can be derived from the string passed
//  -- Assumes no more than 26 item types are present
//-----------------------------------------------------------------------------

#include "itemfactory.h"

// Default values for static class variables for singleton.
bool ItemFactory::instanceFlag = false;
ItemFactory* ItemFactory::_instance = NULL;

/*---------------------------------------------------------------------------
 ===== Instance creation
 Descripton: This is the "constructor" for the singleton. If an instance
    doesn't exist, it is created and returned. If it already does exist,
    it is returned.
 ----------------------------------------------------------------------------*/
ItemFactory* ItemFactory::instance() {
    if(!instanceFlag) {
        _instance = new ItemFactory;
        instanceFlag = true;
    }
    return _instance;
}
/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Constructor for the item factory. The different types of supported
    items are hardcoded here. They are added manually to the hashtable.
 ----------------------------------------------------------------------------*/
ItemFactory::ItemFactory() {
    // create the different types
    Hashable* youth = new Youth;
    Hashable* fiction = new Fiction;
    Hashable* periodical = new Periodical;
    
    // add different types to the item hashtable.
    itemTable.add(youth->hash(), youth);
    itemTable.add(fiction->hash(), fiction);
    itemTable.add(periodical->hash(), periodical);
}

/*---------------------------------------------------------------------------
 ===== Destructor
 Descripton: Destructor for factory. delete must be called upon the original
    instance call in order to correctly destroy all instances.
 ----------------------------------------------------------------------------*/
ItemFactory::~ItemFactory() {
    if(instanceFlag) {
        instanceFlag = false;
        _instance = NULL;
    }
}

/*---------------------------------------------------------------------------
 ===== Create Item
 Descripton: Reads from the input stream to determine the type of item to
    create. The first character is read, and this is used to retrieve the
    correct type from the hash table.
 ----------------------------------------------------------------------------*/
Item* ItemFactory::createItem(istream& input) {
    
    char itemType = input.get(); //get the item type
    input.get();                 //throwaway the space
    
    //cout << "looking for " << itemType << endl;
    
    //read the first character
    if(itemTable.contains(itemType)) {
        Hashable* hashed = itemTable.get(itemType);
        //downcast to item class
        Item* item = static_cast<Item*>(hashed);
        return item->create();
    }
    else { // not supported, throw away line
           // read the rest of the line
        string throwAway;
        getline(input, throwAway);
    }
    return NULL;
}
