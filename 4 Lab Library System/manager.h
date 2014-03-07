//-----------------------------------------------------------------------------
// Manager class: is a class which reads data from files and create users,
// items and transactions objects. The User objects are added to the
// UserCollection users and the items objects are added to the ItemCollection
// items. Transaction objects are created and the the function execute is
// called on them. The class implements following methods:
// -- buildUsers
// -- buildItems
// -- processTransaction
//
// Assumptions:
// -- three data files will be provided, one contains information of users, one
//    contains information about items, and one contains transactions that
//    users performed.
// -- the data in each file is in the correct format.
// -- if the data contain incorrect values (e.g. wrong type of book),
//    the object will not be created and therefore added/executed.

//-----------------------------------------------------------------------------

#ifndef MANAGER_H
#define MANAGER_H

#include "itemfactory.h"
#include "userfactory.h"
#include "transactionfactory.h"
//#include "itemCollection.h"
//#include "userCollection.h"
#include <fstream>
#include <iostream>
#include <map>
#include "user.h"
#include "itemcollection.h"
#include "itemtree.h"

using namespace std;

class Manager {
public:

	// Default constructor
	Manager();

	// Destructor
	~Manager();

	// buildUsers
	// This method reads data from file and parse each line to extract user Id,
	// firstName, lastName and creates a new User object. Then call method
	// insert from UserCollection class.
	void buildUsers(istream&);

	// buildItems
	// This method reads data from file and passes each line to the ItemFactory
	// which creates Item object out of it. Then calls method insert from
	// ItemCollection class.
	
    void buildItems(istream&);

	// ProcessTransaction
	// This method read data from file and pass each line to the
	// TransactionFactory object which creates Transaction object out of it.
	// Then method execute is called on this object.
	
    //void processTransaction(istream&);
    
private:
    
	// ItemFactory object which will be responsible for creating item
	ItemFactory* itemFactory;
    
    UserFactory* userFactory;
    
	// TransactionFactory object which will be responsible for creating
	// transactions
	TransactionFactory* transactionFactory;
    
    // UserCollection keeps all User objects
    map<int, User*> users;
    
    // ItemCollection keeps all Item objects
    ItemCollection items;

    
    
};


#endif 
