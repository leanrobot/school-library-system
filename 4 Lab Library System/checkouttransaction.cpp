#include "checkouttransaction.h"
#include "itemfactory.h"


CheckOutTransaction:: CheckOutTransaction (){
    transactionType = 'C';
    user=NULL;
}
CheckOutTransaction::CheckOutTransaction(const CheckOutTransaction& rhs) {
    user = rhs.user;
    item = rhs.item;
    lookUpItem = rhs.lookUpItem;
    userId = rhs.userId;
    transactionType = 'C';
}

CheckOutTransaction:: ~CheckOutTransaction (){
    user = NULL;
    item = NULL;
    delete lookUpItem;
}



Transaction* CheckOutTransaction:: create(istream&infile){
    CheckOutTransaction * newTransaction = new CheckOutTransaction;
    
    int userId;
    infile >>userId;
    newTransaction->userId = userId;
    infile.get(); // read the blank space
    ItemFactory* factory = ItemFactory::instance();
    newTransaction->lookUpItem = factory -> createItem (infile);
    newTransaction->lookUpItem->initializePartial(infile);
    
    return newTransaction;
}

void CheckOutTransaction:: execute(ItemCollection& items, map <int, User*> & userCollection){
    
    
    if (userCollection.count(this->userId)>0) {      // check if the user with
                                        //the given id is in the map
        user = userCollection[this->userId];     // and if exist assign it to the oneUser
        
        item = items.retrieve(this->lookUpItem); // get the item from itemCollection
    
        if (item != NULL){ // if item exist in the itemCollection
            int checkout = item->getCheckedOutCopies(); // get the numbero of checkout copies
            
            if (checkout < item->getTotalCopies()) { // if they are still available copies, perform operation
                item->setCheckedOutCopies (checkout+1);
                CheckOutTransaction* copy = new CheckOutTransaction(*this);
                user->getHistory()->add(copy); // add transaction to user history;
            }
            else {
                cout << "Command not executed: No copies available\n";
                print();
            }
        }
    }
}

void CheckOutTransaction:: print() const{
    cout << setw (COMMAND_COL_WIDTH) << "Checkout" ;
    item->print();
}


