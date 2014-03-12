//-----------------------------------------------------------------------------
// DISPLAYTRANSACTION.CPP
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
#include "displaytransaction.h"

/*-----------------------------------------------------------------------------
 ===== Constructor
 Descripton: sets the specific transaction type for identification purposes.
-----------------------------------------------------------------------------*/
DisplayTransaction::DisplayTransaction() {
    transactionType = 'D';
}

/*-----------------------------------------------------------------------------
 ===== Destructor
 Descripton:
-----------------------------------------------------------------------------*/
DisplayTransaction::~DisplayTransaction() {}

/*-----------------------------------------------------------------------------
 ===== Create Display Transaction
 Descripton: This functions creates a new display transaction. The data for the
 transaction is read from the istream, which points to the command file.
 Pre:
 Post: returns an initialized display transaction.
-----------------------------------------------------------------------------*/
Transaction* DisplayTransaction::create(istream& infile) {
    return new DisplayTransaction;
}

/*-----------------------------------------------------------------------------
 ===== execute ( run command )
 Descripton: executes the transaction. For a display transaction, this will
 display all of the items in the ItemCollection object
-----------------------------------------------------------------------------*/
void DisplayTransaction::execute(ItemCollection& itemCollection,
                                 map<int, User*> & userCollection) {
    
    int numCategories;
    
    // get the array with the pointers to the itemTrees which keep all items
    ItemTree** categories = itemCollection.retrieveAll(numCategories);
    // iterate through the array
    for(int i = 0; i < numCategories; i++) {
        ItemTree* category = categories[i];
        
        // if the category of the item is not NULL,
        //display all item in given category
        if(category != NULL) {
            category->print();
        }
    }
}

/*-----------------------------------------------------------------------------
 ===== Print
 Descripton: Not implemented for display transaction, it will never be printed.
-----------------------------------------------------------------------------*/
void DisplayTransaction::print()const {}
