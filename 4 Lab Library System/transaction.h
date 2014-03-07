//-----------------------------------------------------------------------------
// Transaction class: is a an abstract class which is a unified interface of
// all of the Transaction available within program. Includes the following
// features:
// -- create a Transaction object
// -- execute certain actions of a Transaction
//-----------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "itemcollection.h"
#include <string>
#include <fstream>
#include <map>
#include "hashable.h"
#include "user.h"

class Transaction: public Hashable {

public:
    // Constructor
    //Transaction();
    
    // Destructor
    //virtual ~Transaction();
    
	// create
	// This is a pure virtual method.
	// Overridden methods will create the Transaction object
	//virtual Transaction* create(istream&) = 0;

	// execute
	// This is a pure virtual method.
	// Overridden methods will execute certain actions on ItemCollection
    // and UserCollection objects
	virtual void execute(ItemCollection& items, map<int, User*> & userCollection) = 0;
    
    char hash() const;
};

#endif 