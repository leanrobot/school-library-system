//-----------------------------------------------------------------------------
// Transaction class: is a an abstract class which is a unified interface of
// all of the Transaction available within program. Includes the following
// features:
// -- create a Transaction object
// -- execute certain actions of a Transaction
//-----------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "itemCollection.h"
#include "userCollection.h"
#include <string>

class Transaction {

public:
    // Constructor
    Transaction()
    
    // Destructor
    virtual ~Transaction()
    
	// create
	// This is a pure virtual method.
	// Overridden methods will create the Transaction object
	virtual Transaction* create(string) = 0;

	// execute
	// This is a pure virtual method.
	// Overridden methods will execute certain actions on ItemCollection
    // and UserCollection objects
	virtual void execute(ItemCollection*, UserCollection*) = 0;
};

#endif 