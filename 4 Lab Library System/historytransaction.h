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
#include "itemcollection.h"
#include <map>
#include <string>
#include <fstream>

class HistoryTransaction: public Transaction {

public:

    // Default constructor
    HistoryTransaction();

    // Destructor
   // ~HistoryTransaction();

    // create
    // This method parses the date out of the string and then checks the data.
    // If the data is correct, creates the HistoryTransaction object and
    // returns it, otherwise does not create the object and returns NULL
    virtual Transaction* create(istream&);

    // execute
    // This method executes history operation on an UserCollection object
    virtual void execute(ItemCollection&, map<int, User*>&);
    
    virtual void print() const;
    

private:
    // Unique user identificaton number
    int userId;
    User* user;
    
    //Item* lookUpItem;
   // Item* item;

    // Constructor used by create method.
    //HistoryTransaction(int);

};

#endif