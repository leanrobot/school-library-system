//-----------------------------------------------------------------------------
// HISTORYTRANSACTION.CPP
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

#include "historytransaction.h"
#include "itemfactory.h"

/*-----------------------------------------------------------------------------
 ===== Constructor
 Descripton: sets the specific transaction type for identification purposes.
 -----------------------------------------------------------------------------*/
HistoryTransaction:: HistoryTransaction (){
    transactionType = 'H';
    user = NULL;
}

/*-----------------------------------------------------------------------------
 ===== Destructor
 Descripton: All items stored in the history transactions are destroyed
 by other destructors.
 -----------------------------------------------------------------------------*/
HistoryTransaction:: ~HistoryTransaction (){}

/*-----------------------------------------------------------------------------
 ===== Create History Transaction
 Descripton: This functions creates a new history transaction. The data for the
 transaction is read from the istream, which points to the command file.
 Pre:
 Post: returns an initialized history transaction.
 -----------------------------------------------------------------------------*/
Transaction* HistoryTransaction:: create(istream&infile){
    HistoryTransaction * newTransaction = new HistoryTransaction;
    int userId;
    
    infile >>userId;                 // input user Id
    infile.get();                    //get (and ignore) blank space
    newTransaction->userId = userId; // set the user id
    return newTransaction;
}

/*-----------------------------------------------------------------------------
 ===== Execute ( run command )
 Descripton: executes the transaction. For a history transaction, this will
 display the history for a specific user.
 -----------------------------------------------------------------------------*/
void HistoryTransaction:: execute(ItemCollection& itemCollection,
                                  map <int, User*> & userCollection) {
    
    // check if the user with given ID exists in the userCollection
    if (userCollection.count(this->userId) > 0) {
        // if exist, assign this user to the user object
        user = userCollection[this->userId];
        
        // get user history list
        list<Transaction*>& userHistory = user->getUserHistory()->getHistory();
        
        cout<< "*** Patron ID = " << userId << " " <<user->getName() << endl;
        
        if(userHistory.begin() == userHistory.end()) {
            cout << "No User History." << endl;
        }
        
        // iterate through the list and print all of the user's transaction
        for(list<Transaction*>::iterator iter = userHistory.begin();
            iter != userHistory.end(); iter++) {
            (*iter)->print();
        }
        cout << endl;
        
        // user with given Id does not exist, so print information about it
    }else {
        cout << "Command not executed: Invalid User ["<<userId<<"]." << endl << endl;
    }
}
/*-----------------------------------------------------------------------------
 ===== Print
 Descripton: Not implemented for history transaction, it will never be printed.
 -----------------------------------------------------------------------------*/
void HistoryTransaction:: print() const{ }
