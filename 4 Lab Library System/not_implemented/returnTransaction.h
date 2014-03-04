//-----------------------------------------------------------------------------
// ReturnTransaction class: is a class which is responsible for creating
// ReturnTransaction object and execute return operation on ItemCollection
// and UserCollection objects. The class implements following methods:
// -- create
// -- execute
//
// Assumptions:
// -- the create method creates and returns object ReturnTransaction only if
//    the provided data is correct, otherwise return NULL
//-----------------------------------------------------------------------------

#ifndef RETURNTRANSACTION_H
#define RETURNTRANSACTION_H

#include "transaction.h"
#include "itemCollection.h"
#include "userCollection.h"
#include <string>

class ReturnTransaction: public Transaction {

public:
	// Default constructor
	ReturnTransaction();

	// Destructor
	~ReturnTransaction();

	// create
	// This method parses the date out of the string and then checks the data.
	// If the data is correct, creates the ReturnTransaction object and
	// returns it, otherwise does not create the object and returns NULL
	virtual Transaction* create(string);

	// execute
	// This method execute return operation on a ItemCollection and
    // UserCollection objects.
	virtual void execute(ItemCollection*, UserCollection*);

private:
	// Unique identification number of a user
    int userId;
    
    // The type of an Item, like, periodical, youth
	char itemType;
    
    // The format of an Item, like, hard copy or soft copy
	char itemFormat;
    
    // Name of an Item
	string itemName;
    
	// Constructor used by create method.
	ReturnTransaction(int, char, char, string);
    

};

#endif
