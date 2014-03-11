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
    
    infile >>userId;
    infile.get(); // read the blank space
    
    newTransaction->userId = userId;
    return newTransaction;
}

/*-----------------------------------------------------------------------------
 ===== Execute ( run command )
 Descripton: executes the transaction. For a history transaction, this will 
 display the history for a specific user.
 Pre:
 Post:
 -----------------------------------------------------------------------------*/
void HistoryTransaction:: execute(ItemCollection& itemCollection,
                                  map <int, User*> & userCollection) {
   
    // check if the user with the given Id is in the userCollection
    if (userCollection.count(this->userId)>0) {
        // and if exist assign it to the user onject
        user = userCollection[this->userId];
        
        // get list of user's transactions
        list<Transaction*>& userHistory = user->getUserHistory()->getHistory();
        
        // iterate through the user's history and print information about
        // transactions prformed by user
        list<Transaction*>::iterator iter = userHistory.begin();
        cout<< "*** Patron ID = " << userId << " " <<user->getName() << endl;
        for(; iter!=userHistory.end(); iter++) {
            (*iter)->print();
        }
     
    // if the user does not exist in userCollection, print information about i
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
void HistoryTransaction:: print()const{ }