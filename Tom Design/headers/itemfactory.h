

//-----------------------------------------------------------------------------
// class ItemFactory
//
// Factory used to build items that will be stored inside the library.
//
//-----------------------------------------------------------------------------

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "item.h"
#include <map>

class ItemFactory {
public:
	ItemFactory(); // constructor.
	~ItemFactory(); // destructor.
    Item* createItem(string data); //creates items from
    				// raw data and returns them.
private:
    map<int,Item*> items; // available items this factory creates.
};