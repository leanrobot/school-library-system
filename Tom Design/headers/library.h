

//-----------------------------------------------------------------------------
// class Library
//
// Contains a collection that holds the items of the library.
//
//-----------------------------------------------------------------------------

#ifndef LIBRARY_H
#define LIBRARY_H
#include <map>
#include <vector>
#include "item.h"

class Library {
public:
	Library();
	~Library();
	
    vector<Item*> getItemCategory(Item*); 
    		// Retrieves a specfic book category.
    map<int, Item*> getAllItems();
    		//Retrieves a map of all items.
    map<int, User*> getAllUsers();
    User* getUser(User*);
    		// Retrieves a map of all users.
private:
    map<int, Item*> itemCategories;
    map<int, User*> users;
};

#endif