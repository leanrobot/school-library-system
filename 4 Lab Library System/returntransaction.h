//-----------------------------------------------------------------------------
// RETURNTRANSACTION.H
// ReturnTransaction class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// ReturnTransaction class: is a class which is responsible for creating
// ReturnTransaction object and execute return operation on ItemCollection
// and UserCollection objects. The class implements following methods:
// -- create return transaction object
// -- execute the operation
// -- print information about the return transaction object
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
    
    // Copy constructor
    ReturnTransaction(const ReturnTransaction& rhs);
    
	// Destructor
	~ReturnTransaction();
    
	// create
	// This method parses the date out of the string and then checks the data.
	// If the data is correct, creates the ReturnTransaction object and
	// returns it, otherwise does not create the object and returns NULL
	virtual Transaction* create(istream& infile);
    
	// execute
	// This method execute return operation on a ItemCollection and
    // UserCollection objects.
    virtual void execute(ItemCollection& itemCollection,
                         map <int, User*>& userCollection);
    
    // print
    // Prints information about the return Transaction object
    virtual void print() const;
    
private:
	// Unique identification number of a user
    int userId;
    
    // User which will perform checkOutTransaction
    User* user;
    
    // Real item with author, title and year
    Item* item;
    
    // lookUp item is an item object which is used to find the item object in
    // ItemCollection on which the operation should be performed
    // lookUp item is created beased in the information provided in the
    // transaction command
    Item* lookUpItem;
    
    
    // isCheckOutByUser
    // Helper methos which is used during return operation to make sure that
    // the user who wants to return book, checkout that item before returing it
    bool isCheckedOutByUser(Item* item, User* user);
};

#endif /*RETURNTRANSACTION_H*/
