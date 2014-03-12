//-----------------------------------------------------------------------------
// DISPLAYTRANSACTION.H
// DisplayTransaction class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// DisplayTransaction class: is a class which is responsible for creating
// DisplayTransaction object and execute display operation on ItemCollection.
// The class implements following methods:
// -- create
// -- execute
// -- print
//
// Assumptions:
// - the create method creates and returns object DisplayTransaction only if
//   the provided data is correct, otherwise return NULL
//-----------------------------------------------------------------------------
#ifndef DISPLAYTRANSACTION_H
#define DISPLAYTRANSACTION_H

#include <string>
#include "transaction.h"
#include "itemcollection.h"

class DisplayTransaction: public Transaction {
    
public:
	// Default constructor
	DisplayTransaction();
    
	// Destructor
	~DisplayTransaction();
    
	// create
	// This method parses the data out of the string and then checks the data.
	// If the data is correct, creates the DisplayTransaction object and
	// returns it, otherwise does not create the object and returns NULL
	virtual Transaction* create(istream& infile);
    
	// execute
	// This method executes display operations on an ItemCollection object
    virtual void execute(ItemCollection& itemCollection,
                         map<int, User*> & userCollection);
    
    // print
    // Not implementd for this class
    virtual void print()const;
    
};

#endif /*DISPLAYTRANSACTION_H*/
