#include "returntransaction.h"
#include "checkouttransaction.h"
#include "itemfactory.h"
//#include "history.h"
//#include <list>


ReturnTransaction:: ReturnTransaction (){
    transactionType = 'R';
    user = NULL;
}
ReturnTransaction::ReturnTransaction(const ReturnTransaction& rhs) {
    item = rhs.item;
    user = rhs.user;
    lookUpItem = rhs.lookUpItem;
    userId = rhs.userId;
    transactionType = 'R';
}


ReturnTransaction::~ReturnTransaction() {
    item = NULL; // handled by other class.
    user = NULL; // handled by other class.
    delete lookUpItem;
}



Transaction* ReturnTransaction:: create(istream&infile){
    ReturnTransaction* newTransaction = new ReturnTransaction;
    
    int userId;
    infile >>userId;
    newTransaction->userId = userId;
    infile.get(); // read the blank space
    ItemFactory* factory = ItemFactory::instance();
    newTransaction->lookUpItem = factory -> createItem (infile);
    
    if(newTransaction->lookUpItem!=NULL){
        newTransaction->lookUpItem->initializePartial(infile);
    }
    return newTransaction;

}

void ReturnTransaction:: execute(ItemCollection& items, map <int, User*> & userCollection){
    
    
    if (userCollection.count(this->userId)>0){      // check if the user with the given id is in the map
        user = userCollection[this->userId];     // and if exist assign it to the oneUser
        
        if (this->lookUpItem!= NULL){
            item = items.retrieve(this->lookUpItem); // get the item from itemCollection
            
            if (item != NULL){ // if item exist in the itemCollection
                int checkout = item->getCheckedOutCopies(); // get the numbero of checkout copies
                
                // if they are still available copies, perform operation
                if (isCheckedOutByUser(this->item, this->user) && checkout > 0 && checkout <= item->getTotalCopies()){
                    item->setCheckedOutCopies (checkout-1);
                    
                    ReturnTransaction* copy = new ReturnTransaction(*this);
                    user->getHistory()->add(copy); // add trnsaction to user history;
                }
                else {
                    cout << "Command not executed: Invalid Return" << endl;
                    print();
                }
            }
        }
        else {
            cout<<"Wrong item type"<<endl;
        }
    }
}

bool ReturnTransaction::isCheckedOutByUser(Item* item, User* user) {
    History* history = user->getHistory();
    list<Transaction*> historyList = history->getHistory();
    
    list<Transaction*>::iterator iter = historyList.begin();
    for(; iter != historyList.end(); iter++) {
	CheckOutTransaction* checkout = dynamic_cast<CheckOutTransaction*>(*iter);
	if(checkout != NULL) {
	    if(*checkout->getItem() == *item) return true;
	}
    }
    return false;
}


void ReturnTransaction:: print() const{
    cout << setw(COMMAND_COL_WIDTH) << "Return";
    item->display();
}