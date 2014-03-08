//-----------------------------------------------------------------------------
// CheckOutTransaction class: is a class which is responsible for creating
// CheckOutTransaction object and execute checkOut opertions on ItemCollection
// and UserCollection objects. The class implements following methods:
// -- create
// -- execute
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
    CheckOutTransaction(const CheckOutTransaction& rhs);
    
	// Destructor
	~CheckOutTransaction();
    
	// create
	// This method parses the data out of the string and then checks the data.
	// If the data is correct, creates the ChechOutTransaction object and
	// returns it, otherwise does not create the object and returns NULL
	virtual Transaction* create(istream&);
    
	// execute
	// This method executes checkOut operation on ItemCollection and
    // UserCollection objects
	virtual void execute(ItemCollection& items, map <int, User*> & userCollection);
    
    virtual void print() const;
    
private:
    
    // Unique identification number of a user
	int userId;
    
    User* user;
    
    Item* item;
    
    Item* lookUpItem;
    
};


#endif