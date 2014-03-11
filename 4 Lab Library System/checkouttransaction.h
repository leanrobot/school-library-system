//-----------------------------------------------------------------------------
// TRANSACTION.H
// Transaction class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// CheckOutTransaction class: is a class which is responsible for creating
// CheckOutTransaction object and execute checkOut opertions on itemsCollection
// and UserCollection objects. The class implements following methods:
// -- create a checkOut transaction object
// -- execute the operation
// -- print information about the checkOut transaction object
// -- getItem
//
// Assumptions:
// -- the create method creates and returns object CheckOutTransaction only if
//    the provided data is correct, otherwise return NULL
//-----------------------------------------------------------------------------

#ifndef CHECKOUTTRANSACTION_H
#define CHECKOUTTRANSACTION_H

#include "transaction.h"
#include "user.h"

class CheckOutTransaction: public Transaction {
    
public:
	// Default constructor
	CheckOutTransaction();
    
    // Copy constructor
    CheckOutTransaction(const CheckOutTransaction& rhs);
    
	// Destructor
	~CheckOutTransaction();
    
	// create
	// This method parses the data out of the string and then checks the data.
	// If the data is correct, creates the ChechOutTransaction object and
	// returns it, otherwise does not create the object and returns NULL
	virtual Transaction* create(istream& input);
    
	// execute
	// This method executes checkOut operation on ItemCollection and
    // UserCollection objects
	virtual void execute(ItemCollection& itemsCollection,
                         map <int, User*> & userCollection);
    
    // print
    // Prints information about the checkOut Transaction object
    virtual void print() const;
    
    
    // getItem
    // Returns item object
    Item* getItem();
    
private:
    
    // Unique identification number of a user
	int userId;
    
    // User which will perform checkOutTransaction
    User* user;
    
    // Real item on which the checkOutTransaction operation will be performed
    Item* item;
    
    // lookUp item is an item object which is used to find the item object in
    // ItemCollection on which the operation should be performed
    // lookUp item is created beased in the information provided in the
    // transaction command
    Item* lookUpItem;
    
};

#endif
