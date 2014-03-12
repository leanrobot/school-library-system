//-----------------------------------------------------------------------------
// HISTORYTRANSACTION.H
// HistoryTransaction class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// HistoryTransaction class: is a class which is responsible for creating
// HistoryTransaction object and execute history operation on an UserCollection
// object. The class implements following methods:
// -- create
// -- execute
// -- print
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
    ~HistoryTransaction();

    // create
    // This method parses the date out of the string and then checks the data.
    // If the data is correct, creates the HistoryTransaction object and
    // returns it, otherwise does not create the object and returns NULL
    virtual Transaction* create(istream& infile);

    // execute
    // This method executes history operation on an UserCollection object
    virtual void execute(ItemCollection& itemCollection,
                         map<int, User*>& userCollection);
    
    // print
    // Not implementd for this class
    virtual void print() const;
    

private:
    // Unique user identificaton number
    int userId;
    
    // User obeject 
    User* user;

};

#endif /*HISTORYTRANSACTION_H*/
