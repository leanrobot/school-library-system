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

class ReturnTransaction: public Transaction {
    
public:
	// Default constructor
	ReturnTransaction();
    ReturnTransaction(const ReturnTransaction& rhs);
    
	// Destructor
	~ReturnTransaction();
    
	// create
	// This method parses the date out of the string and then checks the data.
	// If the data is correct, creates the ReturnTransaction object and
	// returns it, otherwise does not create the object and returns NULL
	virtual Transaction* create(istream&);
    
	// execute
	// This method execute return operation on a ItemCollection and
    // UserCollection objects.
    virtual void execute(ItemCollection& items, map <int, User*> & userCollection);
    
    virtual void print() const;
    
private:
	// Unique identification number of a user
    int userId;
    
    User* user;
    
    Item* item; // real item with author, title and year
    
    Item* lookUpItem; // item to only find the right item in the item collection
    
    bool isCheckedOutByUser(Item*, User*);
};

#endif
