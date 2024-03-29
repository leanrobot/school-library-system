//-----------------------------------------------------------------------------
// MANAGER.H
// Manager class
// Authors: Magdalena Grzmiel and Thomas Petit
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
	// name and creates a new User object. Then insert the user to the users map
	void buildUsers(istream& infile);
    
	// buildItems
	// This method reads data from file and passes each line to the ItemFactory
	// which creates Item object out of it. Then calls method insert from
	// ItemCollection class.
    void buildItems(istream& infile);
    
	// ProcessTransaction
	// This method read data from file and pass each line to the
	// TransactionFactory object which creates Transaction object out of it.
	// Then method execute is called on this object.
    void processTransaction(istream& infile);
    
private:
	// ItemFactory object which will be responsible for creating items
	ItemFactory* itemFactory;
    
    // UserFactory object which will be responsible for creating users
    UserFactory* userFactory;
    
	// TransactionFactory object which will be responsible for creating
	// transactions
	TransactionFactory* transactionFactory;
    
    // Map which keeps all User objects
    map<int, User*> userCollection;
    
    // ItemCollection keeps all Item objects
    ItemCollection itemCollection;
    
};

#endif /*MANAGER_H*/
