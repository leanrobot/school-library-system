//-----------------------------------------------------------------------------
// CHECKOUTTRANSACTION.H
// CheckOutTransaction class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// CheckOutTransaction class: is a class which is responsible for creating
// CheckOutTransaction object and execute checkOut opertions on itemsCollection
// and UserCollection objects. The class implements following methods:
// -- create a checkOut transaction object
// -- execute the operation
// -- print information about the checkOut transaction object
// -- getItem
//
// Assumptions:
// -- the create method creates and returns object CheckOutTransaction only if
//    the provided data is correct, otherwise return NULL
//-----------------------------------------------------------------------------
#include "checkouttransaction.h"
#include "itemfactory.h"

/*---------------------------------------------------------------------------
 ===== Default constructor
 Descripton: sets the specific transaction type for identification purposes.
----------------------------------------------------------------------------*/
CheckOutTransaction:: CheckOutTransaction (){
    transactionType = 'C';
    user=NULL;
}

/*---------------------------------------------------------------------------
 ===== Copy Constructor
 Descripton: Create chekOutTransaction object the same like rhs object
----------------------------------------------------------------------------*/
CheckOutTransaction::CheckOutTransaction(const CheckOutTransaction& rhs) {
    user = rhs.user;
    item = rhs.item;
    lookUpItem = rhs.lookUpItem;
    userId = rhs.userId;
    transactionType = 'C';
}

/*---------------------------------------------------------------------------
 ===== Destructor
 Descripton:
 Pre:
 Post: Dealocated. 
 ----------------------------------------------------------------------------*/
CheckOutTransaction:: ~CheckOutTransaction (){
    user = NULL;  // handled by other class.
    item = NULL;  // handled by other class.
    delete lookUpItem;
}

/*---------------------------------------------------------------------------
 ===== create
 Descripton: This functions creates a new check out transaction. The data for 
 the transaction is read from the istream, which points to the command file.
 Pre:
 Post: returns an initialized checkOut transaction.
 ----------------------------------------------------------------------------*/
Transaction* CheckOutTransaction:: create(istream&infile){
    CheckOutTransaction * newTransaction = new CheckOutTransaction;
    
    int userId;
    infile >>userId;                 // input user Id
    newTransaction->userId = userId; // set the user id
    infile.get();                    //get (and ignore) blank space
    
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
 Descripton: Executes the transaction, for a checkOut transaction, this will
 first check if the user with given Id exist in userCollection, then it will
 find if the item which the user wants to checkOut exist and is available in the
 library, then it will add this transaction to user' history and change the 
 number of checkOut copies for the given item.
-----------------------------------------------------------------------------*/
void CheckOutTransaction:: execute(ItemCollection& itemCollection, map <int,
                                   User*> & userCollection){
    
    // check if the user with given ID exist in the userCollection
    if (userCollection.count(this->userId)>0) {
        // if exist, assign this user to the user object
        user = userCollection[this->userId];
        
	
	
        // check if the lookUp item is not NULL
        if (this->lookUpItem !=NULL){
	    
	    // If there is an invalid item format, abort command.
	    if(this->lookUpItem->getItemFormat() != 'H') {
		cout << "Command not executed: Invalid item format" << endl;
	    }
	    
            // find the item in itemsCollection
            item = itemCollection.retrieve(this->lookUpItem);
            
            // if the item exists in itemCollection
            if (item != NULL){
                // get the number of check out copies
                int checkout = item->getCheckedOutCopies();
                
                // check if the item is available and if yes, perform check out
                // transaction
                if (checkout < item->getTotalCopies()) {
                    // set up new number of check out copies
                    item->setCheckedOutCopies (checkout+1);
                    CheckOutTransaction* copy = new CheckOutTransaction(*this);
                   // add transaction to user's hisoty
                    user->getUserHistory()->add(copy);
                }
                else {
                    // if the item does not exist in the itemCollection,
                    // print the right information
                    cout << "Command not executed: No copies available\n";
                    print();
                }
            }
        
        // lookUp item is NULL so the item does not exist in the itemCollection
        }else{
            // print information about it
            cout<< "Book not found in Library." << endl;
            
        }
    }
}

/*---------------------------------------------------------------------------
 ===== getItem
 Descripton: Returns item object on which the cheOutTransaction is performed.
 Pre:
 Post: Returns item object on which the cheOutTransaction is performed.
 ----------------------------------------------------------------------------*/
Item* CheckOutTransaction::getItem() {
    return this->item;
}

/*---------------------------------------------------------------------------
 ===== print
 Descripton: Print information about the checkOutTransaction object
----------------------------------------------------------------------------*/
void CheckOutTransaction:: print() const{
    cout << setw (COMMAND_COL_WIDTH) << "Checkout" ;
    item->display();
}
