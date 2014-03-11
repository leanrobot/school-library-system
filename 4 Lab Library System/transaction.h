//-----------------------------------------------------------------------------
// TRANSACTION.H
// Transaction class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// Transaction class: is a an abstract class which is a unified interface of
// all of the Transaction available within program. Includes the following
// features:
// -- create a Transaction object
// -- execute certain actions of a Transaction
// -- hashing function which return type of the transaction
// -- print method to display information about the transaction
//-----------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "itemcollection.h"
#include <fstream>
#include <map>
#include "hashable.h"
#include "user.h"
#include <iostream>
#include <iomanip>

class Transaction: public Hashable {
    
public:
    // Constructor
    Transaction();
    
    // Destructor
    virtual ~Transaction();
    
	// create
	// This is a pure virtual method.
	// Overridden methods will create the Transaction object
	virtual Transaction* create(istream&) = 0;
    
	// execute
	// This is a pure virtual method.
	// Overridden methods will execute certain actions on ItemCollection
    // and UserCollection objects
	virtual void execute(ItemCollection& items, map<int,
                         User*> & userCollection) = 0;
    
    // hash
    // Hash function return the type of transaction
    virtual char hash() const;
    
    // print
    // This is a pure virtual method.
    // Overridden method will displays information about the transaction
    virtual void print() const =0;
    
    
protected:
    // transaction type (e.g. C means checkout)
    char transactionType;
    
    // Static const variable which is used in print methods
    // to display information about transaction in the right format
    const static int COMMAND_COL_WIDTH = 9;
};

#endif 