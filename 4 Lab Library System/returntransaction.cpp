//-----------------------------------------------------------------------------
// RETURNTRANSACTION.H
// ReturnTransaction class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// ReturnTransaction class: is a class which is responsible for creating
// ReturnTransaction object and execute return operation on ItemCollection
// and UserCollection objects. The class implements following methods:
// -- create return transaction object
// -- execute the operation
// -- print information about the return transaction object
//
// Assumptions:
// -- the create method creates and returns object ReturnTransaction only if
//    the provided data is correct, otherwise return NULL
//-----------------------------------------------------------------------------

#include "returntransaction.h"
#include "checkouttransaction.h"
#include "itemfactory.h"

/*---------------------------------------------------------------------------
 ===== Default constructor
 Descripton: sets the specific transaction type for identification purposes.
----------------------------------------------------------------------------*/
ReturnTransaction:: ReturnTransaction (){
    transactionType = 'R';
    user = NULL;
}

/*---------------------------------------------------------------------------
 ===== Copy Constructor
 Descripton: Create chekOutTransaction object the same like rhs object
----------------------------------------------------------------------------*/
ReturnTransaction::ReturnTransaction(const ReturnTransaction& rhs) {
    item = rhs.item;
    user = rhs.user;
    lookUpItem = rhs.lookUpItem;
    userId = rhs.userId;
    transactionType = 'R';
}

/*---------------------------------------------------------------------------
 ===== Destructor
 Descripton:
 Pre:
 Post: Dealocated.
 ----------------------------------------------------------------------------*/
ReturnTransaction::~ReturnTransaction() {
    item = NULL; // handled by other class.
    user = NULL; // handled by other class.
    delete lookUpItem;
}

/*---------------------------------------------------------------------------
 ===== create
 Descripton: This functions creates a new return transaction. The data for
 the transaction is read from the istream, which points to the command file.
 Pre:
 Post: returns an initialized return transaction.
 ----------------------------------------------------------------------------*/
Transaction* ReturnTransaction:: create(istream&infile){
    ReturnTransaction* newTransaction = new ReturnTransaction;
    
    int userId;
    infile >>userId;                  // input user Id
    newTransaction->userId = userId;  // set user Id
    infile.get();                     //get (and ignore) blank space
    
    // Create the item factory object
    ItemFactory* factory = ItemFactory::instance();
    // create lookUp item
    newTransaction->lookUpItem = factory -> createItem (infile);
    
    // check if the lookUp item is not NULL
    if(newTransaction->lookUpItem!=NULL){
        // initialized lookUp item from data from file
        newTransaction->lookUpItem->initializePartial(infile);
    }
    
    return newTransaction;
}

/*-----------------------------------------------------------------------------
 ===== execute ( run command )
 Descripton: Executes the transaction, for a return transaction, this will
 first check if the user with given Id exist in userCollection, then it
 will find if the item which the user wants to return exist and if the
 user check out that item earlier. Then it will add this transaction to
 user' history and increase the number of available copies for
 the given item.
 -----------------------------------------------------------------------------*/
void ReturnTransaction:: execute(ItemCollection& itemCollection,
                                 map <int, User*> & userCollection){
    
    // check if the user with given ID exist in the userCollection
    if (userCollection.count(this->userId)>0){
        // and if exists assign it to the user object
        user = userCollection[this->userId];
        
        // check if the lookUp item is not NULL
        if (this->lookUpItem!= NULL){
	  
	    // If there is an invalid item format, abort command.
	    if(this->lookUpItem->getItemFormat() != 'H') {
		cout << "Command not executed: Invalid item format" << endl;
	    }
	    
            // find the item in itemsCollection
            item = itemCollection.retrieve(this->lookUpItem);
            
            // if the item exists in itemCollection
            if (item != NULL){
                // get the number of checkout copies
                int checkout = item->getCheckedOutCopies();
                
                // first check if the user check out that item earlier and if
                // there are still available copies,
                // then perform operation
                if (isCheckedOutByUser(this->item, this->user) && checkout > 0
                    && checkout <= item->getTotalCopies()){
                    // set the new number of chekout copies
                    item->setCheckedOutCopies (checkout-1);
                    ReturnTransaction* copy = new ReturnTransaction(*this);
                    // add transaction to user's hisoty
                    user->getUserHistory()->add(copy);
                }
                
                // if the item does not exist in the itemCollection,
                // print the right information
                else {
                    cout << "Command not executed: Invalid Return" << endl;
                    print();
                }
            }
        }
        // lookUp item is NULL so the item does not exist in the itemCollection
        else {
            // print information about it
            cout<<"Book not found in Library."<<endl;
        }
    }
}

/*---------------------------------------------------------------------------
 ===== isCheckOutByUser
 Descripton: Helper methos which is used during return operation to make sure
 that the user who wants to return book, checkout that item before returing it
 Pre:
 Post: Returns true if the user check out that item before returning, false
 otherwise
 ----------------------------------------------------------------------------*/
bool ReturnTransaction::isCheckedOutByUser(Item* item, User* user) {
    // get user's history object
    History* history = user->getUserHistory();
    list<Transaction*> historyList = history->getHistory();
    
    // iterate through the user's history list to find if the user check out
    // the given item which now wants to return
    list<Transaction*>::iterator iter = historyList.begin();
    for(; iter != historyList.end(); iter++) {
        
        // cast the trasnaction object to checkOutTransaction object
        CheckOutTransaction* checkout = dynamic_cast<CheckOutTransaction*>(*iter);
        
        if(checkout != NULL) {
            // compare the items and if they are the same, return true,
            if(*checkout->getItem() == *item) return true;
        }
    }
    
    // false otherwise
    return false;
}

/*---------------------------------------------------------------------------
 ===== print
 Descripton: Print information about the returnTransaction object
----------------------------------------------------------------------------*/
void ReturnTransaction:: print() const{
    cout << setw(COMMAND_COL_WIDTH) << "Return";
    item->display();
}
