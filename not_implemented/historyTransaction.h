//-----------------------------------------------------------------------------
// HistoryTransaction class: is a class which is responsible for creating
// HistoryTransaction object and execute history operation on an UserCollection
// object. The class implements following methods:
// -- create
// -- execute
//
// Assumptions:
// -- the create method creates and returns object HistoryTransaction only if
//    the provided data is correct, otherwise return NULL
//-----------------------------------------------------------------------------

#ifndef HISTORYTRANSACTION_H
#define HISTORYTRANSACTION_H

#include "transaction.h"
#include "itemCollection.h"
#include "userCollection.h"
#include <string>

class HistoryTransaction: public Transaction {

public:

    // Default constructor
    HistoryTransaction();

    // Destructor
    ~HistoryTransaction();

    // create
    // This method parses the date out of the string and then checks the data.
    // If the data is correct, creates the HistoryTransaction object and
    // returns it, otherwise does not create the object and returns NULL
    virtual Transaction* create(string);

    // execute
    // This method executes history operation on an UserCollection object
    virtual void execute(ItemCollection*, UserCollection*);

private:
    // Unique user identificaton number
    int userID;

    // Constructor used by create method.
    HistoryTransaction(int);

};

#endif