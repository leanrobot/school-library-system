#include "historytransaction.h"
#include "itemfactory.h"

/*-----------------------------------------------------------------------------
 ===== Constructor
 Descripton: sets the specific transaction type for identification purposes.
 Pre:
 Post:
 -----------------------------------------------------------------------------*/
HistoryTransaction:: HistoryTransaction (){
    transactionType = 'H';
    user = NULL;
}

/*-----------------------------------------------------------------------------
 ===== Destructor
 Descripton: All items stored in the history transactions are destroyed
 by other destructors.
 Pre:
 Post:
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
 Pre:
 Post:
 -----------------------------------------------------------------------------*/
void HistoryTransaction:: execute(
                                  ItemCollection& itemCollection,
                                  map <int, User*> & userCollection) {
    
    // check if the user with given ID exists in the userCollection
    if (userCollection.count(this->userId)>0) {
        // if exist, assign this user to the user object
        user = userCollection[this->userId];
        
        // get user history list
        list<Transaction*>& userHistory = user->getUserHistory()->getHistory();
        // iterate through the list and print all of the user's transaction
        list<Transaction*>::iterator iter = userHistory.begin();
        cout<< "*** Patron ID = " << userId << " " <<user->getName() << endl;
        
        for(; iter!=userHistory.end(); iter++) {
            (*iter)->print();
        }
        
    // user with given Id does not exist, so print information about it
    }else {
        cout << "Command not executed: Invalid User ["<<userId<<"].\n";
    }
}
/*-----------------------------------------------------------------------------
 ===== Print
 Descripton: Not implemented for history transaction, it will never be printed.
 Pre:
 Post:
 -----------------------------------------------------------------------------*/
void HistoryTransaction:: print() const{ }
