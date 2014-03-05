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
#include "itemCollection.h"
#include "userCollection.h"
#include <string>

class CheckOutTransaction: public Transaction {

public:
	// Default constructor
	CheckOutTransaction();

	// Destructor
	~CheckOutTransaction();

	// create
	// This method parses the data out of the string and then checks the data.
	// If the data is correct, creates the ChechOutTransaction object and
	// returns it, otherwise does not create the object and returns NULL
	virtual Transaction* create(string);

	// execute
	// This method executes checkOut operation on ItemCollection and
    // UserCollection objects
	virtual void execute(ItemCollection*, UserCollection*);

private:
    
    // Unique identification number of a user
	int userId;
    
    // The type of an Item, like, periodical, youth
	char itemType;
    
    // The format of an Item, like, hard copy or soft copy
	char itemFormat;
    
    // Description of an Item
	string itemDescription;
    
	// Constructor used by create method
	CheckOutTransaction(int, char, char, string);

};


#endif
